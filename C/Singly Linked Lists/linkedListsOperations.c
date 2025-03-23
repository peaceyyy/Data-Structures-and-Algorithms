#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int value;
    struct node* next;
} node_t;


void printLinkedList(node_t* head){

    node_t* traverser = head;

    if (head == NULL){
        printf("The Linked List is empty");
    }

    while (traverser != NULL){

        printf("%d\n", traverser->value);
        traverser = traverser->next;
    
    }
}

void insertNodeAtEnd(node_t** head, int nodeValue){

    node_t* new_node = malloc(sizeof(node_t));

    if (new_node == NULL){
        printf("Failed to allocate memory for new node\n");
        exit(1);
    }

    new_node-> next = NULL;
    new_node-> value = nodeValue;

    if (*head == NULL){
        *head = new_node;
        return;
    }

    node_t* traverser = *head;

    while (traverser->next != NULL){
        traverser = traverser-> next;
    }

    traverser->next = new_node;


}

void insertNodeAtStart(node_t** head, int value){

    

    node_t* new_node = malloc(sizeof(node_t));
    
     if (new_node == NULL){
        printf("Failed to allocate memory for new node\n");
        exit(1);
    }


    new_node -> next = *head;
    new_node -> value = value;

    *head = new_node;
}


void insertNodeAfterAnElement (node_t* nodeToInsertAfter, int value){

    node_t* new_node = malloc(sizeof(node_t));

    if (new_node == NULL){
        printf("Failed to allocate memory for new node\n");
        exit(1);
    }

    new_node->value = value;
    new_node->next = nodeToInsertAfter->next;
    nodeToInsertAfter -> next = new_node;

}

void deallocateLinkedList(node_t** head){

    node_t* traverser = malloc(sizeof(node_t));

    traverser = *head;

    while (traverser != NULL){

        node_t* aux = traverser;
        traverser = traverser->next;
        free(aux);

    }

    *head = NULL;


}



int main(){

    node_t* root = NULL;

    insertNodeAtEnd(&root, 16);
    insertNodeAtEnd(&root, 12);
    insertNodeAtStart(&root, 19);

    printLinkedList(root);

    



    return 0;
}