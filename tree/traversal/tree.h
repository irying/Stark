#ifndef TREE_H
#define TREE_H

typedef struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
} BinaryTreeNode;

typedef int(*COMPARE)(void *, void *);

int compare(BinaryTreeNode *node1, BinaryTreeNode *node2);

BinaryTreeNode insert(BinaryTreeNode *root, BinaryTreeNode *node);

void preOrder(BinaryTreeNode *root);
void inOrder(BinaryTreeNode *root);
void postOrder(BinaryTreeNode *root);

#endif
