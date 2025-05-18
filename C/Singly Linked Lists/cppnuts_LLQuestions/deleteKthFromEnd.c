
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int x;
    struct Node* next;
} node_t;


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

void deleteKthNodeFromEnd (node_t** head, int k)
{

    if (*head == NULL || k <= 0) return;

    node_t* runner = *head;
    int i = 0;


    while (i < k)
    {
        if (runner == NULL){
            printf("index out of bounds!");
            exit(0);
            // return;
        }
        runner = runner -> next;
        i++;
    }   

    if (runner == NULL)
    {
        (*head) = (*head) -> next;
        return;
    }

    node_t* prev = NULL;
    node_t* trav = *head;

    while (runner != NULL){
        prev = trav;
        runner = runner -> next;
        trav = trav -> next;
    }

    node_t* temp = trav;
     
    if (trav -> next != NULL)
    {
        prev -> next = trav -> next;  
    } else {
        prev -> next = NULL;
    }

    free(trav);
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

    int k = 6;
    printf("\n\nRemoved %dth from end of list:\n", k);
    deleteKthNodeFromEnd(&head, k);
    printList(head);

    return 0;
}
