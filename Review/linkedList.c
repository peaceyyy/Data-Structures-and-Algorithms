#include <stdio.h>
#include <stdlib.h>


typedef struct Node {

    int x; 
    struct Node* next;

} node_t;


void initLL(node_t** head, int val){

    *head = malloc(sizeof(node_t));
    (*head)->next = NULL;
    (*head)->x = val;
}

node_t* createNode (int val){

    node_t* newNode = (node_t*) malloc(sizeof(node_t));
    newNode->next = NULL;
    newNode->x = val;
}

void insertAtHead (node_t** head, int val){


    node_t* newNode = createNode(val);
    
    if (*head == NULL){

        *head = newNode; 

    } else {

        newNode->next = *head;
        *head = newNode;
    }
}


void insertAtEnd(node_t** head, int val){

    node_t* newNode = createNode(val);

    if (*head == NULL){

        *head = newNode; 

    } else {
        node_t* trav = *head;
        for (;trav -> next != NULL; trav = trav -> next){}
        trav -> next = newNode;
    }
}


void insertAtKthNode(node_t** head, int val, int k){

    node_t* newNode = createNode(val);

    if (*head == NULL || k == 1){

        *head = newNode; 

    } else { 
        node_t* trav = *head;
        int n = 0;

        for (;trav -> next != NULL && n < k - 1; trav = trav -> next)  n++;
        
        if (trav -> next != NULL){
            newNode -> next = trav -> next; 
            trav -> next = newNode;
        } else {
            trav -> next = newNode;
        }
        

    } 
}


void printLL (node_t* head){
    
    node_t* trav = head;
    while (trav != NULL){
        printf("%d -> ", trav->x);
        trav = trav -> next;
    }
}

int returnMiddle(node_t* head){


    node_t* slow = head;
    node_t* fast = head;

    while (fast != NULL && fast->next != NULL){

        slow = slow->next;
        fast = fast->next->next;

    }

    return slow->x;

}



int main (){

    node_t* L1 = NULL;
    initLL(&L1, 1);

    insertAtHead(&L1, 0);
    insertAtEnd(&L1, 2);
    insertAtEnd(&L1, 3);
    insertAtEnd(&L1, 4);
    insertAtKthNode(&L1, 5, 7);

    printLL(L1);


    printf("The middle of the list is %d", returnMiddle(L1));
}