%{
    #include <stdlib.h>
    #include <stdio.h>
    #include "y.tab.h"
    #include "exprtree.h"

    

    int number;
    char* variable;

%}
num [0-9]
letter [a-zA-Z_]
%%

[0-9]+ {
    number = atoi(yytext); 
    yylval.node = createTree(number, INT_TYPE, NODE_NUM, NULL, NULL, NULL, NULL); 
    return NUM;}
  
"+" {return PLUS;}
"=" {return ASSIGN;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
"%" {return MOD;}

"==" {return EQ;}
"!=" {return NEQ;}
"<=" {return LEQ;}
"<"  {return LESS;}
">=" {return GEQ;}
">"  {return GREATER;}

"begin" {return START;}
"end"   {return END;}

"write" {return WRITE;}
"read"  {return READ;}

"if"    {return IF;}
"then"  {return THEN;}
"else"  {return ELSE;}
"endif" {return ENDIF;}

"while" {return WHILE;}
"do"    {return DO;}
"endwhile" {return ENDWHILE;}

"repeat" {return REPEAT;}
"until"  {return UNTIL;}

"break" {return BREAK;}
"continue" {return CONTINUE;}

"decl" {return DECL;}
"enddecl" {return ENDDECL;}

"int" {return INT;}
"str" {return STR;}

[ \t\n] {}
[();]   {return *yytext;}
[\[\]\,\&] {return *yytext;}


{letter}({letter}|{num})* {
    variable = (char*)malloc(sizeof(yytext));
    strcpy(variable, yytext);
    yylval.node = createTree(0, NO_TYPE, NODE_VAR, variable, NULL, NULL, NULL);
    return ID;
}

\"(\\.|[^\"])*\"    {
    char* str = (char*)malloc(sizeof(yytext));
    strcpy(str, yytext);
    yylval.node = createTree(0, STR_TYPE, NODE_STR, str, NULL, NULL, NULL);
    return STRING;
    }

. {
    printf("unknown character : %s\n", yytext);
    exit(1);
    }

%%

int yywrap(void) {
 return 1;
}
