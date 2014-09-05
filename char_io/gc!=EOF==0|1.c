#include <stdio.h>

/* UNIX lets you put anything in a file name! */

main()
{
    int result;

    while (result = getchar() != EOF) {
        printf("%d\n", result);
    }
}

