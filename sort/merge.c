#include <stdio.h>
#include <stdlib.h>


void merge(int *arr, int low, int mid, int high)
{
    int i = low, j = mid + 1, p = 0;
    int *data;
    data = (int *)malloc(sizeof(int)*(high-low+1));
    if (!data) {
        printf("malloc error");
    }
    
    while (i <= mid && j <= high) {
        data[p++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
    }
    
    while (i <= mid) {
        data[p++] = arr[i++];
    }
    
    while (j <= high) {
        data[p++] = arr[j++];
    }
    
    // 归位很重要
    
    for (p = 0, i = low; i <= high; p++, i++) {
        arr[i] = data[p];
    }
}


int min(int x, int y)
{
    return x <= y ? x : y;
}

// 自底向上
void fromDownToTop(int *arr, int n)
{
    // 每轮归并length长度区间的
    for (int length = 1; length <= n; length += length) {
        // 第一轮对【0到length-1，对length到2length-1】归并，第2轮对【2length~3length-1，3length~4length-1)
        for (int i = 0; i + length < n; i += length + length) {
            // 中间值就是i+length-1
            merge(arr, i, i + length - 1, min(i + length + length - 1, n-1));
        }
    }
}

//自顶向下
void fromTopToDown(int *arr, int left, int right)
{
    if ( left >= right) {
        return;
    }
    
    int mid = (left + right) / 2;
    fromTopToDown(arr, left, mid);
    fromTopToDown(arr, mid + 1, right);
    if (arr[mid] > arr[mid+1]) {
        merge(arr, left, mid, right);
    }
    
}

int main()
{
    int arr[10] = {73, 22, 93, 43, 55, 14, 28, 65, 39, 81};
    int arr1[10] = {73, 22, 93, 43, 55, 14, 28, 65, 39, 81};
    fromTopToDown(arr, 0, 9);
    printf("自顶向下\n");
    for (int i=0; i<10; i++ )
        printf("%d  ", arr[i]);
    printf("\n");
    
    fromDownToTop(arr1, 10);
    printf("自底向上\n");
    for (int i=0; i<10; i++ )
        printf("%d  ", arr1[i]);
    
    return 0;

}

