/* Aspect's CLI handler. */

#include <cli.h>
#include <initializer.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* AspectCLI_is_flag_set(int argc, char* argv[], const char* flag, int expect_argument) {
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], flag) == 0) {
            if (i + 1 < argc || expect_argument == 0) {  /* If the flag is set, and either has an argument after it, or one is not expected. */
                return argv[i + 1];
            } else {
                return "ARGUMENT_NOT_GIVEN";
            }
        }
    }
    return "FLAG_NOT_SET";
}

void AspectCLI_exiterror(char* error, char* errortype) {
    printf("%s: %s\n", error, errortype);
    exit(EXIT_FAILURE);
}

void AspectCLI_Main(int argc, char** argv) {

    char* filename = AspectCLI_is_flag_set(argc, argv, "-f", 1);

    if (strcmp(filename, "FLAG_NOT_SET") == 0) { 
        AspectCLI_exiterror("MissingFileError", "An existing flag must be set for this command.");
    } else if (strcmp(filename, "ARGUMENT_NOT_GIVEN") == 0) {
        AspectCLI_exiterror("FlagError", "Filename expected for the -f flag.\nUsage: aspect -f [filename]");
    }

    AE_execute_by_filename(filename);
}