#ifndef MINSTACK_H
#define MINSTACK_H

typedef struct minStackElement {
    int data;
    int min;
} MinStackElement;

typedef struct minStack {
    MinStackElement *element;
    int size;
    int top;
} MinStack;

void minStackInit(MinStack *stack, int maxSize);

void minStackPush(MinStack *stack, int data);

int minStackPop(MinStack *stack);

int minStackMin(MinStack *stack);

void minStackDestroy(MinStack *stack);

#endif
