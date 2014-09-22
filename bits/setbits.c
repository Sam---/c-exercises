#include <limits.h>
#include <stdio.h>

#define MASK(n) ( ~(~0 << (n)) )

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 * These functions don't have the same API as is requested.  *
 * This can be fixed like so:                                *
 * unsigned wrapper(unsigned x, int p, int n) {              *
 *     return getbits(x, p+1-n, n);                          *
 * }                                                         *
 * …and similar for other functions.                         *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* Not an exercise, just wnated to write it
 * gets the _bits_ bits at position _off_ 
 * getbits(val, 2, 3) would retrieve these bits: ---<=>--
 */
unsigned getbits(unsigned val, int off, int bits) {
    return (val >> off) & MASK(bits);
}

/* 2-6
 * sets _bits_ bits at _off_ to the right part of _rep_2-6
 * if val is ==>...<= and rep is .....<->
 * setbits(val, 2, 3, rep) would return ==><-><=
 */
unsigned setbits(unsigned val, int off, int bits, unsigned rep) {
    unsigned clearedval = val & ~(MASK(bits) << off);
    return clearedval | (rep & MASK(bits)) << off;
}

/* 2-7
 * inverts _bits_ bits at _off_
 * getbits(0b00000000, 2, 3) would return 0b00011100
 */
unsigned invbits(unsigned val, int off, int bits) {
    return val ^ (MASK(bits) << off);
}

/* rotates entire unsigned int _bits_ to the right
 * if val is ..,,--'' rightrot(val, 3) would return -''..,,-
 */
unsigned rightrot(unsigned val, int bits) {
    unsigned ulen = CHAR_BIT * sizeof val;
    bits %= ulen;
    unsigned lowbits = val & MASK(bits);
    return val >> bits | lowbits << (ulen - bits);
}

/* Test stuff */
int main() {
    unsigned funbits = 0x01234678;
    printf("0x00000067 = 0x%08x\n"
           "0x01234f78 = 0x%08x\n"
           "0x0123..78 = 0x%08x\n"
           "0x67801234 = 0x%08x\n",
            getbits(funbits, 4, 8),
            setbits(funbits, 8, 4, 0xf),
            invbits(funbits, 8, 8),
            rightrot(funbits, 12)
          );
    return 0;
}
