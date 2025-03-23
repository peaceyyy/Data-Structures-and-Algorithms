#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
} TreeNode;

TreeNode *createNode(int value)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (!newNode)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode *insert(TreeNode *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}

TreeNode *findMin(TreeNode *root)
{
    while (root && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

TreeNode *deleteNode(TreeNode *root, int value)
{
    if (root == NULL)
    {
        return root;
    }

    // Recur down the tree
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    // Node to be deleted found
    else
    {
        // Case 1: No children (leaf node)
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        // Case 2: One child (right child only)
        else if (root->left == NULL)
        {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        // Case 3: One child (left child only)
        else if (root->right == NULL)
        {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        // Case 4: Two children
        else
        {
            TreeNode *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

void inorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main()
{
    TreeNode *root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
    {
        root = insert(root, values[i]);
    }

    printf("BST In-order before deletion: ");
    inorderTraversal(root);
    printf("\n");

    int nodeToDelete = 50;
    root = deleteNode(root, nodeToDelete);

    printf("BST In-order after deleting %d: ", nodeToDelete);
    inorderTraversal(root);
    printf("\n");

    return 0;
}
