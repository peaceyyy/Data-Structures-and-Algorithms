
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2);
void printList(struct Node* head);
struct Node* createNode(int data);
void freeList(struct Node* head);

int main() {
    // Test Case 1: Both lists are empty
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* mergedList = mergeSortedLists(list1, list2);
    printf("Test Case 1 - Merged Linked List: ");
    printList(mergedList);
    // Expected Output: Merged Linked List: NULL

    // Test Case 2: First list is empty, second list is not
    list1 = NULL;
    list2 = createNode(1);
    list2->next = createNode(3);
    list2->next->next = createNode(5);
    mergedList = mergeSortedLists(list1, list2);
    printf("Test Case 2 - Merged Linked List: ");
    printList(mergedList);
    // Expected Output: Merged Linked List: 1 -> 3 -> 5 -> NULL
    freeList(mergedList);

    // Test Case 3: Second list is empty, first list is not
    list1 = createNode(2);
    list1->next = createNode(4);
    list1->next->next = createNode(6);
    list2 = NULL;
    mergedList = mergeSortedLists(list1, list2);
    printf("Test Case 3 - Merged Linked List: ");
    printList(mergedList);
    // Expected Output: Merged Linked List: 2 -> 4 -> 6 -> NULL
    freeList(mergedList);

    // Test Case 4: Lists with different lengths
    list1 = createNode(1);
    list1->next = createNode(3);
    list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(5);
    list2->next->next->next = createNode(6);
    mergedList = mergeSortedLists(list1, list2);
    printf("Test Case 4 - Merged Linked List: ");
    printList(mergedList);
    // Expected Output: Merged Linked List: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
    freeList(mergedList);

    // Test Case 5: Lists with duplicate values
    list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);
    list2 = createNode(1);
    list2->next = createNode(3);
    list2->next->next = createNode(5);
    mergedList = mergeSortedLists(list1, list2);
    printf("Test Case 5 - Merged Linked List: ");
    printList(mergedList);
    // Expected Output: Merged Linked List: 1 -> 1 -> 3 -> 3 -> 5 -> 5 -> NULL
    freeList(mergedList);

    return 0;
}

// Function to merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;

    struct Node* sortedListHead = createNode(0);
    struct Node* curr = sortedListHead;

    while (list1 && list2) {
        if (list1->data < list2->data) {
            curr->next = list1;
            list1 = list1->next;
        } else {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }

    curr -> next = (list1) ? list1 : list2;

    return sortedListHead->next;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to free the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
