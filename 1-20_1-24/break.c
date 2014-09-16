#include <stdio.h>

#define BUFMAX 2048

#define INFO(str) fprintf(stdout, "\e[34m" str "\e[0m")

int main()
{
    char buffer[BUFMAX];
    int pos;
    int col = 0;
    int c;

    while ((c = getchar()) != EOF) {
        if (('a' <= c&&c <= 'z') || ('A' <= c&&c <= 'Z') ||
            ('0' <= c&&c <= '9'))
        {
            if (pos <= BUFMAX) {
                buffer[pos++] = c;
            } else {
                printf("Word too long\n");
                return;
            }
            ++col;
        } else if (c == '\n') {
            printf("%.*s\n", pos, buffer);
            pos = col = 0;
        } else {
            if (col > 80) {
                INFO("breaking");
                pos = col = 0;
                putchar('\n');
            } else {
                INFO("printing");
                printf("%.*s%c", pos, buffer, c);
                col +=1;
            }
        }
    }

    return 0;
}
