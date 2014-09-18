#include <stdio.h>

#define MASK(n) ( ~(~0 << (n)) )

unsigned getbits(unsigned val, int p, int n) {
    unsigned lowbits = val >> (p + 1 - n);
    return lowbits & MASK(n);
}

unsigned setbits(unsigned val, int p, int n, unsigned replace) {
    unsigned mask = ~( MASK(n) << (p - n));
    return (val & mask) | (getbits(replace) << (p - n));
}

unsigned invbits(unsigned val, int p, int n) {
    unsigned inverted = ~getbits(val, p, n);
    return setbits(val, p, n, inverted);
}

unsigned rightrot(unsigned val, int n) {
    unsigned top = CHAR_BIT * sizeof val; 
    unsigned low = val & MASK(n);
    unsigned high = getbits(val, top, top - n);
    return setbits(low, // continue here
}

int main() {
    unsigned funbits = 0x1234678;
    printf("0x67 = 0x%08x\n"
           "0x1234f78 = 0x%08x\n"
           "0x12dcba78 = 0x%08x\n"
           "0x6781234 = 0x%08x\n",
            getbits(funbits, 4, 8),
            setbits(funbits, 8, 4, 0xf),
            invbits(funbits, 8, 12),
            rightrot(funbits, 12)
          );
    return 0;
}
