%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include "exprtree.h"
    #include "symbol_table.c"
    #include "exprtree.c"
    #include "codegen.c"
    #include "evaluator.c"
    
    extern FILE* yyin;
    FILE* fileptr;

    int decl_type;
    int yylex(void);
    
%}

%union{
    struct tnode *node;
}

%token START END READ WRITE PLUS MINUS MUL DIV ASSIGN NUM ID IF THEN ELSE ENDIF WHILE DO ENDWHILE LESS LEQ GREATER GEQ NEQ EQ BREAK CONTINUE REPEAT UNTIL DECL ENDDECL INT STR STRING
%left LESS LEQ GREATER GEQ NEQ EQ
%left PLUS MINUS
%left MUL DIV 
%left MOD
%type <node> START END ID NUM STRING
%type <node> program slist stmt inputstmt outputstmt asgstmt expr ifstmt whilestmt breakstmt continuestmt repeatsmt decllist declarations decl type varlist varassg

%%

program : START declarations slist END ';'{
    $$ = $4;
    fprintf(fileptr, "MOV SP, %d\n", 4095 + data_size);
    codeGen($3, fileptr);
    exitProgram(fileptr);
    PrintSymbolTable();
    exit(0);
}
   | START declarations END ';' {
    $$ = $3;
    exit(0);
}
;
 
declarations : DECL decllist ENDDECL {}
    | DECL ENDDECL {}
;

decllist : decllist decl | decl {}
;

decl : type varlist ';' {}
;

type : INT {decl_type = INT_TYPE;}
    | STR   {decl_type = STR_TYPE;}
;

varlist : varlist ',' ID {Install($3->varname, decl_type, 1, -1);}
    | ID {Install($1->varname, decl_type, 1, -1);} 
    | varlist ',' ID '[' NUM ']' {Install($3->varname, decl_type, $5->val, -1);}
    | ID '[' NUM ']' {Install($1->varname, decl_type, $3->val, -1);}
    | varlist ',' ID '[' NUM ']' '[' NUM ']' {Install($3->varname, decl_type, $5->val * $8->val, $8->val);}
    | ID '[' NUM ']' '[' NUM ']' {Install($1->varname, decl_type, $3->val * $6->val, $6->val);}
    | varlist ',' MUL ID {Install($4->varname, (decl_type == INT_TYPE) ? INT_PTR : STR_PTR, 1, -1);}
    | MUL ID {Install($2->varname, (decl_type == INT_TYPE) ? INT_PTR : STR_PTR, 1, -1);}
    
;

slist : slist stmt {$$ = createTree(0, NO_TYPE, NODE_CONNECTOR, NULL, $1, $2,NULL);}
    | stmt {$$ = $1;}
;

stmt : inputstmt {$$ = $1;}
    | outputstmt {$$ = $1;}
    | asgstmt    {$$ = $1;}
    | ifstmt     {$$ = $1;}
    | whilestmt  {$$ = $1;}
    | breakstmt  {$$ = $1;}
    | continuestmt {$$ = $1;}
    | repeatsmt {$$ = $1;}
;

repeatsmt : REPEAT slist UNTIL '(' expr ')'';' {$$ = createTree(0, NO_TYPE, NODE_REPEAT, NULL, $2, $5, NULL);}
;

breakstmt : BREAK ';' {$$ = createTree(0, NO_TYPE, NODE_BREAK, NULL, NULL, NULL, NULL);}
;

continuestmt : CONTINUE ';' {$$ = createTree(0, NO_TYPE, NODE_CONTINUE, NULL, NULL, NULL, NULL);}
;

ifstmt : IF '('expr')' THEN slist ELSE slist ENDIF ';'{$$ = createTree(0, NO_TYPE, NODE_IFELSE, NULL, $6, $8, $3);}
    |IF '('expr')' THEN slist ENDIF ';'{$$ = createTree(0, NO_TYPE, NODE_IFTHEN, NULL, $6, NULL, $3);}
;

whilestmt : WHILE '(' expr ')' DO slist ENDWHILE ';'{$$ = createTree(0, NO_TYPE, NODE_WHILEDO, NULL, $3, $6, NULL);}
    | DO slist WHILE '(' expr ')' ';' {$$ = createTree(0, NO_TYPE, NODE_DOWHILE, NULL, $2, $5, NULL);}
;

inputstmt : READ '(' varassg ')' ';' {$$ = createTree(0, NO_TYPE, NODE_READ, NULL, $3, NULL, NULL);}
;

