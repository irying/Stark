#ifndef TREE_H
#define TREE_H

typedef struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
} BinaryTreeNode;

BinaryTreeNode insert(BinaryTreeNode *root, BinaryTreeNode *node);

#endif
