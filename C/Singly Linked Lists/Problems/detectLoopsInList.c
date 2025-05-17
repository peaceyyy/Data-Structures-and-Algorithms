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


bool detectForLoops (node_t* head)
{

    node_t* slowPtr = head;
    node_t* fastPtr = head;


    while (fastPtr != NULL && fastPtr -> next != NULL)
    
    {

           slowPtr = slowPtr -> next;
        fastPtr = fastPtr ->next -> next;

        if (slowPtr == fastPtr){
            return true;
        }


     
    }

    return false;
}   



int main() {
    node_t* head = malloc(sizeof(node_t));
    head->x = 9;
    head->next = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 11);
    insertAtEnd(&head, 12);
    insertAtEnd(&head, 13);
    insertAtEnd(&head, 15);

        node_t* temp = head;
    node_t* loopStart = head->next; // This is the node with value 10

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Create a loop
    temp->next = loopStart;
    

    // Test for loop detection
    if (detectForLoops(head)) {
        printf("Loop detected in the linked list.\n");
    } else {
        printf("No loop detected in the linked list.\n");
    }

    return 0;
}