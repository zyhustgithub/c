/*
 * Copyright (C) 2021-2021 RTFSC All rights reserved.
 * Author:zengyong
 * Date:2021-8-3
 * Description:插入排序算法
 */

#ifndef INSERT_SORT_C
#define INSERT_SORT_C

#include <stdio.h>
#include <stdlib.h>

enum Status {
    STATUS_SUCCESS,
    STATUS_FAILURE
};

int* InsertSort(int* arr, int arrSize)
{
    int insertPos = 0;
    int insertNum = 0;
    for (int pos = 1; pos < arrSize; ++pos) {
        insertNum = arr[pos];
        for (insertPos = pos - 1; insertPos >= 0; insertPos--) {
            if (arr[insertPos] <= insertNum) {
                break;
            } else {
                arr[insertPos + 1] = arr[insertPos];
            }
        }

        arr[insertPos + 1] = insertNum;
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

    InsertSort(buf, bufSize);

    for (int idx = 0; idx < bufSize; ++idx) {
        printf("%d ", buf[idx]);
    }

    free(buf);
    return STATUS_SUCCESS;
}

#endif