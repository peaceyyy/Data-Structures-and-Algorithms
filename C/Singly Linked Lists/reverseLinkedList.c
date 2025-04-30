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

void reverseLinkedList (struct Node **head_ref){

    struct Node *prev = NULL;
    struct Node *trav = *head_ref;
   

    while (trav != NULL)
    {
        struct Node *nextNode = trav -> next;
        trav -> next = prev;
        prev = trav;
        trav = nextNode;
    }

    *head_ref = prev;

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

    printList(head);
    reverseLinkedList(&head);
    printList(head);

    return 0;
}
