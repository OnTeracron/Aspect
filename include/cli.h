/* Aspect's CLI handler. */

#include <aspect.h>

#ifndef AP_CLI_H
#define AP_CLI_H

char* AspectCLI_is_flag_set(int argc, char* argv[], const char* flag, int expect_argument);
void AspectCLI_Main(int argc, char** argv);
void AspectCLI_exiterror(char* error, char* errortype);

#endif // API_CLI_H