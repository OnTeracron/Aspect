#include <filemanager.h>
#include <parser.h>
#include <initializer.h>
#include <stdio.h>
#include <cJSON.h>
#include <stdlib.h>

void AE_execute_by_filename(char* filename) {
    char* string_code = AspectFLM_getfilebyname(filename);

    if (string_code != NULL) {
        cJSON Aspect_AST = parser_build_ast(string_code);
    } else {
        exit(EXIT_FAILURE);
    }

}