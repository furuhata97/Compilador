%option noyywrap
%{
#include "a_sintatico.tab.h"
int lines = 0;
/*enum yytokentype{
	NUMBER = 258,
	ADD = 259,
	SUB = 260,
	MUL = 261,
	DIV = 262,
	WHILE = 263,
	VAR = 264,
	DEF = 265,
	INT = 266,
	BOOL = 267,
	FOR = 268,
	IF = 269,
	ELSE = 270,
	WRITE = 271,
	READ = 272,
	STRING = 273,
	O_PARENTHESIS = 274,
	C_PARENTHESIS = 275,
	O_BRACKETS = 276,
	C_BRACKETS = 277,
	O_BRACES = 278,
	C_BRACES = 279,
	SEMICOLON = 280,
	COLON = 281,
	COMMA = 282,
	ID = 283
};*/

%}


%%
while    { return WHILE; }
var      { yylval.s = strdup(yytext);
			return VAR; }
def      { return DEF; }
int      { return INT; }
bool     { return BOOL; }
true     { return FALSE_; }
false    { return TRUE_; }
for      { return FOR; }
if       { return IF; }
else     { return ELSE; }
write    { return WRITE; }
read     { return READ; }
return   { return RETURN; }
skip     { return SKIP; }
stop     { return STOP; }
string   { return STRING; }
"("      { return O_PARENTHESIS; }
")"      { return C_PARENTHESIS; }
"["      { return O_BRACKETS; }
"]"      { return C_BRACKETS; }
"{"      { return O_BRACES; }
"}"      { return C_BRACES; }
","      { yylval.s = strdup(yytext);
			return COMMA; }
";"      { return SEMICOLON; }
"-"      { return SUB; }
"+"      { return ADD; }
"*"      { return MUL; }
"/"      { return DIV; }
"%"      { return PERCENT; }
"=="     { return EQUAL; }
"!="     { return NOT_EQUAL; }
">"      { return GREATER; }
">="     { return GREATER_EQUAL; }
"<"      { return LESS; }
"<="     { return LESS_EQUAL; }
"||"     { return OR; }
"&&"     { return AND; }
"!"      { return NOT; }
"="      { yylval.s = strdup(yytext);
			return ATR; }
"+="     { return P_EQUAL; }
"-="     { return M_EQUAL; }
"*="     { return T_EQUAL; }
"/="     { return D_EQUAL; }
"%="     { return R_EQUAL; }
"?"      { return INTERROGATION; }
":"      { return COLON; }
\/\/.*   { }
\"(\\.|[^"\\])*\"    { return STRING; }
\"(\\.|[^"\\])*$ { perror( "erro: string nao fechada "); }
[ \t]          ;
\n {lines++;}
[0-9]{1,10}   { yylval.s = strdup(yytext);
				return NUMBER;}
[0-9]{10,}   { perror( "erro: inteiro com tamanho excessivo: "); }
[0-9]+[a-zA-Z0-9_]*   { perror( "erro: identificador iniciou com numero: "); }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.s = strdup(yytext);
			return ID; }
<<EOF>> {   perror( "erro: fim de arquivo");
            yyterminate();}
.                { perror( "erro: alguma coisa"); }
%%

