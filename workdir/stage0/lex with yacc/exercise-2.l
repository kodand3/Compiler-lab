%{
    #include "y.tab.h"
%}

%option noyywrap

OP [*+-/()]
var [a-zA-Z0-9_]+
whitespace [ \t]

%%

{OP} {
    yylval.c=yytext[0];
    return yytext[0];
}
{var} {
    yylval.string=yytext;
    return VARIABLE;
}
[\n] {
    yylval.c=yytext[0];
    return yytext[0];
}

{whitespace} {}

%%