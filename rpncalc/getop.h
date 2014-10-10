#ifndef GETOP_H
#define GETOP_H

int getop(char s[], size_t maxlen, double *num);
#define B_ERR 0x00
#define B_SIN  1
#define B_COS  2
#define B_TAN  3
#define B_ASIN 4
#define B_ACOS 5
#define B_ATAN 6
#define B_QUIT 7
#define B_AND  8
#define B_OR   9
#define B_NOT  10
#define B_PI   11
#define B_E    12
#define B_SUM  13
#define B_SUB  14
#define B_MUL  15
#define B_DIV  16
#define B_MOD  17
#define B_EXP  18
#define B_BAND 19
#define B_BOR  20
#define B_BXOR 21
#define B_BSL  22
#define B_BSR  23
#define B_BNOT 24
#define B_LT   25
#define B_GT   26
#define B_EQ   27
#define B_LTE  28
#define B_GTE  29

#define B_PUSHDBL 30

#endif /* GETOP_H */
