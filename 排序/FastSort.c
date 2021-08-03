/*
 * Copyright (C) 2021-2021 RTFSC All rights reserved.
 * Author:zengyong
 * Date:2021-8-3
 * Description:快速排序算法
 */

#ifndef FAST_SORT_C
#define FAST_SORT_C

#include <stdio.h>
#include <stdlib.h>

enum Status {
    STATUS_SUCCESS,
    STATUS_FAILURE
};

int* FastSort(int* arr, int nArrSize)
{
    if (nArrSize < 2) {
        return arr;
    }

    int low = 0;
    int high = nArrSize - 1;
    int partVal = arr[low];
    while (low < high) {
        while ((arr[high] >= partVal) && (low != high)) {
            high--;
        }
        arr[low] = arr[high];

        while ((arr[low] < partVal) && (low != high)) {
            low++;
        }
        arr[high] = arr[low];
    }

    arr[low] = partVal;
    FastSort(arr, low);
    FastSort(&arr[low + 1], nArrSize - low - 1);
    return arr;
}

int main(int argc, char* argv[])
{
    int* buf = NULL;
    int nBufSize = 0;

    scanf("%d", &nBufSize);
    if ((buf = (int*)calloc(sizeof(int), nBufSize)) == NULL) {
        printf("Error: memory alloc failed.");
        return STATUS_FAILURE;
    }

    for (int idx = 0; idx < nBufSize; idx++) {
        scanf("%d", buf + idx);
    }

    FastSort(buf, nBufSize);

    for (int idx = 0; idx < nBufSize; idx++) {
        printf("%d ", buf[idx]);
    }

    free(buf);
    return STATUS_SUCCESS;
}

#endif