#include <stdio.h>

#define TABSTOP 8

void putn(char, int);

int main()
{
    int c;
    int spaces = 0;
    int column = 0;

    while ((c = getchar()) != EOF) {
        if (column % TABSTOP == 0 && spaces > 0) {
            putchar('\t');
            spaces = column = 0;
        }
        if (c == '\t') {
            putchar('\t');
            spaces = 0;
            column = 0;
        } else if (c == ' ') {
            ++spaces;
            ++column;
        } else if (c == '\n') {
            putchar('\n');
            column = 0;
            spaces = 0;
        } else {
            putn(' ', spaces);
            spaces = 0;
            putchar(c);
            ++column;
        }
    }
    return 0;
}

void putn(char c, int n) {
    while (n > 0) {
        putchar(c);
        --n;
    }
}
