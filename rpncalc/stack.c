#include <stdio.h>

#define MAXDEPTH 128

int sp = 0;
double val[MAXDEPTH];

void mypush(double f) {
    if (sp < MAXDEPTH) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't mypush %g\n", f);
    }
}

double mypop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: empty stack (did you enter any data?)\n");
        return 0.0;
    }
}
