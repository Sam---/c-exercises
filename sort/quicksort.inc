#ifndef QKSORT_NAME
#   define QKSORT_NAME qksort
#endif
#ifndef QKSORT_ELEM_T
#   define QKSORT_ELEM_T int
#endif
#ifndef QKSORT_LT
#   define QKSORT_LT(a, b) ((a) < (b))
#endif

void QKSORT_NAME(QKSORT_ELEM_T array[], size_t length) {
    QKSORT_ELEM_T pivot = array[0];
    size_t pos;
    for ( // this isn't gonna cut it. The array, that is.
        pos = 1;
        pos < length - 1 && QKSORT_LT(array[pos], pivot);
        pos++) {
    }

    array[--pos] = pivot;
    array[0] = array[pos];

    QKSORT_NAME(array, pos);
    QKSORT_NAME(array + pos + 1, length - pos - 1);
}
