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

ListNode *findMid(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while ( fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *newHead = reverseList(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}

bool isPalindrome(ListNode *head)
{   
    if (head == NULL || head -> next == NULL) return true;

    ListNode *trav1 = head;
    bool result = true;

    ListNode *secondHalfHead = findMid(head);
    ListNode *trav2 = reverseList(secondHalfHead->next);

    while (trav2 != NULL)
    {
        if (trav1->val != trav2->val) result = false;
        
        trav1 = trav1->next;
        trav2 = trav2->next;
    }
    reverseList(secondHalfHead->next);  
    return result;
}

ListNode* createListFromArray(int arr[], int size) {
    ListNode* head = NULL;
    for (int i = 0; i < size; i++) {
        appendNode(&head, arr[i]);
    }
    return head;
}

// Main Function
int main() {
    // Test Case 1: Palindrome list
    int arr1[] = {1, 2, 3, 2, 1};
    ListNode* head1 = createListFromArray(arr1, 5);
    printf("Test Case 1: ");
    printList(head1);
    bool result1 = isPalindrome(head1);
    printf("Is Palindrome: %s\n", result1 ? "true" : "false");
    // Expected Output: true

    // Test Case 2: Non-palindrome list
    int arr2[] = {1, 2, 3, 4, 5};
    ListNode* head2 = createListFromArray(arr2, 5);
    printf("Test Case 2: ");
    printList(head2);
    bool result2 = isPalindrome(head2);
    printf("Is Palindrome: %s\n", result2 ? "true" : "false");
    // Expected Output: false

    // Test Case 3: Single element list
    int arr3[] = {1};
    ListNode* head3 = createListFromArray(arr3, 1);
    printf("Test Case 3: ");
    printList(head3);
    bool result3 = isPalindrome(head3);
    printf("Is Palindrome: %s\n", result3 ? "true" : "false");
    // Expected Output: true

    // Test Case 4: Empty list
    ListNode* head4 = NULL;
    printf("Test Case 4: ");
    printList(head4);
    bool result4 = isPalindrome(head4);
    printf("Is Palindrome: %s\n", result4 ? "true" : "false");
    // Expected Output: true

    // Free allocated memory
    freeList(head1);
    freeList(head2);
    freeList(head3);
    freeList(head4);

    return 0;
}
