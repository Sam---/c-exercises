#include <stdio.h>

int in_range(int low, int n, int high) {
    return low <= n && n <= high;
}

unsigned long fromhex(char source[]) {
    int digit = 0;
    unsigned long result = 0;

    if (source[0] == '0' && (source[1] == 'x' || source[1] == 'X')) {
        source += 2;
    }

    while (1) {
        char c = source[digit];
        if (in_range('0',c,'9')) {
            result <<= 4;
            result |= (c - '0');
        } else if (in_range('a',c,'f')) {
            result <<= 4;
            result |= (c - 'a' + 0xa);
        } else if (in_range('A',c,'F')) {
            result <<= 4;
            result |= (c - 'A' + 0xA);
        } else {
            return result;
        }
        ++digit;
    }
}

int main() {
    char test[]  = "deadbeef";
    char test2[] = "0xcafebabe";
    char test3[] = "yo mama";

    printf("%s = %lu\n%s = %lu\n%s = %lu\n",
            test, fromhex(test),
            test2, fromhex(test2),
            test3, fromhex(test3)
          );
    return 0;
}