outputstmt : WRITE'(' expr ')' ';' {$$ = createTree(0, NO_TYPE, NODE_WRITE, NULL, $3, NULL, NULL);}
;

asgstmt : varassg ASSIGN expr ';' {$$ = createTree(0, NO_TYPE, NODE_ASSG, NULL, $1, $3, NULL);}
;

expr : expr PLUS expr {$$ = createTree(0, INT_TYPE, NODE_PLUS, NULL, $1, $3, NULL);}
  | expr MINUS expr   {$$ = createTree(0, INT_TYPE, NODE_MINUS, NULL, $1, $3, NULL);}
  | expr MUL expr {$$ = createTree(0, INT_TYPE, NODE_MUL, NULL, $1, $3, NULL);}
  | expr DIV expr {$$ = createTree(0, INT_TYPE, NODE_DIV, NULL, $1, $3, NULL);}
  | expr MOD expr {$$ = createTree(0, INT_TYPE, NODE_MOD, NULL, $1, $3, NULL);}
  | expr LESS expr {$$ = createTree(0, BOOL_TYPE, NODE_L, NULL, $1, $3, NULL);}
  | expr GREATER expr {$$ = createTree(0, BOOL_TYPE, NODE_G, NULL, $1, $3, NULL);}
  | expr LEQ expr{$$ = createTree(0, BOOL_TYPE, NODE_LE, NULL, $1, $3, NULL);}
  | expr GEQ expr{$$ = createTree(0, BOOL_TYPE, NODE_GE, NULL, $1, $3, NULL);}
  | expr NEQ expr{$$ = createTree(0, BOOL_TYPE, NODE_NE, NULL, $1, $3, NULL);}
  | expr EQ expr{$$ = createTree(0, BOOL_TYPE, NODE_E, NULL, $1, $3, NULL);}
  | ID '[' expr ']'{
    struct Gsymbol* entry = Lookup($1->varname);
    $1->type = entry->type;
    $1->Gentry = entry;
    $$ = createTree(0, $1->type, NODE_ARRAY, NULL, $1, $3, NULL);}
  | ID '[' expr ']' '[' expr ']' {
    struct Gsymbol* entry = Lookup($1->varname);
    $1->type = entry->type;
    $1->Gentry = entry;
    $$ = createTree(0, $1->type, NODE_ARRAY, NULL, $1, $3, $6);}
  | ID {
    struct Gsymbol* entry = Lookup($1->varname);
    if(entry->type == INT_PTR || entry->type == STR_PTR)
        $1->type = INT_TYPE;
    else
        $1->type = entry->type;
    $1->Gentry = entry;
    $$ = $1;}
  | MUL ID {
    struct Gsymbol* entry = Lookup($2->varname);
    $$ = createTree(0, entry->type == STR_PTR ? STR_TYPE : INT_TYPE, NODE_DEREF, NULL, $2, NULL, NULL);
    }
  | '&' ID {
    struct Gsymbol* entry = Lookup($2->varname);
    $$ = createTree(0, INT_TYPE, NODE_ADDR, NULL, $2, NULL, NULL);   
  }
  | STRING {$$ = $1;}
  | NUM    {$$ = $1;}
  ;

varassg : ID {
    struct Gsymbol* entry = Lookup($1->varname);
    $$ = createTree(0, (entry->type == INT_PTR || entry->type == STR_PTR) ? INT_TYPE : entry->type, NODE_VARASSG, $1->varname, $1, NULL, NULL);
    }
    | ID '[' expr ']'{
    struct Gsymbol* entry = Lookup($1->varname);
    $$ = createTree(0, entry->type, NODE_VARASSG, $1->varname, $1, $3, NULL);
    }
    | ID '[' expr ']' '[' expr ']'{
    struct Gsymbol* entry = Lookup($1->varname);
    $$ = createTree(0, entry->type, NODE_VARASSG, $1->varname, $1, $3, $6);             
    }
    | MUL ID {
    struct Gsymbol* entry = Lookup($2->varname);
    $$ = createTree(0, entry->type, NODE_DERASSG,$2->varname, $2, NULL, NULL);          
    }
;
%%
void yyerror(char const *s)
{
    printf("yyerror %s",s);
}


int main(void) {

    fileptr = fopen("test.xsm", "w+");
    fprintf(fileptr, "0\n2056\n0\n0\n0\n0\n0\n0\n"); 
    yyparse();

    return 0;
}
