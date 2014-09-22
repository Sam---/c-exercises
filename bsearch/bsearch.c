/* 3-1 */
int binsearch(int tgt, int v, int max) {
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
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int main(int argc, char *argv[]) {
    switch (argc) {
        case 1:



