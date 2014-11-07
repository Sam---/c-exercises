#ifndef SSORT
#   define SSORT ssort
#endif

#ifndef SSORT_ELT
#   define SSORT_ELT int
#endif

#ifdef SSORT_HEADONLY
extern void SSORT(SSORT_ELT[], size_t);
#else

#   ifndef SSORT_LT
#       define SSORT_LT(a, b) ((a) < (b))
#   endif

void SSORT(SSORT_ELT array[], size_t len) {
    for (size_t end = len; end > 1; end--) {
        size_t maxind = 0;
        for (size_t i = 1; i < end; i++) {
            if (SSORT_LT(array[maxind], array[i])) {
                maxind = i;
            }
        }
        SSORT_ELT tmp = array[end - 1];
        array[end - 1] = array[maxind];
        array[maxind] = tmp;
    }
}
#endif
