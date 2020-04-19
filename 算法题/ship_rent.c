#ifndef SHIP_RENT_C
#define SHIP_RENT_C

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef int ElemSize;

void FindLowestShipRent(ElemType **rentArr, ElemSize arrSize)
{
    for (ElemSize i = arrSize - 1; i >= 0; --i) {
        for (ElemSize j = i + 1; j < arrSize; ++j) {
            ElemType tmp = 
                *((ElemType *)rentArr + (arrSize + 1) * i + j) + *((ElemType *)rentArr + (arrSize + 1) * j + arrSize);
            if (*((ElemType *)rentArr + (arrSize + 1) * i + arrSize) > tmp) {
                *((ElemType *)rentArr + (arrSize + 1) * i + arrSize) = tmp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    ElemSize numShip = 0;
    while (scanf("%d", &numShip) && numShip > 0) {
        ElemType elemArr[numShip][numShip + 1];
        for (ElemSize i = 0; i <= numShip; ++i) {
            for (ElemSize j = i + 1; j <= numShip; ++j) {
                scanf("%d", &elemArr[i][j]);
            }
        }
        FindLowestShipRent((ElemType **)elemArr, numShip);
        printf("%d\n", elemArr[0][numShip]);
    }
    return 0;
}

#endif
