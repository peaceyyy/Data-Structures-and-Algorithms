#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node
{
    int data;
    struct Node *next;
};

// Helper Function 1: Create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Helper Function 2: Print linked list
void printList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// // Helper Function 3: Remove duplicates from sorted linked list
// void removeDuplicates(struct Node* head) {
//     struct Node* trav = head;

//     while (trav -> next != NULL)
//     {
//         if (trav -> data == trav -> next -> data && trav -> next -> next != NULL)
//         {
//             struct Node* temp = trav  -> next;
//             trav -> next = trav -> next -> next;
//             free(temp);
//         }

//         trav = trav -> next;
//     }

//     if (trav -> next -> data == trav -> data) {
//         struct Node* temp = trav  -> next;
//         trav -> next = NULL; 
//         free(temp);
//     }
// }

// void removeDuplicates(struct Node *head)
// {

//     if (head == NULL) return NULL;

//     struct Node *trav = head;
//     struct Node *prev = NULL;

//     while (trav->next != NULL)
//     {

//         prev = trav;
//         trav = trav->next;

//         if (trav->data == prev->data && trav->next != NULL)
//         {
//             prev->next = trav->next;
//         }
//     }

//     if (trav->data == prev->data)
//     {
//         struct Node *temp = prev->next;
//         prev->next = NULL;
//         free(temp);
//     }
// }

void removeDuplicates(struct Node *head) {
    if (head == NULL) return;

    struct Node *current = head;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node *temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

// Main Function
int main()
{
    // Test Case 1
    struct Node *head1 = createNode(1);
    head1->next = createNode(1);
    head1->next->next = createNode(2);
    head1->next->next->next = createNode(3);
    head1->next->next->next->next = createNode(3);
    printf("Test Case 1: Before removing duplicates: ");
    printList(head1);
    removeDuplicates(head1);
    printf("Test Case 1: After removing duplicates: ");
    printList(head1);
    // Expected Output: 1 2 3

    printf("\n\n");

    // Test Case 2
    struct Node *head2 = createNode(1);
    head2->next = createNode(2);
    head2->next->next = createNode(3);
    head2->next->next->next = createNode(3);
    printf("Test Case 2: Before removing duplicates: ");
    printList(head2);
    removeDuplicates(head2);
    printf("Test Case 2: After removing duplicates: ");
    printList(head2);
    // Expected Output: 1 2 3

    // Add more test cases as needed

    return 0;
}