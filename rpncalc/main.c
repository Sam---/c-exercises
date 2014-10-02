#include <stdio.h>
#include <stdlib.h>
#include "shared.h"

#include "getop.h"
#include "stack.h"

#include "main.h"

/* RPN calculator */
int main() {
    int type;
    double op2;
    char oper[MAXOP];

    while ((type = getop(oper)) != EOF) {
        double v;
        info("gotOp");
        switch (type) {
            case NUMBER:
                info("number");
                push(atof(oper));
                break;
            case NNUMBER:
                info("nnumber");
                push(-atof(oper));
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
            case '%':
                op2 = pop();
                v = pop() / op2;
                push(v - (int)v);
                break;
            case 'e':
                push(2.71828182845904523536028747135266249775724709369995957496696762772407663035354759457138217852516642742746);
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            case 'q':
                info("quit");
                return EXIT_SUCCESS;
            default:
                info("Err");
                printf("error: unknown command \"%s\"\n", oper);
                break;
        }
    }
    info("returning");
    return EXIT_SUCCESS;
}
