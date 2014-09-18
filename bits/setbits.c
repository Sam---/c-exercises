#include <stdio.h>
// n: _n_umber of bit to ignore?
// p: bit _p_laces to return?

unsigned getbits(unsigned val, int p, int n) {
    return (val >> n) & ~(~0 << p);
}

unsigned setbits(unsigned val, int p, int n, unsigned replace) {
    return ((replace & ~(~0 << p)) << n) | (val & ~(~(~0 << p) << n));
}

unsigned invbits(unsigned val, int p, int n) {
    return setbits(val, p, n, ~getbits(val, p, n));
}

unsigned rightrot(unsigned val, int n) {
    return (val >> n) | ((val & ~(~0 << n)) << n);
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
