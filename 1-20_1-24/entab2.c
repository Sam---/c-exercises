#include <stdio.h>

#define ENTAB 1
#define DETAB 0

#define TABSTOP 8

#define INFO(fmt, ...) fprintf(stdout, "\e[31m" fmt "\e[0m", ##__VA_ARGS__)

void indent(int start, int end);
int tabup(int col);
void pad(int n);

int main()
{
    int spacecount;
    int start = 0;
    int end = 0;
    int c;
    do {
        c = getchar();
        switch (c) {
            case '\n':
                indent(start, end);
                putchar(c);
                INFO("newline");
                start = end = 0;
                break;
            case ' ':
                ++end;
                break;
            case '\t':
                end = tabup(end);
                break;
            case EOF:
                indent(start, end);
                INFO("end of file");
                putchar('\n');
                break;
            default:
                indent(start, end);
                ++end;
                start = end;
                putchar(c);
        }
    } while (c != EOF);

    return 0;
}

void indent(int start, int end)
{
#if MODE == ENTAB
    int tbegin = tabup(start);

    if (end < tbegin) {
        INFO("padding");
        pad(end - start);
    } else {
        INFO("tabbing");
        putchar('\t');
        for (start = tbegin; start + 4 <= end; start += 4) {
            putchar('\t');
        }
        pad(end - start);
    }
#elif MODE == DETAB
    pad(end - start);
#else
#   error
#endif
}

void pad(int n)
{
    int i;
    for (i = 0; i < n; ++i) {
        putchar(' ');
    }
}


int tabup(int col) {
    int rem = col % TABSTOP;

    if (rem) {
        return col - rem + TABSTOP;
    } else {
        return col;
    }
}



