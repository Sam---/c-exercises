#include <stdio.h>

#define BUFMAX 2048

int main()
{
    int c;
    char line[BUFMAX];
    int pos = 0;
    int linecount = 0;

    while ((c = getchar()) != EOF) {
        if (c != '\n') {
            if (pos < BUFMAX) {
                line[pos++] = c;
            } else {
                fprintf(stderr, "Line too long: %d\n", linecount);
                return 1;
            }
        } else {
            while (pos > 0) {
                putchar(line[--pos]);
            }
            putchar('\n');
            ++linecount;
        }
    }
    while (pos > 0) { // clean out excess chars if input not \n-terminated
        putchar(line[--pos]);
        putchar('\n');
    }
    return 0;
}

