#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *dataArr;
    int front;
    int rear;
    int count;
    int queueCapacity;
} Deque;

Deque *initializeQueue(int size);
bool isFull(Deque *dq);
bool isEmpty(Deque *dq);
void addFront(Deque *dq, int val);
void addRear(Deque *dq, int val);
int dequeueFront(Deque *dq);
int dequeueRear(Deque *dq);
void freeArr(Deque* dq);

int main() {
    int size = 5;
    Deque *dq = initializeQueue(size);

    printf("Adding elements to the front:\n");
    addFront(dq, 10);
    addFront(dq, 20);
    printf("Front: %d, Rear: %d\n", dq->front, dq->rear);

    printf("Adding elements to the rear:\n");
    addRear(dq, 30);
    addRear(dq, 40);
    printf("Front: %d, Rear: %d\n", dq->front, dq->rear);

    printf("Dequeuing from front: %d\n", dequeueFront(dq));
    printf("Dequeuing from rear: %d\n", dequeueRear(dq));

    printf("Checking if deque is empty: %s\n", isEmpty(dq) ? "Yes" : "No");
    printf("Checking if deque is full: %s\n", isFull(dq) ? "Yes" : "No");

    freeArr(dq);
    free(dq);

    return 0;
}

Deque *initializeQueue(int size) {
    Deque *dq = malloc(sizeof(Deque));
    if (dq == NULL) {
        fprintf(stderr, "Memory Allocation for Deque failed");
        exit(1);
    }
    dq->queueCapacity = size;
    dq->dataArr = (int *)malloc(sizeof(int) * dq->queueCapacity);

    if (dq -> dataArr == NULL){
        fprintf(stderr, "Deque Array Memory Allocation failed");
        free(dq);
        exit(2);
    }
    dq->front = 0;
    dq->rear = 0;
    dq->count = 0;
    return dq;
}

bool isFull(Deque *dq) {
    return dq->count == dq->queueCapacity;
}

bool isEmpty(Deque *dq) {
    return dq->count == 0;
}

void addFront(Deque *dq, int val) {
    dq->front = (dq->front - 1 + dq->queueCapacity) % dq->queueCapacity;
    dq->dataArr[dq->front] = val;
    dq->count++;
}

void addRear(Deque *dq, int val) {
    dq->dataArr[dq->rear] = val;
    dq->rear = (dq->rear + 1) % dq->queueCapacity;
    dq->count++;
}

int dequeueFront(Deque *dq) {
    int val = dq->dataArr[dq->front];
    dq->front = (dq->front + 1) % dq->queueCapacity;
    dq->count--;
    return val;
}

int dequeueRear(Deque *dq) {
    dq->rear = (dq->rear - 1 + dq->queueCapacity) % dq->queueCapacity;
    int val = dq->dataArr[dq->rear];
    dq->count--;
    return val;
}

void freeArr(Deque* dq) {
    free(dq->dataArr);
    dq->count = 0;
    dq->front = 0;
    dq->rear = 0;
}