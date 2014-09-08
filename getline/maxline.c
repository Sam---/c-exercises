#include <stdio.h>
#define MAXLINE 1000

int getline(char buffer[], int maxlen);
void copy(char dest[], char src[]);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0) {
        if (max < len) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) {
        printf("%s", longest);
    }
    return EXIT_SUCCESS;
}

int getline(char s[], int lim)
{
    int c, i;

    for (i = 0;
