#include <stdio.h>
#include <stdlib.h>


void quicksort(int *data, int left, int right)
{
    int i,j,t,temp;
    if (left>right) {
        return;
    }
    i = left;
    j = right;
    temp = data[left];
    
    while (i !=j ) {
        while (data[j] >= temp && i<j )
            j--;
        while (data[i] <= temp && i<j)
            i++;
        if (i<j) {
            t = data[i];
            data[i] = data[j];
            data[j] = t;
        }
    }
    data[left] = data[i];
    data[i] = temp;
    quicksort(data, left, i-1);
    quicksort(data, i+1, right);
   
    
}


int main(int argc, char *argv[])
{
    if (argc < 2) {
        exit(1);
    }
    
    int length = argc - 1;
    int *data = (int *)calloc(length, sizeof(int));
    
    for (int i = 0; i < length; i++) {
        data[i] = atoi(argv[i+1]);
    }
    for(int i=0;i<length;i++)
        printf("%d\t",data[i]);
    
    quicksort(data, 0, length-1);
    printf("排序后 \n");
    for(int i=0; i<length; i++)
        printf("%d\t", data[i]);
    printf ("\n");
    
    return 0;
}
