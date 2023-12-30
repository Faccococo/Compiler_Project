#ifndef _TYPE_H
#define _TYPE_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct Type
{
    char* name;
    enum
    {
        PRIMITIVE,
        ARRAY,
        STRUCTURE,
        FUNCTION
    } category;
    union
    {
        enum
        {
            _INT,
            _FLOAT,
            _CHAR
        } primitive;
        struct Array *array;
        struct FieldList *structure;
    } data;
} Type;

typedef struct Array
{
    struct Type *base;
    int size;
} Array;

typedef struct FieldList
{
    char *name;
    struct Type *type;
    struct FieldList *next;
} FieldList;

bool is_same_type(Type *type1, Type *type2);

#endif