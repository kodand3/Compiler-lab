%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "task-1.h"
	
    int yylex(void);

    extern FILE *yyin;
%}

%union{
	struct tnode *no;	
}

%type <no> expr program stmt slist inputstmt outputstmt assgstmt
%token <no> NUM ID READ WRITE
%token PLUS MINUS MUL DIV END BEGIN1 

%left PLUS MINUS
%left MUL DIV

%%

program : BEGIN1 slist END ';'	{
				printPrefix($2);
				exit(0);
			}
	| BEGIN1 END ';'	{ exit(0); }
		;
		
slist : slist stmt	{$$=createTreeNode(-1, -1, "", NODETYPE_CONNECT, $1, $2);}
	| stmt		{$$ = $1;}
	;
	
stmt : inputstmt	{$$ = $1;}
       | outputstmt	{$$ = $1;}
       | assgstmt	{$$ = $1;}
       ;
 
inputstmt : READ '(' ID ')' ';' {$$=createTreeNode(-1,-1,"",NODETYPE_READ ,$3,NULL);}
		;
		
outputstmt : WRITE '(' expr ')' ';' {$$ = createTreeNode(-1,-1,"",NODETYPE_READ ,$3,NULL);}
	       ;

assgstmt : ID '=' expr ';' {$$ = createTreeNode(-1,-1,"",NODETYPE_ASSIGN ,$1,$3);}
	   ;

expr : expr PLUS expr		{$$ = createTreeNode(-1,-1,"",NODETYPE_ADD,$1,$3);}
	 | expr MINUS expr  	{$$ = createTreeNode(-1,-1,"",NODETYPE_SUB,$1,$3);}
	 | expr MUL expr	    {$$ = createTreeNode(-1,-1,"",NODETYPE_MUL,$1,$3);}
	 | expr DIV expr	    {$$ = createTreeNode(-1,-1,"",NODETYPE_DIV,$1,$3);}
	 | '(' expr ')'		    {$$ = $2;}
	 | NUM			        {$$ = $1;}
	 | ID			        {$$ = $1;}
	 ;

%%

int yyerror(char const *s)
{
    printf("yyerror %s",s);
}


int main(int argc,char* argv[]) {
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Error opening file");
        return 1;
    }

    yyparse();
	return 0;
}