#ifndef ROTBUF_H
#define ROTBUF_H

#include <stdbool.h>
#include <stdlib.h>

struct rotbuf {
    char **base;
    size_t n;
    size_t cur;
};

struct rotbuf_iter {
    struct rotbuf rb;
    size_t cur;
    bool passed;
};

void rotbuf_insert(struct rotbuf, char *val);
struct rotbuf_iter rotbuf_each_reverse(struct rotbuf);
char *rotbuf_next(struct rotbuf_iter);

#endif /* ROTBUF_H */
