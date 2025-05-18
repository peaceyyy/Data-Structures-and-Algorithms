#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

// Utility function to create a new node
ListNode *createNode(int val) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the end of the list
void appendNode(ListNode **head, int val) {
    ListNode *newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    ListNode *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(ListNode *head) {
    ListNode *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Placeholder for loop detection function
int hasLoop(ListNode *head) {

    if (head == NULL) return 0;
    
    ListNode* slowPtr = head;
    ListNode* fastPtr = head;

    while (fastPtr ->next != NULL && fastPtr != NULL)
    {
        fastPtr = fastPtr ->next ->next;
        slowPtr = slowPtr -> next;

        if (slowPtr == fastPtr) return 1;
    }
    return 0;
}
int main() {
    // Test Case 1: No Loop
    ListNode *head1 = NULL;
    appendNode(&head1, 1);
    appendNode(&head1, 2);
    appendNode(&head1, 3);
    appendNode(&head1, 4);
    appendNode(&head1, 5);
    printf("Test Case 1: ");
    if (hasLoop(head1)) {
        printf("Loop detected in the linked list.\n");
    } else {
        printf("No loop detected in the linked list.\n");
    }
    // Expected Output: No loop detected in the linked list.

    // Test Case 2: Loop at the End
    ListNode *head2 = NULL;
    appendNode(&head2, 1);
    appendNode(&head2, 2);
    appendNode(&head2, 3);
    appendNode(&head2, 4);
    appendNode(&head2, 5);
    head2->next->next->next->next->next = head2->next->next; // Create loop
    printf("Test Case 2: ");
    if (hasLoop(head2)) {
        printf("Loop detected in the linked list.\n");
    } else {
        printf("No loop detected in the linked list.\n");
    }
    // Expected Output: Loop detected in the linked list.

    // Test Case 3: Single Node, No Loop
    ListNode *head3 = createNode(1);
    printf("Test Case 3: ");
    if (hasLoop(head3)) {
        printf("Loop detected in the linked list.\n");
    } else {
        printf("No loop detected in the linked list.\n");
    }
    // Expected Output: No loop detected in the linked list.

    // Test Case 4: Single Node, Loop to Itself
    ListNode *head4 = createNode(1);
    head4->next = head4; // Create loop
    printf("Test Case 4: ");
    if (hasLoop(head4)) {
        printf("Loop detected in the linked list.\n");
    } else {
        printf("No loop detected in the linked list.\n");
    }
    // Expected Output: Loop detected in the linked list.

    // Test Case 5: Empty List
    ListNode *head5 = NULL;
    printf("Test Case 5: ");
    if (hasLoop(head5)) {
        printf("Loop detected in the linked list.\n");
    } else {
        printf("No loop detected in the linked list.\n");
    }
    // Expected Output: No loop detected in the linked list.

    return 0;
}