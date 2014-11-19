#ifndef INT_INT_H
#define INT_INT_H

#include <stddef.h>
#include <stdbool.h>

typedef int Key;
typedef int Value;

typedef struct table_s {
    bool filled;
    Key key;
    Value value;
} Row;

typedef struct row_s {
    Row *tstart;
    size_t tsize;
    size_t nrows;
} Table;


Table tinit(void *buffer, size_t length);
Value tset(Table* table, Key key, Value value);
Value tget(Table* table, Key key);

#endif /* INT_INT_H */
