#include <stdio.h>

#define NO     0 
#define ALMOST 1 
#define YES    2 
#define KINDA  3 

int line, col;
int braces, brackets, parens;

void balance(char);

int main() {
    extern int line, col;
    extern int braces, brackets, parens;

    int incomment = NO;
    int instring = NO;
    int c;

    braces = brackets = parens = 0;
    line = col = 1;

    while ((c = getchar()) != EOF) {
        switch (c) {
            case '/':
                if (incomment < YES && instring == NO)
                    incomment = ALMOST;
                else if (incomment == KINDA)
                    incomment = NO;
                break;
            case '*':
                if (incomment == YES)
                    incomment = KINDA;
                else if (incomment == ALMOST)
                    incomment = YES;
                break;
            case '"':
                if (instring == YES)
                    instring = NO;
                else if (instring == NO && incomment < YES)
                    instring = YES;
                break;
            case '\\':
                if (instring == YES)
                    instring = KINDA;
                break;
            case '\n':
                if (instring >= YES) {
                    printf("%d: You forgot to end your string.\n", line);
                    instring = NO;
                }
                ++line;
                col = 0;
                break;
            case '~':
                printf("('s: %d\n['s: %d\n{'s: %d\n", parens, brackets, braces);
                break;
        }
        if (instring == KINDA && c != '\\')
            instring = YES;
        if (incomment == ALMOST && c != '/')
            incomment = YES;
        if (incomment == KINDA && c != '*')
            incomment = NO;

        ++col;
        if (incomment < YES && instring < YES)
            balance(c);
    }
    if (brackets > 0)
        printf("You need to close your brackets.\n");

    if (braces > 0)
        printf("You need to close your braces.\n");

    if (parens > 0)
        printf("You need to close your parenthesis.\n");

    return 0;
}

void balance(char c) {
    extern int line, col;
    extern int braces, brackets, parens;

    switch (c) {
        case '[':
            ++brackets; break;
        case ']':
            --brackets;
            if (brackets < 0)
                printf("%d:%d: Unbalanced brackets\n", line, col);
            break;
        case '(':
            ++parens; break;
        case ')':
            --parens;
            if (parens < 0)
                printf("%d:%d: Unbalanced parens\n", line, col);
            break;
        case '{':
            ++braces; break;
        case '}':
            --braces;
            if (braces < 0)
                printf("%d:%d: Unbalanced braces\n", line, col);
            break;
    }
}
