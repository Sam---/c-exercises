.PHONY: all

OBJECTS := main.o tokenize.o vars.o stack.o execop.o getch.o 
CC := gcc
CFLAGS := \
    -std="c99" \
    -iquote'../sharedtools' \
    -pedantic -Werror -Wall -O1 -Wextra -Wno-parentheses \
    -Wno-char-subscripts -lm \

all: rpncalc

rpncalc: $(OBJECTS)
	$(CC) $(CFLAGS) ../sharedtools/shared.o $(OBJECTS)
