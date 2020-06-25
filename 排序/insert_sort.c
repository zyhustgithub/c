#ifndef __INSERT_SORT_C__
#define __INSERT_SORT_C__
 
#include <stdio.h>
#include <stdlib.h>
 
int *insert_sort(int *arr, int arr_size)
{
    int insert_pos, insert_num;
    for (int pos = 1; pos < arr_size; pos++) {
        insert_num = arr[pos];
        for (insert_pos = pos - 1; insert_pos >= 0; insert_pos--) {
            if (arr[insert_pos] <= insert_num) {
                break;
            } else {
                arr[insert_pos + 1] = arr[insert_pos];
            }
        }
        arr[insert_pos + 1] = insert_num;
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
 
    insert_sort(buf, buf_size);
    for (int i = 0; i < buf_size; i++) {
        printf("%d ", buf[i]);
    }
    free(buf);
    return 0;
}
 
#endif