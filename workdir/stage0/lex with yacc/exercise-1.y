%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%union {
    char c;
}

%token CHAR
%token NEWLINE

%type <c> CHAR


%left '+' '-'
%left '*' '/'

%%

start: expr NEWLINE {printf("\n");exit(0);}
     ;

expr: expr '*' expr {printf("MUL ");}
    | expr '-' expr {printf("%c", $<c>2);}
    | expr '+' expr {printf("PLUS ");}
    | expr '/' expr {printf("%c", $<c>2);}
    | '(' expr ')' {}
    | CHAR {
        if( $<c>1 == '1' ){
            printf("ONE ");
        }
        else if( $<c>1 == '2' ){
            printf("TWO ");
        }
        else if( $<c>1 == '3' ){
            printf("THREE ");
        }
        else if($<c>1 == '+'){
            printf("Other char is : %c", $<c>1);
        }
    }
    ;

%%

int yyerror() {
    printf("\nInvalid Input!\n");
    return 0;
}

int main() {
    printf("\nEnter:");
    yyparse();
    return 0;
}
