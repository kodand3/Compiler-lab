/* Exercise - 2 */


%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
%}

%token LETTER DIGIT

%%

S : LETTER REST {printf("Variable detected\n");}
  ;

REST : LETTER { printf("Letter detected: %c\n", $1); } REST
     | DIGIT  { printf("Digit detected: %d\n", $1); } REST
     | /* epsilon */
     ;

%%

void yyerror(const char *s) {
    printf("Error Detected: %s\n", s);
}

int yylex() {
    int c;
    c = getchar();
        if (c == '\n' || c == EOF) { 
        return 0; 
    }
    while (c == ' ' || c == '\n') {
        c = getchar();
    }
    if (isdigit(c)) {
        yylval = c - '0';
        return DIGIT;
    }
    if (isalpha(c)) {
        yylval = c;
        return LETTER;
    }
    return c;
}

int main() {
    yyparse();
    return 0;
}
