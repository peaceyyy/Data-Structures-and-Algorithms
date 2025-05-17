
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int x;
    struct Node* next;
} node_t;


int findKthNodeFromEnd (node_t* head, int k)
{
    if (head == NULL) return -1;


    int i = 0;
    node_t* runner = head;

    while (i < k)
    {
        runner = runner -> next;
        i++;
    }


    node_t* trav = head;

    while (runner != NULL)
    {
        trav = trav -> next;
        runner = runner -> next;
    }   

    return trav -> x;



}

// Function to create a new node
node_t* createNode(int value) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->x = value;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the end of the list
void appendNode(node_t** head, int value) {
    node_t* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    node_t* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(node_t* head) {
    node_t* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->x);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    node_t* head = NULL;

    // Append nodes to the list
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    // Print the list
    printf("Linked List: ");
    printList(head);

    int result = findKthNodeFromEnd(head, 4);
    printf("The 2nd node from the end is: %d\n", result);

    return 0;
}
