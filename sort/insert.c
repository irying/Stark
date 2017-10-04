#include <stdio.h>

void insert(int *arr, int n)
{
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j;
        for (j = i; j > 0 && arr[j-1] > temp; j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
}

int main()
{
    int arr[10] = {73, 22, 93, 43, 55, 14, 28, 65, 39, 81};
    insert(arr, 10);
    for (int i=0; i<10; i++ )
        printf("%d  ", arr[i]);
    printf("\n");
    
    return 0;
}
