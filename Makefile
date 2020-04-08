make:
	bison -v --yacc --defines parser.y
	flex alpha_yylex.l
	gcc -Wall -g lex.yy.c y.tab.c table.c -o calc
clean:
	rm calc y.tab.c lex.yy.c y.tab.h 