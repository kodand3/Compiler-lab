#!/bin/bash

yacc -d exprtree.y
lex exprtree.l
gcc -w lex.yy.c y.tab.c -o exprtree