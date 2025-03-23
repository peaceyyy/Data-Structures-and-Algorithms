#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct QueueNode
{
    TreeNode *treeNode;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue
{
    QueueNode *front;
    QueueNode *rear;
} Queue;

TreeNode *createTreeNode(int data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

QueueNode *createQueueNode(TreeNode *treeNode)
{
    QueueNode *newQueueNode = (QueueNode *)malloc(sizeof(QueueNode));
    newQueueNode->treeNode = treeNode;
    newQueueNode->next = NULL;
    return newQueueNode;
}

Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isQueueEmpty(Queue *queue)
{
    return queue->front == NULL;
}

void enqueue(Queue *queue, TreeNode *treeNode)
{
    QueueNode *newQueueNode = createQueueNode(treeNode);
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = newQueueNode;
        return;
    }
    queue->rear->next = newQueueNode;
    queue->rear = newQueueNode;
}

TreeNode *dequeue(Queue *queue)
{
    if (isQueueEmpty(queue))
    {
        return NULL;
    }
    QueueNode *temp = queue->front;
    TreeNode *treeNode = temp->treeNode;
    queue->front = queue->front->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(temp);
    return treeNode;
}

TreeNode *insertNode(TreeNode *root, int val)
{
    if (root == NULL)
    {
        return createTreeNode(val);
    }
    if (val < root->data)
    {
        root->left = insertNode(root->left, val);
    }
    else
    {
        root->right = insertNode(root->right, val);
    }
    return root;
}

void freeQueue(Queue *queue)
{
    while (!isQueueEmpty(queue))
    {
        dequeue(queue);
    }
    free(queue);
}

void breadthFirstSearch(TreeNode *root)
{
    if (root == NULL)
    {
        fprintf(stderr, "Binary Tree is empty");
        return;
    }
    Queue *queue = createQueue();
    enqueue(queue, root);

    while (!isQueueEmpty(queue))
    {
        TreeNode *curr = dequeue(queue);
        printf("%d ", curr->data);

        if (curr->left != NULL)
        {
            enqueue(queue, curr->left);
        }

        if (curr->right != NULL)
        {
            enqueue(queue, curr->right);
        }
    }

    freeQueue(queue);
}

int main()
{

    TreeNode *root = NULL;

    root = insertNode(root, 10);
    insertNode(root, 11);
    insertNode(root, 13);
    insertNode(root, 15);
    insertNode(root, 5);
    insertNode(root, 15);
    insertNode(root, 3);
    insertNode(root, 7);
    insertNode(root, 12);
    insertNode(root, 18);

    // Expected output for BFS: 10 5 11 3 7 13 15 12 15 18

    printf("Breadth-First Search: ");
    breadthFirstSearch(root);

    return 0;
}