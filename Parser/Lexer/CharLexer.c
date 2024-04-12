/* Aspect's Language Lexer. */
/* -> This implementation combines tokenization, and lexical analysis into one file. */

/*
    Notes:
        ----> The type of the input that is provided into "lexer_get_next_token" should be a char.
        ----> After a token is fetched, it NEEDS to be consumed in order to progress to the next token. The provided function "lexer_consume_token" is able to do this.
        ----> After a token is consumed, the trailing whitespace will need to be removed manually from the input, in order to prevent duplication issues.
              The "parser_skip_whitespace" function from the "Parser.h" file is able to handle this for you.
*/

#include <CharLexer.h>
#include <Keywords.h>
#include <stdlib.h>
#include <stdio.h> /* For debugging, remove in main code. */
#include <string.h>
#include <ctype.h>

/* This function is for fetching the next token in an input. */
Token* lexer_get_next_token(char* input) {
    Token* token = (Token*)malloc(sizeof(Token)); /* Allocate memory for token. */
    token->value = NULL;

    /* Skip whitespace. */
    while (*input && isspace(*input)) input++;

    /* If there's no more tokens. */
    if (*input == '\0') {
        token->type = TOKEN_UNKNOWN;
        return token;
    }
    

    /* Check for TOKEN_IDENTIFIER and discovered keywords. */
    if (isalpha(*input)) {
        char* start = input;
        while (isalnum(*input)) input++; /* Note: 'isalnum' stands for "is alphanumeric".*/

        /* Allocate memory for the value of the identifier token. The additional character is for storing the null terminator "/0". */
        /* 'input - start' is the length of the identifier. */
        token->value = (char*)malloc(input - start + 1); 
        strncpy_s(token->value, input - start + 1, start, input - start);
        token->value[input - start] = '\0'; /* Set the null terminator of the identifier to '\0'. */
        
        /* Begin keyword discovery check. */
        const int keyword = _keywords_iskeyword(token->value);
        if (keyword != -1) { /* If the token is a keyword (isn't NULL, aka "-1"), assign the corresponding type.*/
            token->type = keyword;
        } else {
            token->type = TOKEN_IDENTIFIER; /* Assign the identifier type if it isn't a keyword. */
        }
        return token;
    }

    /* Check for TOKEN_CONSTANT. */
    if (isdigit(*input)) {
        char* start = input;
        while (isdigit(*input)) input++;

        token->value = (char*)malloc(input - start + 1); /* Allocate memory for the number token. */
        strncpy_s(token->value, input - start + 1, start, input - start);
        token->value[input - start] = '\0';
        token->type = TOKEN_CONSTANT;
        return token;
    }

    /* Check for single-character tokens. */
    switch(*input) {
    
    /* Parenthesis */ 
        case '(': token->type = TOKEN_LEFT_PAREN; break;
        case ')': token->type = TOKEN_RIGHT_PAREN; break;
    /* Brackets */
        case '[': token->type = TOKEN_LEFT_BRACKET; break;
        case ']': token->type = TOKEN_RIGHT_BRACKET; break;
    /* Operators */
        case '+': token->type = TOKEN_PLUS; break;
        case '-': token->type = TOKEN_MINUS; break;
        case '=': token->type = TOKEN_EQUAL; break;
    /* Separators */
        case ';': token->type = TOKEN_SEMICOLON; break;
        case ',': token->type = TOKEN_COMMA; break;
        case '.': token->type = TOKEN_DOT; break;
    /* Delimiters */
        case '"': token->type = TOKEN_DOUBLE_QUOTE; break;
        case '\'': token->type = TOKEN_SINGLE_QUOTE; break;
    /* Unknown Token */
        default: token->type = TOKEN_UNEXPECTED; break;
    }
    
    /* Allocate memory if the token is a single-character, and set it's value. */
    if (token->type != TOKEN_UNEXPECTED) {
        token->value = (char*)malloc(2); /* This is set to '2' to include the token, and the null terminator. */
        token->value[0] = *input;
        token->value[1] = '\0';
        input++;
    } else {
        token->value = malloc(sizeof(*input) + 1);
        token->value[0] = *input;
        token->value[sizeof(*input)] = '\0';
    }
    

    return token;
}

/* This function is to free the memory allocated for the token. */
void lexer_consume_token(Token* token) {
    if (token != NULL) {
        free(token->value);
        free(token);
    }
}