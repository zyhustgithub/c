/*
 * Copyright (C) 2021-2021 RTFSC All rights reserved.
 * Author:zengyong
 * Date:2021-8-3
 * Description:冒泡排序算法
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef __TRUE__
#define TRUE 1
#endif

#ifndef __FALSE__
#define FALSE 0
#endif

enum Status {
    STATUS_SUCCESS,
    STATUS_FAILURE
};

int* BubbleSort(int* arr, int arr_size)
{
    int* begin = arr;
    int* end = begin + arr_size;
    int sorted = FALSE;
    while (!sorted) {
        sorted = TRUE;
        for (int* idx = begin; idx + 1 < end; ++idx) {
            if (*idx > *(idx + 1)) {
                *idx ^= *(idx + 1);
                *(idx + 1) ^= *idx;
                *idx ^= *(idx + 1);
                sorted = FALSE;
            }
        }

        end--;
    }

    return begin;
}

int main(int argc, char** argv)
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

    BubbleSort(buf, nBufSize);

    for (int idx = 0; idx < nBufSize; idx++) {
        printf("%d ", buf[idx]);
    }

    free(buf);
    return STATUS_SUCCESS;
}
