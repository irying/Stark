#include <stdio.h>
#include <stdlib.h>
#include "min_stack.h"

void minStackInit(MinStack *stack, int maxSize)
{
    stack->element = (MinStackElement *)malloc(sizeof(MinStackElement) * maxSize);
    if (NULL == stack->element) {
        fprintf(stderr, "init failed");
        exit(1);
    }
    
    stack->size = maxSize;
    stack->top = 0;
    
    return;
}

void minStackPush(MinStack *stack, int data)
{
    MinStackElement *p = NULL;
    if (stack->top == stack->size) {
        fprintf(stderr, "out of stack space");
    }
    
    p = stack->element + stack->top;
    p->data = data;
    
    p->min = (0 == stack->top ? data : stack->element[stack->top - 1].min);
    if (p->min > data)
        p->min = data;

    
    ++stack->top;
    
    return;
}

int minStackPop(MinStack *stack)
{
    if (0 == stack->top) {
        fprintf(stderr, "stack is empty");
    }
    
    return stack->element[--stack->top].data;
}

int minStackMin(MinStack *stack)
{
    if (0 == stack->top) {
        fprintf(stderr, "stack is empty");
    }
    
    return stack->element[stack->top-1].min;
}

void minStackDestroy(MinStack *stack)
{
    free(stack->element);
    
    return;
}
