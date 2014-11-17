.PHONY: all

OBJECTS := swap.o
CC := gcc
CFLAGS := \
    -std="c99" \
    -iquote'../sharedtools' \
    -pedantic -Werror -Wall -O2 -Wextra -Wno-parentheses \
    -Wno-char-subscripts

all: test

test: $(OBJECTS)
	$(CC) $(CFLAGS) -o test $(OBJECTS) ../sharedtools/shared.o 
