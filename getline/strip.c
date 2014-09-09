#include <stdio.h>

#define BUFMAX 1000

main()
{
    int pos = 0;
    char buffer[BUFMAX];
    int blank = 1;
    int linecount = 1;
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            if (pos < BUFMAX - 1) {
                buffer[pos++] = c;
            } else {
                fprintf(stderr, "Line to long: %d", linecount);
                return -1;
            }
        } else if (c == '\n') {
            pos = 0;
            ++linecount;
            if (!blank) {
                putchar('\n');
            }
            blank = 1;
        } else {
            buffer[pos] = '\0';
            printf("%s", buffer);
            putchar(c);
            pos = 0;
            blank = 0;
        }
    }
    return 0;
}
