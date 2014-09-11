#include <stdio.h>

int main()
{
    char buffer[BUFMAX];
    int pos;

    while ((c = getchar()) != EOF) {
        switch (c) {
            case ' ':
            case '\t':
                buffer[pos++] = c;
                printf("%.*s", pos, buffer);
                pos = 0;
                break;
            default:
                buffer[pos++] = c;
        }
    }

    return 0;
}
