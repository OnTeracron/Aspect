/* Aspect's Token Types */

#include <Tokens.h>
#include <stdio.h>

/* This function allows for fetching a stringified token name for an enum. */
inline const char* _tokens_get_token_by_enum(AspectTokenType _enum) {
    if (_enum < 0 || _enum >= NUM_OF_TOKEN_TYPES) return "TOKEN_UNEXPECTED";
    return _TOKENLIST_TOKEN_TYPE_NAMES[_enum];
}