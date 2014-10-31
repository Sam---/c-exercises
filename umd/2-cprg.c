#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

const char * const HOLIDAY = "HOLIDAY";

const int monthlens[] = {
    0, 31, 59, 90,
    120, 151, 181,
    212, 243, 273,
    304, 334, 365
};

size_t convert_date(int day, char buffer[10], int year) {
    int month = day / 28;
    int mday = day % 28;
    if (month < 13) {
        int len = sprintf(buffer, "%4d/%2d/%2d", year, month + 1, mday + 1);
        if (len > 0) {
            return (size_t)len;
        } else {
            return 0;
        }
    } else {
        strcpy(buffer, HOLIDAY);
        return strlen(HOLIDAY);
    }
}

bool readdate(FILE *stream, int *day, int *month, int *year) {
    char buffer[124];
    char *buf = buffer;
    char *nbf;
    fgets(buf, 124, stream);
    *year = strtol(buf, &nbf, 10);
    buf = nbf + 1;
    *month = strtol(buf, &nbf, 10);
    buf = nbf + 1;
    *day = strtol(buf, &nbf, 10);
    if (*year > 0 && *month > 0 && *day > 0) {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    int year, month, day;
    size_t len;
    char buffer[10];
    if (argc > 1) {
        file = fopen(argv[1], "r");
        if (!file) {
            perror("convertdate");
            exit(0);
        }
    } else {
        file = stdin;
    }

    if (!readdate(file, &day, &month, &year)) {
        puts("Invalid date");
        exit(0);
    }

    day += monthlens[month - 1] - 1;
    len = convert_date(day, buffer, year);
    printf("Became %.*s\n", (int)len, buffer);
}
