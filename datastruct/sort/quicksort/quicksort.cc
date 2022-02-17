#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <list>
#include <algorithm>
#include "/home/darwinkong/code/cpp/public/cpp/cpp.hpp"

// quicksort
// 递归
// 左边元素都小于 pivot
// 右边元素都大于 pivot

void QuickSort(int[] vec, int start, int end)
{
    if (start > end)
    {
        int pivot = partition(vec, start, end);
        QuickSort(vec, start, pivot - 1);
        QuickSort(vec, pivot + 1, end);
    }
    return;
}

int partition(int[] vec, int start, int end)
{
    int pivotValue = vec[start];
    int pivotPositon = start;

    for (start < end){
        for (start < end && vec[end] >= pivotValue; end--){
            vec[start] = vec[end];
        }

        for (start < end && vec[start] >= pivotValue ; start++){
            vec[end] = vec[start];
        }
    }

    vec[start] = pivotValue;
    return pivotPositon;
}

int main()
{
    int[] vec = {5, 3, 1, 4, 2};
    QuickSort(vec, 0, 4);
    PrintVec(vec);
    return 0;
}