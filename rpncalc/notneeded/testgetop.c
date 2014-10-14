#include <stdlib.h>
#include <stdio.h>
#include "getop.h"

#define BUFMAX 1024

int main() {
    int oper;
    char token[BUFMAX];
    double num;

    while (oper = getop(token, BUFMAX, &num)) {
        printf("Read operator %d, num is %g", oper, num);
    }
    printf("Read error (%d), code is %g", oper, num);
    return EXIT_SUCCESS;
}

