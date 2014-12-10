#include <stdlib.h>
#include <stdio.h>
#include "prsr.h"
#include "error.h"
#include "stack.h"


int main(int argc, char **argv) {
    for (size_t n = 1; n < (size_t)argc; n++) {
        char *error = interpret(argv[n]);
        if (error) printerr(n, error);
    }
    printf("%g\n", pop());
    return EXIT_SUCCESS;
}
