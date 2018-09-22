a_sintatico.tab.c a_sintatico.tab.h: a_sintatico.y
	bison -d a_sintatico.y

lex.yy.c: a_lexico.l a_sintatico.tab.h
	flex a_lexico.l

run: lex.yy.c a_sintatico.tab.c a_sintatico.tab.h
	g++ a_sintatico.tab.c lex.yy.c -lfl -o executavel
