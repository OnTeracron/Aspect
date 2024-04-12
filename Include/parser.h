/* Aspect's Language Parser. */

#ifndef PARSER_H
#define PARSER_H

#include <tokens.h>
#include <cJSON.h>

/* Parser API | Helper Functions */
cJSON parser_build_ast(char* input);
void parser_next_input_pointer(char** input_ptr, Token* token);
void parser_consume_ast(cJSON* AST);

#endif
