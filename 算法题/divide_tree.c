#ifndef DIVIDE_TREE_C
#define DIVIDE_TREE_C

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ERROR   0
#define SUCCESS 1

typedef struct DataType {
    int data;
    struct DataType *next;
} DataType;

typedef struct {
    DataType *head;
    int length;
} ElemType;

void DestroyData(ElemType *elem)
{
    DataType *tmpPtr = elem->head;
    while(tmpPtr != NULL) {
        elem->head = tmpPtr->next;
        free(tmpPtr);
        tmpPtr = elem->head;
    }
    elem->length = 0;
}

/* 释放内存 */
void Free(ElemType arr[], int size)
{
    for (int i = 0; i < size; ++i) {
        DestroyData(&arr[i]);
    }
    free(arr);
    arr = NULL;
}

/* 申请内存 */
ElemType *Malloc(int size)
{
    ElemType *arr = (ElemType *)calloc(size, sizeof(ElemType));
    if (arr == NULL) {
        printf("Malloc error!\n");
        return NULL;
    }
    int tmpSize;
    for (tmpSize = 0; tmpSize < size; ++tmpSize) {
        arr[tmpSize].head = (DataType *)malloc(sizeof(DataType));
        if (arr[tmpSize].head == NULL) {
            Free(arr, --tmpSize);
            return NULL;
        }
        arr[tmpSize].head->next = NULL;
        arr[tmpSize].head->data = 0;
        arr[tmpSize].length = 0;
    }
    return arr;
}

/* 追加元素，动态分配内存 */
int Append(ElemType *elem, int num)
{
    DataType *newData = (DataType *)malloc(sizeof(DataType));
    if (newData == NULL) {
        return ERROR;
    }
    newData->data = num;
    newData->next = elem->head->next;
    elem->head->next = newData;
    ++elem->length;
    return SUCCESS;
}

/* 遍历节点 */
void GoThrough(ElemType arr[], int weight[], int sum[], int curNode, int preNode)
{
    int dataSize = arr[curNode].length;
    DataType *tmpPtr = arr[curNode].head->next;
    sum[curNode] = weight[curNode];
    while (tmpPtr != NULL) {
        if (tmpPtr->data != preNode) {
            GoThrough(arr, weight, sum, tmpPtr->data, curNode);
            sum[curNode] += sum[tmpPtr->data];
        }
        tmpPtr = tmpPtr->next;
    }
}

/* 寻找两子树权重值最小差 */
void FindLowestDiff(ElemType arr[], int sum[], int curNode, int preNode, int *ans)
{
    int dataSize = arr[curNode].length;
    int tmpData;
    DataType *tmpPtr = arr[curNode].head->next;
    while (tmpPtr != NULL) {
        if (tmpPtr->data != preNode) {
            tmpData = abs((sum[1] - sum[tmpPtr->data]) - sum[tmpPtr->data]);
            *ans = (*ans <= tmpData ? *ans : tmpData);
            FindLowestDiff(arr, sum, tmpPtr->data, curNode, ans);
        }
        tmpPtr = tmpPtr->next;
    }
}

/* 打印数组 */
void ShowArr(int arr[], int len)
{
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

int main(int argc, char *argv[])
{
    int testNum;
    int nodeA, nodeB;
    scanf("%d", &testNum);
    while (testNum--) {
        int ans = 0x3F3F3F3F;  // 足够大、不会轻易溢出且方便memset字节操作
        int nodeNum;
        scanf("%d", &nodeNum);
        ++nodeNum;
        ElemType *tmpElem = Malloc(nodeNum);
        int sum[nodeNum];
        int weight[nodeNum];
        for (int i = 1; i < nodeNum; ++i) {
            scanf("%d", &weight[i]);
        }
        // ShowArr(weight, nodeNum);
        for (int i = 1; i < nodeNum - 1; ++i) {
            scanf("%d %d", &nodeA, &nodeB);
            Append(&tmpElem[nodeA], nodeB);
            Append(&tmpElem[nodeB], nodeA);
        }
        GoThrough(tmpElem, weight, sum, 1, 1);
        FindLowestDiff(tmpElem, sum, 1, 1, &ans);
        printf("%d\n", ans);
        Free(tmpElem, nodeNum);
    }
    return SUCCESS;
}

#endif