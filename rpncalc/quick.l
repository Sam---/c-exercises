%{
#include "stack.h"
#include "main.h"
%}

%%

sin(e)? { push(sin(pop())); }
cos(ine)? { push(cos(pop())); }
tan(gent)? { push(tan(pop()));
// this is where I left off
}
[a-zA-Z_]+ { execop(yytext, yyleng); }
[-+*/&^%#@!~=<>?|]+ { execop(yytext, yyleng); }
-?[0-9,]+(\.[0-9,]+)?(e[-+]?[0-9]+)? { push(atof(yytext)); }
[\np] { return 1; }
\$[a-zA-Z_] { push(getvar(yytext[1])); }
\$>[a-zA-Z_] { putvar(yytext[2], pop()); }
. { printf("%d:%d: bad charecter in stream\n", lineno, colno); return 0; }

%%

void execop(char *text, size_t len) {
    switch (text[0]) {
        case 's':
            push(sin(pop()));
            break;
        case 'c':
            push


