#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

// Utility function to create a new node
ListNode *createNode(int val)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the end of the list
void appendNode(ListNode **head, int val)
{
    ListNode *newNode = createNode(val);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    ListNode *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}
ListNode *reverseList(ListNode *head)
{

    ListNode *prev = NULL;
    ListNode *trav = head;

    while (trav != NULL)
    {
        ListNode *nextNode = trav->next;
        trav->next = prev;
        prev = trav;
        trav = nextNode;
    }

    head = prev;
    return head;
}

int main()
{
    // Test Case 1: Multiple nodes
    ListNode *head1 = NULL;
    appendNode(&head1, 1);
    appendNode(&head1, 2);
    appendNode(&head1, 3);
    appendNode(&head1, 4);
    appendNode(&head1, 5);
    printf("Original List 1: ");
    printList(head1);
    head1 = reverseList(head1);
    printf("Reversed List 1: ");
    printList(head1);
    // Expected Output: Reversed List 1: 5 -> 4 -> 3 -> 2 -> 1 -> NULL

    // Test Case 2: Single node
    ListNode *head2 = createNode(1);
    printf("Original List 2: ");
    printList(head2);
    head2 = reverseList(head2);
    printf("Reversed List 2: ");
    printList(head2);
    // Expected Output: Reversed List 2: 1 -> NULL

    // Test Case 3: Empty list
    ListNode *head3 = NULL;
    printf("Original List 3: ");
    printList(head3);
    head3 = reverseList(head3);
    printf("Reversed List 3: ");
    printList(head3);
    // Expected Output: Reversed List 3: NULL

    return 0;
}