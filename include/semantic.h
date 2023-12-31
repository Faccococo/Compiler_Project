#ifndef _SEMANTIC_H
#define _SEMANTIC_H

#include "parse_tree.h"
#include "type.h"
#include "stdio.h"

void parse_program(Node *program);

void parse_ext_def_list(Node *ext_def_list);

void parse_ext_def(Node *ext_def);

Type *parse_specifier(Node *specifier);

FieldList *parse_def_list(Node *def_list, FieldList *field);

FieldList *parse_def(Node *def, FieldList *field);

FieldList *parse_dec_list(Node *dec_list, FieldList *field, Type *type);

FieldList *parse_dec(Node *dec, FieldList *field, Type *type);

FieldList *parse_var_dec(Node *var_dec, Type *type);

FieldList *parse_var_list(Node *var_dec_list, FieldList *field);

FieldList *parse_param_dec(Node *param_dec, FieldList *field);

Type *parse_exp(Node *exp);

Type *parse_fun_dec(Node *fun_dec, Type *last_type);

void parse_comp_st(Node *comp_st, Type *return_type);

void parse_stmt(Node *stmt, Type *return_type);

void parse_stmt_list(Node *stmt_list, Type *return_type);

void parse_ext_dec_list(Node *ext_dec_list, Type *type);


#endif