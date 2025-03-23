#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int *dataArr;
    int queueSize;
    int front;
    int rear;
    int count;
} Queue;

void initializeQueue(Queue *q, int size)
{
    q->queueSize = size;
    q->dataArr = (int *)malloc(sizeof(int) * q->queueSize);
    q->count = 0;
    q->front = 0;
    q->rear = 0;
}

void resizeQueue(Queue *q)
{

    int newSize = q->queueSize * 2;
    int *temp = malloc(sizeof(int) * newSize);

    for (int i = 0; i < q->count; i++)
    {
        temp[i] = q->dataArr[i];
    }

    free(q->dataArr);
    q->dataArr = temp;
    q->rear = q->count;
    q->front = 0;
    q->rear = q->count;
}

bool isFull(Queue *q)
{
    return q->count == q->queueSize;
}

bool isEmpty(Queue *q)
{
    return q->count == 0;
}

void enqueue(Queue *q, int val)
{

    if (isFull(q))
    {
        printf("Queue is full. Resizing...\n");
        resizeQueue(q);
    }
    q->dataArr[q->rear] = val;
    q->rear = (q->rear + 1) % q->queueSize;
    q->count++;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return -1;
    }

    int val = q->dataArr[q->front];
    q->front = (q->front + 1) % q->queueSize;
    q->count--;

    return val;
}

int peek(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->dataArr[q->front];
}

void freeQueue(Queue *q)
{
    free(q->dataArr);
    free(q);
}

int main()
{
    Queue q1;
    initializeQueue(&q1, 5);
    enqueue(&q1, 1);
    enqueue(&q1, 10);
    enqueue(&q1, 3);
    enqueue(&q1, 4);
    enqueue(&q1, 5);
    enqueue(&q1, 6);

    printf("Peek: %d\n", peek(&q1));

    printf("Dequeue: %d\n", dequeue(&q1));
    printf("Dequeue: %d\n", dequeue(&q1));
    printf("Dequeue: %d\n", dequeue(&q1));
    printf("Dequeue: %d\n", dequeue(&q1));
    printf("Dequeue: %d\n", dequeue(&q1));
    printf("Dequeue: %d\n", dequeue(&q1));
    printf("Dequeue: %d\n", dequeue(&q1));
    enqueue(&q1, 6);
    printf("Dequeue: %d\n", dequeue(&q1));

    freeQueue(&q1);
    return 0;
}