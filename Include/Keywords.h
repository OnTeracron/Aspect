/*
    Aspect's Language Keywords

        Naming Conventions:
        --> Anything prefixed with "_keywords_" is a function.
*/

#ifndef TOKEN_VALUES_H
#define TOKEN_VALUES_H

#include <tokens.h>
#include <stdbool.h>
#include <string.h>

/* Keyword Structure */
struct Keyword {
    int token_type;
    const char *keyword;
};

/*
    This is an array of recognizable keywords for the programming language. The actual values are located in "keywords.c".
    It should only be managed directly from "keywords.c", and assigned explicit TokenTypes from "tokens.h".
*/

extern struct Keyword reserved_keywords[];

// This function checks if the token is a keyword. */
// Note: /* -1 is NULL (no valid keyword). Any other number represents a token constant. */
extern int _keywords_iskeyword(char* token);

#endif /* TOKEN_VALUES_H */