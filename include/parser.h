/* Aspect's Language Parser. */

#ifndef PARSER_H
#define PARSER_H

#include <tokens.h>
#include <cJSON.h>

cJSON build_ast(char* input);
void next_pointer(char** input_ptr, Token* token);
void consume_ast(cJSON* AST);

#endif
