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
"if"	    { return IF; }
"then"	    { return THEN; }
"while"	    {return WHILE;}
"do"	    {return DO;}
"endif"	    {return ENDIF;}
"else"	    {return ELSE;}
"endwhile"  {return ENDWHILE;}

[a-z]   {
    yylval.no = createTreeNode(-1, TYPE_INT, yytext, NODETYPE_ID, NULL, NULL); 
    return ID;
}
[0-9]+	{
    number = atoi(yytext); 
    yylval.no = createTreeNode(number, TYPE_INT, "", NODETYPE_NUM, NULL, NULL); 
    return NUM;
}

"+"	    {return PLUS;}
"-"	    {return MINUS;}
"*"	    {return MUL;}
"/"	    {return DIV;}
">"	    {return GT;}
"<"	    {return LT;}
">="	{return GE;}
"<="	{return LE;}
"!="	{return NE;}
"=="	{return EQ;}

[ \t\n]	{ /* Ignore whitespaces */ }
[()=;]	{ return *yytext; }

%%

int yywrap(void) {
    return 1;
}