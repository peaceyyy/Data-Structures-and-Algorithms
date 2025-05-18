

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

// Placeholder for printing the linked list in reverse
void printListInReverse(ListNode *node) {
    

    if (node == NULL) return;

    printListInReverse(node->next);
    printf("%d ->", node->val);
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

// Function to free the linked list
void freeList(ListNode *head) {
    ListNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Test Case 1: Multiple nodes
    ListNode *head1 = NULL;
    appendNode(&head1, 1);
    appendNode(&head1, 2);
    appendNode(&head1, 3);
    appendNode(&head1, 4);
    appendNode(&head1, 5);
    printf("Original List 1: ");
    printList(head1);
    printf("\nReversed List 1: ");
    printListInReverse(head1);
    

    return 0;
}