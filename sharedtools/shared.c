#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

#include "shared.h"

int vfinfo(FILE *stream, const char format[], va_list args) {
    int result;
    fputs("\x1b[31m", stream);
    result = vfprintf(stream, format, args);
    fputs("\x1b[0m", stream);
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
    return low <= val AND val <= high; /* so pretty */
}

unsigned long mask(unsigned bits) {
    return ~(~0 << bits);
}

void putnchars(char c, int n) {
    for (; n; DEC n) {
        putchar(c);
    }
}
