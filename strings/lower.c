#include <stdio.h>

/* 2-10 */
int lower(int c) {
    return (c >= 'A' && c <= 'Z')? c + 'a' - 'A' : c;
}

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        putchar(lower(c));
    }
    return 0;
}
