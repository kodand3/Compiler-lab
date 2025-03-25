yacc -d exprtree.y
lex exprtree.l
gcc lex.yy.c y.tab.c -o ans
rm lex.yy.c y.tab.c y.tab.h