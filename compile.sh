#/bin/sh

git add "$1"
git commit
gcc "$1" -o "a.out" -std="c89" -ansi -pedantic -Werror -Wall -g -O1 -Wextra
