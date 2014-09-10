#include <stdio.h>

#define BUFMAX 2048
#define UTF8MAXCHARS 4

void reverse(char[], char[], size_t);

int main()
{
    int c;
    char line[BUFMAX];
//  char utf8buf[UTF8MAXCHARS];
    int pos = 0;
//  int u8chars = 0;
    int linecount = 0;

    while ((c = getchar()) != EOF) {
        if (c != '\n') {
            if (pos < BUFMAX) {
//              if ((signed)c < 0) {
//                  if (u8chars > UTF8MAXCHARS) {
//                      fprintf(stderr, "Bad char on line %d", linecount);
//                      return 2;
//                  }
//                  utf8buf[u8chars++] = c;
//              } else {
//                  if (u8chars > 0) {
//                      reverse(line + pos, utf8buf, u8chars);
//                      pos += u8chars;
//                      u8chars = 0;
//                  }
                    line[pos++] = c;
//              }
            } else {
                fprintf(stderr, "Line too long: %d\n", linecount);
                return 1;
            }
        } else {
            while (pos > 0) {
                putchar(line[--pos]);
            }
            putchar('\n');
            ++linecount;
        }
    }
    while (pos > 0) { // clean out excess chars if input not \n-terminated
        putchar(line[--pos]);
        putchar('\n');
    }
    return 0;
}

void reverse(char dest[], char src[], size_t n) {
    int dn = -1;
    while (n > 0) {
        dest[++dn] = src[--n];
    }
}
