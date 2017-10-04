#include <stdio.h>
#include <stdlib.h>

static int radix = 10;

int getDigit(int x, int d)
{
    int t,i;
    for (int i = 1; i <= d; i++) {
        t = x % radix;
        x /= radix;
    }
    
    return t;
}

//分配：这个位数的成一行，无序，排序，第一位拿来统计
//复位
void radixSort(int *arr, int length, int d)
{
    int *bucket[radix];
    int i,j;
    
    for (i = 0; i < radix; i++) {
        bucket[i] = (int *)malloc((length+1)*sizeof(int));
        bucket[i][0] = 0;
    }

    
    for (int pos = 1; pos <= d; pos++) {
        for (i = 0; i < length; i++) {
            int num = getDigit(arr[i], pos);
            int index = ++bucket[num][0];
            bucket[num][index] = arr[i];
        }
        
        for (i = 0, j =0; i < radix; i++) {
            for (int k = 1; k <= bucket[i][0]; k++) {
                arr[j++] = bucket[i][k];
            }
            bucket[i][0] = 0; // 复位
        }
    }
}

int main()
{
    int arr[10] = {73, 22, 93, 43, 55, 14, 28, 65, 39, 81};
    radixSort(arr, 10, 2);
    for (int i=0; i<10; i++ )
        printf("%d  ", arr[i]);
    printf("\n");
    
    return 0;
}


