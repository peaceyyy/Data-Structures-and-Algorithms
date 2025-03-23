#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int value;
    struct node* next;
}   node_t;

void printLinkedList(node_t* head){
    node_t* temporary = head;

    while (temporary != NULL){
        printf("%d\n", temporary -> value);
        temporary = temporary->next;
    
    }



}

int main(){

    node_t n1, n2, n3, n4;
    node_t* head;

    n1.value = 45;
    n2.value = 8;
    n3.value = 32;
    n4.value =  69;
    
    head = &n4;
    n4.next = &n3;
    n3.next = &n2;
    n2.next = &n1;
    n1.next = NULL;

    node_t iStillLoveHer;

    iStillLoveHer.value = 7;
    n2.next = &iStillLoveHer;
    iStillLoveHer.next = &n1;

    head = head -> next -> next -> next;
    
    iStillLoveHer.value = iStillLoveHer.next -> value;


    printLinkedList(head);



    return 0;
}