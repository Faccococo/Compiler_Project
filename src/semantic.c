#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "semantic.h"
#include "symbol.h"

/*
%type <node> Program ExtDefList ExtDef ExtDecList;
%type <node> Specifier StructSpecifier;
%type <node> VarDec FunDec VarList ParamDec;
%type <node> CompSt StmtList Stmt;
%type <node> DefList Def DecList Dec;
%type <node> Exp Args;
*/
extern FILE *file_out;

void parse_program(Node *program) {
    // Program: ExtDefList
    parse_ext_def_list(program->left);
}

void parse_ext_def_list(Node *ext_def_list) {
    // ExtDefList: Epsilon
    //     | ExtDef ExtDefList
    if (ext_def_list->left != NULL && !strcmp(ext_def_list->left->name, "ExtDef")) {
        Node *ext_def = ext_def_list->left;
        parse_ext_def(ext_def);
        parse_ext_def_list(ext_def->right);
    }
}

void parse_ext_def(Node *ext_def) {
    // ExtDef:
    //     | Specifier ...
    Node *specifier = ext_def->left;

    // error
    if (specifier == NULL || specifier->right == NULL)
        return;

    Type *spec_type = parse_specifier(specifier);

    Node *child = specifier->right;
    if (!strcmp(child->name, "ExtDecList")) {
        // |   Specifier ExtDecList SEMI
        Node *ext_def_list = child;
        parse_ext_dec_list(ext_def_list, spec_type);
    } else if (!strcmp(child->name, "FunDec")) {
        // |   Specifier FunDec CompSt
        Node *fun_dec = child;
        Node *comp_st = fun_dec->right;
        Type *fun_dec_type = parse_fun_dec(fun_dec, spec_type);

        if (fun_dec_type != NULL) {
            char *func_name = fun_dec_type->data.structure->name;
            Symbol *func_symbol = get_symbol(func_name);
            if (func_symbol != NULL) {
                fprintf(file_out, "Error type 4 at Line %d: function is redefined \"%s\"\n",
                        fun_dec->lineno, func_symbol->name);
            } else {
                func_symbol = (Symbol *) malloc(sizeof(Symbol));
                char *buf = (char *) malloc(sizeof(char) * strlen(func_name));
                strcpy(buf, func_name);
                func_symbol->name = buf;
                func_symbol->type = fun_dec_type;
                insert_symbol(func_symbol);

                parse_comp_st(comp_st, spec_type);
            }
        }
    } else if (!strcmp(child->name, "SEMI")) {
        // |   Specifier SEMI
        // nothing to do with
    }
}

Type *parse_specifier(Node *specifier) {
    // Specifier:
    Type *type = NULL;
    Node *child = specifier->left;
    if (!strcmp(child->name, "TYPE")) {
        // |    TYPE
        type = (Type *) malloc(sizeof(Type));
        type->category = PRIMITIVE;
        if (!strcmp(child->value_view, "int")) {
            type->data.primitive = _INT;
        } else if (!strcmp(child->value_view, "float")) {
            type->data.primitive = _FLOAT;
        } else if (!strcmp(child->value_view, "char")) {
            type->data.primitive = _CHAR;
        }
    } else if (!strcmp(child->name, "StructSpecifier")) {
        // |    StructSpecifier

        // StructSpecifier:
        Node *_struct = child->left;
        Node *struct_id = _struct->right;
        char *struct_name = struct_id->value_view;

        Symbol *struct_symbol = get_symbol(struct_name);
        if (struct_id->right != NULL) {
            // |    STRUCT ID LC DefList RC
            if (struct_symbol != NULL) {
                fprintf(file_out, "Error type 15 at Line %d: redefine the same structure type \"%s\"\n",
                        struct_id->lineno, struct_name);
            }

            Node *def_list = struct_id->right->right;

            type = (Type *) malloc(sizeof(Type));
            type->category = STRUCTURE;
            type->name = struct_name;
            type->data.structure = parse_def_list(def_list, NULL);

            struct_symbol = (Symbol *) malloc(sizeof(Symbol));
            char *buf = (char *) malloc(sizeof(char) * strlen(struct_name));
            strcpy(buf, struct_name);
            struct_symbol->name = buf;
            struct_symbol->type = type;
            insert_symbol(struct_symbol);
        } else {
            // |   STRUCT ID (Not declaration)
            if (struct_symbol == NULL) {
                fprintf(file_out, "Error type 16 at Line %d: struct is used without definition \"%s\"\n",
                        struct_id->lineno, struct_name);
            }
            if (struct_symbol->type->category != STRUCTURE) {
                fprintf(file_out, "Error type 17 at Line %d: \"%s\" is not a struct\n",
                        struct_id->lineno, struct_name);
            }
            type = struct_symbol->type;
        }
    }
    return type;
}

