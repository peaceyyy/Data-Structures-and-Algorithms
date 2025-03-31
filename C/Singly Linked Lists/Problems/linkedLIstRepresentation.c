#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

ListNode *createNode(int val)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{

    ListNode *newListHead = createNode(0);
    ListNode *trav1 = l1;
    ListNode *trav2 = l2;

    ListNode *curr = newListHead;
    int carry = 0;

    while (trav1 != NULL || trav2 != NULL || carry > 0)
    {

        int val1 = trav1 ? trav1->val : 0;
        int val2 = trav2 ? trav2->val : 0;

        int nodeSum = val1 + val2 + carry;
        carry = nodeSum / 10;
        nodeSum %= 10;

        ListNode *newNode = createNode(nodeSum);
        curr->next = newNode;
        curr = newNode;

        if (trav1 != NULL)
            trav1 = trav1->next;
        if (trav2 != NULL)
            trav2 = trav2->next;
    }

    if (carry > 0) curr->next = createNode(carry);
    

    return newListHead->next;
}

void printList(ListNode *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(ListNode *head)
{

    ListNode *trav = head;

    while (trav != NULL)
    {
        ListNode *temp = trav;
        trav = trav->next;
        free(temp);
    }
}

int main()
{
    // 2 -> 4 -> 3 (represents 342)
    ListNode *l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);

    // 5 -> 6 -> 4 (represents 465)
    ListNode *l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    ListNode *result = addTwoNumbers(l1, l2);

    printf("Sum: ");
    printList(result);

    freeList(result);

    return 0;
}
