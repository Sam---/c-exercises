#/bin/sh

git add "$@"
lsinc -h -l "$@" | xargs git add
git commit
gcc \
    -o "a.out" -std="c99" \
    -iquote'../sharedtools' \
    -ansi -pedantic -Werror -Wall -g -O1 -Wextra -Wno-parentheses \
    -Wno-char-subscripts -lm $CFLAGS \
    ../sharedtools/shared.o \
    "$@" 
