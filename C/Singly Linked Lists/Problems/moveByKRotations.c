
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
void moveByKTimesToTheRight (struct Node** head, int kRotations)
{
    int nodeCount = 1;
    struct Node* trav = *head;

    while (trav->next != NULL)
    {
        trav = trav -> next;
        nodeCount++;
    }

    int k = kRotations % nodeCount, i = 0;
    if (k == 0) return;
 
    trav->next = *head;
    struct Node* trav2 = *head;

    while (i < nodeCount - k)
    {
        trav2 = trav2 -> next;
        i++;
    }
    
  
    *head = trav2->next;
    trav2 -> next = NULL;
}

int main() {
    struct Node* head = NULL;

    // Append nodes to the list
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    printf("Original list: ");
    printList(head);

    // Rotate the list by k positions
    int k = 4;
    moveByKTimesToTheRight(&head, k);

    printf("List after moving by %d positions to the right: ", k);
    printList(head);

    return 0;
}
