#include <stdio.h>
#include <limits.h>

#define CHARS_START 32
#define CHARS_END   127
#define CHAR_RANGE  (CHARS_END - CHARS_START)

main()
{
    long nchar[CHAR_RANGE]; // counts for all printable charecters
    int max = 0;
    int c;
    int i, cn;

    for (i = 0; i < CHAR_RANGE; ++i) {
        nchar[i] = 0;
    }
    
    while ((c = getchar()) != EOF) {
        if (c >= CHARS_START && c < CHARS_END) {
            ++nchar[c - CHARS_START];
        }
    }

    for (i = 0; i < CHAR_RANGE; ++i) {
        if (max < nchar[i]) {
            max = nchar[i];
        }
    }

    for (i = max; i > 0; --i) {
        int cn;
        for (cn = 0; cn < CHAR_RANGE; ++cn) {
            if (nchar[cn] > i) {
                putchar('|');
            } else {
                putchar(' ');
            }
        }
//      fprintf(stderr, "Histo Line #%d\n", i);
        putchar('\n');
    }

    printf("␣");
    for (i = CHARS_START + 1; i < CHARS_END; ++i) {
        putchar(i);
    }
}
