#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "../sharedtools/shared.h"

void reverse(char s[]) {
    size_t len = strlen(s) - 1;
    size_t l = 0, h = len;

    while (l < h) {
        char tmp = s[l];
        s[l] = s[h];
        s[h] = tmp;
        l++;
        h--;
    }
}

/* 3-4 */
size_t itoa(int n, char s[]) {
    int digit;
    int sign;

    sign = n;

    digit = 0;
    do {
        s[digit++] = abs(n % 10) + '0';
        n /= 10;
    } while (n != 0);

    if (sign < 0) {
        s[digit++] = '-';
    }
    s[digit] = '\0';

    reverse(s);
    return digit; // length of string, so caller can be fast
}

/* 3-6 */

size_t itoam(int n, char s[], size_t min) {
    size_t len;

    len = itoa(n, s);
    if (len < min) {
        memmove(s + min - len, s, len + 1);
        memset(s, 0x20, min - len);
        return min;
    }
    return len;
}

/* 3-5 */
size_t itob(unsigned n, char s[], int base) {
    static char nums[62] = "0123456789" "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int digit;

    if (base > 62) {
        return 0;
    }

    digit = 0;
    do {
        s[digit++] = nums[n % base];
        n /= base;
    } while (n != 0);

    s[digit] = '\0';

    reverse(s);
    return digit; // length of string, so caller can be fast
}


/* 3-6 */
int main() {
    char s[1024];
    itoa(INT_MIN, s);
    puts(s);
    itob(UINT_MAX, s, 62);
    puts(s);
    itoam(6, s, 10);
    puts(s);
    itoam(INT_MAX, s, 3);
    puts(s);
    return 0;
}
