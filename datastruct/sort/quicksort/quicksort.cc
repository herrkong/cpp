#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <deque>
#include <list>
#include <iostream>

// quicksort
// partition

//  Paritition1(int A[], int low, int high) {
//    int pivot = A[low];
//    while (low < high) {
//      while (low < high && A[high] >= pivot) {
//        --high;
//      }
//      A[low] = A[high];
//      while (low < high && A[low] <= pivot) {
//        ++low;
//      }
//      A[high] = A[low];
//    }
//    A[low] = pivot;
//    return low;
//  }

int Partition(int a[], int start, int end)
{
    printf("start=%d,end=%d\n", start, end);
    int pivot = a[start];
    while (start < end)
    {
        // 从右向左找
        while (start < end && a[end] >= pivot)
        {
            --end;
        }

        a[start] = a[end];

        // 从左向右找
        while (start < end && a[start] <= pivot)
        {
            ++start;
        }
        a[end] = a[start];
    }
    a[start] = pivot;
    return start;
}

void PrintArray(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d,", a[i]);
    }
    printf("\n");
}

void QuickSort(int a[], int start, int end)
{
    if (start < end)
    {
        int pivot = Partition(a, start, end);
        printf("pivot=%d\n", pivot);
        QuickSort(a, start, pivot - 1);
        QuickSort(a, pivot + 1, end);
    }
}

int main()
{
    int a[] = {5, 4, 2, 3, 1};
    PrintArray(a, 5);
    QuickSort(a, 0, 4);
    PrintArray(a, 5);
    return 0;
}