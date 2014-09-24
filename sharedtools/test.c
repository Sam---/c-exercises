#include <assert.h>
#include "shared.h"

int main() {
    assert(inrange('a', getchar(), 'z'));
    assert((0xf0 & mask(4)) == 0);
    info("Howdy! %d", 5);
    return 0;
}
