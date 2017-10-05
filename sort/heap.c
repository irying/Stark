#include <stdio.h>
#include <stdlib.h>

#define LENGTH(a) ( (sizeof(a)) / (sizeof(a[0])) )

static int heap[11];
static int capacity = 11;
static int size = 0;

int getIndex(int data)
{
    for (int i = 0; i < size; i++) {
        if (data == heap[i]) {
            return i;
        }
    }
    
    return -1;
}

// 最大堆的向下调整
static void filterDown(int start, int end)
{
    int leftChild = start * 2 + 1;
    int temp = heap[start];
    
    while (leftChild <= end) {
        // 左右节点取值大的那个
        if (leftChild < end && heap[leftChild] < heap[leftChild + 1]) {
            leftChild++;
        }
        if (temp >= heap[leftChild]) {
            break;
        } else {
            heap[start] = heap[leftChild];
            start = leftChild;
            leftChild = 2 * leftChild + 1;
        }
    }
    
    heap[start] = temp;
}

// 最大堆的向上调整
static void filterUp(int start)
{
    int parent = (start-1) / 2;
    int temp = heap[start];
    
    while (start > 0) {
        if (heap[parent] < temp) {
            heap[start] = heap[parent];
            start = parent;
            parent = (parent-1) / 2;
        } else {
            break;
        }
    }
    
    heap[start] = temp;
}

int insert(int data)
{
    if (size == capacity) {
        return -1;
    }
    
    heap[size] = data;
    filterUp(size);
    size++;
    
    
    return 0;
}

int heapRemove(int data)
{
    
    if (size == 0) {
        return -1;
    }
    
    int index = getIndex(data);
    if (index == -1) {
        return -1;
    }
    
    heap[index] = heap[--size];
    
    filterDown(index, size-1);
    
    return 0;
}

void heapPrint()
{
    for (int i=0; i < size; i++) {
        printf("%d ", heap[i]);
    }
}

int main()
{
    int a[] = {10, 40, 30, 60, 90, 70, 20, 50, 80};
    int i, len=LENGTH(a);
    printf("== 依次添加: ");
    for(i=0; i<len; i++) {
        printf("%d ", a[i]);
        insert(a[i]);
    }
    printf("\n== 最 大 堆: ");
    heapPrint();
    i=85;
    insert(i);
    printf("\n== 添加元素: %d", i);
    printf("\n== 最 大 堆: ");
    heapPrint();
    
    i=90;
    heapRemove(i);
    printf("\n== 删除元素: %d", i);
    printf("\n== 最 大 堆: ");
    heapPrint();
    printf("\n");
    
    return 0;
}
