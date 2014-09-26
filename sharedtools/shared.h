#ifndef SHAREDTOOLS_H
#define SHAREDTOOLS_H

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

#include "mygetline.h"

/*
 * I don't like the default operators for these things in C, but I'll only
 * use these macros if I can get Vim to highlight them as operators.
#define AND &&
#define OR ||
#define DEC --
#define INC ++
*/

int vfinfo(FILE *stream, const char format[], va_list args) {
    int result;
    fputs("\e[31m", stream);
    result = vfprintf(stream, format, args);
    fputs("\e[0m", stream);
    return result;
}

int info(const char *format, ...) {
    va_list args;
    int result;
    va_start(args, format);
    result = vfinfo(stdout, format, args);
    va_end(args);
    return result;
}

bool inrange(int low, int val, int high) {
    return low <= val && val <= high;
}

unsigned long mask(unsigned bits) {
    return ~(~0 << bits);
}

void putnchars(char c, int n) {
    for (; n; --n) {
        putchar(c);
    }
}

#endif /* SHAREDTOOLS_H */
