#include "mygetline.h"

int main() {
    char buffer[1024];

    mygetline(buffer, 1024);
    puts(buffer);
}
