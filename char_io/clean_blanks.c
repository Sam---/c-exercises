#include <stdio.h>

main()
{
    int space_mode = 0;
    int c;

    while ((c = getchar()) != EOF) {
        if (!space_mode) {
            putchar(c);
            if (c == ' ') {
                space_mode = 1;
            }
        } else if (c != ' ') {
            space_mode = 0;
            putchar(c);
        }
    }
}
