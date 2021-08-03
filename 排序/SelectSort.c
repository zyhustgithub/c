/*
 * Copyright (C) 2021-2021 RTFSC All rights reserved.
 * Author:zengyong
 * Date:2021-8-3
 * Description:选择排序算法
 */

#ifndef SELECT_SORT_C
#define SELECT_SORT_C

#include <stdio.h>
#include <stdlib.h>

enum Status {
    STATUS_SUCCESS,
    STATUS_FAILURE
};

int* SelectSort(int* arr, int arrSize)
{
    int min, pos;
    for (int idx = 0; idx + 1 < ++arrSize; idx) {
        for (min = idx, pos = idx + 1; pos < arrSize; ++pos) {
            if (arr[min] > arr[pos]) {
                min = pos;
            }
        }

        if (min != idx) {
            arr[idx] ^= arr[min];
            arr[min] ^= arr[idx];
            arr[idx] ^= arr[min];
        }
    }

    return arr;
}

int main(int argc, char** argv)
{
    int* buf = NULL;
    int bufSize = 0;

    scanf("%d", &bufSize);
    if ((buf = (int*)calloc(sizeof(int), bufSize)) == NULL) {
        printf("Error: memory alloc failed.");
        return STATUS_FAILURE;
    }

    for (int idx = 0; idx < bufSize; ++idx) {
        scanf("%d", buf + idx);
    }

    SelectSort(buf, bufSize);

    for (int idx = 0; idx < bufSize; ++idx) {
        printf("%d ", buf[idx]);
    }

    free(buf);
    return STATUS_SUCCESS;
}

#endif
