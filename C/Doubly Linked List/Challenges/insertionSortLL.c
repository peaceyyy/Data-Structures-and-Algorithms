#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node_t;

node_t* insertionSortLL(node_t* head); 
node_t* createNode(int data);
node_t* insertAtEnd(node_t* head, int data);
void printList(node_t* head);
void freeList(node_t* head);

node_t* createNode(int data) 
{
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at end of the list
node_t* insertAtEnd(node_t* head, int data) 
{
    node_t* newNode = createNode(data);
    
    if (head == NULL) return newNode;

    node_t* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

// Print linked list
void printList(node_t* head) 
{
    node_t* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Free linked list memory
void freeList(node_t* head) 
{
    node_t* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

node_t* insertionSortLL(node_t* head) 
{
    if (head == NULL || head->next == NULL) 
    {
        return head; 
    }

    node_t* sorted = NULL; // New sorted list
    node_t* curr = head;

    while (curr != NULL) 
    {
        node_t* nextNode = curr->next; // Store next node before detaching

        // Insert curr into sorted list
        if (sorted == NULL || curr->data >= sorted->data) 
        {
            
            // Insert at head of sorted list
            curr->next = sorted;
            if (sorted != NULL) 
            {
                sorted->prev = curr;
            }
            sorted = curr;
            sorted->prev = NULL;
        } else 
        {
            // Find insertion point
            node_t* trav = sorted;
            while (trav->next != NULL && trav->next->data > curr->data) 
            {
                trav = trav->next;
            }

            // Insert curr after trav
            curr->next = trav->next;
            if (trav->next != NULL) 
            {
                trav->next->prev = curr;
            }
            trav->next = curr;
            curr->prev = trav;
        }

        curr = nextNode; // Move to next node in original list
    }

    return sorted;
}

void testSelectionSortLinkedList() {
    // Creating an unsorted linked list: 4 -> 2 -> 1 -> 5 -> 3
    node_t* head = NULL;
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 3);

    printf("Before Sorting:\n");
    printList(head);

    head = insertionSortLL(head);

    printf("After Sorting:\n");
    printList(head);

    
    freeList(head);
}


// Main function to run the test
int main() {
    testSelectionSortLinkedList();
    return 0;
}
    
