#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char* charArr;
    int stackCapacity;
    int stackTop;
} Stack;

Stack* createStack (int size)
{
    Stack* stack = malloc(sizeof(Stack));

    stack->charArr = malloc(sizeof(char) * size);
    stack->stackCapacity = size;
    stack -> stackTop = 0;
}

bool isStackFull (Stack* stack)
{
    if (stack->stackCapacity == stack->stackTop) return true;
    return false;
}
bool isStackEmpty (Stack* stack)
{
    if (stack->stackTop == 0) return true;
    return false;
}

void push (Stack* stack, char character)
{
    if (isStackFull(stack))
    {
        fprintf(stderr, "Stack is full");
    }
    stack->charArr[stack->stackTop++] = character;
    
}

char pop (Stack* stack)
{
    
    if (isStackEmpty(stack))
    {
        fprintf(stderr, "Stack is empty");
    }
    char character = stack->charArr[--stack->stackTop];
    return character;
}

void printStack (Stack* stack)
{
    for (int i = 0; i < stack->stackTop ; i++)
    {
        printf("%c", stack->charArr[i]);
    }
}

bool isBalanced (char* brackets)
{
    Stack* bracketStack = createStack(strlen(brackets));

    for (int i = 0; brackets[i] != '\0'; i++)
    {
        if (brackets[i] == '(' || brackets[i] == '[')
        {
            push(bracketStack, brackets[i]);
        }

        else if (brackets[i] == ')' || brackets[i] == ']')
        {
            if(isStackEmpty(bracketStack)) return false;
            
            else if (brackets[i] == ')')
            {
                if (pop(bracketStack) != '(') return false;
            }

            else if (brackets[i] == ']')
            {
                if (pop(bracketStack) != '[') return false;
            }
        
        }
    }

    if (!isStackEmpty(bracketStack)) return false;

    return true;

}


int main()
{

    char* brackets = "[()]";

    if (isBalanced(brackets)) printf("Brackets are balanced");
    else printf("Brackets are not balanced");

    return 0;
}