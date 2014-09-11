#include <stdio.h>

void block_comment(void);
void line_comment(void);
void indeterminate_comment(void);
void indeterminate_end_comment(void);
void string_literal(void);
void string_escape(void);

int main()
{
    int c;
    int state = 0;

    while ((c = getchar()) != EOF) {
        switch (state) {
            case NORMAL:
                switch (c) {
                    case '/':
                        state = HASSL; break;
                    case '"':
                        state == STRING; break;
                    default:
                        putchar(c);
                } break;
            case HASSL:
                switch (c) {
                    case '*':
                        state = COMMENT;
                    case '/':
                        state = LCOMMENT;
                    } else {
                        putchar(c);
                    }
                break;
            case COMMENT:
                if (c == '*') {
                    state = HASSTAR;
                }
                break;
            case HASSTAR:
                if (c == '/') {
                    state = NORMAL;
                }
                break;
            case LCOMMENT:
                if (c == '\n') {
                    state = NORMAL;
                    putchar(c);
                }
                break;
        }
    }
    return 0;
}

