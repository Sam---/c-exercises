#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void print_ssort_status(int arr[], size_t len, size_t maxp, size_t end) {
    puts("============");
    for (size_t i = 0; i < maxp; i++) printf("%d\n", arr[i]);
    printf("\e[1;31m%d\e[0m\n", arr[maxp]);
    for (size_t i = maxp + 1; i < end; i++) printf("%d\n", arr[i]);
    printf("\e[33m");
    for (size_t i = end; i < len; i++) printf("%d\n", arr[i]);
    printf("\e[0m");
}

#include "selectsort.inc"

#undef SSORT
#undef SSORT_ELT
#undef SSORT_LT
/*
#define SSORT ssort_happies
#define SSORT_ELT struct happy
#define SSORT_LT comparehappieslt

struct happy {
    bool ishappy;
    unsigned long happyness;
    FILE *happytmp;
};

bool comparehappieslt(struct happy a, struct happy b) {
    if (a.ishappy == b.ishappy) {
        if (a.happyness < b.happyness) {
            return true;
        } else if (b.happyness < a.happyness) {
            return false;
        } else if (a.happytmp) {
            return false;
        } else {
            return true;
        }
    } else if (a.ishappy) {
        return false;
    } else {
        return true;
    }
}

#include "selectsort.inc"
*/
int main(int ac, char **av) {
    srand(time(NULL));
    const size_t bmax = 8;
    int b[bmax];
//  struct happy hb[bmax];
    for (size_t i = 0; i < bmax; i++) b[i] = rand();
//  for (size_t i = 0; i < bmax; i++) {
//      hb[i].ishappy = rand() > RAND_MAX / 2;
//      hb[i].happyness = rand();
//      hb[i].happytmp = NULL;
//  }

    ssort(b, bmax);
//  ssort_happies(hb, bmax);

    for (size_t i = 0; i < bmax; i++) printf("%d\n", b[i]);
//  for (size_t i = 0; i < bmax; i++) {
//      printf("%s: (%lu), %s\n", hb[i].ishappy? "true":"false",
//              hb[i].happyness, hb[i].happytmp? "!":"");
//  }

    return EXIT_SUCCESS;
}

