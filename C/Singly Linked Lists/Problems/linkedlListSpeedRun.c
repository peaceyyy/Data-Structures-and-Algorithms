//10:29

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

    int val;
    struct Node* next;
} node_t;

node_t* createNode(int val)
{
    node_t* newNode = malloc(sizeof(node_t));

    if (newNode == NULL)
    {
        printf("Memory allocation for Node failed");
        exit(1);
    }

    newNode->next = NULL;
    newNode->val = val;

    return newNode;
}

void insertNodeAtEnd (node_t** head, int val)
{
    node_t* newNode = createNode(val);

    if(*head == NULL)
    {
        *head = newNode;
        return;    
    }

    
    node_t* trav = *head;

    while (trav -> next != NULL)
    {
        trav = trav-> next;
    }

    trav->next = newNode;
}


void insertNodeAtBeginning (node_t** head, int val)
{
    node_t* newNode = createNode(val);

    if(*head == NULL)
    {
        *head = newNode;
        return;    
    }

    newNode->next = *head;
    *head = newNode;

}

void insertAtMiddle (node_t** head, int n, int val)
{
    node_t* newNode = createNode(val);

    if(n == 1)
    {
        *head = newNode;
        return;    
    }

    int i = 0;
    node_t* trav = *head;

    while (i < n && trav -> next != NULL)
    {
        trav = trav -> next;
        i++;
    }

    newNode->next = trav->next;
    trav->next = newNode;

}


void deleteNode(node_t **head, int k) {
    if (*head == NULL) {
        fprintf(stderr, "LL is already empty\n");
        return;
    }
    node_t* temp;
    node_t* trav = *head;

    if (k == 0) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    } else {
        int i = 0;
        while (i < k - 1) {
            if (trav == NULL || trav->next == NULL) {
                fprintf(stderr, "Index K out of bounds!\n");
                return;
            }
            trav = trav->next;
            i++;
        }

        if (trav->next != NULL) {
            temp = trav->next;
            trav->next = trav->next->next;
            free(temp);
        } else {
            fprintf(stderr, "Index K out of bounds!\n");
        }
    }
}

void printLL (node_t* head)
{
    if (head == NULL)
    {
        printf("LL is empty");
        exit(0);
    }

    node_t* trav = head;

    while (trav != NULL) 
    {
        if (trav -> next != NULL) printf("%d -> ", trav->val);
        else printf("%d", trav->val);
        trav = trav -> next;
    }

} 








int main()
{
    node_t* head = createNode(1);
    insertNodeAtEnd(&head, 2);
    insertAtMiddle(&head, 3, 3);
    insertNodeAtEnd(&head, 4);
    insertNodeAtEnd(&head, 5);
    insertNodeAtBeginning(&head, 0);
    insertNodeAtBeginning(&head, -1);
    deleteNode(&head, 8);
    
    printLL(head);

    return 0;
}

