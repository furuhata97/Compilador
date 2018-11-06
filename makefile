CCC = g++
CCFLAGS= -O2
LEX = flex
LFLAGS= -8     
YACC= bison 
YFLAGS= -d -t -y

RM = /bin/rm -f

comp: y.tab.o lex.yy.o comp.o
	${CCC} ${CCFLAGS} lex.yy.o y.tab.o comp.o -o comp -lfl

comp.o: comp.cpp comp.h
	${CCC} -c comp.cpp
y.tab.o: comp.yacc
	${YACC} ${YFLAGS} comp.yacc
	${CCC} ${CCFLAGS} y.tab.c -c 

lex.yy.o: comp.lex
	${LEX} $(LFLAGS) comp.lex
	${CCC} ${CCFLAGS} lex.yy.c -c 

clean:
	/bin/rm -f lex.yy.* y.tab.* *.o comp
