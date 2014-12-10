#include <errno.h>
#include <stdlib.h>
#include "prsr.h"
#include "stack.h"

char *interpret_oper(char *arg) {
    double val;
    if (arg[1] == '\0') switch (arg[0]) {
        case '+':
            push(pop() + pop());
            return NULL;
        case '-':
            val = pop();
            push(pop() - val);
            return NULL;
        case '*':
            push(pop() * pop());
            return NULL;
        case '/':
            val = pop();
            push(pop() / val);
            return NULL;
    }
    return interpret_num(arg);
}

char *interpret_num(char *arg) {
    char *numend;
    double num;

    errno = 0;
    num = strtod(arg, &numend);
    if (errno == ERANGE) {
        return "value out of range";
    } else if (*numend != '\0') {
        return "invalid argument";
    }

    push(num);
    return NULL;
}
