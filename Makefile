Yaccmake:
	yacc -d parser.y
	lex alpha_yylex.l
	gcc -Wall -g lex.yy.c y.tab.c table.c -o calc

