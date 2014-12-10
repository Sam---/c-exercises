#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "rotbuf.h"

#define LINEMAX 2048

int main(/*int argc, char **argv*/) {
    size_t nlines = 4;
    struct rotbuf lines = rotbuf_new(nlines);
    struct rotbuf_iter it;
    char *line;
    bool ok;

    while (true) {
        ok = fgets(line, LINEMAX, stdin);
        if (!ok) break;
        rotbuf_insert(lines, line);
    }

    it = rotbuf_each_reverse(lines);
    while (line = rotbuf_next(it)) {
        printf("%s", line);
    }
    return EXIT_SUCCESS; // No need to free
}

        
        
    
