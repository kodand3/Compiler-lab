%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "codegen.h"
    
	int yylex(void);
%}

%union{
	struct tnode *no;
}

%type <no> expr NUM program END
%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%

program : expr END	{
                        FILE *fptr = fopen("target.xsm", "w");
                        fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
                        int i = codegen($1, fptr);
                        printConsole(i, fptr);
                        printf("Answer : %d\n", evaluate($1));
                        exit(1);
			}
		;

expr : PLUS expr expr		{$$ = makeOperatorNode('+', $2, $3);}
	 | MINUS expr expr  	{$$ = makeOperatorNode('-' ,$2, $3);}
	 | MUL expr expr		{$$ = makeOperatorNode('*', $2, $3);}
	 | DIV expr expr		{$$ = makeOperatorNode('/', $2, $3);}
	 | '(' expr ')'			{$$ = $2;}
	 | NUM					{$$ = $1;}
	 ;

%%

int yyerror(char const *s)
{
    printf("yyerror : %s",s);
}


int main(void) {
	yyparse();
	
	return 0;
}