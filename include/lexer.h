/* 
    Aspect's Language Lexer.
    --> This defines the primary lexing method, which is fetching tokens in a string.
    --> The integration of these functions can vary depending on the parsing method it's used in.
*/

#ifndef LEXER_H
#define LEXER_H

#include <tokens.h>

Token* lexer_get_next_token(TokenStream stream);
Token* lex_single_character(TokenStream stream, TokenType);

TokenStream lex_identifier(TokenStream stream, Token* token);
TokenStream lex_constant(TokenStream stream, Token* token);

TokenType lexer_get_single_char_type(SingleCharacterToken token);

void lexer_consume_token(Token* token);
void lexer_skip_whitespace(TokenStream stream);

#endif
