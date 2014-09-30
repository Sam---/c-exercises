#include <stdio.h>
#include <stdlib.h>

#include "getop.h"
#include "stack.h"

#include "main.h"

/* RPN calculator */
int main() {
    int type;
    double op2;
    char oper[MAXOP];

    while ((type = getop(oper)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(oper));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("error: divide by zero\n");
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command \"%s\"\n", oper);
                break;
        }
    }
    return EXIT_SUCCESS;
}
