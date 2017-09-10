#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        exit(1);
    }
    
    int length = argc - 1;
    BinaryTreeNode *node,*root = NULL;
    int *data = (int *)calloc(length, sizeof(int));
    
    printf("original data:\n");
    for (int i = 0; i < length; i++) {
        data[i] = atoi(argv[i+1]);
        printf("%d ", data[i]);
        BinaryTreeNode *node = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
        if (node == NULL) {
            exit(1);
        }
        
        node->data = data[i];
        node->left = NULL;
        node->right = NULL;
        
        root = insert(root, node, (COMPARE)compareNode);
    }
    
    
    printf("preOrder:\n");
    preOrder(root);
    
    return 0;
}
