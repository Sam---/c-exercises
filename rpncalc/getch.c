#include <ctype.h>
#include <stdio.h>

#include "getch.h"

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return bufp > 0? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp < BUFSIZE) {
        buf[bufp++] = c;
    } else {
        printf("ungetch: too many charecters");
    }
}
