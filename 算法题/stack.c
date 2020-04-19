#ifndef STACK_C
#define STACK_C

#include <stdio.h>
#include <stdlib.h>

#define INIT_LIST_SIZE 256
#define SIZE_INCREMENT 64
#define SUCCESS 0
#define FAILURE 1

typedef struct stack {
    char *data;
    int size;
    int length;
} stack;

typedef stack * stackList;

int InitStack(stackList SL)
{
    SL->data = (char *)malloc(INIT_LIST_SIZE * sizeof(char));
    if (SL->data == NULL) {
        return FAILURE; 
    }
    SL->size = 0;
    SL->length = INIT_LIST_SIZE;
    return SUCCESS;
}

void DestroyStack(stackList SL)
{
    free(SL->data);
    SL->data = NULL;
    SL->size = 0;
    SL->length = 0;
}

void ClearStack(stackList SL)
{
    SL->size = 0;
}

int Push(stackList SL, char ch)
{
    char *newBase = NULL;
    if (SL->size >= SL->length) {
        newBase = (char *)realloc(SL->data, (SL->length + SIZE_INCREMENT) * sizeof(char));
        if (newBase == NULL) {
            return FAILURE;
        }
        SL->data = newBase;
        SL->length += SIZE_INCREMENT;
    }
    (SL->data)[SL->size++] = ch;
    return SUCCESS;
}

int Pop(stackList SL, char *ch)
{
    if (SL->size == 0) {
        return FAILURE;
    }
    *ch = SL->data[--SL->size];
    return SUCCESS;
}

int main(int argc, char *argv[])
{
    stack S;
    InitStack(&S);
    int ch;
    char tmp;
    while ((ch = getchar()) != EOF) {
        ungetc(ch, stdin);
        while ((ch = getchar()) != '\n') {
            if ((ch != '(') && (ch != ')')) {
                continue;
            }
            if (Pop(&S, &tmp) == SUCCESS) {
                if ((tmp == '(') && (ch == ')')) {
                    continue;
                }
                Push(&S, tmp);
            }
            Push(&S, ch);
        }
        printf("%d\n", S.size);
        ClearStack(&S);
    }
    DestroyStack(&S);
    return 0;
}

#endif