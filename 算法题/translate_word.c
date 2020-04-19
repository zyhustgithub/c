#ifndef TRANSLATE_WORD_C
#define TRANSLATE_WORD_C

#include <stdio.h>
#include <string.h>

#define OK            1
#define ERROR         0
#define NUM_OF_ASCII  26

#define BUF_SIZE      1024

char original[] = "some";
char translate[] = "over";

int Init(char *ori, char *trans, char T[])
{
    int oriLen = strlen(ori);
    int transLen = strlen(trans);
    int i = 0;
    for (; i < oriLen && i < transLen; ++i) {
        T[ori[i] - 'a'] = trans[i];
    }
    if (i != NUM_OF_ASCII) {
        return ERROR;
    }
    return OK;
}

int main(int argc, char *argv[])
{
    char buf[BUF_SIZE];
    char T[NUM_OF_ASCII];
    int testsNum;
    scanf("%d", &testsNum);
    Init(original, translate, T);
    int ch;
    while (testsNum--) {
        int n = 0;
        while ((ch = getchar()) != '\n' && ch != EOF && n < BUF_SIZE) {
            if (ch == ' ') {
                buf[n++] = ch;
                continue;
            }
            buf[n++] = T[ch - 'a'];
        }
        buf[n] = '\0';
        printf("%s\n", buf);
    }
    return 0;
}

#endif