#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int x;
    struct Node *next;
} node_t;

void insertAtEnd(node_t **head, int val)
{
    
    node_t *new_node = malloc(sizeof(node_t));
    new_node->x = val;
    new_node->next = NULL;

      if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    node_t *trav = *head;

    while (trav->next != NULL)
    {
        trav = trav->next;
    }

    trav->next = new_node;
}

void insertAtBeginning(node_t **head, int val)
{

    node_t *new_node = malloc(sizeof(node_t));
    new_node->x = val;
    new_node->next = *head;
    *head = new_node;
}

void swapNodeValues(node_t* node1, node_t* node2){

    if (node1->x == node2->x) return;  

    int temp = node1->x;
    node1->x = node2->x;
    node2->x = temp;

}

void sortLLBubble (node_t* head){

    for (node_t* curr = head; curr -> next != NULL; curr = curr -> next){

        for(node_t* trav = head; trav -> next != NULL; trav = trav -> next){

            if (trav->x > trav->next->x){
                swapNodeValues(trav, trav->next);
            }
        }
    }
}

void sortLLInsertion (node_t* head){

    for (node_t* curr = head; curr != NULL; curr = curr -> next)
    {
        node_t* trav = head;
        while (trav != curr)
        {
            if (trav->x > curr -> x) swapNodeValues(trav, curr);

            trav = trav -> next;
        }
    }
}

void printLinkedList(node_t *head)
{
    node_t *temporary = head;

    while (temporary != NULL)
    {
        printf("%d\n", temporary->x);
        temporary = temporary->next;
    }
}
int main() {
    node_t* head = NULL;

    insertAtEnd(&head,11);
    insertAtEnd(&head, 0);
    insertAtEnd(&head,10);
    insertAtEnd(&head,6);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);

    printf("Original list:\n");
    printLinkedList(head);

     


    printf("Sorted list:\n");
    sortLLBubble(head);
    printLinkedList(head);

    node_t* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
