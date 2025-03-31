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
node_t *mergeTwoLinkedLists(node_t *head1, node_t *head2)
{

    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    node_t *trav = head1;
    while (trav->next != NULL)
    {
        trav = trav->next;
    }

    trav->next = head2;

    return head1;
}

node_t *mergeSortedLists(node_t *head1, node_t *head2)
{

    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    node_t *mergedHead = NULL;

    if (head1->x <= head2->x)
    {
        mergedHead = head1;
        head1 = head1->next;
    }
    else
    {
        mergedHead = head2;
        head2 = head2->next;
    }

    node_t *current = mergedHead;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->x <= head2->x)
        {
            current->next = head1;
            head1 = head1->next;
        }
        else
        {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }

    if (head1 != NULL)
    {
        current->next = head1;
    }
    else
    {
        current->next = head2;
    }

    return mergedHead;
}

int main()
{
    node_t *head2 = malloc(sizeof(node_t));
    head2->x = 9;
    head2->next = NULL;

    insertAtEnd(&head2, 10);
    insertAtEnd(&head2, 11);
    insertAtEnd(&head2, 12);
    insertAtEnd(&head2, 13);
    insertAtEnd(&head2, 15);

    node_t *head1 = malloc(sizeof(node_t));
    head1->x = 16;
    head1->next = NULL;

    insertAtEnd(&head1, 17);
    insertAtEnd(&head1, 18);
    insertAtEnd(&head1, 19);
    insertAtEnd(&head1, 20);
    insertAtEnd(&head1, 21);

    // node_t *mergedListHead = mergeTwoLinkedLists(head1, head2);

    // for (node_t *trav = mergedListHead; trav != NULL; trav = trav->next)
    //     printf("%d\n", trav->x);

    printf("-------------\n");
    node_t *mergedSortedListHead = mergeSortedLists(head1, head2);

    for (node_t *trav = mergedSortedListHead; trav != NULL; trav = trav->next)
        printf("%d\n", trav->x);

    return 0;
}
