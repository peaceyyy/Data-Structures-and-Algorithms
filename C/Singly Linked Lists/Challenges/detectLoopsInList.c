#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {

    int x;
    struct Node* next;
} node_t;

void insertAtEnd(node_t** head, int val){
   
    node_t* new_node = malloc(sizeof(node_t));
    new_node->x = val;
    new_node->next = NULL;
   
 
    node_t* trav = *head;
   
    while (trav -> next != NULL){
        trav = trav -> next;
    }
   
    trav -> next = new_node;
   
}

void insertAtBeginning(node_t** head, int val){
   
    node_t* new_node = malloc(sizeof(node_t));
    new_node->x = val;
    new_node->next = *head;
    *head = new_node;
   
}

int numOfNodes(node_t* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}


int main(){

    node_t* head = malloc(sizeof(node_t));
    head->x = 9;
    head->next = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 11);
    insertAtEnd(&head, 12);
    insertAtEnd(&head, 13);
    insertAtEnd(&head, 15);

 

    return 0;
}
