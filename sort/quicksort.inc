#include <stdbool.h>

#ifndef QKSORT_NAME
#   define QKSORT_NAME qksort
#endif
#ifndef QKSORT_ELEM_T
#   define QKSORT_ELEM_T int
#endif
#ifndef QKSORT_LT
#   define QKSORT_LT(a, b) ((a) < (b))
#endif

#ifndef QKSORT_PARTITION
#   define QKSORT_PARTITION _qksort_part_for_##QKSORT_NAME
QKSORT_ELEM_T *QKSORT_PARTITION(
    QKSORT_ELEM_T *pivot,
    QKSORT_ELEM_T *down, QKSORT_ELEM_T *up)
{
    while (true) {
        while (*down  <= *pivot) down++;
        while (*pivot <= *up)    up--;

        if (down < up) break;
        QKSORT_ELEM_T tmp = *down;
        *down = *up;
        *up = tmp;
    }

    QKSORT_ELEM_T tmp = *up;
    *up = *pivot;
    *pivot = tmp;
    return up;
}

#endif /* ndef QKSORT_PARTITION */




void QKSORT_NAME(QKSORT_ELEM_T array[], size_t length) {
    if (length < 
    QKSORT_PARTITION(*array, array + 1, array + length - 1);

    array[--pos] = pivot;
    array[0] = array[pos];

    QKSORT_NAME(array, pos);
    QKSORT_NAME(array + pos + 1, length - pos - 1);
}
