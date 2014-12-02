CC := gcc
CFLAGS := -std=c99 -iquote'../../sharedtools' -pedantic -Werror -Wall \
	-Wextra -Wno-parentheses -Wno-char-subscripts -g

a.out: sort.o ../../sharedtools/mygetline.h
	$(CC) $(CFLAGS) sort.o
