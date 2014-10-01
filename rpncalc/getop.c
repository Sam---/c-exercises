#include <ctype.h>
#include <stdio.h>
#include "main.h"
#include "getch.h"

#include "getop.h"

/* getop: get next operator or numeric operand */
int getop(char s[]) {
    int i = 1, c;

    while ((c = getch()) != EOF && isspace(c));
    if (c == EOF) {
        return EOF;
    }

    s[0] = c;

    while ((c = getch()) != EOF && !isspace(c)) {
        s[i++] = c;
    }
    if (c == EOF) {
        return EOF;
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
