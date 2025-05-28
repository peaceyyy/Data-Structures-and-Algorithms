#include <stdio.h>
#include <stdlib.h>


typedef struct Node {

    int data;
    struct Node* next;

} node_t;

void swapNodeValues (node_t* node1, node_t* node2)
{
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}


void bubbleSort(node_t* head)
{
    for (node_t* trav = head; trav -> next != NULL; trav = trav -> next)
    {
        for (node_t* traverser = head; traverser ->  next != NULL; traverser = traverser -> next) 
            if (traverser -> data > traverser -> next ->  data) swapNodeValues(traverser, traverser->next); 
        
    }
}


void insertSorted (node_t** head, node_t* nodeToInsert){

    if (*head == NULL || (*head)->data > nodeToInsert->data){
        nodeToInsert -> next = *head;
        *head = nodeToInsert;
      
    } else {
        node_t* trav = *head;
        for (; trav -> next != NULL && nodeToInsert -> data > trav -> next -> data; trav = trav -> next){}
        nodeToInsert -> next = trav -> next;
        trav -> next = nodeToInsert; 
    }
}


void insertionSort (node_t** head){

    node_t* trav = *head;
    node_t* sortedHead = NULL;

    while (trav != NULL){
        
        insertSorted(&sortedHead, trav);
        trav = trav -> next;

    }

    *head = sortedHead;

}

void selectionSort (node_t** head){


    node_t* curr = *head;

    for(; curr -> next != NULL; curr = curr -> next){
        
        node_t* minNode = curr;
        for (node_t* trav = curr -> next; trav != NULL; trav = trav -> next){
            if (minNode->data > trav -> data) minNode = trav;
        }

        if (minNode != curr) swapNodeValues(curr, minNode);

    }


}


// Function to create a new node
node_t* createNode(int data) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the linked list
void appendNode(node_t** head, int data) {
    node_t* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        node_t* trav = *head;
        while (trav->next != NULL) {
            trav = trav->next;
        }
        trav->next = newNode;
    }
}

// Function to print the linked list
void printList(node_t* head) {
    node_t* trav = head;
    while (trav != NULL) {
        printf("%d -> ", trav->data);
        trav = trav->next;
    }
    printf("NULL\n");
}

// Main function to test the sorting functions
int main() {
    node_t* head = NULL;

    // Create a linked list
    appendNode(&head, 4);
    appendNode(&head, 2);
    appendNode(&head, 5);
    appendNode(&head, 1);
    appendNode(&head, 3);

    printf("Original List:\n\n");
    printList(head);

    // Test bubble sort
    bubbleSort(head);
    printf("List after Bubble Sort:\n");
    printList(head);

    // Reset the list
    head = NULL;
    appendNode(&head, 4);
    appendNode(&head, 2);
    appendNode(&head, 5);
    appendNode(&head, 1);
    appendNode(&head, 3);

    // Test insertion sort
    insertionSort(&head);
    printf("List after Insertion Sort:\n");
    printList(head);

    // Reset the list
    head = NULL;
    appendNode(&head, 4);
    appendNode(&head, 2);
    appendNode(&head, 5);
    appendNode(&head, 1);
    appendNode(&head, 3);

    // Test selection sort
    selectionSort(&head);
    printf("List after Selection Sort:\n");
    printList(head);

    return 0;
}