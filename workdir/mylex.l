%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>

	int number_value; // To store the parsed numeric value
%}

number [0-9]+

%%
{number} { 
    number_value = atoi(yytext); // Convert lexeme to integer
    printf("Found: %d\n", number_value);
}
%%

int main() {
    yylex(); // Call the lexer to parse input

    // Use the parsed value
    if (number_value & 1) { // Check if odd
        printf("%d is odd\n", number_value);
    } else {
        printf("%d is even\n", number_value);
    }
	
    return 0; // Return success
}
