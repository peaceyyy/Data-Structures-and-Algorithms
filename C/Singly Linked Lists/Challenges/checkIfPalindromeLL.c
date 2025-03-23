#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

bool isPalindrome(ListNode *head);
ListNode *findMiddleNode(ListNode *head);

ListNode *createNode(int val);
void appendNode(ListNode **head, int val);
void printList(ListNode *head);
void freeList(ListNode *head);

// int main()
// {
//     ListNode *head = NULL;

//     appendNode(&head, 1);
//     appendNode(&head, 2);
//     appendNode(&head, 2);
//     appendNode(&head, 3);
//     printList(head);
    
//     if (isPalindrome(head) ) {
//         printf("The Linked List is a palindrome");
//     } else {
//         printf("The Linked List is not a palindrome");
//     }
    
//     printf("\n--------------\n");
//     printList(head);
    
    
//     freeList(head);
//     return 0;
// }

ListNode *findMiddleNode(ListNode *head)
{
    ListNode *slowPtr = head;
    ListNode *fastPtr = head;

    while (fastPtr != NULL && fastPtr -> next != NULL)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    return slowPtr;
}

ListNode *reverseList(ListNode *head) {
    ListNode *prev = NULL;
    ListNode *current = head;
    ListNode *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

bool isPalindrome(ListNode *head)
{
    if (head == NULL || head->next == NULL) {
        return true;
    }

    ListNode* middleNode = findMiddleNode(head);
    ListNode *middleNodePtr = reverseList(middleNode->next);
    ListNode *headPtr = head;
    ListNode* middleNodePtrCopy = middleNodePtr;

    while (middleNodePtr != NULL)
    {
        if (headPtr -> val != middleNodePtr -> val)
        {   
            reverseList(middleNodePtrCopy);
            return false;
        }

        headPtr = headPtr -> next;
        middleNodePtr = middleNodePtr -> next;
    }

    middleNode->next = reverseList(middleNodePtrCopy);
    return true;
}

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