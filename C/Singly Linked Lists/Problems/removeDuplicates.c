#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int x;
    struct Node *next;
} node_t;

void insertAtEnd(node_t **head, int val)
{

    node_t *new_node = malloc(sizeof(node_t));
    new_node->x = val;
    new_node->next = NULL;

    node_t *trav = *head;

    while (trav->next != NULL)
    {
        trav = trav->next;
    }

    trav->next = new_node;
}

void insertAtBeginning(node_t **head, int val)
{

    node_t *new_node = malloc(sizeof(node_t));
    new_node->x = val;
    new_node->next = *head;
    *head = new_node;
}

void removeDuplicates(node_t *head)
{
    if (head == NULL || head->next == NULL)
    {
        printf("LL is empty or only has one element\n");
        return;
    }

    node_t *trav = head;
    node_t *temp;

    while (trav->next != NULL)
    {
        if (trav->x == trav->next->x)
        {
            temp = trav->next;
            trav->next = trav->next->next;
            free(temp);
        }
        else
        {
            trav = trav->next; 
        }
    }
}


int main()
{

    node_t *head = malloc(sizeof(node_t));
    head->x = 9;
    head->next = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 11);
    insertAtEnd(&head, 11);
    insertAtEnd(&head, 12);
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 17);
    insertAtEnd(&head, 19);
    removeDuplicates(head);

    for (node_t *trav = head; trav != NULL; trav = trav->next)
        printf("%d\n", trav->x);

    return 0;
}
