#include <stdio.h>
#include <stdlib.h>
#include "link.h"

int main()
{
    int arr1[6] = {2,5,6,22,33,55};
    int arr2[9] = {1,3,4,5,6,7,22,33,55};
    
    LinkNode *l1 = createLink(arr1, 6);
    LinkNode *l2 = createLink(arr2, 9);
    
    printf("mid of l1 is %d\n", midNode(l1)->data);
    printf("last 3 of l2 is %d\n", theKthNode(l2, 3)->data);
    printf("intersect of l1 and l2 is %d\n", isIntersect(l1, l2));
    
    return 0;
}
