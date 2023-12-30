//
// Created by mango on 23-12-29.
//

#include "ir_gen.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

string translate_ext_def_list(Node *ext_def_list);

string translate_ext_def(Node *ext_def);

string translate_comp_st(Node *compst);

string translate_def_list(Node *def_list);

string translate_stmt_list(Node *stmt_list);

string translate_def(Node *def);

string translate_dec_list(Node *dec_list);

string translate_dec(Node *dec);

string translate_exp(Node *exp);


extern "C" {
char *translate_program(Node *program) {
//    string ir = translate_ext_def_list(program->left);
//
//    char *ir_cstr = new char[ir.length() + 1];
//    strcpy(ir_cstr, ir.c_str());
//    cout << ir << endl;
//    return ir_cstr;
}
}

std::string translate_ext_def_list(Node *ext_def_list) {
    if (ext_def_list->left != NULL && !strcmp(ext_def_list->left->name, "ExtDef")) {
        Node *ext_def = ext_def_list->left;
        string s1 = translate_ext_def(ext_def);
        string s2 = translate_ext_def_list(ext_def->right);
        return s1 + s2;
    }
    return "";
}

std::string translate_ext_def(Node *ext_def) {
    string result;
    Node *specifier = ext_def->left;

//  TODO: translate specifier

//    result += translate_specifier(specifier);

    Node *child = specifier->right;
    if (!strcmp(child->name, "ExtDecList")) {
        Node *ext_def_list = child;
        result += translate_ext_def_list(ext_def_list);
    } else if (!strcmp(child->name, "FunDec")) {
        Node *func_dec = child;
        Node *comp_st = func_dec->right;
        // TODO: translate func dec
        result += translate_comp_st(comp_st);
    }

    return result;
}

string translate_comp_st(Node *compst) {
    // CompSt: LC DefList StmtList RC
    Node *def_list = compst->left->right;
    translate_def_list(def_list);
    translate_stmt_list(def_list->right);
    return "";
}

string translate_def_list(Node *def_list) {
    // DefList: Epsilon
    if (!strcmp(def_list->name, "Epsilon")) {
        return "";
    }

    // |    Def DefList
    Node *def = def_list->right;
    translate_def(def);

    translate_def_list(def->right);


    return "";
}

string translate_def(Node *def) {
    // Def: Specifier DecList SEMI
    Node *specifier = def->left;
    Node *dec_list = specifier->right;
    translate_dec_list(dec_list);
    return "";
}

string translate_dec_list(Node *dec_list) {
    Node *dec = dec_list->left;
    return "";
}

string translate_dec(Node *dec) {
    Node *var_dec = dec->left;
    if (var_dec->right != nullptr){
        Node *exp = var_dec->right->right;
        translate_exp(exp);
    }
    return "";
}

string translate_stmt_list(Node* stmt_list){
    return "";
}

string translate_exp(Node *exp){
    return "";
}