#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <string.h>
#include "mygetline.h"

#define MAXLINES (5 * 1024)

#define BUFLEN (10 * 1024 * 1024)

char *lines[MAXLINES];

size_t readlines(
        char *lines[], size_t maxlines,
        char *bigbuffer, size_t buflen);
void writelines(char *linesptr[], size_t nlines);

int compare(const void *a, const void *b) {
    return strcoll(*(char**)a, *(char**)b);
}

/* ex. 5-7 */
int main() {
    size_t nlines;
    static char bigbuffer[BUFLEN];

    if ((nlines = readlines(lines, MAXLINES, bigbuffer, BUFLEN)) < SIZE_MAX) {
        qsort(lines, nlines, sizeof *lines, compare);
        writelines(lines, nlines);
        return 0;
    } else {
        fprintf(stderr, "error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1024 /* Maximum length of a single line */

size_t readlines(
        char *lines[], size_t maxlines,
        char *bigbuffer, size_t buflen
    ) {
    size_t len;
    size_t used = 0;
    size_t nlines = 0;
    char line[MAXLEN];
    char *p;

    while ((len = mygetline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || used + len > buflen) {
            return SIZE_MAX;
        } else {
            p = &bigbuffer[used];
            used += len;
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


