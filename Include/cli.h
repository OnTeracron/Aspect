/*
    This is Aspect's CLI handler.
    The prototypes that are specified in this file are exclusively defined in "cli.c".
*/

#include <aspect.h>

#ifndef AP_CLI_H
#define AP_CLI_H

char* AspectCLI_is_flag_set(int argc, char* argv[], const char* flag, int expect_argument);
void AspectCLI_Main(int argc, char** argv);

#endif // API_CLI_H