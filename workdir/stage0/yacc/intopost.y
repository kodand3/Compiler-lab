%{

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void print_operator(char op);

int pos=0;

%}

%token DIGIT
%left '+'
%left '*'

%%
start : expr '\n'  {exit(1);}
      ;

expr: expr '+' expr     {print_operator('+');}
    | expr '*' expr     {print_operator('*');}
    | '(' expr ')'
    | DIGIT             {printf("NUM%d ",pos);}
    ;

%%

void print_operator(char c){
    switch(c){
        case '+'  : printf("PLUS ");
                    break;
        case '*'  : printf("MUL ");
                    break;
    }
    return;
}

int yyerror(char const *s)
{
    printf("yyerror %s",s);
}

int yylex(){
    char c;
    c = getchar();
        pos++;
    if(isdigit(c)){
        return DIGIT;
    }
    else if(c == ' '){
        yylex();         
    }
    else {
        return c;
    }
}

int main()
{
 yyparse();
 return 1;
}