#include <stdio.h>
#include <stdlib.h>

#define KB * 1024
#define MB * (1024 KB)
#define GB * (1024 MB)
#define TB * (1024 GB)
#define PB * (1024 TB)
#define EB * (1024 PB)
#define ZB * (1024 EB)
#define YB * (1024 ZB)

size_t trygetlines(
        char *lines, size_t maxlen,
        size_t nlines, FILE *stream) {
    size_t curline = 0;
    while (curline < nlines
           && fgets(lines + maxlen * curline++, maxlen, stream));
    return curline;
}

void dumplines(char *lines, size_t maxlen, size_t n, FILE *stream) {
    for (size_t i = 0; i < n; i++) {
        fprintf(stream, "%s", lines + maxlen * i);
    }
}

int main(/*int argc, char **argv*/) {
    size_t nlines = 4;
    const size_t linemax = 2 KB;
    char *lines = malloc(linemax * nlines);

    size_t ngot = trygetlines(lines, linemax, nlines, stdin);
    if (ngot < nlines) {
        dumplines(lines, linemax, ngot, stdout);
    } else {
        while (ngot >= nlines) {
            ngot = trygetlines(lines, linemax, nlines, stdin);
        }
        dumplines(lines + linemax * (ngot - 1),
                linemax, nlines - ngot + 1, stdout);
        dumplines(lines, linemax, ngot - 1, stdout);
    }
    return EXIT_SUCCESS;
}
