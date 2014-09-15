#include <stdio.h>

#define NO     0 
#define ALMOST 1 
#define YES    2 
#define KINDA  3 

#define MAXDEPTH 2048

int line, col;
int bracelevel;
char bracebuffer[MAXDEPTH];

void balance(char);

int main() {
    extern int line, col;
    extern int braces, brackets, parens;
    extern char bracebuffer[MAXDEPTH];
    extern int bracelevel;

    int incomment = NO;
    int instring = NO;
    int c;

    bracelevel = 0;
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
                printf("%.*s\n", bracelevel, bracebuffer);
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
    if (bracelevel > 0)
        switch (bracebuffer[bracelevel - 1]) {
            case '(':
                printf("You need to close your parens.\n");
                break;
            case '[':
                printf("You need to close your brackets.\n");
                break;
            case '{':
                printf("You need to close your braces.\n");
                break;
    }

    return 0;
}

void balance(char c) {
    extern int line, col;
    extern char bracebuffer[MAXDEPTH];
    extern int bracelevel;

    switch (c) {
        case '[':
            if (bracelevel >= MAXDEPTH)
                printf("Too many braces, brackets, and parens\n"
                       "I don't want to know what your program"
                       " looks like\n");
            bracebuffer[bracelevel++] = c; 
            break;
        case ']':
            if (bracelevel <= 0 || bracebuffer[--bracelevel] != '[')
                printf("%d:%d: Too many ]'s\n", line, col);
            break;
        case '(':
            if (bracelevel >= MAXDEPTH)
                printf("Too many braces, brackets, and parens\n"
                       "I don't want to know what your program"
                       " looks like\n");
            bracebuffer[bracelevel++] = c; 
            break;
        case ')':
            if (bracelevel <= 0 || bracebuffer[--bracelevel] != '(')
                printf("%d:%d: Too many )'s\n", line, col);
            break;
        case '{':
            if (bracelevel >= MAXDEPTH)
                printf("Too many braces, brackets, and parens\n"
                       "I don't want to know what your program"
                       " looks like\n");
            bracebuffer[bracelevel++] = c; 
            break;
        case '}':
            if (bracelevel <= 0 || bracebuffer[--bracelevel] != '{')
                printf("%d:%d: Too many }'s\n", line, col);
            break;
    }
}
