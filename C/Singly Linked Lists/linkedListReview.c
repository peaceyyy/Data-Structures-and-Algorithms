#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int x;
    struct Node *next;
} Node;

Node *createNode(int val)
{
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Memory Allocation for node failed");
    }

    newNode->x = val;
    newNode->next = NULL;

    return newNode;
}

void insertAtBeginning(Node **head, int val)
{
    Node *newNode = createNode(val);

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {

        newNode->next = *head;
        *head = newNode;
    }
}

void insertAtEnd(Node **head, int val)
{
    Node *newNode = createNode(val);

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {

        Node *trav = *head;

        while (trav->next != NULL)
        {
            trav = trav->next;
        }

        trav->next = newNode;
    }
}

void insertAtIndexK(Node **head, int val, int k)
{
    Node *newNode = createNode(val);

    if (*head == NULL || k == 1)
    {
        *head = newNode;
    }
    else
    {

        Node *trav = *head;
        int n = 0;

        while (n < k)
        {   
            if (trav == NULL)
            {
                printf("Index K out of bounds!");
                return;
            }

            trav = trav->next;
            n++;
        }

        newNode->next = trav->next;
        trav->next = newNode;
    }

}



    int main()
    {
    }