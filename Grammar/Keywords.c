#include <Keywords.h>
#include <Tokens.h>

/* Attach keyword definitions to reserved_keywords in "Keywords.h". */
struct Keyword reserved_keywords[] = {
    {TOKEN_IF, "if"},
    {TOKEN_LIBRARY, "library"},
    {TOKEN_IMPORT, "import"},
    {TOKEN_FUNCTION, "function"}
};

extern int _keywords_iskeyword(char* checked_keyword) {
    int array_length = sizeof(reserved_keywords) / sizeof(reserved_keywords[0]);

    for (int i = 0; i < array_length; i++) {
        const char* keyword_name = reserved_keywords[i].keyword;
        if (strcmp(keyword_name, checked_keyword) == 0) {
            return reserved_keywords[i].token_type; /* Return the token type of the keyword. */
        }
    }
    return -1; /* -1 is NULL (no valid keyword). */
}