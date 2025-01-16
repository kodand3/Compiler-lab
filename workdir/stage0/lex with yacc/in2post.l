%{
    #include <stdio.h>
    #include "y.tab.h"
    extern int yylval;
%}

%%

[0-9]+ {
          yylval = atoi(yytext);
          return DIGIT;
        }
"+"   return *yytext;
"-"   return *yytext;
[()]   return *yytext;
[\n]      return NEWLINE;

%%

int yywrap()
{
 return 1;
}
