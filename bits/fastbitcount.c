/*
 * When 1 is subtracted from 0b11...00, the lowset one will be "carried"
 * down to allow the subtraction. In decimal, this would be like:
 *   345300000
 *  -        1
 *   ---------
 *   345299999
 *
 * The  and  will remove the extra one bits from the subtracted result,
 * and clear the original bit from the origin value.
 */

#include <stdio.h>

/* 2-9 */
int bitcount(unsigned x) {
    int b = 0;
    while (x) {
        ++b;
        x &= x - 1;
    }
    return b;
}

int main() {
    int test = 0x1010102; // 4 bits
    printf("%d\n", bitcount(test));
}
