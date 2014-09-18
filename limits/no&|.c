#include <stdio.h>

const int MAX = 1000;

int main()
{
    int lim, i;
    int c;
    char s[MAX];

    /* No && operators! Am I doing this right? */
    for (i = 0; (i < lim - 1) * ((c = getchar()) != '\n') * (c != EOF); ++i)
        s[i] = c;

    return 0;
}
