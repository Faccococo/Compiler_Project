#include "yyerror_ow.h"

void yyerror_ow(FILE *file_out, yyerror_type type, int lineno)
{
    char *msg;
    switch (type)
    {
    case MISS_RC:
        msg = "Error type B at Line %d: Missing closing curly braces '}'\n";
        break;
    case MISS_LC:
        msg = "Error type B at Line %d: Missing left curly braces '{'\n";
        break;
    case MISS_RB:
        msg = "Error type B at Line %d: Missing closing bracket ']'\n";
        break;
    case MISS_LB:
        msg = "Error type B at Line %d: Missing left bracket '['\n";
        break;
    case MISS_RP:
        msg = "Error type B at Line %d: Missing closing parenthesis ')'\n";
        break;
    case MISS_LP:
        msg = "Error type B at Line %d: Missing left parenthesis '('\n";
        break;
    case MISS_SPEC:
        msg = "Error type B at Line %d: Missing specifier\n";
        break;
    case MISS_SEMI:
        msg = "Error type B at Line %d: Missing semicolon ';'\n";
        break;
    case MISS_COMMA:
        msg = "Error type B at Line %d: Missing COMMA ','\n";
        break;
    case MISS_EXP:
        msg = "Error type B at Line %d: Missing Exp \n";
        break;
    case MISS_VAR_NAME:
        msg = "Error type B at Line %d: Missing variable name \n";
        break;
    case MISS_VAR:
        msg = "Error type B at Line %d: Missing variable \n";
        break;
    case MISS_ARG:
        msg = "Error type B at Line %d: Missing arguments \n";
        break;
    case MISS_FIELD_NAME:
        msg = "Error type B at Line %d: Missing field name \n";
        break;
    case MISS_IF:
        msg = "Error type B at line %d: no 'if' before 'else' \n";
        break;
    case UNEXPECT_COMMA:
        msg = "Error type B at line %d: Unexpected ',' \n";
        break;
    }
    fprintf(file_out, msg, lineno);
}
