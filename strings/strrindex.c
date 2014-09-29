#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "../sharedtools/shared.h"

/* 4-1 */
ptrdiff_t strrindex(char haystack[], char needle[]) {
    size_t hayind;
    size_t neeind = 0;
    ptrdiff_t prevfinal = -1;
    ptrdiff_t final = -1;
    bool inneedle = false;

    for (hayind = 0; haystack[hayind]; hayind++) {
        if (haystack[hayind] == needle[neeind]) {
            neeind++;
            if (!inneedle) {
                inneedle = true;
                prevfinal = final;
                final = hayind;
            }
        } else if (needle[neeind] == '\0') {
            inneedle = false;
            neeind = 0;
        }
    }
    if (needle[neeind] == '\0') {
        return final;
    } else {
        return prevfinal;
    }
    return final;
}

int main() {
    printf("%d\n", strrindex("hayhayhayneedlehayhayhayneedlehay", "nee"));
    return EXIT_SUCCESS;
}
