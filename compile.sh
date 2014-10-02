#/bin/sh

git add "$@"
git commit
gcc "$@" \
    -o "a.out" -std="c89" -lm -iquote'../sharedtools'\
    -ansi -pedantic -Werror -Wall -g -O1 -Wextra
