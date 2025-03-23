#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    int *dataArray;
    int stackCapacity;
    int currStackSize;
} Stack;

Stack *init(int currStackSize)
{

    if (currStackSize <= 0)
    {
        fprintf(stderr, "Stack size must be positive!\n");
        return NULL;
    }

    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL)
    {
        fprintf(stderr, "Memory allocation for the stack failed!\n");
        return NULL;
    }

    stack->dataArray = (int *)malloc(sizeof(int) * currStackSize);
    if (stack->dataArray == NULL)
    {
        fprintf(stderr, "Memory allocation for the array `failed!\n");
        free(stack);
        return NULL;
    }

    stack->stackCapacity = currStackSize;
    stack->currStackSize = 0;

    return stack;
}

bool isStackEmpty(Stack *stack)
{
    return stack->currStackSize == 0;
}

bool isStackFull(Stack *stack)
{
    return stack->currStackSize == stack->stackCapacity;
}

void push(Stack *stack, int val)
{
    if (stack == NULL)
    {
        fprintf(stderr, "Stack is uninitialized!\n");
        return;
    }

    if (isStackFull(stack))
    {
        stack->stackCapacity *= 2;
        int *temp = (int *)realloc(stack->dataArray, sizeof(int) * stack->stackCapacity);
        if (temp == NULL)
        {
            fprintf(stderr, "Memory allocation failed!\n");
            return ;
        }
        stack->dataArray = temp;
    }
    stack->dataArray[stack->currStackSize++] = val;
}

int peek(Stack *stack)
{
    if (stack == NULL)
    {
        fprintf(stderr, "Stack is uninitialized!\n");
        return -1;
    }
    if (isStackEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->dataArray[stack->currStackSize - 1];
}

int pop(Stack *stack)
{
    if (stack == NULL)
    {
        fprintf(stderr, "Stack is uninitialized!\n");
        return -1;
    }
    if (isStackEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->dataArray[--stack->currStackSize];
}

void printStackFromBottom(Stack *stack)
{

    for (int i = 0; i < stack->currStackSize; i++)
    {
        printf("%d\n", stack->dataArray[i]);
    }
}

void printStackFromTop(Stack *stack)
{

    for (int i = stack->currStackSize - 1; i > 0; i--)
    {
        printf("%d\n", stack->dataArray[i]);
    }
}

void resetStack(Stack *stack)
{   
    stack->currStackSize = 0;
    free(stack->dataArray);
}

void freeStack(Stack *stack)
{   
    stack->currStackSize = 0;
    free(stack->dataArray);
    free(stack);
}

int main()
{
    Stack *s1 = init(5);
    if (s1 == NULL)
    {
        return 1;
    }

    push(s1, 3);
    push(s1, 3);
    push(s1, 4);
    push(s1, 5);
    push(s1, 6);
    push(s1, 7);
    push(s1, 9);
    push(s1, 10);

    printStackFromBottom(s1);
    printf("---------\n");
    resetStack(s1);
    printStackFromTop(s1);
    freeStack(s1);
    return 0;
}