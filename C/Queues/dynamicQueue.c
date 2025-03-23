#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (!q)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue *q, int val)
{
    Node *newNode = createNode(val);

    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
    }

    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }

    Node *temp = q->front;
    int val = q->front->val;
    q->front = q->front->next;

    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    free(temp);
    return val;
}

void displayQueue(Queue *q)
{
    Node *trav = q->front;

    while (trav != NULL)
    {
        printf("%d ", trav->val);
        trav = trav->next;
    }
}

void freeQueue(Queue *q)
{
    Node *trav = q->front;

    while (trav != NULL)
    {
        Node *temp = trav;
        trav = trav->next;
        free(temp);
    }
}

int main()
{
    Queue *q = createQueue();

    // Enqueue some elements
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    // Display the queue
    printf("Queue after enqueues: ");
    displayQueue(q);
    printf("\n");

    // Dequeue an element
    printf("Dequeued: %d\n", dequeue(q));

    // Display the queue again
    printf("Queue after dequeue: ");
    displayQueue(q);
    printf("\n");

    // Free the queue
    freeQueue(q);
    free(q);

    return 0;
}