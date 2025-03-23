#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int value)
{
    Node *newNode = malloc(sizeof(Node));

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
Node *insert(Node *root, int value)
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

// Depth-First Traversals

void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node *root)
{

    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void postorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

void freeTree(Node *root)
{
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);

    free(root);
}

int main()
{
    Node *root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n"); // Expected output: 50 30 20 40 70 60 80

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n"); // Expected output: 20 30 40 50 60 70 80

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n"); // Expected output: 20 40 30 60 80 70 50

    freeTree(root);

    return 0;
}