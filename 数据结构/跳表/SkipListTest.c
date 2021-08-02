#include "SkipList.h"

// test
int main(int argc, char** argv)
{
    const int NUM_TEST = 20;
    keyType key[NUM_TEST];
    ValType val[NUM_TEST];

    for (int idx = 0; idx < NUM_TEST; idx++) {
        key[idx] = idx;
        val[idx].stuff = idx;
    }

    // init list
    if (InitList() != STATUS_OK) {
        printf("Error: init skip list failed.\n");
        return -1;
    }

    // insert test
    for (int idx = 0; idx < NUM_TEST; ++idx) {
        Status status = Insert(key[idx], &val[idx]);
        if (status != STATUS_OK) {
            printf("Error: insert failed, key=%d, val=%d, errno=%d.\n", key[idx], val[idx].stuff, status);
        }
    }

    printf("The size of skip list is %d.\n", list.size);
    PrintSList();

    // search test
    for (int idx = NUM_TEST - 1; idx >= 0; --idx) {
        Status status = Find(key[idx], &val[idx]);
        if (status != STATUS_OK) {
            printf("Error: Find failed, errno=%d.\n", status);
        }
    }

    // delete test
    for (int idx = NUM_TEST - 1; idx >= 0; --idx) {
        Status status = Delete(key[idx]);
        if (status != STATUS_OK) {
            printf("Error: delete failed, errno=%d.\n", status);
        }
    }

    printf("The size of skip list is %d.\n", list.size);
    PrintSList();

    return 0;
}