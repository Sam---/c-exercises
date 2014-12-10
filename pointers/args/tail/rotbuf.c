#include <stdbool.h>
#include <stdlib.h>
#include "rotbuf.h"

struct rotbuf rotbuf_new(size_t n) {
    struct rotbuf self;
    self.n = n;
    self.base = calloc(n, sizeof (char*));
    self.cur = 0;
    return self;
}

void rotbuf_insert(struct rotbuf self, char *val) {
    self.base[self.cur++] = val;
    self.cur %= self.n;
}

struct rotbuf_iter rotbuf_each_reverse(struct rotbuf rb) {
    struct rotbuf_iter self;
    self.rb = rb;
    self.cur = rb.cur;
    self.passed = false;
    while (!rb.base[self.cur]) rotbuf_next(self);
    return self;
}

char *rotbuf_next(struct rotbuf_iter self) {
    char *val = self.rb.base[self.cur++];
    self.cur %= self.rb.n;
    if (self.passed) val = NULL;
    if (self.cur == self.rb.cur) self.passed = true;
    return val;
}
