    #include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int value;
    Node *next;
} Node;

void insertAtBeginning(Node **head, int value)
{

    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Failed to allocate memory");
        exit(1);
    }
    new_node->next = *head;
    new_node->value = value;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    *head = new_node;
}

void insertAtEnd(Node **head, int value)
{

    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Failed to allocate memory");
        exit(2);
    }

    new_node->value = value;
    new_node->next = NULL;

    if (*head == NULL)
    {

        *head = new_node;
        return;
    }

    Node *traverser = *head;

    while (traverser->next != NULL)
    {
        traverser = traverser->next;
    }

    traverser->next = new_node;
}

void insertAfterANode(Node *nodeToInsertAfter, int value)
{
    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Failed to allocate memory");
        exit(3);
    }

    new_node->value = value;
    new_node->next = nodeToInsertAfter->next;
    nodeToInsertAfter->next = new_node;
}

void insertSorted(Node **head, int value)
{

    if (*head == NULL || value >= (**head).value)
    {
        insertAtBeginning(head, value);
        return;
    }

    Node *traverser = *head;

    while (traverser->next != NULL && value >= traverser->next->value) traverser = traverser->next;
    
    insertAfterANode(traverser, value);
}

void removeAValue(Node **head, int valueToRemove)
{

    if (*head == NULL)
    {
        printf("Linked List is empty");
        return;
    }

    if ((**head).value == valueToRemove)
    {
        Node *valueToRemove = *head;
        *head = (*head)->next;
        free(valueToRemove);
        return;
    }

    for (Node *traverser = *head; traverser->next != NULL; traverser = traverser->next)
    {

        if (traverser->next->value == valueToRemove)
        {
            Node *nodeToRemove = traverser->next;
            traverser->next = traverser->next->next;
            free(nodeToRemove);
            return;
        }
    }

    printf("The value (%d) not in the Linked List\n", valueToRemove);
}

void removeANode(Node **head, Node *nodeToRemove)
{

    if (head == NULL || *head == NULL || nodeToRemove == NULL)
    {
        printf("Error: Invalid input.\n");
        return;
    }

    // If the node to remove is the head
    if (*head == nodeToRemove)
    {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node *traverser = *head;

    while (traverser->next != NULL)
    {

        if (traverser->next == nodeToRemove)
        {

            traverser->next = traverser->next->next;
            free(nodeToRemove);
            return;
        }

        traverser = traverser->next;
    }
}

void reverseLinkedList(Node **head)
{

    if ((*head == NULL) || (*head)->next == NULL)
    {
        printf("List is empty or has only one node");
        return;
    }

    Node *prev = NULL;
    Node *traverser = *head;

    while (traverser != NULL)
    {

        Node *next = traverser->next;
        traverser->next = prev;
        prev = traverser;
        traverser = next;
    }

    *head = prev;
}

void printLinkedList(Node *head)
{
    Node *traverser = head;

    if (head == NULL)
    {
        printf("Linked list is empty");
        exit(4);
    }

    while (traverser != NULL)
    {
        printf("%d\n", traverser->value);
        traverser = traverser->next;
    }
}

int countNumOfNodes(Node *node)
{

    if (node == NULL)
    {
        return 0;
    }

    return 1 + countNumOfNodes(node->next);
}

Node* findANode(Node* node, int nodeToFind) {
    if (node == NULL) {
        return NULL; 
    }

    if (node->value == nodeToFind) {
        return node; 
    }

    return findANode(node->next, nodeToFind); 
}

int checkForLoopsInLinkedList(Node *head)
{

    Node *slowPtr = head->next;
    Node *fastPtr = head->next->next;

    while (slowPtr != NULL && fastPtr != NULL && fastPtr->next != NULL)
    {

        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if (slowPtr == fastPtr)
            return 1;
    }

    return 0;
}

void deallocateLinkedList(Node **head)
{

    Node *traverser = *head;

    while (traverser != NULL)
    {
        Node *aux = traverser;
        traverser = traverser->next;
        free(aux);
    }

    *head = NULL;
}

int main()
{

    Node *head = NULL;

    insertSorted(&head, 9);
    insertSorted(&head, 10);
    insertSorted(&head, 1);
    insertSorted(&head, 2);
    insertAfterANode(head->next, 3);
    printLinkedList(head);
    // deallocateLinkedList(&head);
    printf("-----------\n");

    Node* foundNode = findANode(head, 3);

    if (foundNode != NULL) {
        printf("The value %d is at %p\n", foundNode->value, foundNode);
    } else {
        printf("Value 3 not found in the list.\n");
    }

    

    return 0;
}