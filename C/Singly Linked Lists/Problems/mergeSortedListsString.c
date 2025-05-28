#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StringNode
{
    char *data;
    struct StringNode *next;
};

void appendNode(struct StringNode **head, struct StringNode *newNode)
{
    if (*head == NULL)
    {
        (*head) = newNode;
        return;
    }
    struct StringNode *trav = *head;

    while (trav->next != NULL)
        trav = trav->next;

    trav->next = newNode;
}

struct StringNode *mergeSortedStringLists(struct StringNode *list1, struct StringNode *list2)
{
    if (!list1) return list2;
    if (!list2) return list1;

    struct StringNode *sortedStringListHead = NULL;

    if (strcmp(list1->data, list2->data) < 0)
    {
        sortedStringListHead = list1;
        list1 = list1->next;
    }
    else
    {
        sortedStringListHead = list2;
        list2 = list2->next;
    }

    struct StringNode *trav = sortedStringListHead;

    while (list1 && list2)
    {
        if (strcmp(list1->data, list2->data) < 0)
        {
            trav->next = list1;
            list1 = list1->next;
        }

        else
        {
            trav->next = list2;
            list2 = list2->next;
        }

        trav = trav->next;
    }

    trav -> next = (list1) ? list1 : list2;

    return sortedStringListHead;
}

void printStringList(struct StringNode *head)
{
    while (head != NULL)
    {
        printf("%s -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct StringNode *createStringNode(const char *data)
{
    struct StringNode *newNode = (struct StringNode *)malloc(sizeof(struct StringNode));
    newNode->data = strdup(data);
    newNode->next = NULL;
    return newNode;
}

void freeStringList(struct StringNode *head)
{
    struct StringNode *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp->data);
        free(temp);
    }
}

int main()
{

    struct StringNode *list1 = NULL;
    struct StringNode *list2 = NULL;
    struct StringNode *mergedList = mergeSortedStringLists(list1, list2);
    printf("Test Case 1 - Merged String Linked List: ");
    printStringList(mergedList);
    // Expected output: NULL

    list1 = NULL;
    list2 = createStringNode("apple");
    list2->next = createStringNode("banana");
    list2->next->next = createStringNode("cherry");
    mergedList = mergeSortedStringLists(list1, list2);
    printf("Test Case 2 - Merged String Linked List: ");
    printStringList(mergedList);
    // Expected output: apple -> banana -> cherry -> NULL

    freeStringList(mergedList);

    list1 = createStringNode("date");
    list1->next = createStringNode("fig");
    list1->next->next = createStringNode("grape");
    list2 = NULL;
    mergedList = mergeSortedStringLists(list1, list2);
    printf("Test Case 3 - Merged String Linked List: ");
    printStringList(mergedList);
    // Expected output: date -> fig -> grape -> NULL

    freeStringList(mergedList);

    list1 = createStringNode("apple");
    list1->next = createStringNode("banana");
    list2 = createStringNode("cherry");
    list2->next = createStringNode("date");
    list2->next->next = createStringNode("fig");
    list2->next->next->next = createStringNode("grape");
    mergedList = mergeSortedStringLists(list1, list2);
    printf("Test Case 4 - Merged String Linked List: ");
    printStringList(mergedList);
    // Expected output: apple -> banana -> cherry -> date -> fig -> grape -> NULL

    freeStringList(mergedList);

    list1 = createStringNode("apple");
    list1->next = createStringNode("banana");
    list1->next->next = createStringNode("cherry");
    list2 = createStringNode("apple");
    list2->next = createStringNode("banana");
    list2->next->next = createStringNode("cherry");
    mergedList = mergeSortedStringLists(list1, list2);
    printf("Test Case 5 - Merged String Linked List: ");
    printStringList(mergedList);
    // Expected output: apple -> apple -> banana -> banana -> cherry -> cherry -> NULL

    freeStringList(mergedList);

    return 0;
}
