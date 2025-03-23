#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int x;
    struct Node* next;
} Node;


void printLinkedList(Node* head){
    Node* traverser = head;

    if(head == NULL){
        printf("Linked list is empty");
        exit(4);
    }

    while (traverser != NULL){
        printf("%d\n", traverser->x);
        traverser = traverser -> next;
    }

}


void insertAtBeginningOfList(Node** head, int val){

    Node* new_node = malloc(sizeof(Node));

    new_node -> next = *head;
    new_node -> x = val;
    *head = new_node;

}

void insertAtEndOfList(Node** head, int val){

    Node* new_node = malloc(sizeof(Node));

    new_node -> next = NULL;
    new_node -> x = val;

    Node* traverser = *head;

    while (traverser -> next != NULL){

        traverser = traverser -> next;

    }

    traverser -> next = new_node;
    
}

void insertAfterAnElement(Node* nodeToInsertAfter, int val){

    Node* new_node = malloc(sizeof(Node));

    new_node -> x = val;
    new_node -> next = nodeToInsertAfter -> next;
    nodeToInsertAfter -> next = new_node;

}

void deleteNode(Node** head, int valueToDelete){

    if(*head == NULL){

        printf("Linked List is empty");
        return;
    }

    Node* temp;
    if (*head != NULL && (*head)->x == valueToDelete) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    Node* traverser = *head;

    while (traverser -> next != NULL){

        if (traverser->next->x == valueToDelete){
            temp = traverser -> next;
            traverser -> next = traverser -> next -> next;
            free(temp);
            return;
        }
        
        traverser = traverser -> next;
    }

}

void reverserALinkedList(Node** head){

    if((*head == NULL) || (*head)->next == NULL){
        printf("List is empty or has only one node");
        return;
    }

    Node* traverser = *head;
    Node* prev = NULL;

    while(traverser!= NULL){

        Node* nextNode = traverser->next;
        traverser -> next = prev;
        prev = traverser;
        traverser = nextNode;

    }

     *head = prev;

}


void deallocateLinkedList(Node** head){

    Node* traverser = *head;


    while (traverser != NULL){
        Node* aux =  traverser;
        traverser = traverser -> next;
        free(aux);
    }

    *head = NULL;

}


int main(){

    Node* head = malloc(sizeof(Node));
    Node n2;

    head->x = 10;
    head->next = &n2;

    n2.x = 12;
    n2.next = NULL;

    
    insertAtBeginningOfList(&head, 19);
    insertAtBeginningOfList(&head, 29);
    insertAtEndOfList(&head, 69);
    insertAfterAnElement(head, 3);
    printLinkedList(head);
    printf("-----------\n");
    deleteNode(&head, 19);
    deleteNode(&head, 69);
    insertAfterAnElement(head->next->next, 70);
    printLinkedList(head);
    printf("-----------\n");
    reverserALinkedList(&head);
    printLinkedList(head);
    printf("-----------\n");
    deallocateLinkedList(&head);
    printLinkedList(head);

    return 0;
}