#ifndef __INT_SPLIT_C__
#define __INT_SPLIT_C__

#include <stdio.h>
#include <string.h> //memset

#define MAXNUM 1024

int gNode[MAXNUM];
int gNum;

void int_split(int sum, int len, int limit)
{
    if (sum == gNum) {
        printf("%d=%d", gNum, gNode[1]);
        for (int i = 2; i < len; i++) {
            printf("+%d", gNode[i]);
        }
        printf("\n");
        return;
    }

    for (int i = limit; i <= gNum; i++) {
        if (sum + i > gNum) {
            break;
        }

        gNode[len] = i;
        int_split(sum + i, len + 1, i);
        gNode[len] = 0;
    }

}

int main(int argc, char *argv[])
{
    memset(gNode, 0, sizeof(int)*MAXNUM);
    while (scanf("%d", &gNum) != EOF) {
        if (gNum > 1024 || gNum & 0x80000000) {
            printf("Error: too big, should less than 1024...\n");
            continue;
        }
        int_split(0, 1, 1);
    }
    return 0;
}

#endif