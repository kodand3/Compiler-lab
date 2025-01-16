%option noyywrap
%{
    #include "y.tab.h"
%}

OP [*+-/()]
CHARACTER [a-zA-Z]
whitespace [ \t]+

%%
{OP} {
  yylval.c=yytext[0];
  return yytext[0];
}

{CHARACTER} {
  yylval.c=yytext[0];
  return CHAR;
}

[\n] {
  return NEWLINE;
}

{whitespace} { }
%%