#ifndef MINSTACK_H
#define MINSTACK_H

typedef struct minStackElement {
    int data;
    int min;
} minStackElement;

typedef struct minStack {
    minStackElement *element;
    int size;
    int top;
} MinStack;

void minStackInit(minStack *stack, int maxSize);

void minStackPush(minStack *stack, int data);

int minStackPop(minStack *stack);

int minStackMin(minStack *stack);

void minStackDestroy(minStack *stack);

#endif
