// MYSORT_NAME < Name to give function
// MYSORT_TYPE < Name of element type
// MYSORT_COMPARE(a, b) < should a go after b?

void MYSORT_NAME(MYSORT_TYPE array[], size_t size) {
    for (; size > 1; size--) {
        for (size_t i = 0; i < size - 1; i++) {
            if (MYSORT_COMPARE(array[i], array[i+1])) {
                MYSORT_TYPE tmp0 = array[i];
                MYSORT_TYPE tmp1 = array[i+1];
                array[i] = tmp1;
                array[i+1] = tmp0;
            }
        }
    }
}
