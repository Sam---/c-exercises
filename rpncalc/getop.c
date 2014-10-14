#include <ctype.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include "shared.h"

#include "main.h"
#include "tokenize.h"
#include "stack.h"
#include "vars.h"
#include "getch.h"

#include "getop.h"

int execop(char* s) {
    double tmp;
    switch (s[0]) {
        case 's':
            switch (s[1]) {
                case 'i':
                    push(sin(pop()));
                    break;
                case 'q':
                    push(sqrt(pop()));
                    break;
                default:
                    printf("Not found: \"%s\"\n", s);
                    return 0;
            }
            break;
        case 'c':
            switch (s[1]) {
                case 'o':
                    push(cos(pop()));
                    break;
                case 'e':
                    push(ceil(pop()));
                    break;
                default:
                    printf("Not found: \"%s\"\n", s);
                    return 0;
            }
            break;
        case 't':
            push(tan(pop()));
            break;
        case '^':
            tmp = pop();
            push(pow(pop(), tmp));
            break;
        case 'a':
            switch (s[1]) {
                case 's':
                    push(asin(pop()));
                    break;
                case 'c':
                    push(acos(pop()));
                    break;
                case 't':
                    push(atan(pop()));
                    break;
                default:
                    printf("Not found: \"%s\"\n", s);
                    return 0;
            }
            break;
        case 'h':
            switch (s[1]) {
                case 's':
                    push(sinh(pop()));
                    break;
                case 'c':
                    push(cosh(pop()));
                    break;
                case 't':
                    push(tanh(pop()));
                    break;
                default:
                    printf("Not found: \"%s\"\n", s);
                    return 0;
            }
            break;
        case 'l':
            push(log(pop()));
            break;
        case 'f':
            push(floor(pop()));
            break;
        case '%':
            tmp = pop();
            push(fmod(pop(), tmp));
            break;
        case '$':
            push(getvar(s[1]));
            break;
        default:
            printf("Not found: \"%s\"\n", s);
            return 0;
    }
    return 1;
}
