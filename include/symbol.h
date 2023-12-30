#ifndef _SYMBOL_H
#define _SYMBOL_H

#include "uthash/uthash.h"
#include "type.h"

typedef struct Symbol
{
    char *name;
    Type *type;
    UT_hash_handle hh;
} Symbol;

extern Symbol *symbols;

void insert_symbol(Symbol *value);

Symbol *get_symbol(const char *symbol_name);

#endif