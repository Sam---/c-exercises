#ifndef PRSR_H
#define PRSR_H

char *interpret_oper(char *arg);
char *interpret_num(char *arg);

static inline char *interpret(char *arg) {
    return interpret_oper(arg);
}

#endif /* PRSR_H */
