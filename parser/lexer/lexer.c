/* Aspect's Language Lexer. */
/* -> This implementation combines tokenization and lexical analysis into one file. */

/*
    Notes:
        ----> The type of the stream that is provided into "lexer_get_next_token" should be a char.
        ----> After a token is fetched, it NEEDS to be consumed to progress to the next token. The provided function "lexer_consume_token" is able to do this.
*/

#include <lexer.h>
#include <keywords.h>
#include <stdlib.h>
#include <ctype.h>

Token* lexer_get_next_token(TokenStream stream) {
    Token* token = (Token*)malloc(sizeof(Token));
    token->value = NULL;

    lexer_skip_whitespace(*stream);

    if (*stream == '\0') {
        token->type = TOKEN_UNKNOWN;
        return token;
    }

    if (isalpha(*stream)) {
        stream = lex_identifier(stream, token);
    } else if (isdigit(*stream)) {
        lex_constant(stream, token);
    } else {
        TokenType type = lexer_get_single_char_type(*stream);
        token = lex_single_character(stream, type);
    }

    return token;
}

void lexer_consume_token(Token* token) {
    if (token != NULL) {
        free(token->value);
        free(token);
    }
}

TokenType lexer_get_single_char_type(SingleCharacterToken token) {
    switch(token) {
        /* Parenthesis */
        case '(': return TOKEN_LEFT_PAREN; break;
        case ')': return TOKEN_RIGHT_PAREN; break;
        /* Brackets */
        case '[': return TOKEN_LEFT_BRACKET; break;
        case ']': return TOKEN_RIGHT_BRACKET; break;
        /* Operators */
        case '+': return TOKEN_PLUS; break;
        case '-': return TOKEN_MINUS; break;
        case '=': return TOKEN_EQUAL; break;
        /* Separators */
        case ';': return TOKEN_SEMICOLON; break;
        case ',': return TOKEN_COMMA; break;
        case '.': return TOKEN_DOT; break;
        /* Delimiters */
        case '"': return TOKEN_DOUBLE_QUOTE; break;
        case '\'': return TOKEN_SINGLE_QUOTE; break;
        /* Unknown Token */
        default: return TOKEN_UNEXPECTED; break;
    }
}

Token* lex_single_character(TokenStream stream, TokenType type) {
    Token* token = (Token*)malloc(sizeof(Token));

    token->value = (TokenStream)malloc(2);

    token->value[0] = *stream;
    token->value[1] = '\0';
    token->type = type;

    return token;
}

TokenStream lex_identifier(TokenStream stream, Token* token) {
    TokenStream start = stream;

    while (isalnum(*stream)) stream++;

    token->value = (TokenStream)malloc(stream - start + 1);
    strncpy(token->value, start, stream - start);
    token->value[stream - start] = '\0';

    const int keyword = _keywords_iskeyword(token->value);

    if (keyword != -1) {
        token->type = keyword;
    } else {
        token->type = TOKEN_IDENTIFIER;
    }

    return stream;
}

TokenStream lex_constant(TokenStream stream, Token* token) {
    TokenStream start = stream;
    while (isdigit(*stream)) stream++;

    token->value = (TokenStream)malloc(stream - start + 1);
    strncpy(token->value, start, stream - start);
    token->value[stream - start] = '\0';
    token->type = TOKEN_CONSTANT;

    return stream;
}

void lexer_skip_whitespace(TokenStream* stream) {
    while (**stream && isspace(**stream)) (*stream)++;
}