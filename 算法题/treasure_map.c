#ifndef TREASURE_MAP_C
#define TREASURE_MAP_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS   1
#define ERROR     0
#define YES       1
#define NO        0
#define INVALIDE -1
#define OVERFLOW -2

typedef struct ElemType {
    int lx, ly;
    int rx, ry;
    int area;
} ElemType;

typedef struct Map {
    int *idx;
    int length;
    int size;
} Map;

int InitMap(Map *M, int size)
{
    if (size == 0) {
        return ERROR;
    }
    M->idx = (int *)calloc(size, sizeof(int));
    if (!M->idx) {
        return OVERFLOW;
    }
    M->length = 0;
    M->size = size;
    return SUCCESS;
}

void DestroyMap(Map *M)
{
    if (M) {
        if (M->idx) {
            free(M->idx);
            M->idx = NULL;
        }
        M->length = 0;
        M->size = 0;
    }
}

void CopyMap(Map Ma, Map *Mb)
{
    Mb->length = Ma.length;
    Mb->size = Ma.size;
    Mb->idx = (int *)calloc(Mb->size, sizeof(int));
    memcpy(Mb->idx, Ma.idx, Ma.size * sizeof(int));
}

int IfOverlap(ElemType Ma, ElemType Mb)
{
    if (Ma.lx >= Mb.rx || Mb.lx >= Ma.rx || Ma.ly >= Mb.ry || Mb.ly >= Ma.ry) {
        return NO;
    }
    return YES;
}

void OverlapMatrix(int *OL, ElemType elem[], int size)
{
    for (int i = 0; i < size; ++i) {
        OL[i * size + i] = INVALIDE;
        for (int j = i + 1; j < size; ++j) {
            OL[i * size + j] = IfOverlap(elem[i], elem[j]);
            OL[j * size + i] = OL[i * size + j];
        }
    }
}

int GetMinMap(Map *M, int curIndex, int leftArea, int size, int sumArea[], int *OL, ElemType elem[])
{
    int res = -1;
    if (curIndex <= 0 || sumArea[curIndex - 1] < leftArea) {
        return res;
    }
    for (int i = curIndex - 1; i >= 0; --i) {
        if (elem[i].area > leftArea) {
            continue;
        }
        int j = 0;
        for (; j < M->length; ++j) {
            if (OL[i * size + M->idx[j]]) {
                break;
            }
        }
        if (j < M->length) {
            continue;
        }
        if (elem[i].area == leftArea) {
            M->idx[M->length++] = i;
            return 1;
        }
        Map tmpMap;
        CopyMap(*M, &tmpMap);
        tmpMap.idx[tmpMap.length++] = i;
        int tmpRes = GetMinMap(&tmpMap, i, leftArea - elem[i].area, size, sumArea, OL, elem);
        if (tmpRes > 0 && (res < 0 || res > tmpRes + 1)) {
            res = tmpRes + 1;
        }
        DestroyMap(&tmpMap);
    }
    return res;
}

int Cmp(const void *e1, const void *e2)
{
    return ((ElemType *)e1)->area > ((ElemType *)e2)->area;
}

int main(int argc, char *argv[])
{
    int testsNum;
    scanf("%d", &testsNum);
    while (testsNum--) {
        int width, height, nums;
        scanf("%d %d %d", &width, &height, &nums);
        int mapArea = width * height;

        ElemType elem[nums];
        ElemType tmpElem;
        int size = 0;
        for (int i = 0; i < nums; ++i) {
            scanf("%d %d %d %d", &tmpElem.lx, &tmpElem.ly, &tmpElem.rx, &tmpElem.ry);
            tmpElem.area = (tmpElem.rx - tmpElem.lx) * (tmpElem.ry - tmpElem.ly);
            if (tmpElem.area <= mapArea) {
                elem[size++] = tmpElem;
            }
        }
        qsort(elem, size, sizeof(ElemType), Cmp);

        int sumArea[size];
        sumArea[0] = elem[0].area;
        for (int i = 1; i < size; ++i) {
            sumArea[i] = sumArea[i - 1] + elem[i].area;
        }
        
        int OL[size * size];
        OverlapMatrix(OL, elem, size);
        Map M;
        InitMap(&M, size);
        int res = GetMinMap(&M, size, mapArea, size, sumArea, OL, elem);
        printf("%d\n", res);
        DestroyMap(&M);
    }
    return 0;
}

#endif

#if 0
测试用例
3
5 5 1
0 0 5 5

5 5 2
0 0 3 5
2 0 5 5

30 30 5
0 0 30 10
0 10 30 20
0 20 30 30
0 0 15 30
15 0 30 30

输出
1
-1
2
#endif