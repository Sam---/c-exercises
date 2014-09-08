#include <stdio.h>

#define MAXWORDLEN 64 // I don't think there are any words longer than this.

main()
{
    int word_len_count[MAXWORDLEN];
    int word_len = 0; // length of the current word
    int i;
    int c;
    int max = 0;
    
    for (i = 0; i < MAXWORDLEN; ++i) {
        word_len_count[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if ( ('a' <= c && c <= 'z') || ( 'A' <= c && c <= 'Z') ) {
            word_len += 1;
        } else {
            word_len_count[word_len] += 1;
            word_len = 0;
        }
    }

    for (i = 0; i < MAXWORDLEN; ++i) {
        if (max < word_len_count[i]) {
            max = word_len_count[i];
        }
    }

    for (i = max; i < 0; --i) {
        for (word_len = 0; word_len < MAXWORDLEN; ++word_len) {
            if (word_len_count[word_len] >= i) {
                putchar('|');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }

}

    
