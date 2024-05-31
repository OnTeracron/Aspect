/* This is the Aspect Initializer. */
/* The Aspect Initializer is responsible for building an AST, and initializing compilation. */

/* Notes:
    --> The 'AE_execute_by_filename' function executes Aspect code using a filename given inside of the CLI.
*/

#ifndef AP_EXECUTOR_H
#define AP_EXECUTOR_H

void AE_execute_by_filename(char* filename);

#endif // AP_EXECUTOR_H