FieldList *parse_def_list(Node *def_list, FieldList *field) {
    // DefList: Epsilon
    if (!strcmp(def_list->name, "Epsilon")) {
        return field;
    }

    // |    Def DefList
    Node *def = def_list->left;
    if (field == NULL) {
        field = parse_def(def, field);
    } else {
        field->next = parse_def(def, field);
    }
    parse_def_list(def->right, field);

    return field;
}

FieldList *parse_def(Node *def, FieldList *field) {
    // Def: Specifier DecList SEMI
    Node *specifier = def->left;
    Node *dec_list = specifier->right;

    Type *type = parse_specifier(specifier);
    field = parse_dec_list(dec_list, field, type);

    return field;
}

FieldList *parse_dec_list(Node *dec_list, FieldList *field, Type *type) {
    // DecList: Dec
    Node *dec = dec_list->left;

    field = parse_dec(dec, field, type);
    if (dec->right != NULL) {
        // |   Dec COMMA DecList
        field = parse_dec_list(dec->right->right, field, type);
    }

    return field;
}

FieldList *parse_dec(Node *dec, FieldList *field, Type *type) {
    // Dec: VarDec
    // |   VarDec ASSIGN Exp
    Node *var_dec = dec->left;
    FieldList *var_dec_fields = parse_var_dec(var_dec, type);

    if (var_dec->right != NULL) {
        Node *exp = var_dec->right->right;
        Type *exp_type = parse_exp(exp);
        if ((type != NULL && exp_type != NULL) && !is_same_type(type, exp_type)) {
            fprintf(file_out, "Error type 5 at Line %d: unmatching types on both sides of assignment operator\n",
                    var_dec->lineno);
        }
    }
    if (var_dec_fields != NULL) {
        FieldList *temp = (FieldList *) malloc(sizeof(FieldList));
        temp->name = var_dec_fields->name;
        temp->type = var_dec_fields->type;
        temp->next = field;
    }

    return var_dec_fields;
}

FieldList *parse_var_dec(Node *var_dec, Type *type) {
    // VarDec: ID
    //      |   VarDec LB INT RB
    Node *child = var_dec->left;
    Type *last_type = type;
    FieldList *result = (FieldList *) malloc(sizeof(FieldList));
    Node *array_size_node;

    // there may be multi-level array
    while (!strcmp(child->name, "VarDec")) {
        Type *new_type = (Type *) malloc(sizeof(Type));
        new_type->data.array = (Array *) malloc(sizeof(Array)); // IMPORTANT: initalize Array pointer
        new_type->category = ARRAY;
        array_size_node = child->right->right;

        new_type->data.array->size = array_size_node->int_value;
        new_type->data.array->base = last_type;
        last_type = new_type;
        child = child->left; // Goto ID
    }

    result->name = child->value_view;
    result->type = last_type;
    result->next = NULL;

    Symbol *var_symbol = get_symbol(result->name);

    if (var_symbol != NULL) {
        fprintf(file_out, "Error type 3 at Line %d: a variable is redefined in the same scope \"%s\"\n",
                child->lineno, result->name);
    }

    var_symbol = (Symbol *) malloc(sizeof(Symbol));
    char *buf = (char *) malloc(sizeof(char) * strlen(result->name));
    strcpy(buf, result->name);
    var_symbol->name = buf;
    var_symbol->type = result->type;
    insert_symbol(var_symbol);

    return result;
}

FieldList *parse_var_list(Node *var_dec_list, FieldList *field) {
    // VarList: ParamDec COMMA VarList
    //      |   ParamDec
    Node *param_dec = var_dec_list->left;
    field = parse_param_dec(param_dec, field);
    if (param_dec->right != NULL) {
        field = parse_var_list(param_dec->right->right, field);
    }

    return field;
}

FieldList *parse_param_dec(Node *param_dec, FieldList *field) {
    // ParamDec: Specifier VarDec
    Type *spec = parse_specifier(param_dec->left);
    if (spec != NULL) {
        field->next = parse_var_dec(param_dec->left->right, spec);
        field = field->next;
    }

    return field;
}

