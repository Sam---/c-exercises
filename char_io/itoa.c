#include <stdio.h>
#include <string.h>
#include <limits.h>
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
void itoa(int n, char s[]) {
    int i;
    int sign;
    bool doinc1 = false;

    if (n == INT_MIN) {
        n = INT_MAX;
        doinc1 = true;
    }

    sign = n;
    if (n < 0) {
        n = -n;
    }

    i = 0;
    do {
        s[i++] = n % 10 + '0';
        n /= 10;
    } while (n > 0);

    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';

    if (doinc1) {
        size_t cell;
        while (s[cell] == '9') {
            s[cell++] = '0';
        }
        s[cell]++;
    }

    reverse(s);
}

int main() {
    char s[1024];
    itoa(INT_MIN, s);
    puts(s);
    return 0;
}
