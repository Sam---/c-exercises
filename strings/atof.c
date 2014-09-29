#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "../sharedtools/shared.h"

double myatof(char s[]) {
    double val, power;
    int i, sign, expo = 1;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e') {
        i++;
        if (s[i] == '-') {
            i++;
            sign = -sign;
        } else if (s[i] == '+') {
            i++;
        }
        expo = pow(10, atoi(s+i));
    }
    return expo * sign * val / power;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        return EXIT_FAILURE;
    }
    printf("%g\n", myatof(argv[1]));
    return EXIT_SUCCESS;
}
