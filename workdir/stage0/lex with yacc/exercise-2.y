%{

    #include<stdio.h>
    #include<stdlib.h>

%}


%union{
    char c;
    char* string;
}

%token VARIABLE
%left '+' '-'
%left '*' '/'

%type <string> VARIABLE
%type <string> expr


%%

start : expr '\n' {printf("%c ", $<c>2);exit(0);}
;

expr  : expr '+' expr{printf("%c ", $<c>2);}|
        expr '-' expr{printf("%c ", $<c>2);}|
        expr '/' expr{printf("%c ", $<c>2);}|
        expr '*' expr{printf("%c ", $<c>2);}|
        VARIABLE{$<string>$ = $<string>1; printf("%s ", $<string>1);}

;


%%
int yyerror() {
    printf("\nInvalid Input!\n");
    return 0;
}

int main()
{
    printf("Enter: ");
    yyparse();
    return 0;
}