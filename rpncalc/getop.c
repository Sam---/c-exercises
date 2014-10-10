#include <ctype.h>
#include <stdio.h>
#include "shared.h"

#include "main.h"
#include "tokenize.h"

#include "getop.h"

// int hash_string(char s[]) {
//     size_t i = 0;
//     int hash;
//     while (s[i]) {
//         hash += s[i++];
//     }
//     return hash;
// }

char *table[] = {
    "sin[e]", "cos[ine]", "tan[gent]",
    "a[rc]sin[e]", "a[rc]tan[gent]", "a[rc]cos[ine]0"
    "q[uit]",
    "and", "or", "!",
    "pi", "e",
    "+", "-", "*", "/", "%", "^",
    "&", "|", "xor", "<<", ">>", "~",
    "<", ">", "=", "<=", ">=",
    "\x1b"
}

int getf(char s[]) {
    size_t key;
    for (key = 0; table[key][0] != '\x1b'; key++) {
        if (strcmp(table[key], s) == 0) {
            return key + 1;
        }
    }
    return 0;
}

// setf(int row, char s[], size_t size) {
//     size_t key;
//     if (key = /* = */ getf(s)) {
//         size_t len = min(KEYMAX, size)
//         memcpy(table[key], s, len);
//         memset(table[key] + len, '\0', KEYMAX - len);
//     }



/* getop: get next operator or numeric operand 
 * returns 0 if EOL or error else B_* */
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

