
all: parser

OBJS = parser.o  \
       lexer.o  \


clean:
	$(RM) -rf parser.cpp parser.hpp parser lexer.cpp $(OBJS)

parser.cpp: parser.y
	bison -d -v -o $@ $^
	
parser.hpp: parser.cpp

lexer.cpp: lexer.l parser.hpp
	flex -o $@ $^

%.o: %.cpp
	g++ -c -o $@ $<


parser: $(OBJS)
	g++ -o $@ $(OBJS)
