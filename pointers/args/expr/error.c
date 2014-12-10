#include <stdio.h>
#include <stdlib.h>
#include "error.h"

void printerr(size_t n, char *err) {
    fprintf(stderr, "expr: %zu: %s\n", n, err);
    exit(-1);
}

