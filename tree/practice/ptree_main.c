#include <stdio.h>
#include <stdlib.h>
#include "ptree.h"


int main(int argc, char *argv[])
{
    if (argc < 2) {
        exit(1);
    }
    
    int length = argc - 1;
    BinaryTreeNode *node,*root,*node2,*root2 = NULL;
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
// 6 3 9 5 7 8 2 4 1 10
    
    int arr[5] = {3,2,5,1,4};
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
    
    
//    printf("in it %d:\n", hasSubtree(root, root2));

    return 0;
}
