/*
 * Copyright (C) 2021-2021 RTFSC All rights reserved.
 * Author:zengyong
 * Date:2021-8-2
 * Description:跳表算法
 */

#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#include <stdio.h>
#include <stdlib.h>

#define MAXLEVEL 6

typedef enum {
    STATUS_OK,
    STATUS_MEM_EXHAUSTED,
    STATUS_DUPLICATE_KEY,
    STATUS_KEY_NOT_FOUND
} Status;

typedef int keyType;

typedef struct {
    int stuff;
} ValType;

typedef struct NodeType {
    keyType key;
    ValType val;
    struct NodeType *forward[MAXLEVEL + 1];
} NodeType;

typedef struct {
    NodeType *head;
    int listLevel;
    int size;
} SkipList;

SkipList list;
#define NIL list.head

#define CmpLT(a,b) (a < b)
#define CmpEQ(a,b) (a == b)

Status InitList();
void PrintSList();
Status Insert(keyType key, ValType* val);
Status Delete(keyType key);
Status Find(keyType key, ValType* val);

#endif
