#include <stdio.h>

int squeeze(char s1[], char s2[]) {
    int c;
    int r = 0;
    int q;

    for (c = 0; s1[c]; ++c) {
        for (q = 0; s1[c] != s2[q] && s2[q]; ++q)
            ; //

        if (s1[c] != s2[q]) {
            s1[r++] = s1[c];
        }
    }
    s1[r++] = 0;
    return r;
}

int main() {
    char stuff[1000];
    fgets(stuff, stdin);
    squeeze(stuff, "aeiou");
    printf("%s", stuff);
    return 0;
}
