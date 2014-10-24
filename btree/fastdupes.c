#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int *findnextdup(int list[], size_t listlen, int *buffer, size_t *bpos) {
    int *end = list + listlen;
    for (int i = *list; list < end; list++) {
        size_t node = 0;
        while (true) {
            if (node >= *bpos) {
                buffer[node] = i;
                *bpos++;
                break;
            } else if (buffer[node] > i) {
                node *= 2;
                node += 1;
            } else if (buffer[node] < i) {
                node *= 2;
            } else {
                return list; // list now &i
            }
        }
    }
    return NULL; // no more
}

int main(int argc, char *argv[]) {
    int *list = malloc((argc - 1) * sizeof(int));
    int *buf =  malloc(1024 * 1024); // should be enough
    for (size_t i; i < argc; i++) {
        list[i] = strtol(argv[i], NULL, 10);
    }
    size_t bpos;
    for (int *next = list; next; next = findnextdup(next, argc, buf, &bpos)) {
        printf("Duplicate found: %d", *next);
    }
    // free(list);
    // free(buf);
    return 0;
}

