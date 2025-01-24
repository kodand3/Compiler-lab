%{


#include <stdlib.h>
#include <stdio.h>
#include "y.tab.h"

%}


upper [a-z]
lower [A-Z]

%%

({upper}|{lower}) {
                            yylval = *yytext;
                            return LETTER;
                             }

('+'|'-'|'*'|'/') {
                            printf("+");
                            yylval = *yytext;
                            return *yytext;
                    }   
("\n")                {
                            printf("newline seen\n");
                            return *yytext;
                }
%%

int yywrap(){
    return 1;
}