#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *top;

} Stack;

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

Stack *createStack()
{
    Stack *s = malloc(sizeof(Stack));

    if (!s)
    {
        printf("Memory allocation for stack failed\n");
        exit(2);
    }

    s->top = NULL;

    return s;
}

bool isEmpty (Stack* s)
{
    if (s->top == NULL)
    {
        return true;
    }

    return false;
}


void push(Stack *s, int val)
{
    Node *newNode = createNode(val);
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        fprintf(stderr, "Stack is empty");
        exit(3);
    }

    Node* temp = s->top;
    int val = s->top->val;
    s->top = s->top->next;
    free(temp);

    return val;
}

void freeStack(Stack *s)
{   
      if (isEmpty(s))
    {
        fprintf(stderr, "Stack is empty");
        exit(4);
    }

    Node *trav = s->top;

    while (trav != NULL)
    {
        Node *temp = trav;
        trav = trav->next;
        free(temp);
    }
}

int main()
{
    Stack *stack = createStack();

    // Push elements onto the stack
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    // Pop elements from the stack
    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));

    // Free the stack
    freeStack(stack);

    return 0;
}