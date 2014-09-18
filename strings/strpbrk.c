#include <stdio.h>
int any(char si[], char sj[]) {
    int i, j;
    for (i = 0; si[i]; ++i) {
        for (j = 0; sj[j]; ++i) {
            if (si[i] == sj[j]) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    printf("%d\n", any("azerty", "etoin"));
    return 0;
}
