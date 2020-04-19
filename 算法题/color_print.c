#ifndef COLOR_PRINT_C
#define COLOR_PRINT_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST_INIT_SIZE 1024
#define LIST_INCREMENT 256
#define SUCCESS        1
#define ERROR          0

typedef struct LNode {
    char *data;
    int length;
    int listSize;
} LNode;

int InitList(LNode *L)
{
    L->data = (char *)calloc(LIST_INIT_SIZE, sizeof(char));
    if (L->data == NULL) {
        return ERROR;
    }
    L->length = 0;
    L->listSize = LIST_INIT_SIZE;
    return SUCCESS;
}

void ClearList(LNode *L)
{
    L->length = 0;
    memset((void *)L->data, 0, L->listSize);
}

void DestroyList(LNode *L)
{
    free(L->data);
    L->data = NULL;
    L->length = L->listSize = 0;
}

int Insert(LNode *L, int pos, char e)
{
    if (pos < 1 || pos > L->length + 1) {
        return ERROR;
    }
    char *newBase = NULL;
    if (L->length >= L->listSize) {
        newBase = realloc(L->data, (LIST_INCREMENT + L->listSize) * sizeof(char));
        if (newBase == NULL) {
            return ERROR;
        }
        L->data = newBase;
        L->listSize += LIST_INCREMENT;
    }
    L->data[pos - 1] = e;
    if (pos == L->length + 1) {
        ++L->length;
    }
    return SUCCESS;
}

void Multiply(LNode *La, char e)
{
    char overflow = 0;
    char val = 0;
    int pos;
    for (pos = 1; pos <= La->length; ++pos) {
        val = (overflow + La->data[pos - 1] * e) % 10;
        overflow = (overflow + La->data[pos - 1] * e) / 10;
        Insert(La, pos, val);
    }
    if (overflow) {
        Insert(La, pos, overflow);
    }
}

void Add(LNode *La, char e)
{
    char overflow = e;
    char val = 0;
    int pos = 1;
    do {
        val = (overflow + La->data[pos - 1]) % 10;
        overflow = (overflow + La->data[pos - 1]) / 10;
        Insert(La, pos, val);
        ++pos;
    } while (overflow && pos <= La->length);
    if (overflow) {
        Insert(La, pos, overflow);
    }
}

void Show(LNode L, int dotPos)
{
    for (int i = L.length - 1; i >= dotPos; --i) {
        printf("%c", L.data[i] + '0');
    }
    putchar('\n');
}

int main(int argc, char *argv[])
{
    LNode L;
    InitList(&L);
    Insert(&L, 1, 3);
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i < n; ++i) {
            Multiply(&L, 3);
        }
        Add(&L, 1);
        Multiply(&L, 5);
        Show(L, 1);
        ClearList(&L);
        Insert(&L, 1, 3);
    }
    DestroyList(&L);
    return 0;
}

#endif