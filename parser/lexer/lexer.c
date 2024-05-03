/* Aspect's Language Lexer. */
/* -> This implementation combines tokenization, and lexical analysis into one file. */

/*
    Notes:
        ----> The type of the input that is provided into "lexer_get_next_token" should be a char.
        ----> After a token is fetched, it NEEDS to be consumed in order to progress to the next token. The provided function "lexer_consume_token" is able to do this.
*/

#include <lexer.h>
#include <Keywords.h>
#include <stdlib.h>
#include <ctype.h>


Token* lexer_get_next_token(char* input) {
    Token* token = (Token*)malloc(sizeof(Token));
    token->value = NULL;

    while (*input && isspace(*input)) input++; /* Skip any spaces in front of the input. */

    if (*input == '\0') { /* If there's no more tokens left, return unknown. */
        token->type = TOKEN_UNKNOWN;
        return token;
    }

    if (isalpha(*input)) {
        input = lex_identifier(input, token);
    } else if (isdigit(*input)) {
        lex_constant(input, token);
    } else {
        AspectTokenType type = lexer_get_single_char_type(*input);
        token = lex_single_character(input, type);
    }

    return token;
}

void lexer_consume_token(Token* token) {
    if (token != NULL) {
        free(token->value);
        free(token);
    }
}

AspectTokenType lexer_get_single_char_type(char input) {
    switch(input) {
    
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

Token* lex_single_character(char* input, AspectTokenType type) {
    Token* token = (Token*)malloc(sizeof(Token));
    token->value = (char*)malloc(2);
    token->value[0] = *input;
    token->value[1] = '\0';
    token->type = type;

    return token;
}

char* lex_identifier(char* input, Token* token) {
    char* start = input;
    while (isalnum(*input)) input++;

    token->value = (char*)malloc(input - start + 1);
    strncpy(token->value, start, input - start);
    token->value[input - start] = '\0';

    const int keyword = _keywords_iskeyword(token->value);
    if (keyword != -1) {
        token->type = keyword;
    } else {
        token->type = TOKEN_IDENTIFIER;
    }

    return input;
}

char* lex_constant(char* input, Token* token) {
    char* start = input;
    while (isdigit(*input)) input++;

    token->value = (char*)malloc(input - start + 1);
    strncpy(token->value, start, input - start);
    token->value[input - start] = '\0';
    token->type = TOKEN_CONSTANT;

    return input;
}

void lexer_skip_whitespace(char** input_ptr) {
    while (**input_ptr && isspace(**input_ptr)) (*input_ptr)++;
}
