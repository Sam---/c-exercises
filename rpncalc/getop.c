#include <ctype.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "shared.h"

#include "main.h"
#include "tokenize.h"

#include "getop.h"

/*
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
*/

/* getop: get next operator or numeric operand 
 * returns 0 if EOL or error else B_*
 */
/*
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
*/
int execop(char* s) {
    double tmp;
    switch (s[0]) {
        case 's':
            switch (s[1]) {
                case 'i':
                    push(sin(pop()));
                    break;
                case 'q':
                    push(sqrt(pop()));
                    break;
                default:
                    printf("Not found: \"%s\"\n", s);
                    return 0;
            }
            break;
        case 'c':
            switch (s[1]) {
                case 'o':
                    push(cos(pop()));
                    break;
                case 'e':
                    push(ceil(pop()));
                    break;
                default:
                    printf("Not found: \"%s\"\n", s);
                    return 0;
            }
            break;
        case 't':
            push(tan(pop()));
            break;
        case '^':
            tmp = pop();
            push(pow(pop(), tmp));
            break;
        case 'a':
            switch (s[1]) {
                case 's':
                    push(asin(pop()));
                    break;
                case 'c':
                    push(acos(pop()));
                    break;
                case 't':
                    push(atan(pop()));
                    break;
                default:
                    printf("Not found: \"%s\"\n", s);
                    return 0;
            }
            break;
        case 'h':
            switch (s[1]) {
                case 's':
                    push(sinh(pop()));
                    break;
                case 'c':
                    push(cosh(pop()));
                    break;
                case 't':
                    push(tanh(pop()));
                    break;
                default:
                    printf("Not found: \"%s\"\n", s);
                    return 0;
            }
            break;
        case 'l':
            push(log(pop()));
            break;
        case 'f':
            push(floor(pop()));
            break;
        case '%':
            tmp = pop();
            push(fmod(pop(), tmp));
            break;
        case '$':
            push(getvar(s[1]));
            break;
        default:
            printf("Not found: \"%s\"\n", s);
            return 0;
    }
    return 1;
}
