#include <stdio.h>
#include <stdlib.h>
#include "ptree.h"


int main(int argc, char *argv[])
{
    if (argc < 2) {
        exit(1);
    }
    
    int length = argc - 1;
    BinaryTreeNode *node1,*root1,*node2,*root2 = NULL;
    int *data = (int *)calloc(length, sizeof(int));

    printf("original data:\n");
    for (int i = 0; i < length; i++) {
        data[i] = atoi(argv[i+1]);
        printf("%d ", data[i]);
        BinaryTreeNode *node1 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
        if (node1 == NULL) {
            exit(1);
        }
        
        node1->data = data[i];
        node1->left = NULL;
        node1->right = NULL;
        
        root1 = insert(root1, node1, (COMPARE)compareNode);
    }
// 6 3 9 5 7 8 2 4 1 10
    
    char arr[5] = {3,2,5,1,4};
    for (int j = 0; j < 5; j++) {
        BinaryTreeNode *node2 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
        if (node2 == NULL) {
            exit(1);
        }
        
        node2->data = arr[j];
        node2->left = NULL;
        node2->right = NULL;
        
        root2 = insert(root2, node2, (COMPARE)compareNode);
    }
   
    
    printf("in it %d:\n", hasSubtree(root1, root2));
    int sum;
    printf("to find a path which the node value sum is: ");
    scanf("%d", &sum);
    if(sum<0) exit(1);
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = 0;
    findPath(root1, sum, stack);
    
    printf("to rebuid a tree\n");
    printf("enter the preOrder:\n");
    char pre[100];
    for(i = 0; i < 100; i++) {
        scanf("%d ",&pre[i]);
        if (<#condition#>) {
            <#statements#>
        }
    }
        
    scanf("%d", &sum);
    
    
    free(stack);
    destoryTree(root1);
    return 0;
}
