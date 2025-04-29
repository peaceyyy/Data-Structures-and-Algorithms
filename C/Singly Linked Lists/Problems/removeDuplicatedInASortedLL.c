#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;

} ;

// void deleteDuplicates(struct ListNode* head) {

//     if (head == NULL)
//     {
//         return;
//     }

//     struct ListNode* trav = head;
//     struct ListNode* prev = NULL;
//     struct ListNode* temp = NULL;

//     while (trav -> next != NULL)
//     {
//         prev = trav;
//         trav = trav -> next;

//         if (prev -> val == trav -> val && trav -> next != NULL)
//         {   
//             temp = trav;
//             prev -> next = trav -> next;
//             free(temp);
            
//         }

//         else if (prev -> val == trav -> val && trav -> next == NULL)
//         {
//             temp = trav;
//             prev -> next = NULL;
//             free(temp);
//         }

        
//     }

    
// }

struct ListNode* createNode (int val)
{
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode -> val = val;
    newNode -> next = NULL;

    return newNode;

}

void insertAtEnd (struct ListNode** head, int val)
{       
    struct ListNode* newNode = createNode(val);

    if ((*head) == NULL)
    {
        (*head) = newNode;
        return;
    }

    struct ListNode* trav = (*head);

    while (trav->next != NULL)
    {
        trav = trav -> next;
    }

    trav -> next = newNode;

}

struct ListNode* deleteDuplicates(struct ListNode* head) {

    if (head == NULL)
    {
        return NULL;
    }
    
    struct ListNode* newHead = NULL;
    struct ListNode* trav = head;
    struct ListNode* prev;

    while (trav -> next != NULL)
    {
        prev = trav;
        trav = trav -> next;

        if (prev -> val != trav -> val)
        {   
    
            insertAtEnd(&newHead, prev->val);
            
        }

        
    }

    insertAtEnd(&newHead, trav->val); 
    return newHead;

    
}

void printList(struct ListNode* head);

int main() {
    struct ListNode* head = NULL;

    // Creating a linked list with duplicate values
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);

    printf("Original List:\n");
    printList(head);

    // Removing duplicates
    struct ListNode* newHead = deleteDuplicates(head);

    printf("\nList after removing duplicates:\n");
    printList(newHead);

    return 0;
}


void printList(struct ListNode* head) {
    struct ListNode* trav = head;
    while (trav != NULL) {
        printf("%d -> ", trav->val);
        trav = trav->next;
    }
    printf("NULL\n");
}
