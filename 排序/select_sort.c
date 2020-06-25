#ifndef __SELECT_SORT_C__
#define __SELECT_SORT_C__
 
#include <stdio.h>
#include <stdlib.h>
 
int *select_sort(int *arr, int arr_size)
{
    int cur, sel, min;
    for (cur = 0; cur + 1 < arr_size; cur++) {
        for (min = cur, sel = cur + 1; sel < arr_size; sel++) {
            if (arr[min] > arr[sel]) {
                min = sel;
            }
        }
        if (min != cur) {
            arr[cur] ^= arr[min];
            arr[min] ^= arr[cur];
            arr[cur] ^= arr[min];
        }
    }
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
 
    select_sort(buf, buf_size);
    for (int i = 0; i < buf_size; i++) {
        printf("%d ", buf[i]);
    }
    free(buf);
    return 0;
}
#endif