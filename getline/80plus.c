#include <stdio.h>
#define main fake_main // avoids "multiple definitions of main"
#   include "maxline.c"
#undef main

#define MAXLEN 1000

int main()
{
    char line[MAXLEN];
    int len;

    while ((len = my_getline(line, MAXLEN)) > 0) {
        if (len > 80) {
            printf("%s", line);
        }
    }
    return 0;
}
    
