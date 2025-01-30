%{
    #include <stdlib.h>
    #include <stdio.h>
    #include "codegen.h"

    int yylex(void);

    extern FILE *yyin;
%}

%union{
    struct tnode *no;
}

%type <no> expr program stmt slist inputstmt outputstmt assgstmt ifstmt whilestmt repeatstmt dowhilestmt
%token <no> NUM ID READ WRITE BREAK CONTINUE
%token PLUS MINUS MUL DIV END BEGIN1 LT GT LE GE NE EQ IF THEN ELSE ENDIF WHILE DO ENDWHILE REPEAT UNTIL

%left LT GT LE GE NE EQ
%left PLUS MINUS
%left MUL DIV

%%

program : BEGIN1 slist END ';' {
                printf("Prefix Tree:\n");
                printPrefix($2);
                printf("\n ----- Generating code ------\n");
                //evaluate($2);
                start();
                codegen($2);
                end();
                exit(0);
            }
        | BEGIN1 END ';' {
                exit(0);
            }
        ;

slist : slist stmt {
            $$ = createTreeNode(-1, TYPE_NONE, "", NODETYPE_CONNECT, $1, $2);
        }
      | stmt {
            $$ = $1;
        }
      ;

ifstmt : IF '(' expr ')' THEN slist ELSE slist ENDIF ';' {
            struct tnode* t = createTreeNode(-1, TYPE_NONE, "", NODETYPE_ELSE, $6, $8);
            $$ = createTreeNode(-1, TYPE_NONE, "", NODETYPE_IFELSE, $3, t);
        }
      | IF '(' expr ')' THEN slist ENDIF ';' {
            struct tnode* t = createTreeNode(-1, TYPE_NONE, "", NODETYPE_ELSE, $6, NULL);
            $$ = createTreeNode(-1, TYPE_NONE, "", NODETYPE_IFELSE, $3, $6);
        }
      ;

whilestmt : WHILE '(' expr ')' DO slist ENDWHILE ';' {
                $$ = createTreeNode(-1, TYPE_NONE, "", NODETYPE_WHILE, $3, $6);
            }
            ;

repeatstmt : REPEAT slist UNTIL '(' expr ')' ';'  {
                $$ = createTreeNode(-1, TYPE_NONE, "", NODETYPE_REPEAT, $2, $5);
            }
            ;

dowhilestmt : DO slist WHILE '(' expr ')' ';'	{
                $$ = createTreeNode(-1, TYPE_NONE, "", NODETYPE_DOWHILE, $2, $5);
            }
            ;


stmt : inputstmt	    { $$ = $1; }
       | outputstmt	    { $$ = $1; }
       | assgstmt	    { $$ = $1; }
       | ifstmt		    { $$ = $1; }
       | whilestmt	    { $$ = $1; }
       | BREAK ';'	    { $$ = $1; }
       | CONTINUE ';'	{ $$ = $1; }
       | repeatstmt	    { $$ = $1; }
       | dowhilestmt	{ $$ = $1; }
       ;


inputstmt : READ '(' ID ')' ';' {
                $$ = createTreeNode(-1, TYPE_NONE, "", NODETYPE_READ, $3, NULL);
            }
          ;

outputstmt : WRITE '(' expr ')' ';' {
                $$ = createTreeNode(-1, TYPE_NONE, "", NODETYPE_WRITE, $3, NULL);
            }
          ;

assgstmt : ID '=' expr ';' {
                $$ = createTreeNode(-1, TYPE_NONE, "", NODETYPE_ASSIGN, $1, $3);
            }
         ;

expr : expr PLUS expr {
            $$ = createTreeNode(-1, TYPE_INT, "", NODETYPE_ADD, $1, $3);
        }
     | expr MINUS expr {
            $$ = createTreeNode(-1, TYPE_INT, "", NODETYPE_SUB, $1, $3);
        }
     | expr MUL expr {
            $$ = createTreeNode(-1, TYPE_INT, "", NODETYPE_MUL, $1, $3);
        }
     | expr DIV expr {
            $$ = createTreeNode(-1, TYPE_INT, "", NODETYPE_DIV, $1, $3);
        }
     | expr LT expr {
            $$ = createTreeNode(-1, TYPE_BOOL, "", NODETYPE_LT, $1, $3);
        }
     | expr GT expr {
            $$ = createTreeNode(-1, TYPE_BOOL, "", NODETYPE_GT, $1, $3);
        }
     | expr GE expr {
            $$ = createTreeNode(-1, TYPE_BOOL, "", NODETYPE_GE, $1, $3);
        }
     | expr LE expr {
            $$ = createTreeNode(-1, TYPE_BOOL, "", NODETYPE_LE, $1, $3);
        }
     | expr NE expr {
            $$ = createTreeNode(-1, TYPE_BOOL, "", NODETYPE_NE, $1, $3);
        }
     | expr EQ expr {
            $$ = createTreeNode(-1, TYPE_BOOL, "", NODETYPE_EQ, $1, $3);
        }
     | '(' expr ')' {
            $$ = $2;
        }
     | NUM                   {$$ = $1;}
     | ID                    {$$ = $1;}
     ;

%%

int yyerror(char const *s)
{
    printf("yyerror %s", s);
}


int main(int argc, char* argv[]) {
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Error opening file");
        return 1;
    }

    yyparse();
    return 0;
}
