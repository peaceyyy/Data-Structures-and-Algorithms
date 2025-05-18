#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

// Utility function to create a new node
ListNode *createNode(int val) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to find the intersection node
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    for (ListNode *travA = headA; travA != NULL; travA = travA->next) {
        for (ListNode *travB = headB; travB != NULL; travB = travB->next) {
            if (travA == travB) return travA;
        }
    }
    return NULL;
}

ListNode *cleanGetIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* travA = headA;
    ListNode* travB = headB;

    while (travA != travB){

        travA = (!travA) ? headB : travA ->next;
        travB = (!travB) ? headA : travB ->next;


    }

    return travA;
}

int main() {
    // Test Case 1: No Intersection
    ListNode *headA1 = createNode(1);
    headA1->next = createNode(2);
    headA1->next->next = createNode(3);

    ListNode *headB1 = createNode(4);
    headB1->next = createNode(5);
    headB1->next->next = createNode(6);

    ListNode *result1 = cleanGetIntersectionNode(headA1, headB1);
    if (result1)
        printf("Test Case 1: Intersected at node with value: %d\n", result1->val);
    else
        printf("Test Case 1: No intersection found.\n");
    // Expected Output: No intersection found.

    // Test Case 2: Intersection at the Head
    ListNode *headA2 = createNode(1);
    headA2->next = createNode(2);
    headA2->next->next = createNode(3);

    ListNode *headB2 = headA2; // Same nodes as List A

    ListNode *result2 = cleanGetIntersectionNode(headA2, headB2);
    if (result2)
        printf("Test Case 2: Intersected at node with value: %d\n", result2->val);
    else
        printf("Test Case 2: No intersection found.\n");
    // Expected Output: Intersected at node with value: 1

    // Test Case 3: Intersection at the Last Node
    ListNode *headA3 = createNode(1);
    headA3->next = createNode(2);
    headA3->next->next = createNode(3);

    ListNode *headB3 = createNode(4);
    headB3->next = createNode(5);
    headB3->next->next = headA3->next->next; // Last node is shared

    ListNode *result3 = cleanGetIntersectionNode(headA3, headB3);
    if (result3)
        printf("Test Case 3: Intersected at node with value: %d\n", result3->val);
    else
        printf("Test Case 3: No intersection found.\n");
    // Expected Output: Intersected at node with value: 3

    // Test Case 4: Intersection in the Middle
    ListNode *headA4 = createNode(1);
    headA4->next = createNode(2);
    headA4->next->next = createNode(3);
    headA4->next->next->next = createNode(4);

    ListNode *headB4 = createNode(5);
    headB4->next = headA4->next->next; // Intersection starts at node with value 3

    ListNode *result4 = cleanGetIntersectionNode(headA4, headB4);
    if (result4)
        printf("Test Case 4: Intersected at node with value: %d\n", result4->val);
    else
        printf("Test Case 4: No intersection found.\n");
    // Expected Output: Intersected at node with value: 3

    // Test Case 5: One List is Empty
    ListNode *headA5 = NULL;

    ListNode *headB5 = createNode(1);
    headB5->next = createNode(2);
    headB5->next->next = createNode(3);

    ListNode *result5 = cleanGetIntersectionNode(headA5, headB5);
    if (result5)
        printf("Test Case 5: Intersected at node with value: %d\n", result5->val);
    else
        printf("Test Case 5: No intersection found.\n");
    // Expected Output: No intersection found.

    // Test Case 6: Both Lists are Empty
    ListNode *headA6 = NULL;
    ListNode *headB6 = NULL;

    ListNode *result6 = cleanGetIntersectionNode(headA6, headB6);
    if (result6)
        printf("Test Case 6: Intersected at node with value: %d\n", result6->val);
    else
        printf("Test Case 6: No intersection found.\n");
    // Expected Output: No intersection found.

    // Test Case 7: Single Node Intersection
    ListNode *headA7 = createNode(1);

    ListNode *headB7 = headA7; // Same node as List A

    ListNode *result7 = cleanGetIntersectionNode(headA7, headB7);
    if (result7)
        printf("Test Case 7: Intersected at node with value: %d\n", result7->val);
    else
        printf("Test Case 7: No intersection found.\n");
    // Expected Output: Intersected at node with value: 1

    // Test Case 8: Different Lengths, Intersection
    ListNode *headA8 = createNode(1);
    headA8->next = createNode(2);
    headA8->next->next = createNode(3);
    headA8->next->next->next = createNode(4);
    headA8->next->next->next->next = createNode(5);

    ListNode *headB8 = createNode(6);
    headB8->next = createNode(7);
    headB8->next->next = headA8->next->next->next; // Intersection starts at node with value 4

    ListNode *result8 = cleanGetIntersectionNode(headA8, headB8);
    if (result8)
        printf("Test Case 8: Intersected at node with value: %d\n", result8->val);
    else
        printf("Test Case 8: No intersection found.\n");
    // Expected Output: Intersected at node with value: 4

    return 0;
}