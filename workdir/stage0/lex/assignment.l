%{
    #include<stdio.h>
    #include<ctype.h>
    int num;
%}


%option noyywrap

%%

"1" {
        printf("one ");
}

"2" {
    printf("two ");
}

"+" {
    printf("plus ");
}



%%

int main()
{
  yylex();
  return 0;
}