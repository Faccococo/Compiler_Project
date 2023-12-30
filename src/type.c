#include "type.h"
#include "string.h"

bool is_same_type(Type *type1, Type *type2)
{
    if (type1 == NULL || type2 == NULL)
    {
        return false;
    }
    if (type1->category == type2->category)
    {
        if (type1->category == PRIMITIVE)
        {
            return type1->data.primitive == type2->data.primitive;
        }
        else if (type1->category == ARRAY)
        {
            return is_same_type(type1->data.array->base, type2->data.array->base) && type1->data.array->size == type2->data.array->size;
        }
        else if (type1->category == STRUCTURE || type1->category == FUNCTION)
        {

            // shit code
            if (type1->category == STRUCTURE)
            {
                if (strcmp(type1->name, type2->name) != 0)
                {
                    return false;
                }
            }

            FieldList *field1 = type1->data.structure;
            FieldList *field2 = type2->data.structure;
            while (field1 != NULL && field2 != NULL)
            {
                if (!is_same_type(field1->type, field2->type))
                {
                    return false;
                }
                field1 = field1->next;
                field2 = field2->next;
            }
            if (field1 != NULL || field2 != NULL)
            {
                return false;
            }
            return true;
        }
    }
    return false;
}