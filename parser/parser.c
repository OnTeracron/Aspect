#include "parser.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <tokens.h>
#include <lexer.h>
#include <cJSON.h>

void next_pointer(char** input_ptr, Token* token) {
    *input_ptr += strlen(token->value);
}

void skip_whitespace(char** input_ptr) {
    while (**input_ptr && isspace(**input_ptr)) (*input_ptr)++;
}

void consume_ast(cJSON* AST) {
    if (AST != NULL) {
        free(AST);
    }
}

cJSON build_ast(char* input) {
    Token* token;
    char* input_ptr = input;

    cJSON* AST = cJSON_CreateObject();
    
    while ((token = next_token(input_ptr))->type != TOKEN_UNKNOWN) {

        printf("Token type: %s, Value: %s\n", _tokens_get_token_by_enum(token->type), token->value);

        next_pointer(&input_ptr, token);

        /*
        Resolution to an issue where ending quote and last character will re-appear inside of a stream due to next_pointer functionality.
        This will remove the ending quote, and the previous character from the stream, so tokenization doesn't break.        
        */

        if (token->type == TOKEN_STRING_LITERAL) {

            char *first_quote = strchr(input_ptr, '\"');

            if (first_quote != NULL) {
                first_quote++;
                memmove(input_ptr, first_quote, strlen(first_quote) + 1);
            }
        }

        consume_token(token);
        skip_whitespace(&input_ptr);
    }
    return *AST;
    //consume_ast(AST);
}