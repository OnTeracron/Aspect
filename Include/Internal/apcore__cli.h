/* This is Aspect's CLI handler. */

#ifndef AP_CLI_H
#define AP_CLI_H

#include <Aspect.h>

 /* These prototypes are defined by "apcore__cli.c". */
char* AspectCLI_is_flag_set(int argc, char* argv[], const char* flag, int expect_argument);
void AspectCLI_Main(int argc, char** argv);

#endif // API_CLI_H