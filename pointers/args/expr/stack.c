#include <stdlib.h>
#include <stdio.h>
#include "error.h"
#include "stack.h"

#define BUFFERSIZE 2 * 1024 * sizeof(double)
static double stack[BUFFERSIZE];
static double *sp = stack;
static double *stackmax = stack + BUFFERSIZE;

void push(double d) {
    if (sp < stackmax) {
        *sp++ = d;
    } else {
        printf("expr: emergency stop: stack overflow (no room for %g)\n",
                d);
        exit(-2);
    }
}

double pop(void) {
    if (sp > stack) {
        return *--sp;
    } else {
        printf("expr: emergency stop: stack underflow (no more values)\n");
        exit(-3);
        return 0.0;
    }
}

