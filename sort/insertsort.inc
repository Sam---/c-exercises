#ifndef ISORT
#   define ISORT isort
#endif

#ifndef ISORT_COPY
#   define ISORT_IP ISORT##_copy
#endif

#ifndef ISORT_ELT
#   define ISORT_ELT int
#endif

#ifndef ISORT_LT
#   define ISORT_LT(a, b) ((a) < (b))
#endif

#define INSERT ISORT_insert
#define INSERT_ELT ISORT_ELT
#define INSERT_LT ISORT_LT
#include "insert.inc"

void ISORT_COPY(ISORT_ELT array[], size_t len, ISORT_ELT dest[]) {
    size_t min, max;
    min = max = len/2;

    dest[0] = array[0];
    for (size_t src = 1; src < len; src++) {
        if (ISORT_LT(dest[max], array[src])) {
            if (max + 2 < len) {
                max++;
                dest[max] = array[src];
            } else {
                memmove(
                    &array[(len - (max+1 - min)) / 2],
                    max+1 - min,
                    min);
            }
        } else if (ISORT_LT(array[src], dest[min])) {
            


    }
}


