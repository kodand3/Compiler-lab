/* Main */

/* 

%{
#include<stdio.h>
char *file1;
%}

%%
[0-9]+  printf("number");
%%

int yywrap()
{
    FILE *newfile_pointer;
    char *file2 = "file2";
    newfile_pointer = fopen("file2", "r");
    if (strcmp(file1, file2) != 0)
    {
        file1 = file2;
        yyin = newfile_pointer;
        return 0;
    }
    else
        return 1;
}

int main()
{
    file1 = "file1";
    yyin = fopen("file1", "r");
    yylex();
    return 1;
}

*/



/* Exercise - 1 */

/* 

%{
#include<stdio.h>
int visit = 0;
%}

%%
[0-9]+  printf("number");
%%

int yywrap()
{
    if(visit)
        return 1;
    visit = 1;
    FILE *newfile_pointer;
    newfile_pointer = fopen("file2", "r");
    yyin = newfile_pointer;
    return 0;
}

int main()
{
    yylex();
    return 1;
}

*/

/* Exercise - 2 */

/*

%{
#include<stdio.h>
int visit = 0;
%}

%%
[0-9]+  printf("number");
%%

int yywrap()
{
    if(visit)
        return 1;
    visit = 1;
    yyin = stdin;
    return 0;
}

int main()
{
    yyin = fopen("file1", "r");
    yylex();
    return 1;
}

*/


/* Exercise - 3 */

%{
   #include<stdio.h>
   #include<stdlib.h>
   int cnt;  // Counter to track the number of console reads
%}

%%

[0-9]+  { printf("number: %d\n", atoi(yytext)); }
(.)     { printf("Unaccounted %s\n", yytext); }

%%

int yywrap()
{
    if (cnt == 0) {  
        cnt++;
        printf("Enter input Second time:\n");
        close(fileno(stdin));         
        freopen("/dev/tty", "r", stdin); 
        yyin = stdin;           
        return 0;               
    }
    return 1;                  
}

int main()
{
    cnt = 0; 
    printf("Enter input First time:\n");
    yylex();               
    yylex();               
    return 0;
}