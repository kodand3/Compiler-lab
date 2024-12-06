rm lexer lex.yy.c
lex usinglex.l
gcc lex.yy.c -o lexer
./lexer

