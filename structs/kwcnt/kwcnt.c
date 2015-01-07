#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

typedef struct {
    char *word;
    int count;
} key_t;

key_t keytab[] = {
    { "auto", 0 },
    { "break", 0 },
    { "case", 0 },
    { "char", 0 },
    { "const", 0 },
    { "continue", 0 },
    { "default", 0 },
    /* … … … */
    { "unsigned", 0 },
    { "void", 0 },
    { "volatile", 0 },
    { "while", 0 }
};

#define NKEYS (sizeof keytab / sizeof 0[keytab])

int getword(char *word, size_t lim) {
    int c;
    char *w = word;

    while (isspace(c = getc(stdin)))
        ;
    if (c != EOF) {
        *w++ = c;
    }
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++) {
        if (!isalnum(*w = getc(stdin))) {
            ungetc(*w, stdin);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

size_t searchwords(char *word, key_t tab[], size_t n) {
    int cond;
    size_t low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        cond = strcmp(word, tab[mid].word);
        if (cond < 0) {
            high = mid - 1;
        } else if (cond > 0) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return (size_t)-1;
}

int main() {
    size_t n;
    char word[NKEYS];

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            n = searchwords(word, keytab, NKEYS);
            if (n != (size_t)-1) {
                keytab[n].count++;
    }   }   }
    for (n = 0; n < NKEYS; n++) {
        if (keytab[n].count > 0) {
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
    }   }
    return 0;
}

    
