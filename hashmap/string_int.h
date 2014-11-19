#ifndef STRING_INT_H
#define STRING_INT_H

#include <stddef.h>
#include <stdbool.h>

typedef char *Key;
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

#endif /* STRING_INT_H */
