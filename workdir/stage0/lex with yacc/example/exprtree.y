%{
#include <stdlib.h>
#include <stdio.h>
#include "exprtree.h"

int yylex(void);
%}

%union {
    struct tnode *no;
}

%type <no> expr NUM program END
%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%

program : expr END {
             printf("Answer: %d\n", evaluate($1));
             exit(0);
         }
         ;

expr    : expr PLUS expr   { $$ = makeOperatorNode('+', $1, $3); }
        | expr MINUS expr  { $$ = makeOperatorNode('-', $1, $3); }
        | expr MUL expr    { $$ = makeOperatorNode('*', $1, $3); }
        | expr DIV expr    { $$ = makeOperatorNode('/', $1, $3); }
        | '(' expr ')'     { $$ = $2; }
        | NUM              { $$ = $1; }
        ;

%%

void yyerror(char const *s) {
    printf("yyerror: %s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}
