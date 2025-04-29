#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{

    int val;
    struct Node *next;

} node_t;

node_t *createNode(int val)
{

    node_t *Node = malloc(sizeof(node_t));
    Node->val = val;
    Node->next = NULL;

    return Node;
}



node_t *mergeSortedLists(node_t *head1, node_t *head2)
{

    node_t* newHead = NULL;


    if (head1 -> val <= head2 -> val)
    {
        newHead = head1;
        head1 = head1 -> next;
    } else {
        newHead = head2;
        head2 = head2 -> next;
    }

    node_t* trav = newHead;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1 -> val <= head2 ->val)
        {
            trav -> next = head1;
            head1 = head1 -> next;
        } else {
            trav -> next = head2;
            head2 = head2 -> next;
        }   

        trav = trav -> next;
    }

    if (head1 !=NULL) trav -> next = head1;
    else if (head2 !=NULL) trav -> next = head2;

    return newHead;

}

void printList(node_t *head)
{
    node_t *currNode = head;
    while (currNode)
    {
        printf("%d -> ", currNode->val);
        currNode = currNode->next;
    }
    printf("NULL\n");
}

int main()
{
    // First sorted linked list: 1 -> 3 -> 5
    node_t *head1 = createNode(1);
    head1->next = createNode(3);
    head1->next->next = createNode(5);

    // Second sorted linked list: 2 -> 4 -> 6
    node_t *head2 = createNode(2);
    head2->next = createNode(4);
    head2->next->next = createNode(6);

    printf("List 1: ");
    printList(head1);
    printf("List 2: ");
    printList(head2);

    node_t *mergedHead = mergeSortedLists(head1, head2);

    printf("Merged List: ");
    printList(mergedHead);

    return 0;
}
