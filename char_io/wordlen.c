#include <stdio.h>

#define MAXWORDLEN 64 // I don't think there are any words longer than this.

main()
{
    long word_len_count[MAXWORDLEN];
    int word_len = 0; // length of the current word
    int i;
    
    for (i = 0; i < MAXWORDLEN; ++i) {
        word_len_count[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if ( (c >= 'a' && c <= 'z') || ( c >= 'A' && c <= 'Z') ) {
            word_len += 1;
        } else {
            word_len_count[word_len] += 1;
            word_len = 0;
        }
    }

    
