#include <stdio.h>
#include <stdlib.h>
#include "link.h"

LinkNode *createLink(int arr[], int len)
{
    if (arr == NULL || len <= 0) {
        fprintf(stderr, "arg error");
        return NULL;
    }
    
    LinkNode *head = (LinkNode *)malloc(sizeof(LinkNode));
    if (head == NULL) {
        fprintf(stderr, "head malloc error");
        return NULL;
    }
    head->data = 0;
    head->next = NULL;
    LinkNode *p = head;
    
    for (int i = 0; i < len; i++) {
        LinkNode *node = (LinkNode *)malloc(sizeof(LinkNode));
        if (node == NULL) {
            fprintf(stderr, "node malloc error");
            return NULL;
        }
        node->data = arr[i];
        node->next = NULL;
        p->next = node;
        p = node;
    }
    
    return head;
}
