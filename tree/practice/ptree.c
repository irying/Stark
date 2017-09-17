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


void findPath(BinaryTreeNode *root, int sum, Stack *stack)
{
    if (root == NULL) {
        return;
    }
    
    currentSum += root->data;
    stackPush(stack, root->data);
    
    
    _Bool isLeaf = root->left == NULL && root->right == NULL;
    if (currentSum == sum && isLeaf) {
        printf("\n");
        printPath(stack);
    }
    
    if (root->left != NULL) {
        findPath(root->left, sum, stack);
    }
    if (root->right != NULL) {
        findPath(root->right, sum, stack);
    }
    currentSum -= root->data;
    stackPop(stack);
}

void stackPush(Stack *stack, int data)
{
    if (!stack) return;
    stack->element[stack->top++] = data;
    return;
}

int stackPop(Stack *stack)
{
    if (!stack || stack->top == 0) {
        return 0;
    }
    
    return stack->element[--stack->top];
}

void printPath(Stack *stack)
{
    if (stack->top == 0) {
        printf("no path\n");
        return;
    }
    
    for (int i = 0; i < stack->top; i++) {
        printf("%d\t", stack->element[i]);
    }
    
    printf("\n");
    return;
}

void destoryTree(BinaryTreeNode *tree) {
    if (!tree) { return; }
    
    destoryTree(tree->left);
    destoryTree(tree->right);
    free(tree);
}
