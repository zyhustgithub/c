/*
 * Copyright (C) 2021-2021 RTFSC All rights reserved.
 * Author:zengyong
 * Date:2021-8-2
 * Description:跳表算法
 */

#include "SkipList.h"

int NewLevel()
{
    int level = 0;
    while (rand() % 2) {
        ++level;
    }

    level = (level < MAXLEVEL) ? level : MAXLEVEL;
    return level;
}

Status InitList()
{
    if ((list.head = malloc(sizeof(NodeType))) == 0) {
        printf("Error: memory alloc failed.\n");
        return STATUS_MEM_EXHAUSTED;
    }

    for (int idx = 0; idx <= MAXLEVEL; ++idx) {
        list.head->forward[idx] = NIL;
    }

    list.listLevel = 0;
    list.size = 0;
    return STATUS_OK;
}

void PrintSList()
{
    if (list.size == 0) {
        printf("Skip list is empty.");
        return;
    }

    for (int idx = list.listLevel; idx >= 0; --idx) {
        NodeType* slNode = list.head->forward[idx];
        printf("level[%d]", idx);
        while (slNode->forward[idx] != NIL) {
            printf("%4d", slNode->key);
            slNode = slNode->forward[idx];
        }

        printf("%4d\n", slNode->key);
    }

    putchar('\n');
}

Status Insert(keyType key, ValType* val)
{
    NodeType* update[MAXLEVEL + 1];
    NodeType* slNode = list.head;
    for (int idx = list.listLevel; idx >= 0; idx--) {
        while (slNode->forward[idx] != NIL && CmpLT(slNode->forward[idx]->key, key)) {
            slNode = slNode->forward[idx];
        }

        update[idx] = slNode;
    }

    slNode = slNode->forward[0];

    if ((slNode != NIL) && CmpEQ(slNode->key, key)) {
        return STATUS_DUPLICATE_KEY;
    }

    int newLevel = NewLevel();
    if (newLevel > list.listLevel) {
        for (int idx = list.listLevel + 1; idx <= newLevel; idx++) {
            update[idx] = NIL;
        }
        list.listLevel = newLevel;
    }

    if ((slNode = malloc(sizeof(NodeType))) == 0) {
        return STATUS_MEM_EXHAUSTED;
    }

    slNode->key = key;
    slNode->val = *val;

    for (int idx = 0; idx <= newLevel; idx++) {
        slNode->forward[idx] = update[idx]->forward[idx];
        update[idx]->forward[idx] = slNode;
    }

    ++list.size;
    return STATUS_OK;
}

Status Delete(keyType key)
{
    NodeType* update[MAXLEVEL + 1];
    NodeType* slNode = list.head;
    for (int idx = list.listLevel; idx >= 0; --idx) {
        while ((slNode->forward[idx] != NIL) && CmpLT(slNode->forward[idx]->key, key)) {
            slNode = slNode->forward[idx];
        }
        update[idx] = slNode;
    }

    slNode = slNode->forward[0];
    if ((slNode == NIL) || !CmpEQ(slNode->key, key)) {
        return STATUS_KEY_NOT_FOUND;
    }

    for (int idx = 0; idx <= list.listLevel; ++idx) {
        if (update[idx]->forward[idx] != slNode) {
            break;
        }
        update[idx]->forward[idx] = slNode->forward[idx];
    }

    free(slNode);

    while ((list.listLevel > 0) && (list.head->forward[list.listLevel] == NIL)) {
        list.listLevel--;
    }

    --list.size;
    return STATUS_OK;
}

Status Find(keyType key, ValType* val)
{
    NodeType* slNode = list.head;

    for (int idx = list.listLevel; idx >= 0; idx--) {
        while (slNode->forward[idx] != NIL && CmpLT(slNode->forward[idx]->key, key)) {
            slNode = slNode->forward[idx];
        }
    }

    slNode = slNode->forward[0];

    if ((slNode != NIL) && CmpEQ(slNode->key, key)) {
        *val = slNode->val;
        return STATUS_OK;
    }

    return STATUS_KEY_NOT_FOUND;
}
