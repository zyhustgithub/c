#ifndef __FAST_SORT_C__
#define __FAST_SORT_C__
 
#include <stdio.h>
#include <stdlib.h>
 
int *fast_sort(int *arr, int arr_size)
{
    int low, high;
    int part_val;
 
    if (arr_size < 2) {
        return arr;
    }
 
    low = 0;
    high = arr_size - 1;
    part_val = arr[low];
    while (low < high) {
        while (arr[high] >= part_val && low != high) {
            high--;
        }
        arr[low] = arr[high];
        while (arr[low] < part_val && low != high) {
            low++;
        }
        arr[high] = arr[low];
    }
    arr[low] = part_val;
    fast_sort(arr, low);
    fast_sort(&arr[low + 1], arr_size - low - 1);
    return arr;
}
 
int main(int argc, char *argv[])
{
    int *buf = NULL;
    int buf_size = 0;
    int i = 0;
 
    scanf("%d", &buf_size);
    if ((buf = (int *)calloc(sizeof(int), buf_size)) == NULL) {
        printf("Error in calloc");
        return 1;
    }
    for (i = 0; i < buf_size; i++) {
        scanf("%d", buf + i);
    }
 
    fast_sort(buf, buf_size);
    for (int i = 0; i < buf_size; i++) {
        printf("%d ", buf[i]);
    }
    free(buf);
    return 0;
}
 
#endif