#include <stdio.h>
#define MAXLINE 1000

int my_getline(char buffer[], int maxlen);
void copy(char dest[], char src[]);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = my_getline(line, MAXLINE)) > 0) {
        if (max < len) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) {
        printf("%s", longest);
    }
    return 0;
}

int my_getline(char buffer[], int maxlen)
{
    int c; // the char
    int i;

    for (i = 0; i < maxlen - 1 && (c=getchar()) != EOF && c != '\n'; ++i) {
        buffer[i] = c;
    }
    if (c == '\n') {
        buffer[i] = c;
        ++i;
    }
    buffer[i] = '\0';
    return i;
}

void copy(char dest[], char src[])
{
    int i;

    i = 0;
    while ((dest[i] = src[i]) != '\0') {
        ++i;
    }
}
