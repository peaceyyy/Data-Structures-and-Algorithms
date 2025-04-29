#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the end of the list
void appendNode(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
}

// Function to print the entire list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to rotate the list and print the last n nodes
void printLastNNodes(struct Node* head, int n);

// Main function to test the program
int main() {
    struct Node* head = NULL;

    appendNode(&head, 1);
    appendNode(&head, 3);
    appendNode(&head, 5);
    appendNode(&head, 11);

    printf("Original list:\n");
    printList(head);

    // Call the function to print the last n nodes
    printf("Last 2 nodes from the end of the said singly list:\n");
    printLastNNodes(head, 2);

    printf("Last 3 nodes from the end of the said singly list:\n");
    printLastNNodes(head, 3);

    printf("Last 4 nodes from the end of the said singly list:\n");
    printLastNNodes(head, 4);

    printf("Last 1 node from the end of the said singly list:\n");
    printLastNNodes(head, 1);

    printf("Last 5 nodes from the end of the said singly list:\n");
    printLastNNodes(head, 5);

    return 0;
}