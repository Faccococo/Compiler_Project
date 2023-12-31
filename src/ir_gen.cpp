//
// Created by mango on 23-12-29.
//

#include "ir_gen.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string translate_ext_def_list(Node *ext_def_list);

string translate_ext_def(Node *ext_def);

string translate_comp_st(Node *compst);

string translate_def_list(Node *def_list);

string translate_stmt_list(Node *stmt_list);

string translate_stmt(Node *stmt);

string translate_def(Node *def);

string translate_dec_list(Node *dec_list);

string translate_dec(Node *dec);

string translate_exp(Node *exp, string &place);

string translate_cond_exp(Node *exp, string &lb_t, string &lb_f);

string translate_args(Node *args, vector<string> &args_list);

string translate_func_dec(Node *func_dec);


string new_place() {
    static int place = 0;
    return "t" + to_string(place++);
}

string symtab_lookup(Node *node) {
    return node->left->value_view;
}

string new_label() {
    static int label = 0;
    return "label" + to_string(label++);
}

int write_file(string data) {
    std::ofstream file("example.txt"); // 创建一个ofstream实例来打开文件
    if (file.is_open()) { // 检查文件是否成功打开
        file << data;     // 将字符串写入到文件中
        file.close();     // 关闭文件流
        std::cout << "文件写入成功" << std::endl;
    } else {
        std::cout << "无法打开文件" << std::endl;
    }
}

