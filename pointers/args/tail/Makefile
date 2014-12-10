CC := gcc
CFLAGS := -std=c99 -iquote'../../sharedtools' -pedantic -Werror -Wall \
	-Wextra -Wno-parentheses -Wno-char-subscripts -g

SRC := rotbuf.c tail.c
OBJ := $(SRC:.c=.o)

.PHONY: all clean

all: tail

clean:
	rm $(OBJ)

tail: $(OBJ)
	$(CC) $(CFLAGS) -o tail $(OBJ)

tail.o: tail.c rotbuf.h
	$(CC) $(CFLAGS) -c -o tail.o tail.c

rotbuf.o: rotbuf.c rotbuf.h
	$(CC) $(CFLAGS) -c -o rotbuf.o rotbuf.c

alt-tail: ntail.c
	$(CC) $(CFLAGS) -o alt-tail ntail.c
