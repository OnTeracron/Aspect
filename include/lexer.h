/* 
    Aspect's Language Lexer.
    --> This defines the primary lexing method, which is fetching tokens in a string.
    --> The integration of these functions can vary depending on the parsing method it's used in.
*/

#ifndef LEXER_H
#define LEXER_H

#include <tokens.h>

Token* lexer_get_next_token(char* input);
void lexer_consume_token(Token* token);
char* lex_identifier(char* input, Token* token);
char* lex_constant(char* input, Token* token);
Token* lex_single_character(char* input, AspectTokenType);
AspectTokenType lexer_get_single_char_type(char input);
void lexer_skip_whitespace(char** input_ptr);

#endif
