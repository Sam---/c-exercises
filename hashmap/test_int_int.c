#include <stdlib.h>
#include <stdio.h>
#include "int_int.h"

int main() {
    int buffer[256];
    Table table = tinit(buffer, 256);
    tset(&table, 0, 5);
    tset(&table, 500, 4);
    tset(&table, 256, 7);

    printf("5 = %d\n4 = %d\n7 = %d\n",
            tget(&table, 0),
            tget(&table, 500),
            tget(&table, 256));
    return EXIT_SUCCESS;
}
