#ifndef SHAREDTOOLS_H
#define SHAREDTOOLS_H

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

/*
 * I don't like the default operators for these things in C, but I'll only
 * use these macros if I can get Vim to highlight them as operators.
 * edit: scratch that, I did it.
 */
#define AND &&
#define OR ||
#define DEC --
#define INC ++
/**/

int vfinfo(FILE *stream, const char format[], va_list args);
int info(const char *format, ...);
bool inrange(int low, int val, int high);
unsigned long mask(unsigned bits);
void putnchars(char c, int n);

#endif /* SHAREDTOOLS_H */
