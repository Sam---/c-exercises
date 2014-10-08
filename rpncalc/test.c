#include <stdlib.h>
#include <stdio.h>
#include "tokenize.h"

#define BUFMAX 1024

int main() {
    size_t len;
    char token[BUFMAX];
    int tkclass;

    while (len = get_tokens(token, BUFMAX, &tkclass)) {
        char *class;
        switch (tkclass) {
            case TK_WORD: class = "WORD"; break;
            case TK_NUM: class = "NUM"; break;
            case TK_SYMBOL: class = "SYMBOL"; break;
            case TK_NEWLINE: class = "NEWLINE"; break;
            case TK_INVALID: class = "INVALID"; break;
            default: exit(EXIT_FAILURE);
        }
        printf("Read token \"%s\" which is a(n) %s\n", token, class);
    }
    puts("Done");
    return EXIT_SUCCESS;
}

