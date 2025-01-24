/* Exercise - a */

/*

%{
    #include <stdio.h>
    int wordCount, lineCount;
    int map[256] = {0};
%}

digit [0-9]
lower [a-z]
upper [A-Z]
floating {digit}+\.{digit}+
newline \n
op     [-|+|*|/|=]
word ({digit}|{lower}|{upper}|\/)+

%%
{newline} {
    lineCount++;
}
{word} {
    for(int i = 0;i < yyleng;i++) {
        map[yytext[i]] = 1;
    }
    wordCount++;
}
%%

int yywrap() {
    printf("\nTotal words = %d\n", wordCount);
    printf("Total lines = %d\n", lineCount);
    int chars = 0;
    for(int i = 0;i < 256;i++)
        chars += map[i];
    printf("Total characters = %d", chars);
    return 1;
}

int main() {
    wordCount = 0, lineCount = 0;
    yylex();
    return 0;
}

*/

/* Exercise - b */

/*

%{
    #include <stdio.h>
    int numCount, floatCount;
%}

digit [0-9]
number {digit}+
lower [a-z]
upper [A-Z]
floating {digit}+\.{digit}+
op     [-|+|*|/|=]

%%
{number}  { 
    printf("Found : %d",atoi(yytext)); 
    numCount++;
}
{op}      { printf("operator"); }
{floating} {
    printf("Found : %s", yytext);
    floatCount++;
}
(.)   printf("Unrecognized input: %s", yytext);
%%

int yywrap() {
    printf("Total numbers = %d\n", numCount);
    printf("Total flaoting numbers = %d", floatCount);
    return 1;
}

int main() {
    numCount = 0, floatCount = 0;
    yylex();
    return 0;
}

*/


/* Exercise - c */

/*

%{
    #include <stdio.h>
    int cnt;
%}

digit [0-9]
lower [a-z]
upper [A-Z]
number {digit}+
floating {digit}+\.{digit}+
identifier ({lower}|{upper})+({lower}|{upper}|{digit})*
op     [-|+|*|/|=]


%%
{number}  { 
    printf("Found : %d",atoi(yytext)); 
}
{op}      { printf("operator"); }
{floating} {
    printf("Found : %s", yytext);
}
{identifier} {
    if(yyleng == 3 && yytext[0] == 'A')
        cnt++;
}
[ \t]+ ;
(.)   printf("Unrecognized input: %s", yytext);

%%

int yywrap() {
    printf("Total words of length three, starting with A = %d\n", cnt);
    return 1;
}

int main() {
    cnt = 0;
    yylex();
    return 0;
}

*/


/* Exercise - d */

%{
    #include<stdio.h>
    #include<ctype.h>
%}

lower    [a-z]
upper    [A-Z]
number [0-9]

%option noyywrap

%%
("//")(.)*       {printf("single line comment:%s\n", yytext);}
("/*")({lower}|{upper}|{number}|"\n"|" ")*("*/") {printf("multiline comment:%s\n", yytext);}
%%

int main()
{
  yylex();
  return 0;
}


