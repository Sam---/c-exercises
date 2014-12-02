#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <string.h>
#include "mygetline.h"

#define MAXLINES 5000

char *lines[MAXLINES];

size_t readlines(char *linesptr[], size_t nlines);
void writelines(char *linesptr[], size_t nlines);

int compare(const void *a, const void *b) {
    return strcoll(*(char**)a, *(char**)b);
}

int main() {
    size_t nlines;

    if ((nlines = readlines(lines, MAXLINES)) < SIZE_MAX) {
        qsort(lines, nlines, sizeof *lines, compare);
        writelines(lines, nlines);
        return 0;
    } else {
        fprintf(stderr, "error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000 /* Maximum length of a single line */

size_t readlines(char *lines[], size_t maxlines) {
    size_t len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = mygetline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = malloc(len)) == NULL) {
            return SIZE_MAX;
        } else {
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lines[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *linesptr[], size_t nlines) {
    size_t i;
    for (i = 0; i < nlines; i++) printf("%s\n", linesptr[i]);
}


