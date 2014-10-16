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
                    mypush(sin(mypop()));
                    break;
                case 'q':
                    mypush(sqrt(mypop()));
                    break;
                default:
                    printf("Not found: \"%s\"\n", s);
                    return 0;
            }
            break;
        case 'c':
            switch (s[1]) {
                case 'o':
                    mypush(cos(mypop()));
                    break;
                case 'e':
                    mypush(ceil(mypop()));
                    break;
                default:
                    printf("Not found: \"%s\"\n", s);
                    return 0;
            }
            break;
        case 't':
            mypush(tan(mypop()));
            break;
        case '^':
            tmp = mypop();
            mypush(pow(mypop(), tmp));
            break;
        case 'a':
            switch (s[1]) {
                case 's':
                    mypush(asin(mypop()));
                    break;
                case 'c':
                    mypush(acos(mypop()));
                    break;
                case 't':
                    mypush(atan(mypop()));
                    break;
                default:
                    printf("Not found: \"%s\"\n", s);
                    return 0;
            }
            break;
        case 'h':
            switch (s[1]) {
                case 's':
                    mypush(sinh(mypop()));
                    break;
                case 'c':
                    mypush(cosh(mypop()));
                    break;
                case 't':
                    mypush(tanh(mypop()));
                    break;
                default:
                    printf("Not found: \"%s\"\n", s);
                    return 0;
            }
            break;
        case 'l':
            mypush(log(mypop()));
            break;
        case 'f':
            mypush(floor(mypop()));
            break;
        case '%':
            tmp = mypop();
            mypush(fmod(mypop(), tmp));
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
