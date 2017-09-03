#ifndef LINK_H  
#define LINK_H

typedef struct linkNode {
    int data;
    struct linkNode *next;
} LinkNode;

LinkNode *createLink(int num[], int len);

#endif
