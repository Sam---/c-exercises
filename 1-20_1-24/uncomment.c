#include <stdio.h>
#include <stdlib.h>

void block_comment(void); // ok
void line_comment(void); // ok
void indeterminate_comment(void); // ok
int indeterminate_end_comment(void); // ok
void string_literal(void); // ok
void string_escape(void); // ok

int main()
{
    int c;
    while (1) {
        switch (c = getchar()) {
            case EOF:
                exit(0); break;
            case '/':
                indeterminate_comment();
                break;
            case '"':
                putchar(c);
                string_literal();
                break;
            default:
                putchar(c);
        }
    }
    return 0;
}

void indeterminate_comment(void)
{
    int c = getchar();
    switch(c) {
        case EOF:
            exit(0); break;
        case '*':
            block_comment(); break;
        case '/':
            line_comment(); break;
        default:
            putchar(c);
    }
}

void block_comment(void)
{
    int c;
    while (1) {
        switch (c = getchar()) {
            case EOF:
                exit(0); break;
            case '*':
                if (indeterminate_end_comment()) return; break;
        }
    }
}

void line_comment(void)
{
    int c;
    while (1) {
        switch(c = getchar()) {
            case EOF:
                exit(0); break;
            case '\n':
                putchar(c);
                return;
        }
    }
}

int indeterminate_end_comment(void)
{
    int c = getchar();
    switch (c) {
        case EOF:
            exit(0); break;
        case '/':
            return;
        default:
            putchar(c);
            return 0;
    }
}

void string_literal(void)
{
    int c;
    while (1) {
        switch (c = getchar()) {
            case EOF:
                exit(0); break;
            case '\\':
                string_escape(); break;
            case '"':
                putchar(c);
                return;
            default:
                putchar(c);
        }
    }
}

void string_escape(void)
{
    int c = getchar();
    if (c == EOF) {
        exit(0);
    }
    putchar('\\');
    putchar(c);
}

