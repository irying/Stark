#ifndef PTREE_H
#define PTREE_H
#define true 1
#define false 0
static int currentSum = 0;

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} BinaryTreeNode;

typedef int(*COMPARE)(void *, void *);

typedef struct stack {
    char element[101];
    int top;
} Stack;

int compareNode(BinaryTreeNode *node1, BinaryTreeNode *node2);

BinaryTreeNode *insert(BinaryTreeNode *root, BinaryTreeNode *node, COMPARE compare);
void preOrder(BinaryTreeNode *root);
void inOrder(BinaryTreeNode *root);
void postOrder(BinaryTreeNode *root);

// 树的子结构，树A有没有包含树B
// 二叉树中和为某值的路径
// 二叉树的深度
// 重建二叉树

_Bool hasSubtree(BinaryTreeNode *node1, BinaryTreeNode *node2);

_Bool doesTree1HasTree2(BinaryTreeNode *node1, BinaryTreeNode *node2);

void findPath(BinaryTreeNode *root, int sum, Stack *stack);

void stackPush(Stack *stack, int data);

int stackPop(Stack *stack);

void printPath(Stack *stack);

void destoryTree(BinaryTreeNode *tree);

BinaryTreeNode *rebuildTree(int *preOrder, int *inOrder,)

#endif
