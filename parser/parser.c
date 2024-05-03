/* Aspect's Language Parser */

#include <parser.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <tokens.h>
#include <lexer.h>
#include <cJSON.h>
#include <tokens.h>

void advance_stream(char** stream, Token* token) {
    *stream += strlen(token->value);
}

void consume_ast(cJSON* AST) {
    if (AST != NULL) {
        free(AST);
    }
}

cJSON build_ast(TokenStream stream) {
    Token* token;

    cJSON* AST = cJSON_CreateObject();
    
    while ((token = next_token(stream))->type != TOKEN_UNKNOWN) {

        printf("Token type: %s, Value: %s\n", _tokens_get_token_by_enum(token->type), token->value);


        advance_stream(&stream, token);
        consume_token(token);
    }
    return *AST;
    //parser_consume_ast(AST);
}