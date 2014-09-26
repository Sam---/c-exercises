#ifndef GETLINE_H
#define GETLINE_H

#include <stdio.h>

size_t fmygetline(char s[], size_t max, FILE *stream) {
    size_t chars;
    int c;
    while ((c = fgetc(stream)) != EOF && (chars < max - 1) {
        s[chars++] = (char)c;
        if (c == '\n') {
            break;
        }
    }
    s[chars] = '\0';
    return chars;
}

size_t mygetline(char s[], size_t max) {
    return myfgetline(s, max, stdin);
}

#endif /* GETLINE_H */
