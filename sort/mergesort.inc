#ifndef MSORT
#   define MSORT msort
#endif

#ifndef MSORT_ELT
#   define MSORT_ELT int
#endif

#ifndef MSORT_LT
#   define MSORT_LT(a, b) ((a) < (b))
#endif

#define DIVUP(a, b) ((a)/(b) + (a)%(b))

void MSORT(MSORT_ELT array, size_t len) {
    if (len < 2) return;

    size_t p2len = 1;
    while (p2len < len) p2len *= 2;

    size_t lowlen = p2len / 2;
    size_t highlen = len - lowlen;
    MSORT(array, lowlen);
    MSORT(array + lowlen, highlen);
    if (!MSORT_LT(array[0], array[lowlen])) {
        MSORT_ELT tmp[highlen];

        memcpy(tmp, array[lowlen]);              // <======><-->
        memmove(array + highlen, array, lowlen); // ....<======>
        memcpy(array, tmp, highlen);             // <--><======>
