#include <stdio.h>
#include <stdlib.h>

#define SWAP(type, a, b) do {\
    type _swap_tmp = (a);\
    (a) = (b);\
    (b) = _swap_tmp;\
} while (0)

int main(void) {
    int a = 99;
    int b = 42;
    char *c = "over 9000";
    char *d = "Richard Stallman";
    printf("(%d) (%d) \"%s\" \"%s\"\n", a, b, c, d);
    SWAP(int, a, b);
    printf("(%d) (%d) \"%s\" \"%s\"\n", a, b, c, d);
    SWAP(char *, c, d);
    printf("(%d) (%d) \"%s\" \"%s\"\n", a, b, c, d);
    return EXIT_SUCCESS;
}
