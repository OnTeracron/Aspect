/* 
    Aspect's Language Lexer.
    --> This defines the primary lexing method, which is fetching tokens in a string.
    --> The integration of these functions can vary depending on the parsing method it's used in.
*/

#ifndef LEXER_H
#define LEXER_H

#include <tokens.h>

Token* next_token(TokenStream stream);
Token* lex_single_character(TokenStream stream, TokenType type);
TokenStream lex_string_literal(TokenStream stream, Token* token);

TokenStream lex_identifier(TokenStream stream, Token* token);
TokenStream lex_constant(TokenStream stream, Token* token);

TokenType single_char_type(SingleCharacterToken token);

void consume_token(Token* token);

#endif
