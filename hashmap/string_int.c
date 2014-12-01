#include <stdbool.h>
#include "string_int.h"

size_t hash(Table *table, char *k) {
    size_t acc;
    for (size_t i = 0; k[i]; i++) {
        acc += k[i];
    }
    return acc % table->tsize;
}

Table tinit(void *buffer, size_t length) {
    Table table;
    table.tstart = buffer;
    table.tsize = length;
    return table;
}

Value tset(Table* table, Key key, Value value) {
    size_t h = hash(table, key);
    while (table->tstart[h].filled &&
            table->tstart[h].key != key) {
        h = (h + 1) % table->tsize;
    }
    table->tstart[h].key = key;
    table->tstart[h].value = value;
    table->tstart[h].filled = true;
    return value;
}

Value tget(Table* table, Key key) {
    size_t h = hash(table, key);
    while (table->tstart[h].filled && table->tstart[h].key != key) {
        h = (h + 1) % table->tsize;
    }
    return table->tstart[h].value;
}
