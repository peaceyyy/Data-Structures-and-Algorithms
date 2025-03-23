#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int x;
    struct Node* prev;
    struct Node* next;
} node_t;

void initializeDoublyLinkedList(node_t ** head, node_t** tail, int val){
    node_t* new_node = malloc(sizeof(node_t));
    new_node->x = val;
    new_node->next = NULL;
    new_node->prev = NULL;
    *head = new_node;
    *tail = new_node;
}

void printDoublyLinkedListFromStart(node_t* head){
    node_t* traverser = head;
    while (traverser != NULL) {
        printf("%d\n", traverser->x);
        traverser = traverser->next;
    }
}

void printDoublyLinkedListFromEnd(node_t* tail){
    node_t* traverser = tail;
    while (traverser != NULL) {
        printf("%d\n", traverser->x);
        traverser = traverser->prev;
    }
}

void insertAtBeginning(node_t** head, int val) {
    node_t* new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    new_node->prev = NULL;
    new_node->x = val;
    new_node->next = *head;

    (*head)->prev = new_node;

    *head = new_node;
}

void insertAtEnd(node_t** tail, int val){
    node_t* new_node = malloc(sizeof(node_t));
    new_node->x = val;
    new_node->next = NULL;
    new_node->prev = *tail;
    (*tail) -> next = new_node; 
    *tail = new_node;
}

void insertAfterANode(node_t* node, int val){

    node_t* new_node = malloc(sizeof(node_t));
    new_node->x = val;
    new_node -> prev = node;
    new_node->next = node->next;
    if (node->next != NULL){
        node->next->prev = new_node;
    }
  
    node -> next = new_node;
}

void insertBeforeANode(node_t* node, int val){

    node_t* new_node = malloc(sizeof(node_t));
    new_node->x = val;

    new_node -> prev = node -> prev;
    new_node->next = node;

    if (node->prev != NULL){
        node->prev->next = new_node;
    }
  
    node -> prev = new_node;
}


void removeAValue(node_t** head, int valToRemove) {
    if (head == NULL || *head == NULL) {
        printf("Error: The list is empty.\n");
        return;
    }

    node_t* traverser = *head;

    // Traverse the list to find the node to remove
    while (traverser != NULL && traverser->x != valToRemove) {
        traverser = traverser->next;
    }

    // If the node was not found
    if (traverser == NULL) {
        printf("Error: Value not found in the list.\n");
        return;
    }

    // If the node to be removed is the head
    if (traverser == *head) {
        *head = traverser->next;
    }

    // Update the pointers
    if (traverser->prev != NULL) {
        traverser->prev->next = traverser->next;
    }
    if (traverser->next != NULL) {
        traverser->next->prev = traverser->prev;
    }

    // Free the node
    free(traverser);
}

void removeANode(node_t* node){

    if (node -> prev != NULL){

        node -> prev -> next = node -> next;
    }

    if (node -> next != NULL){
        node -> next -> prev = node -> prev;
    }

    free(node);
}

int countNumOfNodes(node_t *node){

    int nodeCount = 0;

    if (node == NULL){
        return nodeCount;
    }

    return 1 + countNumOfNodes(node->prev);

}

void reverseLinkedList(node_t** head, node_t** tail){

        
    if ((*head == NULL) || (*head)->next == NULL)
    {
        return;
    }

    node_t* traverser = *head;
    

    while (traverser != NULL){
        node_t* nextNode = traverser -> next;
        traverser -> next = traverser -> prev;
        traverser -> prev = nextNode;
        traverser = nextNode;

    }

    node_t* temp = *tail;
    *tail = *head;
    *head = temp;

}


int main(){
    node_t* head = NULL;
    node_t* tail = NULL;

    initializeDoublyLinkedList(&head, &tail, 7);
    insertAtEnd(&tail,8);
    insertAtBeginning(&head, 69);
    insertAtEnd(&tail,15);
    insertAtEnd(&tail,9);
    insertAtEnd(&tail,18);
    insertAfterANode(head->next -> next, 3);
    printDoublyLinkedListFromStart(head);
    printf("-----------\n");
    reverseLinkedList(&head, &tail);
    printDoublyLinkedListFromStart(head);
    

    // printf("\nThere are %d nodes in the DLL", countNumOfNodes(tail));

    return 0;
}