Type *parse_exp(Node *exp) {
    // Exp:
    Node *child = exp->left;
    Type *type = (Type *) malloc(sizeof(Type));

    // avoid default value of type
    type->data.primitive = 3;

    if (!strcmp(child->name, "Exp")) {
        if (!strcmp(child->right->name, "ASSIGN")) {
            // |    Exp ASSIGN Exp
            Node *exp1 = child;
            Node *exp2 = child->right->right;
            Type *exp1_type = parse_exp(exp1);
            Type *exp2_type = parse_exp(exp2);

            if (!((!strcmp(exp1->left->name, "ID") && exp1->left->right == NULL) ||
                  (!strcmp(exp1->left->name, "Exp") && !strcmp(exp1->left->right->name, "DOT")) ||
                  (!strcmp(exp1->left->name, "Exp") && !strcmp(exp1->left->right->name, "LB")))) {
                fprintf(file_out, "Error type 6 at Line %d: rvalue on the left side of assignment operator\n",
                        child->lineno);
            } else if (!is_same_type(exp1_type, exp2_type)) {
                fprintf(file_out, "Error type 5 at Line %d: unmatching types on both sides of assignment operator\n",
                        child->lineno);
            } else {
                type = exp1_type;
            }
        }
        else if (!strcmp(child->right->name, "AND") ||
                   !strcmp(child->right->name, "OR")) {
            // |    Exp AND Exp
            // |    Exp OR Exp
            Node *exp1 = child;
            Node *exp2 = child->right->right;
            Type *exp1_type = parse_exp(exp1);
            Type *exp2_type = parse_exp(exp2);
            if (is_same_type(exp1_type, exp2_type) &&
                exp1_type->category == PRIMITIVE &&
                exp1_type->data.primitive == _INT) {
                type = exp1_type;
            } else {
                fprintf(file_out, "Error type 7 at Line %d: unmatching operands\n",
                        child->lineno);
            }
        }
        else if (!strcmp(child->right->name, "LT") ||
                   !strcmp(child->right->name, "LE") ||
                   !strcmp(child->right->name, "GT") ||
                   !strcmp(child->right->name, "GE") ||
                   !strcmp(child->right->name, "NE") ||
                   !strcmp(child->right->name, "EQ") ||
                   !strcmp(child->right->name, "PLUS") ||
                   !strcmp(child->right->name, "MINUS") ||
                   !strcmp(child->right->name, "MUL") ||
                   !strcmp(child->right->name, "DIV")) {
            // |    Exp LT Exp
            // |    Exp LE Exp
            // |    Exp GT Exp
            // |    Exp GE Exp
            // |    Exp NE Exp
            // |    Exp EQ Exp
            // |    Exp PLUS Exp
            // |    Exp MINUS Exp
            // |    Exp MUL Exp
            // |    Exp DIV Exp
            Node *exp1 = child;
            Node *exp2 = child->right->right;
            Type *exp1_type = parse_exp(exp1);
            Type *exp2_type = parse_exp(exp2);
            if (is_same_type(exp1_type, exp2_type) &&
                exp1_type->category == PRIMITIVE &&
                (exp1_type->data.primitive == _INT || exp1_type->data.primitive == _FLOAT)) {
                type = exp1_type;
            } else {
                fprintf(file_out, "Error type 7 at Line %d: unmatching operands\n",
                        child->lineno);
            }
        }
        else if (!strcmp(child->right->name, "LB")) {
            // |    Exp LB Exp RB
            Node *exp1 = child;
            Node *exp2 = child->right->right;
            Type *exp1_type = parse_exp(exp1);
            Type *exp2_type = parse_exp(exp2);
            if (exp1_type->category != ARRAY) {
                fprintf(file_out, "Error type 10 at Line %d: applying indexing operator on non-array type variables\n",
                        child->lineno);
            } else if (!(exp2_type->category == PRIMITIVE && exp2_type->data.primitive == _INT)) {
                fprintf(file_out, "Error type 12 at Line %d: array indexing with non-integer type expression\n",
                        child->lineno);
                //  type = exp1_type->array->base;
            } else {
                type = exp1_type->data.array->base;
            }
        }
        else if (!strcmp(child->right->name, "DOT")) {
            // |    Exp DOT ID
            Node *exp1 = child;
            Node *member_id = child->right->right;
            Type *exp1_type = parse_exp(exp1);
            if (exp1_type->category != STRUCTURE) {
                fprintf(file_out, "Error type 13 at Line %d: accessing member of non-structure variable\n",
                        child->lineno);
            } else {
                FieldList *field = exp1_type->data.structure;
                while (field != NULL) {
                    if (!strcmp(field->name, member_id->string_value)) {
                        break;
                    }
                    field = field->next;
                }

                if (field == NULL) {
                    fprintf(file_out, "Error type 14 at Line %d: accessing an undefined structure member \"%s\".\n",
                            member_id->lineno, member_id->value_view);
                } else {
                    type = field->type;
                }
            }
        }
    }
    else if (!strcmp(child->name, "LP")) {
        // |    LP Exp RP
        type = parse_exp(child->right);
    } else if (!strcmp(child->name, "MINUS")) {
        // |    MINUS Exp
        Type *exp_type = parse_exp(child->right);
        if (exp_type->category != PRIMITIVE) {
            fprintf(file_out, "Error type 7 at Line %d: unmatching operands\n",
                    child->lineno);
        } else {
            type = exp_type;
        }
    } else if (!strcmp(child->name, "NOT")) {
        // |   NOT Exp
        Type *exp_type = parse_exp(child->right);
        if (!(exp_type->category == PRIMITIVE && exp_type->data.primitive == _INT)) {
            fprintf(file_out, "Error type 7 at Line %d: unmatching operands\n",
                    child->lineno);
        } else {
            type = exp_type;
        }
    } else if (!strcmp(child->name, "ID")) {
        Symbol *id_symbol = get_symbol(child->value_view);
        if (child->right != NULL) {
            // |    ID LP Args RP
            // |    ID LP RP
            if (id_symbol == NULL) {
                // child->right should be LP, and rightmost should be RP
                Node *rightmost = child;
                while (rightmost->right != NULL) {
                    rightmost = rightmost->right;
                }
                if (!strcmp(child->right->name, "LP") && !strcmp(rightmost->name, "RP")) {
                    if (strcmp(child->value_view, "read") != 0 && strcmp(child->value_view, "write") != 0) {
                        fprintf(file_out, "Error type 2 at Line %d: a function is used without definition \"%s\"\n",
                                child->lineno, child->value_view);
                    }
                } else {
                    fprintf(file_out, "Error type 1 at Line %d: a variable is used without definition \"%s\"\n",
                            child->lineno, child->value_view);
                }
                return NULL;
            } else if (id_symbol->type->category != FUNCTION) {
                fprintf(file_out,
                        "Error type 11 at Line %d: applying function invocation operator on non-function names \"%s\"\n",
                        child->lineno, child->value_view);
                return NULL;
            }
            Type *func_type = id_symbol->type;
            if (!strcmp(child->right->right->name, "Args")) {
                Node *args = child->right->right;
                FieldList *args_type = func_type->data.structure->next;
                if (args_type == NULL) {
                    fprintf(file_out,
                            "Error type 9 at Line %d: a function %s's arguments mismatch the declared parameters (too many)\n",
                            child->lineno, child->value_view);
                } else {
                    // Args: Exp COMMA Args
                    //   |   Exp
                    Node *exp = args->left;
                    while (1) {
                        Type *exp_type = parse_exp(exp);
                        if (exp_type != NULL) {
                            if (!is_same_type(exp_type, args_type->type)) {
                                fprintf(file_out,
                                        "Error type 9 at Line %d: the function %s's arguments mismatch the declared parameters (type mismatch)\n",
                                        child->lineno, child->string_value);
                                break;
                            } else {
                                args_type = args_type->next;
                                if (args_type == NULL && exp->right == NULL) {
                                    type = func_type->data.structure->type;
                                    break;
                                } else if (args_type != NULL && exp->right == NULL) {
                                    fprintf(file_out,
                                            "Error type 9 at Line %d: the function %s's arguments mismatch the declared parameters (too few)\n",
                                            child->lineno, child->string_value);
                                    break;
                                } else if (args_type == NULL && exp->right != NULL) {
                                    fprintf(file_out,
                                            "Error type 9 at Line %d: the function %s's arguments mismatch the declared parameters (too many)\n",
                                            child->lineno, child->string_value);
                                    break;
                                }
                                exp = exp->right->right->left;
                            }
                        }
                    }
                }
            } else {
                if (func_type->data.structure->next == NULL) {
                    type = func_type->data.structure->type;
                } else {
                    fprintf(file_out,
                            "Error type 9 at Line %d: a function %s's arguments mismatch the declared parameters (too few)\n",
                            child->lineno, child->value_view);
                }
            }
        } else {
            // |    ID
            if (id_symbol == NULL) {
                fprintf(file_out, "Error type 1 at Line %d: a variable is used without definition \"%s\".\n",
                        child->lineno, child->string_value);
            } else {
                type = id_symbol->type;
            }
        }
    } else if (!strcmp(child->name, "INT")) {
        // |    INT
        type->category = PRIMITIVE;
        type->data.primitive = _INT;
    } else if (!strcmp(child->name, "FLOAT")) {
        // |    FLOAT
        type->category = PRIMITIVE;
        type->data.primitive = _FLOAT;
    } else if (!strcmp(child->name, "CHAR")) {
        // |    CHAR
        type->category = PRIMITIVE;
        type->data.primitive = _CHAR;
    }

    return type;
}

