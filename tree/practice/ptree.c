#include <stdio.h>
#include <stdlib.h>
#include "ptree.h"

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

_Bool hasSubtree(BinaryTreeNode *node1, BinaryTreeNode *node2)
{
    _Bool result = false;
    if (node1->data == node2->data) {
        result = doesTree1HasTree2(node1, node2);
    }
    
    if (!result) {
        result = doesTree1HasTree2(node1->left, node2);
    }
    
    if (!result) {
        result = doesTree1HasTree2(node1->right, node2);
    }
    
    return result;
}

_Bool doesTree1HasTree2(BinaryTreeNode *node1, BinaryTreeNode *node2)
{
    if (node2 == NULL) {
        return true;
    }
    
    if (node1 == NULL) {
        return false;
    }
    
    if (node1->data != node2->data) {
        return false;
    }
    
    return doesTree1HasTree2(node1->left, node2->left) && doesTree1HasTree2(node1->right, node2->right);
    
}