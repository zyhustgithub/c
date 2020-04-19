#ifndef GREATEST_NUM_C
#define GREATEST_NUM_C

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int ElemType;
typedef unsigned int ElemSize;

/* 二分查找 */
ElemType FindGreatestNum(ElemType arr[], ElemSize len, ElemType limit)
{
    ElemSize beg, end;
    ElemSize mid = 0;
    ElemType tmp = 0;
    ElemType ans = 0;  // ElemType ans = arr[len-1]
    for (int i = 0; i < len; ++i) {
        beg = 0;
        end = len;
        while (beg < end) {
            mid = (beg + end) / 2;
            tmp = arr[i] + arr[mid];
            if (tmp <= limit) {
                ans = (ans < tmp ? tmp : ans);
                beg = mid + 1;
            } else {
                end = mid;
            }
        }
    }
    return ans;
}

/* 快速排序 */
void FastSort(ElemType arr[], ElemSize len)
{
    ElemSize low = 0;
    ElemSize high = len - 1;
    if (len < 2) {
        return;
    }
    ElemType partVal = arr[low];
    while(low < high) {
        while (arr[high] >= partVal && low != high) {
            --high;
        }
        arr[low] = arr[high];
        while (arr[low] < partVal && low != high) {
            ++low;
        }
        arr[high] = arr[low];
    }
    arr[low] = partVal;
    FastSort(arr, low);
    FastSort(arr + low + 1, len - low -1);
}

/* 求和 */
ElemType GetSize(ElemType num)
{
    if (num == 1) {
        return num;
    } else {
        return num + GetSize(num - 1);
    }
}

/* 测试：打印数组 */
void ShowArr(ElemType arr[], ElemSize len)
{
    for (int i = 0; i < len; ++i) {
        printf("%u ", arr[i]);
    }
    putchar('\n');
}

int main(int argc, char *argv[])
{
    ElemType limit = 0;
    ElemType *arr = NULL;
    ElemSize arrSize = 0;
    ElemType tmp = 0;
    ElemSize count = 0;
    while (scanf("%u %u", &arrSize, &limit) && arrSize != 0) {
        arr = (ElemType *)calloc(arrSize + GetSize(arrSize), sizeof(ElemType));
        int tmpArrSize = 0;
        for (int i = 0; i < arrSize; ++i) {
            scanf("%u", &tmp);
            if (tmp <= limit) {
                arr[tmpArrSize++] = tmp;
            }
        }
        // ShowArr(arr, tmpArrSize);
        arrSize = tmpArrSize;
        for (int i = 0; i < tmpArrSize; ++i) {
            for (int j = 0; j < i + 1; ++j) {
                tmp = arr[i] + arr[j];
                if (tmp <= limit) {
                    arr[arrSize++] = tmp;
                }
            }
        }
        FastSort(arr + tmpArrSize, arrSize - tmpArrSize);
        // ShowArr(arr + tmpArrSize, arrSize - tmpArrSize);
        tmp = FindGreatestNum(arr + tmpArrSize, arrSize - tmpArrSize, limit);
        ++count;
        printf("Case %d: %d\n", count, tmp);

        /* 释放内存 */
        free(arr);
        arr = NULL;
    }
    return 0;
}

#endif