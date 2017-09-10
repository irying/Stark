#ifndef TREE_H
#define TREE_H

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} BinaryTreeNode;

typedef int(*COMPARE)(void *, void *);

int compareNode(BinaryTreeNode *node1, BinaryTreeNode *node2);

BinaryTreeNode *insert(BinaryTreeNode *root, BinaryTreeNode *node, COMPARE compare);

void preOrder(BinaryTreeNode *root);
void inOrder(BinaryTreeNode *root);
void postOrder(BinaryTreeNode *root);

#endif
