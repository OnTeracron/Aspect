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

extern int _keywords_iskeyword(char* token);
struct Keyword {
    int token_type;
    const char *keyword;
};

/* 
    This is an array of recognizable keywords for the programming language.
    The actual values are located in "keywords.c".
    It should only be managed directly from "keywords.c", and assigned explicit TokenTypes from "tokens.h".
*/
extern struct Keyword reserved_keywords[];

#endif /* TOKEN_VALUES_H */