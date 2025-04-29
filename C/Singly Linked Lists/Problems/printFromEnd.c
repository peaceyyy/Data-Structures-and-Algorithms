#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *next;
};


struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void appendNode(struct Node **head_ref, int new_data)
{
    struct Node *newNode = createNode(new_data);
    struct Node *last = *head_ref;

    if (*head_ref == NULL)
    {
        *head_ref = newNode;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = newNode;
}


void printLastNNodes(struct Node *head, int n)
{

    int i = 0;
    struct Node *runningPtr = head;

    while (i < n)
    {
        runningPtr = runningPtr -> next;
        i++;
    }

    struct Node *trav = head;

    while (trav != NULL)
    {   
        if (runningPtr != NULL)
        {
            runningPtr = runningPtr -> next;
            trav = trav -> next;
        } else {

            printf("%d ", trav -> data);
            trav = trav -> next;
        }
}
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


int main()
{
    struct Node *head = NULL;

    appendNode(&head, 1);
    appendNode(&head, 3);
    appendNode(&head, 5);
    appendNode(&head, 11);

    printf("Original list:\n");
    printList(head);

    printf("\nLast 2 nodes from the end of the said singly list:\n");
    printLastNNodes(head, 2);

    printf("\nLast 3 nodes from the end of the said singly list:\n");
    printLastNNodes(head, 3);

    printf("\nLast 4 nodes from the end of the said singly list:\n");
    printLastNNodes(head, 4);

    printf("\nLast 1 node from the end of the said singly list:\n");
    printLastNNodes(head, 1);

    printf("\nLast 5 nodes from the end of the said singly list:\n");
    printLastNNodes(head, 5);

    return 0;
}
