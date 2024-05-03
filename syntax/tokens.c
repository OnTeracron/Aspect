/*
    Aspect's Token Types
        --> This file only possess one function, "_tokens_get_token_by_enum".
        --> This function returns a stringified token name based on the enum that is given.
        --> However, the header file is essentially a directive for Token related information.
*/

#include <tokens.h>
#include <stdio.h>

inline const char* _tokens_get_token_by_enum(AspectTokenType _enum) {
    if (_enum < 0 || _enum >= NUM_OF_TOKEN_TYPES) return "TOKEN_UNEXPECTED";
    return _TOKENLIST_TOKEN_TYPE_NAMES[_enum];
}