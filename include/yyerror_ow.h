#ifndef _YYERROR_OW_H
#define _YYERROR_OW_H

#include <stdio.h>

typedef enum yyerror_type
{
    MISS_RC,
    MISS_LC,
    MISS_RB,
    MISS_LB,
    MISS_RP,
    MISS_LP,
    MISS_SPEC,
    MISS_SEMI,
    MISS_COMMA,
    MISS_EXP,
    MISS_VAR_NAME,
    MISS_VAR,
    MISS_ARG,
    MISS_FIELD_NAME,
    MISS_IF,
    UNEXPECT_COMMA,
} yyerror_type;

void yyerror_ow(FILE *, yyerror_type, int);

#endif