extern "C" {
char *translate_program(Node *program) {
    string ir = translate_ext_def_list(program->left);

    char *ir_cstr = new char[ir.length() + 1];
    strcpy(ir_cstr, ir.c_str());
    write_file(ir);

    return ir_cstr;
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
    Node *specifier = ext_def->left;
//  TODO: translate specifier

//    result += translate_specifier(specifier);

    Node *child = specifier->right;
    if (!strcmp(child->name, "ExtDecList")) {
        // |   Specifier ExtDecList SEMI
        Node *ext_def_list = child;
        return translate_ext_def_list(ext_def_list);
    } else if (!strcmp(child->name, "FunDec")) {
        // |   Specifier FunDec CompSt
        Node *func_dec = child;
        Node *comp_st = func_dec->right;
        string s1 = translate_func_dec(func_dec);
        string s2 = translate_comp_st(comp_st);
        return s1 + s2;
    }

    return "";
}

string translate_var_list(Node *var_list) {
    // VarList: ParamDec COMMA VarList
    // |    ParamDec
    Node *param_dec = var_list->left;
    string param_name = param_dec->left->right->left->value_view;

    if (param_dec->right != NULL) {
        // |    ParamDec COMMA VarList
        string code1 = "PARAM " + param_name + "\n";
        string code2 = translate_var_list(param_dec->right->right);
        return code1 + code2;
    } else {
        // |    ParamDec
        string code1 = "PARAM " + param_name + "\n";
        return code1;
    }
}

string translate_func_dec(Node *func_dec) {
    // FunDec: ID LP VarList RP
    // |    ID LP RP
    string func_name = func_dec->left->value_view;
    string code1 = "FUNCTION " + func_name + " :\n";
    if (!strcmp(func_dec->left->right->right->name, "VarList")) {
        // |    ID LP VarList RP
        Node *var_list = func_dec->left->right->right;
        string code2 = translate_var_list(var_list);
        return code1 + code2;
    }else{
        // |    ID LP RP
        return code1;
    }

}

string translate_comp_st(Node *compst) {
    // CompSt: LC DefList StmtList RC
    Node *stmt_list = compst->left->right;
    return translate_stmt_list(stmt_list);
}

string translate_stmt_list(Node *stmt_list) {
    // StmtList: Stmt StmtList
    // | DefList StmtList
    // | Epsilon
    if (stmt_list == NULL || !strcmp(stmt_list->name, "Epsilon")) {
        return "";
    }

    if (!strcmp(stmt_list->left->name, "Stmt")) {
        Node *stmt = stmt_list->left;
        string s1 = translate_stmt(stmt);
        string s2 = translate_stmt_list(stmt->right);
        return s1 + s2;
    } else if (!strcmp(stmt_list->left->name, "DefList")) {
        Node *def_list = stmt_list->left;
        string s1 = translate_def_list(def_list);
        string s2 = translate_stmt_list(def_list->right);
        return s1 + s2;
    }
    return "";
}

string translate_stmt(Node *stmt) {
    Node *child = stmt->left;
    string place = new_place();
    if (!strcmp(child->name, "Exp")) {
        // |    Exp SEMI
        return translate_exp(child, place);
    } else if (!strcmp(child->name, "CompSt")) {
        // |    CompSt
        return translate_comp_st(child);
    } else if (!strcmp(child->name, "RETURN")) {
        // |    RETURN Exp SEMI
        Node *exp = child->right;
        string tp = new_place();
        string code = translate_exp(exp, tp);
        return code + "RETURN " + tp + "\n";
    } else if (!strcmp(child->name, "IF")) {
        // |    IF LP Exp RP Stmt
        // |    IF LP Exp RP Stmt ELSE Stmt
        if (child->right->right->right->right->right == NULL) {
            // |    IF LP Exp RP Stmt
            string lb1 = new_label();
            string lb2 = new_label();
            string code1 = translate_cond_exp(child->right->right, lb1, lb2);
            string code2 = "LABEL " + lb1 + " :\n";
            string code3 = translate_stmt(child->right->right->right->right);
            string code4 = "LABEL " + lb2 + " :\n";
            return code1 + code2 + code3 + code4;
        } else {
            // |    IF LP Exp RP Stmt ELSE Stmt
            string lb1 = new_label();
            string lb2 = new_label();
            string lb3 = new_label();
            string code1 = translate_cond_exp(child->right->right, lb1, lb2);
            string code2 = "LABEL " + lb1 + " :\n";
            string code3 = translate_stmt(child->right->right->right->right);
            string code4 = "GOTO " + lb3 + "\n";
            string code5 = "LABEL " + lb2 + " :\n";
            string code6 = translate_stmt(child->right->right->right->right->right->right);
            string code7 = "LABEL " + lb3 + " :\n";
            return code1 + code2 + code3 + code4 + code5 + code6 + code7;
        }
    } else if (!strcmp(child->name, "WHILE")) {
        // |    WHILE LP Exp RP Stmt
        string lb1 = new_label();
        string lb2 = new_label();
        string lb3 = new_label();
        string code1 = "LABEL " + lb1 + " :\n";
        string code2 = translate_cond_exp(child->right->right, lb2, lb3);
        string code3 = "LABEL " + lb2 + " :\n";
        string code4 = translate_stmt(child->right->right->right->right);
        string code5 = "GOTO " + lb1 + "\n";
        string code6 = "LABEL " + lb3 + " :\n";
        return code1 + code2 + code3 + code4 + code5 + code6;
    }
    return "";
}

string translate_def_list(Node *def_list) {
    // DefList: Epsilon
    if (!strcmp(def_list->name, "Epsilon")) {
        return "";
    }

    // |    Def DefList
    Node *def = def_list->left;
    string s1 = translate_def(def);
    string s2 = translate_def_list(def->right);
    return s1 + s2;
}

string translate_def(Node *def) {
    // Def: Specifier DecList SEMI
    Node *specifier = def->left;
    Node *dec_list = specifier->right;
    return translate_dec_list(dec_list);
}

string translate_dec_list(Node *dec_list) {
    // DecList: Dec
    Node *dec = dec_list->left;
    string s1 = translate_dec(dec);
    if (dec->right != NULL) {
        // |   Dec COMMA DecList
        string s2 = translate_dec_list(dec_list->right->right);
        return s1 + s2;
    }
    return s1;
}

string translate_dec(Node *dec) {
    // Dec: VarDec
    // |   VarDec ASSIGN Exp
    Node *var_dec = dec->left;
    if (var_dec->right == NULL) {
        // |   VarDec
        return "";
    } else {
        // |   VarDec ASSIGN Exp
        string tp = new_place();
        string code1 = translate_exp(var_dec->right->right, tp);
        string code2 = symtab_lookup(var_dec) + " := " + tp + "\n";
        return code1 + code2;
    }
}


string translate_exp(Node *exp, string &place) {
    Node *child = exp->left;
    if (!strcmp(child->name, "Exp")) {
        if (!strcmp(child->right->name, "ASSIGN")) {
            // |    Exp ASSIGN Exp
            Node *exp1 = child;
            Node *exp2 = child->right->right;
            string variable = symtab_lookup(exp1);
            string tp = new_place();
            string code1 = translate_exp(exp2, tp);
            string code2 = variable + " := " + tp + "\n";
//            string code3 = "[" + place + " := " + variable + "]\n";
//            return code1 + code2 + code3;
            return code1 + code2;
        } else if (!strcmp(child->right->name, "PLUS") ||
                   !strcmp(child->right->name, "MINUS") ||
                   !strcmp(child->right->name, "MUL") ||
                   !strcmp(child->right->name, "DIV")) {
            // |    Exp PLUS Exp
            // |    Exp MINUS Exp
            // |    Exp MUL Exp
            // |    Exp DIV Exp

            string t1 = new_place();
            string t2 = new_place();
            Node *exp1 = child;
            Node *exp2 = child->right->right;
            string code1 = translate_exp(exp1, t1);
            string code2 = translate_exp(exp2, t2);
            string op = child->right->value_view;
            string code3 = place + " := " + t1 + " " + op + " " + t2 + "\n";
            return code1 + code2 + code3;

        } else if (!strcmp(child->right->name, "LB")) {
            // |    Exp LB Exp RB
            string t1 = new_place();
            string t2 = new_place();
            Node *exp1 = child;
            Node *exp2 = child->right->right;
            string code1 = translate_exp(exp1, t1);
            string code2 = translate_exp(exp2, t2);
            string code3 = place + " := " + t1 + "[" + t2 + "]" + "\n";
            return code1 + code2 + code3;
        } else if (!strcmp(child->right->name, "DOT")) {
            // |    Exp DOT ID
            string t1 = new_place();
            Node *exp1 = child;
            string code1 = translate_exp(exp1, t1);
            string code2 = place + " := " + t1 + "." + child->right->right->value_view + "\n";
            return code1 + code2;

        } else if (!strcmp(child->right->name, "LT") ||
                   !strcmp(child->right->name, "LE") ||
                   !strcmp(child->right->name, "GT") ||
                   !strcmp(child->right->name, "GE") ||
                   !strcmp(child->right->name, "NE") ||
                   !strcmp(child->right->name, "EQ") ||
                   !strcmp(child->right->name, "AND") ||
                   !strcmp(child->right->name, "OR")) {
            string lb1 = new_label();
            string lb2 = new_label();
            string code0 = place + " := " + "#0" + "\n";
            string code1 = translate_cond_exp(exp, lb1, lb2);
            string code2 = "LABEL " + lb1 + " :\n";
            string code3 = place + " := " + "#1" + "\n";
            string code4 = "LABEL " + lb2 + " :\n";
            return code0 + code1 + code2 + code3 + code4;
        }
    } else if (!strcmp(child->name, "LP")) {
        // |    LP Exp RP
        return translate_exp(child->right, place);
    } else if (!strcmp(child->name, "MINUS")) {
        // |    MINUS Exp
        string tp = new_place();
        Node *exp1 = child->right;
        string code1 = translate_exp(exp1, tp);
        string code2 = place + " := " + "#0" + " - " + tp + "\n";
        return code1 + code2;
    } else if (!strcmp(child->name, "ID")) {
        // |    ID
        // |    ID LP Args RP
        // |    ID LP RP

        if (child->right == NULL){
            // |    ID
            place = new_place();
            return place + " := " + child->value_view + "\n";
        } else if (!strcmp(child->right->name, "LP")){
            // |    ID LP Args RP
            // |    ID LP RP
            Node *LP = child->right;
            string func_name = child->value_view;
            if (!strcmp(LP->right->name, "Args")) {
                // |    ID LP Args RP
                if (!strcmp(func_name.c_str(), "write")) {
                    Node *args = LP->right;
                    string tp = new_place();
                    string code1 = translate_exp(args->left, tp);
                    string code2 = "WRITE " + tp + "\n";
                    return code1 + code2;
                }
                Node *args = LP->right;
                vector<string> arg_list;
                string code1 = translate_args(args, arg_list);
                string code2;
                // for (const auto &arg: arg_list) {
                //     code2 += "ARG " + arg + "\n";
                // }
                for (int i = arg_list.size() - 1; i >= 0; i--) {
                    code2 += "ARG " + arg_list[i] + "\n";
                }
                string code3 = place + " := " + "CALL " + func_name + "\n";
                return code1 + code2 + code3;
            } else {
                // |    ID LP RP
                if (!strcmp(func_name.c_str(), "read")) {
                    return "READ " + place + "\n";
                }
                return place + " := " + "CALL " + func_name + "\n";
            }
        }

    } else if (!strcmp(child->name, "INT")) {
        // |    INT
        int value = child->int_value;
        place = new_place();
        return place + " := #" + to_string(value) + "\n";

    } else if (!strcmp(child->name, "FLOAT")) {
        // |    FLOAT
    } else if (!strcmp(child->name, "CHAR")) {
        // |    CHAR
    }

    return "";
}

string translate_args(Node *args, vector<string> &args_list) {
    // Args: Exp COMMA Args
    // |    Exp
    Node *exp = args->left;
    string tp = new_place();
    string code1 = translate_exp(exp, tp);
    args_list.push_back(tp);
    if (exp->right != nullptr) {
        // |    Exp COMMA Args
        string code2 = translate_args(exp->right->right, args_list);
        return code1 + code2;
    }
    return code1;
}

string translate_cond_exp(Node *exp, string &lb_t, string &lb_f) {
    Node *child = exp->left;
    if (!strcmp(child->right->name, "LT") ||
        !strcmp(child->right->name, "LE") ||
        !strcmp(child->right->name, "GT") ||
        !strcmp(child->right->name, "GE") ||
        !strcmp(child->right->name, "NE") ||
        !strcmp(child->right->name, "EQ")) {
        // |    Exp LT Exp
        // |    Exp LE Exp
        // |    Exp GT Exp
        // |    Exp GE Exp
        // |    Exp NE Exp
        // |    Exp EQ Exp
        string t1 = new_place();
        string t2 = new_place();
        Node *exp1 = child;
        Node *exp2 = child->right->right;
        string code1 = translate_exp(exp1, t1);
        string code2 = translate_exp(exp2, t2);
        string op = child->right->value_view;
        string code3 = "IF " + t1 + " " + op + " " + t2 + " GOTO " + lb_t + "\n";
        string code4 = "GOTO " + lb_f + "\n";
        return code1 + code2 + code3 + code4;
    } else if (!strcmp(child->right->name, "AND")) {
        // |    Exp AND Exp
        string lb1 = new_label();
        string code1 = translate_cond_exp(child, lb1, lb_f);
        string code2 = "LABEL " + lb1 + " :\n";
        string code3 = translate_cond_exp(child->right->right, lb_t, lb_f);
        return code1 + code2 + code3;

    } else if (!strcmp(child->right->name, "OR")) {
        // |    Exp OR Exp
        string lb1 = new_label();
        string code1 = translate_cond_exp(child, lb_t, lb1);
        string code2 = "LABEL " + lb1 + " :\n";
        string code3 = translate_cond_exp(child->right->right, lb_t, lb_f);
        return code1 + code2 + code3;

    } else if (!strcmp(child->name, "NOT")) {
        // |   NOT Exp
        return translate_cond_exp(child->right, lb_f, lb_t);
    }
    return "";
}
