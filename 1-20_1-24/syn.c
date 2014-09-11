#include <stdio.h>

#define MODE_COMMENT_INDET 0
#define MODE_COMMENT_END 1
#define MODE_COMMENT_BLOCK 2
#define MODE_COMMENT_LINE 3
#define MODE_STRING 4
#define MODE_STRING_ESCAPE 5

int main()
{
    int c;

    char braces[MAXDEPTH];
    int depth;

    while ((c = getchar()) != EOF) {
        switch (c) {
            case '"':
                /* continue here */; break;
            case '/':
                comment();
            default:
                dorealchar(c);
        }
    }
    if (pos != 0) {
        printf("You need to fix these: %s\n", g_braces);
    }
    return 0;
}

void dorealchar(int c)
{
    switch (c) {
        case '(':
            g_braces[g_depth++] = c; break;
        case ')':
            if (g_braces[--g_depth] != '(') {
                printf("Too many )'s\n");
            } break;
        case '{':
            g_braces[g_depth++] = c; break;
        case '}':
            if (g_braces[--g_depth] != '{') {
                printf("Too many }'s\n");
            } break;
        case '[':
            g_braces[g_depth++] = c; break;
        case ']':
            if (g_braces[--g_depth] != '[') {
                printf("Too many ]'s\n");
            } break;
    }
}
