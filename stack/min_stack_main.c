#include <stdio.h>
#include <stdlib.h>
#include "min_stack.h"

int main()
{
    int data[10] = {12,34,77,66,44,24,7,92,56,3};
    int i;
    
    MinStack ms;
    
    minStackInit(&ms, 10);
    
    for (i = 0; i < 10; i++) {
        printf("push element %d\n", data[i]);
        minStackPush(&ms, data[i]);
        printf("min is %d\n", minStackMin(&ms));
    }
    
    printf("\n");
    
    for (i = 0; i < 10; i++) {
        printf("pop element %d\n", minStackPop(&ms));
        printf("min is %d\n", minStackMin(&ms));
    }
    
    minStackDestroy(&ms);
    
    exit(0);
}
