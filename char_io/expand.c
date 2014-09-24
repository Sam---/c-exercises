#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../sharedtools/shared.h"

#define BUFMAX 1024

size_t expand(char src[], char buf[], size_t max) {
    int srcpos, bufpos;
    bool dashok = false;

    for (srcpos = bufpos = 0; src[srcpos] && bufpos < max - 1; srcpos++) {
        if (dashok && src[srcpos] == '-' && src[srcpos+1] != '\0') {
            char i;
            for (i = src[srcpos-1] + 1;
                    bufpos < max - 1 && i < src[srcpos+1] + 1; i++)
            {
                buf[bufpos++] = i;
            }
//          info("[%d-%d]", src[srcpos-1], src[srcpos+1]);
            srcpos++;
            dashok = false;
        } else {
            buf[bufpos++] = src[srcpos];
            dashok = true;
        }
    }
    buf[bufpos] = '\0';
    return bufpos;
}

int main() {
    char buffer[BUFMAX];
    char result[BUFMAX];

    while (fgets(buffer, BUFMAX, stdin)) {
        expand(buffer, result, BUFMAX);
        printf("%s", result);
    }
    return EXIT_SUCCESS;
}
