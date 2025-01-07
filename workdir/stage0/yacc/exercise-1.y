%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int nesting_level = 0; // To track nesting level
%}

/* Tokens */
%token IF ELSE LPAREN RPAREN LBRACE RBRACE SEMICOLON ASSIGN ID NUMBER RELOP

/* Precedence to resolve dangling else */
%nonassoc IFX
%nonassoc ELSE

%%

/* Grammar Rules */
program : stmt { printf("Valid IF statement with nesting level: %d\n", nesting_level); }
        ;

stmt : IF LPAREN condition RPAREN stmt %prec IFX
        { 
            nesting_level++;
            printf("Nesting Level: %d\n", nesting_level); 
        }
     | IF LPAREN condition RPAREN stmt ELSE stmt
        { 
            nesting_level++;
            printf("Nesting Level: %d\n", nesting_level); 
        }
     | ID ASSIGN expr SEMICOLON
        { 
            printf("Assignment detected.\n"); 
        }
     ;

condition : expr RELOP expr
          ;

expr : ID
     | NUMBER
     ;

%%

/* Error Handling */
void yyerror(const char *s) {
    printf("Error: %s\n", s);
}

/* Lexer */
int yylex() {
    int c;

    // Skip whitespace and newlines
    while ((c = getchar()) == ' ' || c == '\t' || c == '\n');

    // Parentheses, braces, and semicolons
    if (c == '(') return LPAREN;
    if (c == ')') return RPAREN;
    if (c == '{') return LBRACE;
    if (c == '}') return RBRACE;
    if (c == ';') return SEMICOLON;
    if (c == '=') return ASSIGN;

    // Relational operators
    if (c == '<' || c == '>' || c == '!') {
        int next = getchar();
        if (next == '=') return RELOP; // <=, >=, !=
        ungetc(next, stdin);
        return RELOP; // <, >, !=
    }

    // Identifiers (IDs)
    if (isalpha(c)) {
        while (isalnum(c)) c = getchar();
        ungetc(c, stdin);
        return ID;
    }

    // Numbers
    if (isdigit(c)) {
        while (isdigit(c)) c = getchar();
        ungetc(c, stdin);
        return NUMBER;
    }

    // Keywords: if, else
    if (c == 'i') {
        if (getchar() == 'f') return IF;
    }
    if (c == 'e') {
        if (getchar() == 'l' && getchar() == 's' && getchar() == 'e') return ELSE;
    }

    return c; // Return unmatched characters as-is
}

int main() {
    yyparse();
    return 0;
}
