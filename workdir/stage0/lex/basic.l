%option noyywrap

%{
    #include <stdio.h>
%}

number [0-9]+
op     [-|+|*|/|=]

%%
{number}  { 
    printf("Found : %d\n",atoi(yytext)); 
    printf("Number of digits = %d",yyleng);
}
{op}      { printf("operator\n"); }
%%

int main() {
    yylex();
    return 0;
}