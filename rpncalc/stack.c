#include <stdio.h>

#define MAXDEPTH

int sp = 0;
double val[MAXDEPTH];

void push(double f) {
    if (sp < MAXDEPTH) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: empty stack (did you enter any data?)\n");
        return 0.0;
    }
}
