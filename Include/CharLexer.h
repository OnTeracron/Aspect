/* Aspect's Language Lexer. */

#ifndef LEXER_H
#define LEXER_H

#include <Tokens.h>

/* Lexer API */
Token* lexer_get_next_token(char* input);
void lexer_consume_token(Token* token);


#endif