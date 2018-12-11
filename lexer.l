%option noyywrap
%{
#include "nodes.h"
#include <string>
#include <list>
#include "parser.hpp"
#include <iostream>
#include <stack>
#define SAVE_TOKEN  yylval.id = new std::string(yytext, yyleng)
/* This is executed before every action. */
#define YY_USER_ACTION                                                  	\
	yylloc.first_line = yylloc.last_line;                      \
	yylloc.first_column = yylloc.last_column;                  \
	if (yylloc.first_line == yylineno)                         \
		yylloc.last_column += yyleng;                           \
	else {                                                     \
		int col;                                                \
		for (col = 1; yytext[yyleng - col] != '\n'; ++col) {}   \
		yylloc.last_column = col;                               \
		yylloc.last_line = yylineno;                            \
	}
%}

%option yylineno

%%

while    				{ return WHILE; }
var      				{ return VAR; }
def      				{ return DEF; }
int      				{ SAVE_TOKEN; return INT; }
bool     				{ SAVE_TOKEN; return BOOL; }
true     				{ SAVE_TOKEN; return FALSE; }
false    				{ SAVE_TOKEN; return TRUE; }
for      				{ return FOR; }
if       				{ return IF; }
else     				{ return ELSE; }
write    				{ return WRITE; }
read     				{ return READ; }
return   				{ return RETURN; }
skip     				{ return SKIP; }
stop     				{ return STOP; }
string   				{ SAVE_TOKEN; return STRING_TYPE; }
"("      				{ return '('; }
")"      				{ return ')'; }
"["      				{ return '['; }
"]"      				{ return ']'; }
"{"      				{ return '{'; }
"}"      				{ return '}'; }
","      				{ return ','; }
";"      				{ return ';'; }
"-"      				{ SAVE_TOKEN; return '-'; }
"+"      				{ SAVE_TOKEN; return '+'; }
"*"      				{ SAVE_TOKEN; return '*'; }
"/"      				{ SAVE_TOKEN; return '/'; }
"%"      				{ SAVE_TOKEN; return '%'; }
"=="     				{ SAVE_TOKEN; return EQUAL; }
"!="     				{ SAVE_TOKEN; return NOT_EQUAL; }
">"      				{ SAVE_TOKEN; return '>'; }
">="     				{ SAVE_TOKEN; return GREATER_EQUAL; }
"<"      				{ SAVE_TOKEN; return '<'; }
"<="     				{ SAVE_TOKEN; return LESS_EQUAL; }
"||"     				{ SAVE_TOKEN; return OR; }
"&&"     				{ SAVE_TOKEN; return AND; }
"!"      				{ return '!'; }
"="      				{ SAVE_TOKEN; return '='; }
"+="     				{ SAVE_TOKEN; return ADD_EQUAL; }
"-="     				{ SAVE_TOKEN; return SUB_EQUAL; }
"*="     				{ SAVE_TOKEN; return MUL_EQUAL; }
"/="     				{ SAVE_TOKEN; return DIV_EQUAL; }
"%="     				{ SAVE_TOKEN; return RES_EQUAL; }
"?"      				{ return '?'; }
":"      				{ return ':'; }
\/\/.*   			   	{ }
\"(\\.|[^"\\])*\"      	{SAVE_TOKEN; return STRING; }
\"(\\.|[^"\\])*$ 	   	{  std::cerr << "\033[1;31mErro lexico - \033[0m" << "String não fechada na linha " << yylloc.first_line << " e coluna " << yylloc.first_column << std::endl; }
[ \t]                  	{  }
[\r\n|\n]              	{  }
[0-9]{1,10}            	{SAVE_TOKEN; return NUMBER;}
[0-9]{10,}             	{ std::cerr << "\033[1;31mErro lexico - \033[0m" << "Inteiro com tamanho excessivo na linha " << yylloc.first_line << " e coluna " << yylloc.first_column << std::endl; }
[0-9]+[a-zA-Z0-9_]*    	{ std::cerr << "\033[1;31mErro lexico - \033[0m" << "Identificador iniciando com número na linha " << yylloc.first_line << " e coluna " << yylloc.first_column << std::endl; SAVE_TOKEN; return T_INV; }
[a-zA-Z_][a-zA-Z0-9_]* 	{SAVE_TOKEN; return ID; }
<<EOF>>    			   	{  yyterminate();
						 	//return ENDOFFILE;
					   	}
.                      	{ std::cerr << "\033[1;31mErro lexico - \033[0m" << "Foi encontrado na linha " << yylloc.first_line << " e coluna " << yylloc.first_column << " o caracter inesperado \"" << yytext << "\"" << std::endl;}
%%


