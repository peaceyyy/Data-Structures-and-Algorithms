#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int* dataArray;
    int queueSize;
    int front;
    int rear;
    int count; 
} Queue;

void initializeQueue(Queue* q, int size) {
    q->queueSize = size;
    q->dataArray = (int*)malloc(sizeof(int) * size);
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

bool isFull(Queue* q) {
    return q->count == q->queueSize;
}

bool isEmpty(Queue* q) {
    return q->count == 0;
}

void resizeQueue(Queue* q) {

    int newSize = q->queueSize * 2;
    int* newArray = malloc(sizeof(int) * newSize);
    if (newArray == NULL) {
        fprintf(stderr, "Memory allocation failed during resizing.\n");
        return;
    }
    for (int i = 0; i < q->count; i++) {
        newArray[i] = q->dataArray[q->queueSize];
    }

    free(q->dataArray);
    q->dataArray = newArray;
    q->front = 0;
    q->rear = q->count;
    q->queueSize = newSize;

}

void enqueue(Queue* q, int val) {
    if (isFull(q)) {
        printf("Queue is full. Resizing...\n");
        resizeQueue(q);
    }
    q->dataArray[q->rear] = val;
    q->rear++;
    q->count++;
}

int dequeue(Queue* q) {
    
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }

    int value = q->dataArray[q->front];
    q->front++;
    q->count--;
    return value;
}

int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->dataArray[q->front];
}

void freeQueue(Queue* q) {
    free(q->dataArray);
    q->dataArray = NULL;
}

int main() {
    Queue q1;
    initializeQueue(&q1, 5);

    enqueue(&q1, 1);
    enqueue(&q1, 2);
    enqueue(&q1, 3);
    enqueue(&q1, 4);
    enqueue(&q1, 5);
    enqueue(&q1, 6);

    printf("Peek: %d\n", peek(&q1));

    printf("Dequeue: %d\n", dequeue(&q1));
    printf("Dequeue: %d\n", dequeue(&q1));

    freeQueue(&q1);
    return 0;
}
