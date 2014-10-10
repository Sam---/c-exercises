#include <ctype.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "shared.h"

#include "main.h"
#include "tokenize.h"

#include "getop.h"

char *table[] = {
    "sin[e]", "cos[ine]", "tan[gent]",
    "a[rc]sin[e]", "a[rc]tan[gent]", "a[rc]cos[ine]0",
    "q[uit]",
    "and", "or", "!",
    "pi", "e",
    "+", "-", "*", "/", "%", "^",
    "&", "|", "xor", "<<", ">>", "~",
    "<", ">", "=", "<=", ">=",
    "\x1b"
};

int getf(char s[]) {
    size_t key;
    for (key = 0; table[key][0] != '\x1b'; key++) {
        if (strcmp(table[key], s) == 0) {
            return key + 1;
        }
    }
    return 0;
}

/* getop: get next operator or numeric operand 
 * returns 0 if EOL or error else B_*
 */
int getop(char s[], size_t maxlen, double *num) {
    size_t tklen;
    int tkclass;

    tklen = get_tokens(s, maxlen, &tkclass);

    if (tkclass == TK_WORD || tkclass == TK_SYMBOL) {
        return getf(s);

    } else if (tkclass = TK_NUM) {
        char *end;
        errno = 0;
        double result = strtod(s, &end);

        if (errno == ERANGE) {
            *num = GETOP_ERANGE;
            return 0;

        } else if (*end != '\0') {
            *num = GETOP_BADNUM;
            return 0;

        } else {
            *num = result;
            return B_PUSHDBL;
        }
    } else if (tkclass == TK_INVALID) {
        *num = GETOP_INVALIDT;
        return 0;
    }
}

