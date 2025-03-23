/*

4. Insert a Node at the Head
Description: Insert a new node at the beginning of a doubly linked list.
Return Type: node_t* (new head of the list)
Parameters: node_t* head, int value


5. Delete a Node from a Given Position
Description: Delete the node at a given position in a doubly linked list.
Return Type: node_t* (new head of the list)
Parameters: node_t* head, int position


*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} node_t;

// Function prototypes
node_t* insertAtHead(node_t* head, int val);
node_t* deleteNode(node_t* head, int pos);

// Function to print the doubly linked list
void printList(node_t* head) {
    node_t* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test the insert and delete functions
int main() {
    node_t* head = NULL;

    // Insert nodes at the head
    head = insertAtHead(head, 10);
    head = insertAtHead(head, 20);
    head = insertAtHead(head, 30);
    head = insertAtHead(head, 40);

    printf("List after insertions:\n");
    printList(head);

    // Delete node at position 2
    head = deleteNode(head, 2);
    printf("\nList after deleting node at position 2:\n");
    printList(head);

    // Delete the head node
    head = deleteNode(head, 1);
    printf("\nList after deleting head:\n");
    printList(head);

    return 0;
}

node_t* insertAtHead(node_t* head, int val) {
    node_t* newNode = malloc(sizeof(node_t));
    
    if (newNode == NULL) {
        fprintf(stderr, "Memory Allocation Failed!\n");
        exit(1);
    }
    
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;
    
    if (head != NULL) {
        head->prev = newNode;
    }
    
    return newNode;  
}

node_t* deleteNode(node_t* head, int pos) {
    if (head == NULL) {
        return NULL;  
    }

    node_t* trav = head;
    
    if (pos == 1) {  // Deleting the first node
        node_t* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }

    int k = 1;  
    while (k < pos - 1 && trav->next != NULL) {
        trav = trav->next;
        k++;
    }

    if (trav->next == NULL) {
        return head;  // Position out of range
    }

    node_t* temp = trav->next;

    if (trav->next->next != NULL) {
        trav->next->next->prev = trav;
    }

    trav->next = trav->next->next;

    free(temp);

    return head;
}