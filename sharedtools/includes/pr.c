#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LNMAX 1024

int main(int argc, char *argv[]) {
    int i;
    char buffer[LNMAX];

    for (i = 1; i < argc; i++) {
        FILE *f;

        printf("*** File: %s ***\n", argv[i]);
        f = fopen(argv[i], "r");
        if (!f) {
            perror(argv[i]);
            continue;
        }

        while (fgets(buffer, LNMAX, f)) {
            char *pos = buffer;
            while (isspace(*pos)) {
                pos++;
            }
            if (pos[0] == '#') {
                pos++;
                while (isspace(*pos)) { pos++; }
                if (!strncmp(pos, "include", strlen("include"))) {
                    pos += strlen("include");
                    while (isspace(*pos)) { pos++; }
                    printf("\t%.*s", 60, pos);
                }
            }
        }

        fclose(f);
    }
    return 0;
}
