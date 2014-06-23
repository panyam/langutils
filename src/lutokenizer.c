
#include "langutils.h"

LUTokenizer *lu_tokenizer_create()
{
    LUTokenizer *tokenizer = ZNEW(LUTokenizer);
    return tokenizer;
}

void lu_tokenizer_destroy(LUTokenizer *tokenizer)
{
    if (tokenizer)
    {
        free(tokenizer);
    }
}

int lu_tokenizer_peek_char(LUTokenizer *tokenizer)
{
    if (tokenizer->pushedCharsLen <= 0)
    {
        tokenizer->pushedChars[tokenizer->pushedCharsLen++] = cu_istream_read_byte(tokenizer->input);
    }
    return tokenizer->pushedChars[tokenizer->pushedCharsLen - 1];
}

int lu_tokenizer_next_char(LUTokenizer *tokenizer)
{
    // is there a character we ungetted?
    int outChar = -1;
    if (tokenizer->pushedCharsLen > 0)
    {
        outChar = tokenizer->pushedChars[--tokenizer->pushedCharsLen];
    }
    else
    {
        return cu_istream_read_byte(tokenizer->input);
    }
    if (outChar == '\n')
    {
        tokenizer->currLine++;
        tokenizer->currColumn = 0;
    }
    tokenizer->currColumn++;
    return outChar;
}

void lu_tokenizer_unget_char(LUTokenizer *tokenizer, int ch)
{
    assert("Unget character stack is full" && tokenizer->pushedCharsLen < MAX_PUSHED_CHARS);
    tokenizer->pushedChars[tokenizer->pushedCharsLen++] = ch;
}

void lu_tokenizer_advance_line(LUTokenizer *tokenizer)
{
    tokenizer->currColumn = 0;
    tokenizer->currLine ++;
}

void lu_tokenizer_consume_line(LUTokenizer *tokenizer)
{
    /*
    int nextChar = lu_tokenizer_next_char(tokenizer);
    while (TRUE)
    {
    }
    */
}

void lu_tokenizer_consume_spaces(LUTokenizer *tokenizer)
{
}

