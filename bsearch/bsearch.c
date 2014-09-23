#include <assert.h>
#include <stdio.h>

#define TASIZE (1024)

void genrange(int arr[], int start, int max) {
    int i;
    for (i = start; i < max; i++) {
        arr[i] = i;
    }
}

/* 3-1 
 * Dosen't actually work.
 * */
int binsearch(int tgt, int v[], int max) {
    int low = 0;
    int high = max- 1;
    int mid;

    while (low < high) {
        mid = (low + high) / 2;
        if (tgt < v[mid]) {
            high = mid - 1;
        } else {
            low = mid;
        }
    }
    if (tgt == v[mid]) {
        return mid;
    } else {
        return -1;
    }
}

int exbinsearch(int tgt, int v[], int max) {
    int low = 0;
    int high = max- 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (tgt < v[mid])
            high = mid - 1;
        else if (tgt > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int realbinsearch(int tgt, int v[], int max) {
    int high, mid, low;
    low = 0;
    high = max - 1;
    mid = (low+high) / 2;
    while (low <= high && tgt != v[mid]) {
        if (tgt < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (tgt == v[mid])
        return mid;
    else
        return -1;
}

int main(int argc, char *argv[]) {
    int testarr[TASIZE];

    genrange(testarr, 0, TASIZE);
    switch (argc) {
        case 1:
            printf("%d\n", binsearch(22, testarr, TASIZE) == 22);
            break;
        case 2:
            printf("%d\n", exbinsearch(22, testarr, TASIZE) == 22);
    }
    return 0;
}
