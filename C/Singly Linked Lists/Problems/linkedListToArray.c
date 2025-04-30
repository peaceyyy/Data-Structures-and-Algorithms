// 10:29

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{

    int val;
    struct Node *next;
} node_t;

node_t *createNode(int val)
{
    node_t *newNode = malloc(sizeof(node_t));

    if (newNode == NULL)
    {
        printf("Memory allocation for Node failed");
        exit(1);
    }

    newNode->next = NULL;
    newNode->val = val;

    return newNode;
}

void insertNodeAtEnd(node_t **head, int val)
{
    node_t *newNode = createNode(val);

    if (*head == NULL)
    {
        *head = newNode;
    }

    else
    {
        node_t *trav = *head;

        while (trav->next != NULL)
        {
            trav = trav->next;
        }

        trav->next = newNode;
    }
}

void insertNodeAtBeginning(node_t **head, int val)
{
    node_t *newNode = createNode(val);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    newNode->next = *head;
    *head = newNode;
}

void insertAtMiddle(node_t **head, int n, int val)
{
    node_t *newNode = createNode(val);

    if (n == 1)
    {
        *head = newNode;
        return;
    }

    int i = 0;
    node_t *trav = *head;

    while (i < n && trav->next != NULL)
    {
        trav = trav->next;
        i++;
    }

    newNode->next = trav->next;
    trav->next = newNode;
}

void deleteNode(node_t **head, int n, int val)
{

    if (n == 1 && (*head)->next != NULL)
    {
        *head = (*head)->next;
    }

    int i = 0;
    node_t *trav = *head;

    while (i < n && trav->next != NULL)
    {
        trav = trav->next;
        i++;
    }

    node_t *aux = trav->next;
    trav->next = trav->next->next;

    free(aux);
}
void printLL(node_t *head)
{
    if (head == NULL)
    {
        printf("LL is empty");
        exit(0);
    }

    node_t *trav = head;

    while (trav != NULL)
    {
        if (trav->next != NULL)
            printf("%d -> ", trav->val);
        else
            printf("%d", trav->val);
        trav = trav->next;
    }
}

int *LLToArr(node_t *head)
{
    int *dataArr = malloc(sizeof(100));

    node_t *trav = head;
    int i = 0;

    while (trav != NULL)
    {

        dataArr[i++] = trav->val;
        trav = trav->next;
    }

    return dataArr;
}

int main()
{
    node_t *head = NULL;
    int numOfNodes;

    printf("Input the number of nodes: ");
    scanf("%d", &numOfNodes);
    int data;

    for (int i = 0; i < numOfNodes; i++)
    {
        printf("Input data for Node %d: ", i + 1);
        scanf("%d", &data);
        insertNodeAtEnd(&head, data);
    }
    int *LLArray = LLToArr(head);

    for (int i = 0; i < numOfNodes; i++)
        printf("%d ", LLArray[i]);

    return 0;
}
