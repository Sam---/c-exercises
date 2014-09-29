#/bin/sh

git add "$@"
git commit
gcc "$@" -o "a.out" -std="c89" -ansi -pedantic -Werror -Wall -g -O1 -Wextra
