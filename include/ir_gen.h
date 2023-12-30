#ifndef IR_GEN_H
#define IR_GEN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "parse_tree.h"
#include "type.h"
#include "symbol.h"

char* translate_program(Node *program);

#ifdef __cplusplus
}
#endif
#endif