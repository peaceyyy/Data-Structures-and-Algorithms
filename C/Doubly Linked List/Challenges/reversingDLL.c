#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node_t;

// Helper function to create a new node
node_t* createNode(int data) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

node_t* reverseDoublyLinkedList(node_t* head) {
    if (head == NULL) {
        fprintf(stderr, "List is empty\n");
        return NULL;
    }

    node_t* trav = head;
    node_t* newHead = NULL;

    while (trav != NULL) {
        node_t* temp = trav->next;

        // Swap next and prev pointers
        trav->next = trav->prev;
        trav->prev = temp;
        
        newHead = trav; // Track the new head (last node reached)
        trav = temp;
    }

    return newHead; 
}

// Helper function to insert a node at the end of the list
node_t* insertAtEnd(node_t* head, int data) {
    node_t* newNode = createNode(data);
    if (!head) return newNode;

    node_t* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Helper function to print a doubly linked list
void printList(node_t* head) {
    node_t* temp = head;
    printf("Forward: ");
    while (temp) {
        printf("%d ", temp->data);
        if (temp->next == NULL) break; // Stop at the last node for reverse printing
        temp = temp->next;
    }
    printf("\n");

    printf("Reverse: ");
    while (temp) { // Print in reverse order
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Function to test reversing a doubly linked list
void testReverse() {
    printf("Testing Reverse Doubly Linked List...\n");

    // Create sample doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    node_t* head = NULL;
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);

    printf("Original List:\n");
    printList(head);

    // Call the reverse function
    head = reverseDoublyLinkedList(head);

    printf("Reversed List:\n");
    printList(head);
}

// Main function to run the test
int main() {
    testReverse();
    return 0;
}

