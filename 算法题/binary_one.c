#ifndef BINARY_ONE_C
#define BINARY_ONE_C

#include <stdio.h>

int NumberOfOne(int number)
{
    int nums = 0;
    while (number) {
        number &= (number - 1);
        ++nums;
    }
    return nums;
}

int main(int argc, char *argv[])
{
    int interger = 0;
    while (scanf("%d", &interger)) {
        printf("%d\n", NumberOfOne(interger));
    }
    return 0;
}

#endif
