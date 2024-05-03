/* Aspect's Language Parser */

#include "parser.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <tokens.h>
#include <lexer.h>
#include <cJSON.h>

void parser_next_input_pointer(char** input_ptr, Token* token) {
    *input_ptr += strlen(token->value);
}

void parser_skip_whitespace(char** input_ptr) { /* This function skips the remaining whitespace in the input. This is extremely important when interacting with the lexer. */
    while (**input_ptr && isspace(**input_ptr)) (*input_ptr)++;
}

void parser_consume_ast(cJSON* AST) { /* This function frees the allocated memory for the AST. */
    if (AST != NULL) {
        free(AST);
    }
}

cJSON parser_build_ast(char* input) { /* This function builds an AST based on the input. */
    Token* token;
    char* input_ptr = input;

    cJSON* AST = cJSON_CreateObject(); // Define the AST.
    
    /* Parse each token in the input until all are consumed. */
    while ((token = lexer_get_next_token(input_ptr))->type != TOKEN_UNKNOWN) {

        printf("Token type: %s, Value: %s\n", _tokens_get_token_by_enum(token->type), token->value);
        /* Cleanup Process */
        parser_next_input_pointer(&input_ptr, token); /* This function progresses the pointer of the input to the next character. */
        lexer_consume_token(token); /* Consume the token after it is used. */
        parser_skip_whitespace(&input_ptr); /* Skip the remaining whitespace. */
    }
    return *AST;
    //parser_consume_ast(AST); /* Consume the AST after it's used. */
}