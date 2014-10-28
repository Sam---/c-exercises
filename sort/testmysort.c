#include <stdio.h>
#include <stdlib.h>

#define MYSORT_NAME mysort
#define MYSORT_TYPE int
#define MYSORT_COMPARE(a, b) ((a) > (b))

#include "mysort.inc"

int main(int argc, char *argv[]) {
    char *end;
    size_t size = strtol(argv[1], &end, 10);
    int *buffer = malloc(size * sizeof(int));

    for (size_t i = 0; i < size; i++) {
        buffer[i] = rand();
    }

    mysort(buffer, size);

    for (size_t i = 0; i < size; i++) {
        printf("%d\n", buffer[i]);
    }

    return EXIT_SUCCESS;
}
