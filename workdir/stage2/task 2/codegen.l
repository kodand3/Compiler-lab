%{
    #include <stdlib.h>
    #include <stdio.h>
    #include "y.tab.h"
    #include "codegen.h"

    int number;
    void yyerror(char const *);
%}

%%
"begin"     { return BEGIN1;}
"end"       { return END;}
"read"      { return READ;}
"write"     { return WRITE;}

[a-z]   {
    yylval.no = createTreeNode(-1,-1,yytext,NODETYPE_ID,NULL,NULL); 
    return ID;
}
[0-9]+	{
    number = atoi(yytext); 
    yylval.no = createTreeNode(number,-1, "", NODETYPE_NUM,NULL,NULL); 
    return NUM;
}
"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
[ \t\n]	{}
[()=;]	{ return *yytext; }

%%

int yywrap(void) {
    return 1;
}