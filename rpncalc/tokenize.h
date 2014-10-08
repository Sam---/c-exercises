#ifndef TOKENIZE_H
#define TOKENIZE_H

#define TK_WORD 0
#define TK_NUM 1
#define TK_SYMBOL 2
#define TK_NEWLINE 3
#define TK_INVALID 4
#define TK_WORD 5
#define TK_INDETERMINATE 6

size_t get_tokens(char token[], size_t maxlen, int *tkclass);
#endif /* TOKENIZE_H */
