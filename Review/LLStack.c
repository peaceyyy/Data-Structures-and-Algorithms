#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {

    int data; 
    struct Node* next;
    
} node_t;



node_t* createNode (int value){

    node_t* newNode = (node_t*) malloc(sizeof(node_t));
    newNode -> data = value;
    newNode -> next = NULL;

    return newNode;
}



bool isEmpty (node_t* head){

    return head == NULL;
}


void push (node_t** head, int value){
    
    node_t* newNode = createNode(value);

    if (isEmpty(*head)){
        *head = newNode;
    }  else {

        newNode -> next = *head; 
        *head = newNode; 
    }

}


int pop (node_t** head){
    

    if (isEmpty(*head)){
        printf("Stack is empty!");
        return -1;
    }  else {

        int tempData = (*head)->data;
        node_t* tempNode = *head; 

        (*head) = (*head) -> next;
        free(tempNode);
        return tempData;
    }

}


int peek (node_t** head){
    

    if (isEmpty(*head)){
        printf("Stack is empty!");
        return -1;
    }  else return (*head)->data;
}


void displayStack (node_t* head){
    
    node_t* trav = head;
    while (trav != NULL){
        printf("%d -> ", trav->data);
        trav = trav -> next;
    }
}
void freeStack (node_t* head){
    
    node_t* trav = head;
    while (trav != NULL){
        node_t* temp = trav;
        trav = trav -> next;
        free(temp);
        temp = NULL;
    }
}



int main(){

    node_t* L1 = NULL;
    push(&L1, 10);
    push(&L1, 20);
    push(&L1, 30);
    displayStack(L1);
    printf("\n%d\n", pop(&L1));
    displayStack(L1);
    printf("\n%d\n\n", peek(&L1));
    displayStack(L1);


    return 0;
}