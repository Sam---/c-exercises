#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "rotbuf.h"

#define LINEMAX 2048
#define GETSMEM(ptr, siz) ((ptr) = malloc((siz) * sizeof *(ptr)))

int main(/*int argc, char **argv*/) {
    struct rotbuf lines;
    struct rotbuf_iter it;
    char *line;
    bool ok;
    lines.n = 4 * sizeof *lines.base;
    GETSMEM(lines.base, lines.n);
    lines.cur = 0;
    memset(lines.base, 0, lines.n *sizeof* lines.base); // lookit dat syntax

    while (true) {
        GETSMEM(line, LINEMAX); // You wouldn't sizeof a char
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

        
        
    
