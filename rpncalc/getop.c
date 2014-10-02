#include <ctype.h>
#include <stdio.h>
#include "main.h"
#include "getch.h"

#include "getop.h"

int isign(char c) {
    if (isdigit(c) && c != '\n') {
        return 1;
    } else {
        return 0;
    }
}

/* getop: get next operator or numeric operand */
int getop(char s[]) {
    int i = 1, c;

    while ((c = getch()) != EOF && isign(c));
    if (c == EOF) {
        return EOF;
    }

    s[0] = c;

    while ((c = getch()) != EOF && !isign(c)) {
        s[i++] = c;
    }
    ungetch(c);

    s[--i] = '\0';

    if (i == 1) {
        if (isdigit(s[0]) || s[0] == '.') {
            return NUMBER;
        }
        return s[0];
    }

    if (s[0] == '-') {
        return NNUMBER;
    }
    return -1;
}
