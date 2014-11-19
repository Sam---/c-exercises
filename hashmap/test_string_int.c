#include <stdio.h>
#include <stdlib.h>
#include "string_int.h"

int main() {
    Row buffer[256];
    Table table = tinit(buffer, 256);

    tset(&table, "abracadabra", 1337);
    tset(&table, "nulla", 42);
    tset(&table, "ab cdef", 007);
    tset(&table, "Samuel Phillips", 17);

    printf("abracadabra = %d; nulla = %d; ab cdef = %d; Samuel Phillips = %d\n",
            tget(&table, "abracadabra"), tget(&table, "nulla"),
            tget(&table, "ab cdef"), tget(&table, "Samuel Phillips"));
    return EXIT_SUCCESS;
}
