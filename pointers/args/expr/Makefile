CC := gcc
CFLAGS := -std=c99 -iquote'../../sharedtools' -pedantic -Werror -Wall \
	-Wextra -Wno-parentheses -Wno-char-subscripts -Os

SRC := main.c prsr.c stack.c error.c
OBJ := $(SRC:.c=.o)

.PHONY: all clean

clean:
	rm $(OBJ)

all: expr

expr: $(OBJ)
	$(CC) $(CFLAGS) -o expr $(OBJ)

main.o: main.c prsr.h stack.h error.h
	$(CC) $(CFLAGS) -c -o main.o main.c

prsr.o: prsr.c prsr.h stack.h
	$(CC) $(CFLAGS) -c -o prsr.o prsr.c

stack.o: stack.c stack.h error.h
	$(CC) $(CFLAGS) -c -o stack.o stack.c

error.o: error.c error.h
	$(CC) $(CFLAGS) -c -o error.o error.c

