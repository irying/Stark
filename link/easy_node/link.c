#include <stdio.h>
#include <stdlib.h>
#include "link.h"
#define true 1
#define false 0

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

LinkNode *theKthNode(LinkNode *head, int k)
{
    if (k < 0 || head == NULL) {
        return NULL;
    }
    
    LinkNode *fast,*slow;
    fast = slow = head;
    int i = k;
    for(;i > 0; i--)
    {
        fast = fast->next;
    }
    
    if (i>0) return NULL; // k 大于链表长度的情况
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    return slow;
}

LinkNode *midNode(LinkNode *head)
{
    if (head == NULL) {
        return NULL;
    }
    
    LinkNode *slow,*fast;
    slow = fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return slow;
}

_Bool hasCircle(LinkNode *head, LinkNode **circleNode)
{
    if (head == NULL) {
        return NULL;
    }
    
    LinkNode *slow,*fast;
    
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        
        if (fast == slow) {
            *circleNode = fast;
            return true;
        }
    }
    
    
    return false;
}

LinkNode *findCirclePort(LinkNode *head)
{
    if (head == NULL) {
        return NULL;
    }
    
    LinkNode *slow,*fast;
    slow = fast = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            break;
        }
    }
    
    if (fast != slow) {
        return NULL;
    }
    
    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    
    return fast;
}

_Bool isIntersect(LinkNode *l1, LinkNode *l2)
{
    if (l1 == NULL || l2 == NULL) {
        return false;
    }
    
    while (l1->next != NULL) {
        l1 = l1->next;
    }
    
    while (l2->next != NULL) {
        l2 = l2->next;
    }
    
    if (l1 == l2) {
        return true;
    }
    
    return false;
    
}

LinkNode *findIntersectNode(LinkNode *l1, LinkNode *l2)
{
    if (l1 == NULL || l2 == NULL) {
        return NULL;
    }
    
    int len1 = getLinkLength(l1);
    int len2 = getLinkLength(l2);
    int diff = 0;
    
    if (len1 > len2) {
        diff = len1 - len2;
        for (int i = 0; i < diff; i++) {
            l1 = l1->next;
        }
        
    }else {
        diff = len2 - len1;
        for (int i = 0; i < diff; i++) {
            l2 = l2->next;
        }
    }
    
    while (l1 != NULL) {
        if (l1 == l2) {
            return l1;
        }
        
        l1 = l1->next;
        l2 = l2->next;
    }
    
    return NULL;
    
}

int getLinkLength(LinkNode *head)
{
    if (head == NULL) {
        return 0;
    }
    
    int length = 0;
    while (head->next) {
        length++;
        head = head->next;
    }
    
    return length;
}

LinkNode *reverseByLoop(LinkNode *head)
{
    if (head == NULL) {
        return NULL;
    }
    
    LinkNode *newHead = NULL;
    LinkNode *prev = NULL;
    LinkNode *node = head;
    
    while (node != NULL) {

        LinkNode *next = node->next;
        if (next == NULL) {
            newHead = node;
        }
        
        node->next = prev;
        prev = node;
        node = node->next;
    }
    
    return newHead;
}
