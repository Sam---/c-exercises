#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "../shared.h"

#define LNMAX 1024

#define ALL 0
#define SYSTEMONLY 1
#define LOCALONLY 2

int main(int argc, char *argv[]) {
    int i;
    char buffer[LNMAX];

    bool tree = false, print_headers = true, hideown = false;
    int types = ALL, indentlevel = 1;

    for (i = 1; i < argc; i++) {
        FILE *f;

        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
                case '-':
                    argv[i] += 2;
                    break;
                case 'l':
                    types = LOCALONLY;
                    continue;
                case 's':
                    types = SYSTEMONLY;
                    continue;
                case 'h':
                    print_headers = false;
                    indentlevel--;
                    continue;
                case 'H':
                    print_headers = true;
                    indentlevel++;
                    continue;
                case 'a':
                    types = ALL;
                    continue;
                case 't':
                    tree = true;
                    continue;
                case 'o':
                    hideown = true;
                    continue;
                case 'O':
                    hideown = false;
                    continue;
                default:
                    printf("Bad argument: \"%s\"\n", argv[i]);
                    continue;
            }
        }

        if (print_headers) {
            putnchars('\t', indentlevel - 1);
            printf("*** File: %s ***\n", argv[i]);
        }
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
                    char *filename;
                    pos += strlen("include");
                    while (isspace(*pos)) {
                        pos++;
                    }
                    if (pos[0] == '"') {
                        char *cpos;
                        filename = pos + 1;
                        *strchr(filename, '"') = '\0';
                        if (types == SYSTEMONLY) {
                            continue;
                        }
                        cpos = strrchr(argv[i], 'c');
                        if (cpos) {
                            *cpos = 'h';
                            if (hideown && !strcmp(filename, argv[i])) {
                                continue;
                            }
                        }
                        putnchars('\t', indentlevel);
                        if (types == ALL) {
                            printf("\"%s\"\n", filename);
                        } else {
                            puts(filename);
                        }
                    } else if (pos[0] == '<') {
                        filename = pos + 1;
                        *strchr(filename, '>') = '\0';
                        if (types == LOCALONLY) {
                            continue;
                        }
                        putnchars('\t', indentlevel);
                        if (types == ALL) {
                            printf("<%s>\n", filename);
                        } else {
                            puts(filename);
                        }
                    } else {
                        continue;
                    }
//                  if (types == ALL) {
//                      printf("%s%.*s", print_headers? "\t":"", 60, pos);

//                  } else if (types == LOCALONLY && pos[0] == '"') {
//                      *strchr(++pos, '"') = '\0';
//                      printf("%s%s\n", print_headers? "\t":"", pos);

//                  } else if (types == SYSTEMONLY && pos[0] == '<') {
//                      *strchr(++pos, '>') = '\0';
//                      printf("%s%s\n", print_headers? "\t":"", pos);
//                  }
                }
            }
        }

        fclose(f);
    }
    return 0;
}
