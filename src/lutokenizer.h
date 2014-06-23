
#ifndef __LANGUTILS_TOKENIZER_H__
#define __LANGUTILS_TOKENIZER_H__

#include "lufwddefs.h"

#if defined(_cplusplus) || defined(__cplusplus)
extern "C" {
#endif

#define MAX_PUSHED_CHARS 128

/**
 * The tokenizer for the chuck language.
 */
struct LUTokenizer
{
    CUIStream *input;
    int currLine;
    int currColumn;
    int pushedChars[MAX_PUSHED_CHARS];
    int pushedCharsLen;
};


struct LUToken
{
    int tokenType;
};

extern LUTokenizer *lu_tokenizer_create();
extern void lu_tokenizer_destroy(LUTokenizer *tokenizer);
extern BOOL lu_tokenizer_get_token(LUTokenizer *tokenizer, LUToken *token);
extern void lu_tokenizer_advance_line(LUTokenizer *tokenizer);
extern void lu_tokenizer_consume_line(LUTokenizer *tokenizer);
extern void lu_tokenizer_consume_spaces(LUTokenizer *tokenizer);
extern int lu_tokenizer_peek_char(LUTokenizer *tokenizer);
extern int lu_tokenizer_next_char(LUTokenizer *tokenizer);
extern void lu_tokenizer_unget_char(LUTokenizer *tokenizer, int ch);

#if defined(_cplusplus) || defined(__cplusplus)
}
#endif

#endif

