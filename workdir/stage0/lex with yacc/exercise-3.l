%{
    #include "y.tab.h"
    #include <string.h>
    #include <stdlib.h>
%}

%option noyywrap

OP [*+\-/()]
var [a-zA-Z0-9_]+
whitespace [ \t]

%%

{OP} {
    yylval.c = yytext[0];
    return yytext[0];
}

{var} {
    yylval.string = strdup(yytext);
    return VARIABLE;
}

[\n] {
    yylval.c = yytext[0];
    return yytext[0];
}

{whitespace} { }

. {
    printf("Unexpected character: %s\n", yytext);
}

%%

