#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symbol.h"

Symbol *symbols = NULL;

void insert_symbol(Symbol *value)
{
    HASH_ADD_STR(symbols, name, value);
}

Symbol *get_symbol(const char *symbol_name)
{
    Symbol *symbol;
    HASH_FIND_STR(symbols, symbol_name, symbol);
    return symbol;
}