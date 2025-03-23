#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {

    int val ;
    struct treeNode* left;
    struct treeNode* right;

} treeNode;

treeNode* newNode (int val)
{
    treeNode* node = malloc(sizeof(treeNode));
    node->val = val; 
    node->left = NULL; 
    node->right = NULL;

    return node;
}

int main(){

    treeNode* root = newNode(0);
    root -> left = newNode(1);
    root -> right = newNode(2);
    printf("Root value is %d\n", root->val);
    printf("The left child is %d\n", root->left->val);
    printf("The right child is %d", root->right->val);

    
    return 0;   

}