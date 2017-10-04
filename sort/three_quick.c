#include <stdio.h>
#include <stdlib.h>


void quicksort3Ways(int *arr, int left, int right)
{

    if (left>right) {
        return;
    }
    int lt = left; // arr[left+1..left] < temp
    int gt = right +1; // arr[gt...right] > temp
    int i = left + 1; // arr[lt+1..i] = temp
    int temp = arr[left];
    
    while (i < gt ) {
        if (arr[i] < temp) {
            int j = arr[i];
            arr[i] = arr[lt+1];
            arr[lt+1] = j;
            lt++;
            i++;
        } else if(arr[i] > temp) {
            int t = arr[i];
            arr[i] = arr[gt-1];
            arr[gt-1] = t;
            gt--;
        } else{
            i++;
        }
        
    }
    arr[left] = arr[lt];
    arr[lt] = temp;
    quicksort3Ways(arr, left, lt-1);
    quicksort3Ways(arr, gt, right);
    
    
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
    
    quicksort3Ways(data, 0, length-1);
    printf("排序后 \n");
    for(int i=0; i<length; i++)
        printf("%d\t", data[i]);
    printf ("\n");
    
    return 0;
}
