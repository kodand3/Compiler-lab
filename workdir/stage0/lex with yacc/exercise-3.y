%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>

    char *concatante(char* str0, char* str1, char* str2);
%}

%union {
    char c;
    char* string;
}

%token <string> VARIABLE

%type <string> expr

%left '+' '-'
%left '*' '/'

%type <string> expr

%%

start : expr '\n' {
            printf("final answer : %s\n", $<string>1);
            exit(0);
        }
;

expr : expr '+' expr {
            $<string>$ = concatante("+", $<string>1, $<string>3);
        } |
        expr '-' expr {
            $<string>$ = concatante("-", $<string>1, $<string>3);
        } |
        expr '*' expr {
            $<string>$ = concatante("*", $<string>1, $<string>3);
        } |
        expr '/' expr {
            $<string>$ = concatante("/", $<string>1, $<string>3);
        } |
        '(' expr ')' {
            $<string>$ = $<string>2;
        } |
        VARIABLE {
            $<string>$ = strdup($<string>1);
        }
;

%%

char *concatante(char* str0, char* str1, char* str2) {
    int len = 2 + strlen(str0) + strlen(str1) + strlen(str2);
    char *ans = (char*)malloc(len);

    strcpy(ans, str0);
    strcat(ans, " ");
    strcat(ans, str1);
    strcat(ans, " ");
    strcat(ans, str2);

    return ans;
}

int yyerror() {
    printf("\nInvalid Input!\n");
    return 0;
}

int main() {
    printf("Enter: ");
    yyparse();
    return 0;
}
