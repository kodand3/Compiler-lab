%option noyywrap
%{
    #include "y.tab.h"
%}

OP [*+-/()]
CHARACTER [a-zA-Z]
whitespace [ \t]+
NUMBER [0-9]

%%



{OP} {
  yylval.c=yytext[0];
  return yytext[0];
}

{CHARACTER} {
  yylval.c=yytext[0];
  return CHAR;
}

{NUMBER} {
    yylval.c = yytext[0];
    return CHAR;
}

[\n] {
  return NEWLINE;
}

{whitespace} { }
%%