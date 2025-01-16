%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
int yyerror(const char *s);
%}

%token IF
%token ELSE
%token ID
%token NUM

%left ELSE

%%
program
    : stmt_list
      {
        printf("Parsing complete.\n");
      }
    ;

stmt_list
    : stmt_list stmt
    | stmt
    ;

stmt
    : if_stmt
    | ID
    ;

if_stmt
    : IF '(' condition ')' stmt
    | IF '(' condition ')' stmt ELSE stmt
    ;

condition
    : ID
    ;

%%

int main()
{
    printf("Enter your input:\n");
    yyparse();
    return 0;
}

int yyerror(const char *s)
{
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}
