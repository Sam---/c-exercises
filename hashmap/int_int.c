#include <stdbool.h>
#include "int_int.h"

size_t hash(Table *table, int k) {
    return (size_t)(k % table->tsize);
}

Table tinit(void *buffer, size_t length) {
    Table table;
    table.tstart = buffer;
    table.tsize = length;
    return table;
}

Value tset(Table* table, Key key, Value value) {
    size_t h = hash(table, key);
    while (table->tstart[h].filled && table->tstart[h].key != key) {
        h = (h + 1) % table->tsize;
    }
    table->tstart[h].key = key;
    table->tstart[h].value = value;
    return value;
}

Value tget(Table* table, Key key) {
    size_t h = hash(table, key);
    while (table->tstart[h].filled && table->tstart[h].key != key) {
        h = (h + 1) % table->tsize;
    }
    return table->tstart[h].value;
}
