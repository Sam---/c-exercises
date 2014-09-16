#include <limits.h>
#include <float.h>
#include <stdio.h>

#define PINFO(tp, min, max, t) printf("%10s: %23" t " to %-23" t " %2d bits\n", \
    #tp, min, max, CHAR_BIT * sizeof ( tp ))

int main()
{
    PINFO(char,   CHAR_MIN, CHAR_MAX, "d");
    PINFO(short,  SHRT_MIN, SHRT_MAX, "d");
    PINFO(int,     INT_MIN,  INT_MAX, "d");
    PINFO(long,   LONG_MIN, LONG_MAX, "ld");
    PINFO(long long,LLONG_MIN,LLONG_MAX,"lld");
    PINFO(float,   FLT_MIN,  FLT_MAX, "g");
    PINFO(double,  DBL_MIN,  DBL_MAX, "g");
}

