#ifndef __BUBBLE_SORT_C__ 
#define __BUBBLE_SORT_C__ 
#include <stdio.h>
#include <stdlib.h>
 
#ifndef __TRUE__ 
    #define TRUE 1 
#endif 
#ifndef __FALSE__ 
    #define FALSE 0 
#endif 
 
int *bubble_sort(int *arr, int arr_size) 
{ 
    int *i; 
    int sorted = FALSE; 
    int *begin, *end; 
    begin = arr; 
    end = begin + arr_size; 
    while (!sorted) { 
        sorted = TRUE; 
        for (i = begin; i + 1 < end; i++) { 
            if (*i > *(i + 1)) { 
                *i ^= *(i + 1); 
                *(i + 1) ^= *i; 
                *i ^= *(i + 1); 
                sorted = FALSE; 
            } 
        } 
        end--; 
    } 
    return begin; 
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
    bubble_sort(buf, buf_size); 
    for (int i = 0; i < buf_size; i++) { 
        printf("%d ", buf[i]); 
    } 
    free(buf); 
    return 0; 
} 
 
#endif