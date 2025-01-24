%{

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int lvl = 0;

%}

%token DIGIT LETTER IF
%left '+' '-'
%left '*' '/'

%%
start : stmt '\n'{exit(1);};

stmt :  if_stmt{printf("IF seen\n");}| 
        stmt stmt |
        var '=' expr';'{printf("var = expr seen\n");}
;

if_stmt : IF '(' cond_stmt ')' '{' stmt '}' {
                                                 printf("IF level %d closed: \n", --lvl);
                                             }
;

cond_stmt : cond_stmt '&''&'  cond_stmt{printf("&& cond seen\n");}|
            cond_stmt '|''|' cond_stmt{printf("|| cond seen\n");}|
            expr '>' expr {printf("> cond seen\n");}|
            expr '<' expr {printf("< cond seen\n");}|
            expr '=''=' expr {printf("== cond seen\n");}
;

expr : expr '+' expr|
       expr '*' expr|
       expr '/' expr|
       expr '-' expr|
       '('expr')'|
       var {printf("var reduced to expr\n");}|
       num
;

var : var DIGIT|
      var LETTER|
      LETTER
;

num : num DIGIT|
      DIGIT
;

%%

int yyerror()
{
    printf("Error");
}

int yylex()
{
    int c;
    c = getchar();
    if (isdigit(c))
    {
        yylval = c - '0';
        return DIGIT;
    }

    if (isalpha(c))
    {

        if (c == '_')
            return LETTER;
        if (c == 'i')
        {
            c = getchar();
            if (c == 'f')
            {
                c = getchar();
                if (c == '(' || c == ' ')
                {
                    ungetc(c, stdin);
                    printf("IF level %d opened: \n", lvl++);

                    return IF;
                }
                else
                {
                    ungetc(c, stdin);
                    ungetc('f', stdin);
                    return LETTER;
                }
            }
            else
            {
                ungetc(c, stdin);
                return LETTER;
            }
        }
        return LETTER;
    }
    else if (c == ' ')
    {
        yylex(); /*This is to ignore whitespaces in the input*/
    }
    else
    {
        return c;
    }
}

int main()
{
    yyparse();
    return 1;
}