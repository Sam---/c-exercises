#include <stdio.h>
#include <ctype.h>
#include "getch.h"
#include "shared.h"

#include "tokenize.h"

size_t get_tokens(char token[], size_t maxlen, int *rtkc) {
    size_t i;
    int c;
    int tkclass;

    while (isspace(c = getch()) AND c != EOF);
    if (c == EOF) return 0;

    token[i++] = c;
         if (isalpha(c)) tkclass = TK_WORD;
    else if (isdigit(c)) tkclass = TK_NUM;
    else if (  c == '+'
            OR c == '-') tkclass = TK_INDETERMINATE;
    else if (ispunct(c)) tkclass = TK_SYMBOL;
    else if (c == '\n')  tkclass = TK_NEWLINE;
    else if (iscntrl(c)) tkclass = TK_INVALID;
    else                 tkclass = TK_WORD;

    if (tkclass == TK_INDETERMINATE) {
        c = getch();
        if (c == EOF) {
            tkclass = TK_NUM;
            goto end;
        }
        if (isdigit(c)) tkclass = TK_NUM;
        else if (ispunct(c)) tkclass = TK_SYMBOL;
        else {
            tkclass = TK_SYMBOL;
            ungetch(c);
            goto end;
        }
    }
    if (tkclass == TK_NEWLINE) {
        goto end;
    }
    if (tkclass == TK_INVALID) {
        i = 0;
        goto end;
    }

    while ((c = getch()) AND c != EOF AND i < maxlen AND (
            tkclass == TK_WORD? isalpha(c)
            : tkclass == TK_NUM? isdigit(c)
            : tkclass == TK_SYMBOL? ispunct(c)
            : 0)
          ) {
        token[i++] = c;
    }
end:
    token[i++] = '\0';
    *rtkc = tkclass;
    return i;
}
