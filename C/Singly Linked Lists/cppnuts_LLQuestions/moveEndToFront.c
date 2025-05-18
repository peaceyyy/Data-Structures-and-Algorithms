

#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct ListNode {
    int data;
    struct ListNode* next;
};

// Helper Function 1: Create a new node
struct ListNode* createNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Helper Function 2: Print linked list
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


struct ListNode* moveEndToFront (struct ListNode* head)
{
    struct ListNode* trav = head; 
    struct ListNode* prev = NULL; 
    
    while (trav -> next != NULL)
    {
        prev = trav;
        trav = trav -> next;
    }

    prev -> next = NULL;
    trav -> next = head;
    head = trav;

    return head;
}

// Main Function
int main() {
    // Test Case 1
    struct ListNode* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);
    printf("Test Case 1: Before moving last to front: ");
    printList(head1);
    head1 = moveEndToFront(head1);
    printf("Test Case 1: After moving last to front: ");
    printList(head1);
    // Expected Output: 4 1 2 3

    // Test Case 2
    struct ListNode* head2 = createNode(10);
    head2->next = createNode(20);
    printf("Test Case 2: Before moving last to front: ");
    printList(head2);
    head2 = moveEndToFront(head2);
    printf("Test Case 2: After moving last to front: ");
    printList(head2);
    // Expected Output: 20 10

    // Add more test cases as needed

    return 0;
}




