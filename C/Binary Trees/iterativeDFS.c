#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

} TreeNode;
TreeNode *createNode(int value)
{
    TreeNode *newNode = malloc(sizeof(TreeNode));

    if (!newNode)
    {
        fprintf(stderr, "Memory allocation for node failed!");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

TreeNode *insert(TreeNode *root, int value)
{

    if (root == NULL)
    {
        return createNode(value);
    }

    if (value == root->data)
    {
        printf("Value %d is already here in the tree lol. We can't add this one bruv\n", value);
        return root;
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}

typedef struct
{

    int stackSize;
    TreeNode **dataArr;
    int currentCapacity;

} Stack;

Stack *createStack(int size)
{
    Stack *stack = malloc(sizeof(Stack));

    if (stack == NULL)
    {
        fprintf(stderr, "Stack memory allocation failed");
        exit(1);
    }

    stack->currentCapacity = 0;
    stack->stackSize = size;
    stack->dataArr = malloc(sizeof(TreeNode *) * stack->stackSize);

    if (stack->dataArr == NULL)
    {
        fprintf(stderr, "Stack Array memory allocation failed");
        free(stack);
        exit(2);
    }

    return stack;
}

int isStackEmpty(Stack *stack)
{
    if (stack->currentCapacity == 0)
    {
        return 1;
    }

    return 0;
}

int isStackFull(Stack *stack)
{
    if (stack->currentCapacity == stack->stackSize)
    {
        return 1;
    }

    return 0;
}

void push(Stack *stack, TreeNode *Node)
{
    if (isStackFull(stack))
    {
        printf("Stack is full!");
        return;
    }

    stack->dataArr[stack->currentCapacity++] = Node;
}

TreeNode *pop(Stack *stack)
{
    if (isStackEmpty(stack))
    {
        printf("Stack is empty!");
        return NULL;
    }

    TreeNode *Node = stack->dataArr[--stack->currentCapacity];
    return Node;
}

void iterativeDepthFirstSearch(TreeNode *root)
{
    Stack *process_stack = createStack(100);

    push(process_stack, root);

    while (!isStackEmpty(process_stack))
    {
        TreeNode *curr = pop(process_stack);
        printf("%d ", curr->data);

        if (curr->right != NULL)
        {
            push(process_stack, curr->right);
        }

        if (curr->left != NULL)
        {
            push(process_stack, curr->left);
        }
    }

    free(process_stack->dataArr);
    free(process_stack);
}

int main()
{
    TreeNode *root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Preorder traversal: ");
    iterativeDepthFirstSearch(root);
    printf("\n"); // Expected output: 50 30 20 40 70 60 80
}
