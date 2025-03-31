#include <stdio.h>
#include <stdlib.h>

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
node_t* findMiddleNode(node_t* head) {
    int nodeCount = numOfNodes(head);  // Get total number of nodes
    int midIndex = nodeCount / 2;    
    node_t* trav = head;
    for (int i = 0; i < midIndex; i++) {
        trav = trav->next;  // Traverse to the middle node
    }

    return trav;
}

//Solution using Floyd's Cycle Detection Algo
node_t* findMiddleNodeTwoPointer(node_t* head) {
    node_t* slow = head;
    node_t* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;         // Move slow one step
        fast = fast->next->next;   // Move fast two steps
    }

    return slow;  // Slow will be at the middle
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
  
    for(node_t* trav = head; trav != NULL; trav = trav -> next) printf("%d\n", trav->x);
   
    node_t* middleNode = findMiddleNode(&head);
    printf("Middle node is at %p with the value of %d", middleNode, middleNode->x);

    return 0;
}
