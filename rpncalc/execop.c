#include <stdio.h>
#include <math.h>

#include "stack.h"
#include "vars.h"

#include "execop.h"

int execop(char* s) {
    double tmp;
    switch (s[0]) {
        case 's':
            switch (s[1]) {
                case 'i':
                    mypush(sin(my()));
                    break;
                case 'q':
                    mypush(sqrt(my()));
                    break;
                default:
                    printf("Not found: \"%s\"\n", s);
                    return 0;
            }
            break;
        case 'c':
            switch (s[1]) {
                case 'o':
                    mypush(cos(my()));
                    break;
                case 'e':
                    mypush(ceil(my()));
                    break;
                default:
                    printf("Not found: \"%s\"\n", s);
                    return 0;
            }
            break;
        case 't':
            mypush(tan(my()));
            break;
        case '^':
            tmp = my();
            mypush(pow(my(), tmp));
            break;
        case 'a':
            switch (s[1]) {
                case 's':
                    mypush(asin(my()));
                    break;
                case 'c':
                    mypush(acos(my()));
                    break;
                case 't':
                    mypush(atan(my()));
                    break;
                default:
                    printf("Not found: \"%s\"\n", s);
                    return 0;
            }
            break;
        case 'h':
            switch (s[1]) {
                case 's':
                    mypush(sinh(my()));
                    break;
                case 'c':
                    mypush(cosh(my()));
                    break;
                case 't':
                    mypush(tanh(my()));
                    break;
                default:
                    printf("Not found: \"%s\"\n", s);
                    return 0;
            }
            break;
        case 'l':
            mypush(log(my()));
            break;
        case 'f':
            mypush(floor(my()));
            break;
        case '%':
            tmp = my();
            mypush(fmod(my(), tmp));
            break;
        case '$':
            mypush(getvar(s[1]));
            break;
        default:
            printf("Not found: \"%s\"\n", s);
            return 0;
    }
    return 1;
}
