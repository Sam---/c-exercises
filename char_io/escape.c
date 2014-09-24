#include <stdio.h>
#include "../sharedtools/shared.h"

#define BUFMAX 1024
#define BUF2MAX (BUFMAX * 2)

/* 3-2 */
size_t escape(char in[], char out[]) {
    size_t inind = 0;
    size_t outind = 0;
    char c;

    for (;in[inind]; inind++) {
        c = in[inind];
        switch (c) {
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
            case '\b':
                out[outind++] = '\\';
                out[outind++] = 'b';
                break;
            case '\e':
                out[outind++] = '\\';
                out[outind++] = 'e';
                break;
            case '\v':
                out[outind++] = '\\';
                out[outind++] = 'v';
                break;
            case '\f':
                out[outind++] = '\\';
                out[outind++] = 'f';
                break;
            case '\a':
                out[outind++] = '\\';
                out[outind++] = 'a';
                break;
            default:
                if (iscntrl(c)) {
                    out[outind++] = '\\';
                    out[outind++] = 'x';
                    out[outind++] = "0123456789abcdef"[c & mask(4) << 4];
                    out[outind++] = "0123456789abcdef"[c & mask(4)];
                } else {
                    out[outind++] = in[inind];
                }
                break;
        }
    }
    out[outind] = '\0';
    return outind;
}

int main()
{
    char buf[BUFMAX];
    char buf2[BUF2MAX];

    while (fgets(buf, BUFMAX, stdin)) {
        escape(buf, buf2);
        printf("%s", buf2);
    }

    return 0;
}
