#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../sharedtools/shared.h"

#define STRRINDEX_FAIL ((int)-1)

/* 4-1 
 * int as index is bad but ptrdiff_t is declared in a weird place 
 */
int strrindex(char haystack[], char needle[]) {
    size_t haymax = strlen(haystack) - 1;
    size_t neemax = strlen(needle) - 1;

    size_t neeind = neemax;
    size_t hayind = haymax;

    for (;hayind > 0; hayind--) {
        if (needle[neeind] == haystack[hayind]) {
            neeind--;
        } else if (needle[neeind] == '\0') {
            return hayind;
        } else {
            neeind = neemax;
        }
    }
    return STRRINDEX_FAIL;
}


int main() {
    printf("%d\n", strrindex("hayhayhayneedlehayhayhayneedlehay", "nee"));
    return EXIT_SUCCESS;
}
