#include "uthash.h"

#define KEYMAX

struct funcrow {
    char name[KEYMAX];
    void (*action)(void);
    UT_hash_handle hh;
}

struct funcrow *funcs = NULL;

void addf(char name[KEYMAX], void (*action)(void)) {
    struct funcrow *row = malloc(sizeof(struct funcrow));
    struct funcrow *row 
    strncpy(row->name, name, KEYMAX);
    row->action = action;
    HASH_REPLACE_STR(funcs, hh, row, NULL
