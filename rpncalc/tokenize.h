#ifndef TOKENIZE_H
#define TOKENIZE_H
enum tkclass {
    TK_WORD,
    TK_NUM,
    TK_SYMBOL,
    TK_NEWLINE,
    TK_INVALID,
    TK_WORD,
    TK_INDETERMINATE
}

size_t get_tokens(char token[], size_t maxlen, enum tkclass *tkclass);
#endif /* TOKENIZE_H */
