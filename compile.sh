#!/bin/sh

## git add "$@"
## lsinc -h -l "$@" | xargs git add
## git commit
gcc \
    -o "a.out" -std="c89" \
    -iquote'../sharedtools' \
    -ansi -pedantic -Werror -Wall -Wextra -Wno-parentheses \
    -Wno-char-subscripts \
    "$@" 
