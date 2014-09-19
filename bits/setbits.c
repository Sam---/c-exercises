#include <limits.h>
#include <stdio.h>

#define MASK(n) ( ~(~0 << (n)) )

unsigned getbits(unsigned val, int off, int bits) {
    return (val >> off) & MASK(bits);
}

unsigned setbits(unsigned val, int off, int bits, unsigned rep) {
    unsigned clearedval = val & ~(MASK(bits) << off);
    return clearedval | (rep & MASK(bits)) << off;
}

unsigned invbits(unsigned val, int off, int bits) {
    return val ^ (MASK(bits) << off);
}

unsigned rightrot(unsigned val, int bits) {
    unsigned ulen = CHAR_BIT * sizeof val;
    bits %= ulen;
    unsigned lowbits = val & MASK(bits);
    return val >> bits | lowbits << (ulen - bits);
}

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
