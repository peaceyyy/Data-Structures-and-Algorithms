#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* dataArr;
    int size;
    int top;
} Stack;

Stack* initializeStack(int size) {
    Stack* S = malloc(sizeof(Stack));
    S->dataArr = (int*) malloc(sizeof(int) * size);
    S->size = size;
    S->top = -1;
    return S;
}

bool isFull(Stack* S) {
    return S->top == S->size - 1;
}

bool isEmpty(Stack* S) {
    return S->top == -1;
}

void displayStack(Stack* S) {
    if (isEmpty(S)) {
        printf("Stack is empty!\n");
        return;
    }
    for (int i = 0; i <= S->top; i++) printf("%d ", S->dataArr[i]);
    printf("\n");
}

void push(Stack* S, int val) {
    if (isFull(S)) {
        printf("Stack is full!\n");
        return;
    }
    S->dataArr[++S->top] = val;
}

int pop(Stack* S) {
    if (isEmpty(S)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return S->dataArr[S->top--];
}

int peek(Stack* S) {
    if (isEmpty(S)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return S->dataArr[S->top];
}

void freeStack(Stack* S) {
    
    free(S->dataArr);
    free(S);
}

void clearStack (Stack* S){


    for (int i = 0; i <= S->top; i++) S->dataArr[i] = 0;
    S->top = -1;
}


void resizeStack (Stack* S) {

    int newSize =  S->size * 2;
    int* tempArr = (int*) malloc(sizeof(int) * newSize);
    for (int i = 0; i <= S->top; i++) tempArr[i] = S->dataArr[i];  

    free(S->dataArr);
    S->dataArr = tempArr;
    S->size = newSize;

}



int main() {
    Stack* S1 = initializeStack(5);

    push(S1, 1);
    push(S1, 2);
    push(S1, 3);
    push(S1, 4);
    push(S1, 5);
    
    displayStack(S1);
    
    printf("\n%d\n\n", pop(S1));
    displayStack(S1);
    printf("\n%d\n\n", peek(S1));
    printf("\n%d\n\n", S1->size);
    resizeStack(S1);
    printf("\n%d\n\n", S1->size);

    return 0;
}