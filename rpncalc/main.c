#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "shared.h"

#include "getop.h"
#include "tokenize.h"
#include "stack.h"

#include "main.h"

#define CBMAX 1024

/* RPN calculator */
int main() {
    char buffer[CBMAX];
    int tkclass;
    while (get_tokens(buffer, CBMAX, &tkclass)) {
        if (tkclass == TK_WORD || tkclass == TK_SYMBOL) {
            execop(buffer);
        } else if (tkclass == TK_NUM) {
            double num;
            char *end;
            errno = 0;
            num = strtod(buffer, &end);
            if (errno == ERANGE) {
                printf("num2big?\n");
            }
            push(num);
        } else {
            puts("What is \"%s\" suppsed to mean?\n");
        }
    }

    return EXIT_SUCCESS;
}
