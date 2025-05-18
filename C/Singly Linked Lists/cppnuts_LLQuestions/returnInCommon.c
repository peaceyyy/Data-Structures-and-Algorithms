#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

ListNode *createNode(int val)
{
    ListNode *newNode = (struct ListNode *)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void appendNode(struct ListNode **head, int val)
{
    ListNode *newNode = createNode(val);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        ListNode *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(struct ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(struct ListNode *head)
{
    ListNode *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

ListNode* returnSharedValues (ListNode* headA, ListNode* headB)
{

    ListNode* sharedValuesList = NULL;

    for (ListNode* travA = headA; travA != NULL; travA = travA -> next)
    {
        for (ListNode* travB = headB; travB != NULL; travB = travB -> next)
        {
            if (travA -> val == travB -> val) appendNode(&sharedValuesList, travA->val);
        }
    }

    return sharedValuesList;
}


ListNode* cleanReturnSharedValues (ListNode* headA, ListNode* headB)
{
    ListNode* travA = headA;
    ListNode* travB = headB;
    ListNode* sharedValuesList = NULL;

    while (travA && travB)
    {   
        if (travA->val > travB->val) {
            travB = travB->next;
        } else if (travA->val < travB->val) {
            travA = travA->next;
        } else {
            appendNode(&sharedValuesList, travA->val);
            int matchedVal = travA->val;

            while (travA && travA->val == matchedVal) {
                travA = travA->next;
            }

            while (travB && travB->val == matchedVal) {
                travB = travB->next;
            }
        }
    }

    return sharedValuesList;
}

int main()
{
    // Test Case 1
    ListNode *listA1 = NULL;
    ListNode *listB1 = NULL;
    appendNode(&listA1, 1);
    appendNode(&listA1, 2);
    appendNode(&listA1, 3);
    appendNode(&listB1, 3);
    appendNode(&listB1, 4);
    appendNode(&listB1, 5);

    ListNode *shared1 = cleanReturnSharedValues(listA1, listB1);
    printf("Test Case 1: ");
    printList(shared1);
    // Expected Output: 3 -> NULL

    freeList(listA1);
    freeList(listB1);
    freeList(shared1);

    // Test Case 2
    ListNode *listA2 = NULL;
    ListNode *listB2 = NULL;
    appendNode(&listA2, 10);
    appendNode(&listA2, 20);
    appendNode(&listA2, 30);
    appendNode(&listB2, 40);
    appendNode(&listB2, 50);
    appendNode(&listB2, 60);

    ListNode *shared2 = cleanReturnSharedValues(listA2, listB2);
    printf("Test Case 2: ");
    printList(shared2);
    // Expected Output: NULL

    freeList(listA2);
    freeList(listB2);
    freeList(shared2);

    // Test Case 3
    ListNode *listA3 = NULL;
    ListNode *listB3 = NULL;
    appendNode(&listA3, 7);
    appendNode(&listA3, 8);
    appendNode(&listA3, 9);
    appendNode(&listB3, 7);
      appendNode(&listB3, 8);
    appendNode(&listB3, 9);
  

    ListNode *shared3 = cleanReturnSharedValues(listA3, listB3);
    printf("Test Case 3: ");
    printList(shared3);
    // Expected Output: 7 -> 8 -> 9 -> NULL

    freeList(listA3);
    freeList(listB3);
    freeList(shared3);

    // Test Case 4: Both lists are empty
    ListNode *listA4 = NULL;
    ListNode *listB4 = NULL;

    ListNode *shared4 = cleanReturnSharedValues(listA4, listB4);
    printf("Test Case 4: ");
    printList(shared4);
    // Expected Output: NULL

    freeList(shared4);

    // Test Case 5: One list is empty, the other contains elements
    ListNode *listA5 = NULL;
    ListNode *listB5 = NULL;
    appendNode(&listB5, 1);
    appendNode(&listB5, 2);
    appendNode(&listB5, 3);

    ListNode *shared5 = cleanReturnSharedValues(listA5, listB5);
    printf("Test Case 5: ");
    printList(shared5);
    // Expected Output: NULL

    freeList(listB5);
    freeList(shared5);

    return 0;
}