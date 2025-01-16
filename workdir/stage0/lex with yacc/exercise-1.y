%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%union {
    char c;
}

%token CHAR
%token NEWLINE

%type <c> CHAR


%left '+' '-'
%left '*' '/'

%%

start: expr NEWLINE {printf("\n");exit(0);}
     ;

expr: expr '*' expr {printf("%c", $<c>2);}
    | expr '-' expr {printf("%c", $<c>2);}
    | expr '+' expr {printf("%c", $<c>2);}
    | expr '/' expr {printf("%c", $<c>2);}
    | '(' expr ')' {}
    | CHAR {printf("%c", $<c>1);}
    ;

%%

int yyerror() {
    printf("\nInvalid Input!\n");
    return 0;
}

int main() {
    printf("\nEnter:");
    yyparse();
    return 0;
}
