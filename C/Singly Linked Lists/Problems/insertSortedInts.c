    #include <stdio.h>
    #include <stdlib.h>

    typedef struct Node
    {
        int value;
        struct Node *next;
    } Node;

    Node *createNode(int value);
    void insertAtBeginning(Node **head, int value);
    void insertAfterANode(Node *prevNode, int value);
    void insertSorted(Node **head, int value);
    void printList(Node *head);

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

        if (*head == NULL || value <= (*head)->value)
        {
            insertAtBeginning(head, value);
            return;
        }

        Node *traverser = *head;

        while (traverser->next != NULL && value >= traverser->next->value)
            traverser = traverser->next;
        insertAfterANode(traverser, value);
    }

    int main()
    {
        Node *head = NULL;

    
        insertSorted(&head, 5);
        insertSorted(&head, 2);
        insertSorted(&head, 8);
        insertSorted(&head, 1);
        insertSorted(&head, 7);


        printf("Linked List after sorted insertions:\n");
        printList(head);

        return 0;
    }

    void printList(Node *head)
    {
        Node *trav = head;
        while (trav != NULL)
        {
            printf("%d -> ", trav->value);
            trav = trav->next;
        }
        printf("NULL\n");
    }
