#include <lexer.h>
#include <keywords.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

Token* next_token(TokenStream stream)
{
    Token* token = (Token*)malloc(sizeof(Token));
    if (!token) exit(1);  // Handle allocation failure

    token->value = NULL;

    while (*stream && isspace(*stream)) stream++;

    if (*stream == '\0')
    {
        token->type = TOKEN_UNKNOWN;
        return token;
    }

    if (isalpha(*stream))
    {
        stream = lex_identifier(stream, token);
    }
    else if (isdigit(*stream))
    {
        stream = lex_constant(stream, token);
    }
    else if (*stream == '\"')
    {
        stream = lex_string_literal(stream, token);
    }
    else
    {
        TokenType type = single_char_type(*stream);
        if (type == TOKEN_UNEXPECTED)
        {
            token->type = TOKEN_UNEXPECTED;
            token->value = strdup("(null)");
        }
        else
        {
            token = lex_single_character(stream, type);
        }
        stream++;
    }
    
    return token;
}

void consume_token(Token* token)
{
    if (token != NULL) {
        if (token->value != NULL) free(token->value);
        free(token);
    }
}

TokenType single_char_type(SingleCharacterToken token)
{
    switch(token)
    {
        /* Parenthesis */
        case '(': return TOKEN_LEFT_PAREN;
        case ')': return TOKEN_RIGHT_PAREN;
        /* Brackets */
        case '[': return TOKEN_LEFT_BRACKET;
        case ']': return TOKEN_RIGHT_BRACKET;
        /* Operators */
        case '+': return TOKEN_PLUS;
        case '-': return TOKEN_MINUS;
        case '=': return TOKEN_EQUAL;
        /* Separators */
        case ';': return TOKEN_SEMICOLON;
        case ',': return TOKEN_COMMA;
        case '.': return TOKEN_DOT;
        /* Delimiters */
        case '"': return TOKEN_DOUBLE_QUOTE;
        case '\'': return TOKEN_SINGLE_QUOTE;
        /* Unknown Token */
        default: return TOKEN_UNEXPECTED;
    }
}

Token *lex_single_character(TokenStream stream, TokenType type)
{
    Token *token = (Token*)malloc(sizeof(Token));
    if (!token) exit(1);  // Handle allocation failure

    token->value = (TokenStream)malloc(2);
    if (!token->value) exit(1);  // Handle allocation failure

    token->value[0] = *stream;
    token->value[1] = '\0';
    token->type = type;

    return token;
}

TokenStream lex_identifier(TokenStream stream, Token *token)
{
    TokenStream start = stream;

    while (isalnum(*stream)) stream++;

    token->value = (TokenStream)malloc(stream - start + 1);
    if (!token->value) exit(1);  // Handle allocation failure

    memcpy(token->value, start, stream - start);
    token->value[stream - start] = '\0';

    int keyword = iskeyword(token->value);
    if (keyword != -1)
    {
        token->type = keyword;
    }
    else if (strcmp(token->value, "library") == 0)
    {
        token->type = TOKEN_LIBRARY;
    }
    else
    {
        token->type = TOKEN_IDENTIFIER;
    }

    return stream;
}

TokenStream lex_constant(TokenStream stream, Token* token)
{
    TokenStream start = stream;
    while (isdigit(*stream)) stream++;

    token->value = (TokenStream)malloc(stream - start + 1);
    if (!token->value) exit(1);  // Handle allocation failure

    memcpy(token->value, start, stream - start);
    token->value[stream - start] = '\0';
    token->type = TOKEN_CONSTANT;

    return stream;
}

TokenStream lex_string_literal(TokenStream stream, Token* token)
{
    stream++;
    TokenStream start = stream;

    while (*stream && *stream != '\"') {
        stream++;
    }

    if (*stream == '\0')
    {
        token->type = TOKEN_UNEXPECTED;
        token->value = strdup("Unterminated string literal");
    }
    else
    {
        token->value = (TokenStream)malloc(stream - start + 1);
        if (!token->value) exit(1);

        memcpy(token->value, start, stream - start);
        token->value[stream - start] = '\0';
        token->type = TOKEN_STRING_LITERAL;
    }

    return stream;
}
