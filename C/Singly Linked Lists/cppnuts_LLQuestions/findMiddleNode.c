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

// Placeholder for finding the middle node function
ListNode *findMiddleNode(ListNode *head)
{

    ListNode *slowPtr = head;
    ListNode *fastPtr = head;

    while (fastPtr != NULL && fastPtr->next != NULL)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    return slowPtr;
}

int main()
{
    // Test Case 1: Odd number of nodes
    ListNode *head1 = NULL;
    appendNode(&head1, 1);
    appendNode(&head1, 2);
    appendNode(&head1, 3);
    appendNode(&head1, 4);
    appendNode(&head1, 5);
    printf("Test Case 1: ");
    ListNode *middle1 = findMiddleNode(head1);
    if (middle1)
    {
        printf("Middle node value: %d\n", middle1->val);
    }
    else
    {
        printf("List is empty.\n");
    }
    // Expected Output: Middle node value: 3

    // Test Case 2: Even number of nodes
    ListNode *head2 = NULL;
    appendNode(&head2, 1);
    appendNode(&head2, 2);
    appendNode(&head2, 3);
    appendNode(&head2, 4);
    printf("Test Case 2: ");
    ListNode *middle2 = findMiddleNode(head2);
    if (middle2)
    {
        printf("Middle node value: %d\n", middle2->val);
    }
    else
    {
        printf("List is empty.\n");
    }
    // Expected Output: Middle node value: 3

    // Test Case 3: Single node
    ListNode *head3 = createNode(1);
    printf("Test Case 3: ");
    ListNode *middle3 = findMiddleNode(head3);
    if (middle3)
    {
        printf("Middle node value: %d\n", middle3->val);
    }
    else
    {
        printf("List is empty.\n");
    }
    // Expected Output: Middle node value: 1

    // Test Case 4: Empty list
    ListNode *head4 = NULL;
    printf("Test Case 4: ");
    ListNode *middle4 = findMiddleNode(head4);
    if (middle4)
    {
        printf("Middle node value: %d\n", middle4->val);
    }
    else
    {
        printf("List is empty.\n");
    }
    // Expected Output: List is empty.

    return 0;
}