Type *parse_fun_dec(Node *fun_dec, Type *last_type) {
    // FunDec: ID LP VarList RP
    //      |   ID LP RP
    Type *type = (Type *) malloc(sizeof(Type));
    type->data.structure = (FieldList *) malloc(sizeof(FieldList));

    Node *func_id = fun_dec->left;
    type->category = FUNCTION;
    type->data.structure->name = func_id->value_view;
    type->data.structure->type = last_type;

    Node *child = func_id->right->right;
    if (!strcmp(child->name, "RP")) {
        // |    ID LP RP
        type->data.structure->next = NULL;
    } else {
        // |    ID LP VarList RP
        parse_var_list(child, type->data.structure);
    }

    return type;
}

void parse_comp_st(Node *compst, Type *return_type) {
    // CompSt: LC StmtList RC
    Node *stmt_list = compst->left->right;
    parse_stmt_list(stmt_list, return_type);
}

void parse_stmt(Node *stmt, Type *return_type) {
    // Stmt:
    Node *child = stmt->left;
    if (!strcmp(child->name, "Exp")) {
        // |    Exp SEMI
        parse_exp(child);
    } else if (!strcmp(child->name, "CompSt")) {
        // |    CompSt
        parse_comp_st(child, return_type);
    } else if (!strcmp(child->name, "RETURN")) {
        // |    RETURN Exp SEMI
        Node *exp = child->right;
        Type *exp_type = parse_exp(exp);
        if (exp_type != NULL && !is_same_type(return_type, exp_type)) {
            fprintf(file_out,
                    "Error type 8 at Line %d: the function's return value type mismatches the declared type\n",
                    child->lineno);
        }
    } else if (!strcmp(child->name, "IF")) {
        // |    IF LP Exp RP Stmt
        // |    IF LP Exp RP Stmt ELSE Stmt
        Node *exp = child->right->right;
        Type *exp_type = parse_exp(exp);
        if (exp_type != NULL) {
            if (!(exp_type->category == PRIMITIVE && exp_type->data.primitive == _INT)) {
                fprintf(file_out, "Error type 7 at Line %d: unmatching operands\n", exp->lineno);
            } else {
                Node *stmt = exp->right->right;
                parse_stmt(stmt, return_type);
                if (stmt->right != NULL)
                    parse_stmt(stmt->right->right, return_type);
            }
        }
    } else if (!strcmp(child->name, "WHILE")) {
        // |    WHILE LP Exp RP Stmt
        Node *exp = child->right->right;
        Type *exp_type = parse_exp(exp);
        if (exp_type != NULL) {
            if (!(exp_type->category == PRIMITIVE && exp_type->data.primitive == _INT)) {
                fprintf(file_out, "Error type 7 at Line %d: unmatching operands\n", exp->lineno);
            } else {
                Node *stmt = exp->right->right;
                parse_stmt(stmt, return_type);
            }
        }
    }
}

void parse_stmt_list(Node *stmt_list, Type *return_type) {
    // StmtList: Epsilon
    //          |    DefList StmtList
    //          |    Stmt StmtList
    if (stmt_list->left == NULL) {
        return;
    }
    if (!strcmp(stmt_list->left->name, "Stmt")) {
        Node *stmt = stmt_list->left;
        parse_stmt(stmt, return_type);
        parse_stmt_list(stmt->right, return_type);
    } else if (!strcmp(stmt_list->left->name, "DefList")) {
        Node *def_list = stmt_list->left;
        parse_def_list(def_list, NULL);
    }
}

void parse_ext_dec_list(Node *ext_dec_list, Type *type) {
    // ExtDecList: VarDec
    Node *var_dec = ext_dec_list->left;
    parse_var_dec(var_dec, type);
    if (var_dec->right != NULL) {
        // |    VarDec COMMA ExtDecList
        parse_ext_dec_list(var_dec->right->right, type);
    }
}
