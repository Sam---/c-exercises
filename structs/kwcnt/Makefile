CC := gcc
CFLAGS := -std=c99 -pedantic -Werror -Wall \
	-Wextra -Wno-parentheses -Wno-char-subscripts -g

SRC := kwcnt.c
OBJ := $(SRC:.c=.o)

.PHONY: all clean

all: kwcnt

clean:
	rm $(OBJ)

kwcnt: $(OBJ)
	$(CC) $(CFLAGS) -o kwcnt $(OBJ)

kwcnt.o: kwcnt.c
	$(CC) $(CFLAGS) -c -o kwcnt.o kwcnt.c
