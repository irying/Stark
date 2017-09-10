#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

BinaryTreeNode *insert(BinaryTreeNode *root, BinaryTreeNode *node, COMPARE compare)
{
    if (root == NULL) {
        return node;
    }
    if (compare(root, node) > 0) {
        root->left = insert(root->left, node, compare);
    }else {
        root->right = insert(root->right, node, compare);
    }
    
    
    return root;
}

int compareNode(BinaryTreeNode *node1, BinaryTreeNode *node2)
{
    return node1->data > node2->data;
}

void preOrder(BinaryTreeNode *root)
{
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }else{
        return;
    }
}

// 递归版本
void inOrder(BinaryTreeNode *root)
{
    
    if (root->left != NULL) {
        inOrder(root->left);
    }
    printf("%d ", root->data);
    if (root->right != NULL) {
        inOrder(root->right);
    }
    return;

}

// 不想写，两个while，一个数组存数据
void inOrderWithLoop(BinaryTreeNode *root)
{
    
}

void postOrder(BinaryTreeNode *root)
{
    if (root->left != NULL) {
        postOrder(root->left);
    }
    
    if (root->right != NULL) {
        postOrder(root->right);
    }
    
    printf("%d ", root->data);
    return;
}
