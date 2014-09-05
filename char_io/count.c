#include <stdio.h>

main()
{
    long blanks = 0, tabs = 0, lines = 0;
    int c;

    while ((c = getchar()) != EOF) {
        switch (c) {
            case ' ':
                ++blanks;
                break;
            case '\t':
                ++tabs;
                break;
            case '\n':
                ++lines;
                break;
        }
    }

    printf("Tabs: %ld\nSpaces: %ld\nNewlines: %ld\n", tabs, blanks, blanks);
}

