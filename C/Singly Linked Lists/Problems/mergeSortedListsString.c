#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a linked list node
struct StringNode {
    char* data;
    struct StringNode* next;
};

// Function prototypes
struct StringNode* mergeSortedStringLists(struct StringNode* list1, struct StringNode* list2);
void printStringList(struct StringNode* head);
struct StringNode* createStringNode(const char* data);
void freeStringList(struct StringNode* head);

int main() {
    // Test Case 1: Both lists are empty
    struct StringNode* list1 = NULL;
    struct StringNode* list2 = NULL;
    struct StringNode* mergedList = mergeSortedStringLists(list1, list2);
    printf("Test Case 1 - Merged String Linked List: ");
    printStringList(mergedList);
    // Expected Output: Merged String Linked List: NULL

    // Test Case 2: First list is empty, second list is not
    list1 = NULL;
    list2 = createStringNode("apple");
    list2->next = createStringNode("banana");
    list2->next->next = createStringNode("cherry");
    mergedList = mergeSortedStringLists(list1, list2);
    printf("Test Case 2 - Merged String Linked List: ");
    printStringList(mergedList);
    // Expected Output: Merged String Linked List: apple -> banana -> cherry -> NULL
    freeStringList(mergedList);

    // Test Case 3: Second list is empty, first list is not
    list1 = createStringNode("date");
    list1->next = createStringNode("fig");
    list1->next->next = createStringNode("grape");
    list2 = NULL;
    mergedList = mergeSortedStringLists(list1, list2);
    printf("Test Case 3 - Merged String Linked List: ");
    printStringList(mergedList);
    // Expected Output: Merged String Linked List: date -> fig -> grape -> NULL
    freeStringList(mergedList);

    // Test Case 4: Lists with different lengths
    list1 = createStringNode("apple");
    list1->next = createStringNode("banana");
    list2 = createStringNode("cherry");
    list2->next = createStringNode("date");
    list2->next->next = createStringNode("fig");
    list2->next->next->next = createStringNode("grape");
    mergedList = mergeSortedStringLists(list1, list2);
    printf("Test Case 4 - Merged String Linked List: ");
    printStringList(mergedList);
    // Expected Output: Merged String Linked List: apple -> banana -> cherry -> date -> fig -> grape -> NULL
    freeStringList(mergedList);

    // Test Case 5: Lists with duplicate values
    list1 = createStringNode("apple");
    list1->next = createStringNode("banana");
    list1->next->next = createStringNode("cherry");
    list2 = createStringNode("apple");
    list2->next = createStringNode("banana");
    list2->next->next = createStringNode("cherry");
    mergedList = mergeSortedStringLists(list1, list2);
    printf("Test Case 5 - Merged String Linked List: ");
    printStringList(mergedList);
    // Expected Output: Merged String Linked List: apple -> apple -> banana -> banana -> cherry -> cherry -> NULL
    freeStringList(mergedList);

    return 0;
}

// Function to merge two sorted linked lists of strings
struct StringNode* mergeSortedStringLists(struct StringNode* list1, struct StringNode* list2) {
    // Implementation goes here
    return NULL; // Placeholder return
}

// Function to print the linked list of strings
void printStringList(struct StringNode* head) {
    while (head != NULL) {
        printf("%s -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to create a new node with a string
struct StringNode* createStringNode(const char* data) {
    struct StringNode* newNode = (struct StringNode*)malloc(sizeof(struct StringNode));
    newNode->data = strdup(data); // Duplicate the string
    newNode->next = NULL;
    return newNode;
}

// Function to free the linked list of strings
void freeStringList(struct StringNode* head) {
    struct StringNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->data); // Free the duplicated string
        free(temp);
    }
}