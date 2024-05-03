/* Aspect's Token Types */

#ifndef TOKENS_H
#define TOKENS_H

/* Naming Conventions:
    -> "_TOKENLIST_TOKEN_TYPE_ENUM" and anything prefixed with "_TOKENLIST_" is either a data macro, or an array.
    -> Anything prefixed with "_tokens_" is a function.

    -> "NUM_OF_TOKEN_TYPES" is the only non-prefixed enum.
    -> "ENUM_ENTRY" is the only non-prefixed macro.
*/


/* This token enum (or macro) represents a constant, and is used to signify tokens.  */
/* This is expanded by the _TOKENLIST_TOKEN_TYPE_ENUM macro to enumerate Aspect's tokens. */
#define ENUM_ENTRY(name) name,
#define _TOKENLIST_TOKEN_TYPE_ENUM \
    ENUM_ENTRY(TOKEN_IDENTIFIER) /* <-- Identifier, Constant, Unknown, and Unexpected */ \
    ENUM_ENTRY(TOKEN_CONSTANT) \
    ENUM_ENTRY(TOKEN_UNKNOWN)  \
    ENUM_ENTRY(TOKEN_UNEXPECTED) \
    ENUM_ENTRY(TOKEN_IF) /* <-- [Keywords] */ \
    ENUM_ENTRY(TOKEN_LIBRARY) \
    ENUM_ENTRY(TOKEN_IMPORT) \
    ENUM_ENTRY(TOKEN_FUNCTION) \
    ENUM_ENTRY(TOKEN_PLUS) /* <-- [Operators] */ \
    ENUM_ENTRY(TOKEN_MINUS) \
    ENUM_ENTRY(TOKEN_EQUAL) \
    ENUM_ENTRY(TOKEN_LEFT_PAREN) \
    ENUM_ENTRY(TOKEN_RIGHT_PAREN) \
    ENUM_ENTRY(TOKEN_FUNCTION_CALL) \
    ENUM_ENTRY(TOKEN_LEFT_BRACKET) \
    ENUM_ENTRY(TOKEN_RIGHT_BRACKET) \
    ENUM_ENTRY(TOKEN_SEMICOLON) /* <-- [Separators] */ \
    ENUM_ENTRY(TOKEN_COMMA) \
    ENUM_ENTRY(TOKEN_DOT)   \
    ENUM_ENTRY(TOKEN_SINGLELINE_COMMENT) /* <-- [Comments (Delimiters)] */ \
    ENUM_ENTRY(TOKEN_START_MULTILINE_COMMENT) \
    ENUM_ENTRY(TOKEN_END_MULTILINE_COMMENT) \
    ENUM_ENTRY(TOKEN_DOUBLE_QUOTE) /* <-- [Separators] */ \
    ENUM_ENTRY(TOKEN_SINGLE_QUOTE)

/* enum AspectTokenType */
/* This is a macro to expand the enum entries from the _TOKENLIST_TOKEN_TYPE_ENUM data macro. */
/* This allows for referencing the tokens in the codebase. */
typedef enum {
    _TOKENLIST_TOKEN_TYPE_ENUM
    NUM_OF_TOKEN_TYPES /* This is used to hold the number of elements in the enum. */
} AspectTokenType;
#undef ENUM_ENTRY

/* const char* _TOKENLIST_TOKEN_TYPE_NAMES[] */
/* This is a macro to expand the enum names as usable strings, and to place them in the _TOKEN_TYPE_NAMES[] array. */
/* This way, we can retrieve the corresponding name for enum aliases by specifying them in a function, instead of directly using constants as representations for tokens. */
#define ENUM_ENTRY(name) #name,
static const char* _TOKENLIST_TOKEN_TYPE_NAMES[] = {
    _TOKENLIST_TOKEN_TYPE_ENUM
};
#undef ENUM_ENTRY

/* This function allows for fetching a stringified token name for an enum. */
extern const char* _tokens_get_token_by_enum(AspectTokenType _enum);

/* Token Structure */
typedef struct {
    AspectTokenType type;     /* Type of the token */
    char* value;        /* Value of the token */
} Token;

#endif /* TOKENS_H */
