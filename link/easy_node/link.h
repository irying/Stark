#ifndef LINK_H  
#define LINK_H

typedef struct linkNode {
    int data;
    struct linkNode *next;
} LinkNode;

LinkNode *createLink(int num[], int len);

LinkNode *theKthNode(LinkNode *head, int k);

LinkNode *midNode(LinkNode *head);

_Bool hasCircle(LinkNode *head, LinkNode **circleNode);

_Bool isIntersect(LinkNode *l1, LinkNode *l2);

LinkNode *findIntersectPort(LinkNode *l1, LinkNode *l2);

LinkNode *reverseByLoop(LinkNode *head);

LinkNode *reverseByRecursion(LinkNode *head);   

int getLinkLength(LinkNode *head);

#endif
