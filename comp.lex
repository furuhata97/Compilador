%option noyywrap
%{
#include <string>
#include <list>
#include "y.tab.h"
#include <iostream>
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
int      				{ return INT; }
bool     				{ return BOOL; }
true     				{ return FALSE; }
false    				{ return TRUE; }
for      				{ return FOR; }
if       				{ return IF; }
else     				{ return ELSE; }
write    				{ return WRITE; }
read     				{ return READ; }
return   				{ return RETURN; }
skip     				{ return SKIP; }
stop     				{ return STOP; }
string   				{ return STRING_TYPE; }
"("      				{ return '('; }
")"      				{ return ')'; }
"["      				{ return '['; }
"]"      				{ return ']'; }
"{"      				{ return '{'; }
"}"      				{ return '}'; }
","      				{ return ','; }
";"      				{ return ';'; }
"-"      				{ return '-'; }
"+"      				{ return '+'; }
"*"      				{ return '*'; }
"/"      				{ return '/'; }
"%"      				{ return '%'; }
"=="     				{ return EQUAL; }
"!="     				{ return NOT_EQUAL; }
">"      				{ return '>'; }
">="     				{ return GREATER_EQUAL; }
"<"      				{ return '<'; }
"<="     				{ return LESS_EQUAL; }
"||"     				{ return OR; }
"&&"     				{ return AND; }
"!"      				{ return '!'; }
"="      				{ return '='; }
"+="     				{ return ADD_EQUAL; }
"-="     				{ return SUB_EQUAL; }
"*="     				{ return MUL_EQUAL; }
"/="     				{ return DIV_EQUAL; }
"%="     				{ return RES_EQUAL; }
"?"      				{ return '?'; }
":"      				{ return ':'; }
\/\/.*   			   	{ }
\"(\\.|[^"\\])*\"      	{yylval.sval=strdup(yytext); return STRING; }
\"(\\.|[^"\\])*$ 	   	{  std::cerr << "\033[1;31mErro lexico - \033[0m" << "String não fechada na linha " << yylloc.first_line << " e coluna " << yylloc.first_column << std::endl; }
[ \t]                  	{  }
[\r\n|\n]              	{  }
[0-9]{1,10}            	{yylval.ival=atoi(yytext); return NUMBER;}
[0-9]{10,}             	{ std::cerr << "\033[1;31mErro lexico - \033[0m" << "Inteiro com tamanho excessivo na linha " << yylloc.first_line << " e coluna " << yylloc.first_column << std::endl; }
[0-9]+[a-zA-Z0-9_]*    	{ std::cerr << "\033[1;31mErro lexico - \033[0m" << "Identificador iniciando com número na linha " << yylloc.first_line << " e coluna " << yylloc.first_column << std::endl; }
[a-zA-Z_][a-zA-Z0-9_]* 	{yylval.sval=strdup(yytext); return ID; }
<<EOF>>    			   	{  yyterminate();
						 	//return ENDOFFILE;
					   	}
.                      	{ std::cerr << "\033[1;31mErro lexico - \033[0m" << "Foi encontrado na linha " << yylloc.first_line << " e coluna " << yylloc.first_column << " o caracter inesperado \"" << yytext << "\"" << std::endl;}
%%


