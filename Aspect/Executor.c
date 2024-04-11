#include <apcore__filemanager.h>
#include <Parser.h>
#include <Executor.h>
#include <stdio.h>
#include <cJSON.h>

void AE_execute_by_filename(char* filename) {
    char* code = AspectFLM_getfilebyname(filename);

    if (code != NULL) {

        /* This parses the file content into an AST. */

        cJSON Aspect_AST = parser_build_ast(code);

    } else {
        printf("---> Aspect Executor Failed");
    }

}