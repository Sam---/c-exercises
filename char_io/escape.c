#include <stdio.h>

#define BUFMAX 1024
#define BUF2MAX (BUFMAX * 2)

/* 3-2 */
size_t escape(char in[], char out[]) {
    size_t inind = 0;
    size_t outind = 0;

    for (;in[inind]; inind++) {
        switch (in[inind]) {
            case '\\':
                out[outind++] = '\\';
                out[outind++] = '\\';
                break;
            case '\n':
                out[outind++] = '\\';
                out[outind++] = 'n';
                break;
            case '\t':
                out[outind++] = '\\';
                out[outind++] = 't';
                break;
            default:
                out[outind++] = in[inind];
                break;
        }
    }
    out[outind] = '\0';
    return outind;
}

main()
{
    char buf[BUFMAX];
    char buf2[BUF2MAX];

    while (fgets(buf, BUFMAX, stdin)) {
        escape(buf, buf2);
        printf("%s", buf2);
    }

    return 0;
}
