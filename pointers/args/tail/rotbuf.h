#ifndef ROTBUF_H
#define ROTBUF_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct rotbuf_s {
    char **base;
    size_t n;
    size_t cur;
} RotBuf;

typedef struct rotbuf_iter_s {
    RotBuf rb;
    size_t cur;
    bool passed;
} RotBufIter;

RotBuf rotbuf_new(size_t);
void rotbuf_insert(RotBuf, RString);

RotBufIter rotbuf_each_reverse(RotBuf);
RString rotbuf_iter_next(RotBufIter);

#endif /* ROTBUF_H */
