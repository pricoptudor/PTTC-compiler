all:
	yacc -d limbaj.y
	lex limbaj.l
	
	gcc -w -g lex.yy.c y.tab.c -o limbaj
