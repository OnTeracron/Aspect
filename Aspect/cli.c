/* This is Aspect's CLI handler. */

#include <cli.h>
#include <filemanager.h>
#include <initializer.h>
#include <string.h>
#include <stdio.h>

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

void AspectCLI_Main(int argc, char* argv[]) {

    /* Filename Flag */
    char* filename = AspectCLI_is_flag_set(argc, argv, "-f", 1);

    if (filename == "FLAG_NOT_SET") {
        printf("An *existing* flag must currently be set for this command.");
        exit(EXIT_FAILURE);
    } else if (filename == "ARGUMENT_NOT_GIVEN") {
        printf("Filename expected for the -f flag.");
        exit(EXIT_FAILURE);
    }

    AE_execute_by_filename(filename);
}
