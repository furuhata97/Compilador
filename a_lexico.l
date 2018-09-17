%{
#include <iostream>
using namespace std;
extern "C" int yylex();
int lines = 0;
enum yytokentype{
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
};

int yylval;

%}
%%
while    { return WHILE; }
var      { return VAR; }
def      { return DEF; }
int      { return INT; }
bool     { return BOOL; }
true     { cout << "palavra reservada:" << yytext << endl; }
false    { cout << "palavra reservada:" << yytext << endl; }
for      { return FOR; }
if       { return IF; }
else     { return ELSE; }
write    { return WRITE; }
read     { return READ; }
return   { cout << "palavra reservada:" << yytext << endl; }
skip     { cout << "palavra reservada:" << yytext << endl; }
stop     { cout << "palavra reservada:" << yytext << endl; }
string   { return STRING; }
"("      { return O_PARENTHESIS; }
")"      { return C_PARENTHESIS; }
"["      { return O_BRACKETS; }
"]"      { return C_BRACKETS; }
"{"      { return O_BRACES; }
"}"      { return C_BRACES; }
","      { return COMMA; }
";"      { return SEMICOLON; }
"-"      { return SUB; }
"+"      { return ADD; }
"*"      { return MUL; }
"/"      { return DIV; }
"%"      { cout << "simbolo:" << yytext << endl; }
"=="     { cout << "simbolo:" << yytext << endl; }
"!="     { cout << "simbolo:" << yytext << endl; }
">"      { cout << "simbolo:" << yytext << endl; }
">="     { cout << "simbolo:" << yytext << endl; }
"<"      { cout << "simbolo:" << yytext << endl; }
"<="     { cout << "simbolo:" << yytext << endl; }
"||"     { cout << "simbolo:" << yytext << endl; }
"&&"     { cout << "simbolo:" << yytext << endl; }
"!"      { cout << "simbolo:" << yytext << endl; }
"="      { cout << "simbolo:" << yytext << endl; }
"+="     { cout << "simbolo:" << yytext << endl; }
"-="     { cout << "simbolo:" << yytext << endl; }
"*="     { cout << "simbolo:" << yytext << endl; }
"/="     { cout << "simbolo:" << yytext << endl; }
"%="     { cout << "simbolo:" << yytext << endl; }
"?"      { cout << "simbolo:" << yytext << endl; }
":"      { return COLON; }
\/\/.*   { cout << "comentario:" << yytext << endl; }
\"(\\.|[^"\\])*\"    { return STRING; }
\"(\\.|[^"\\])*$ { cout << "erro: string nao fechada" << " linha: " << lines+1 << endl; }
[ \t]          ;
\n {lines++;}
[0-9]{1,10}   { yylval = atoi(yytext); return NUMBER;}
[0-9]{10,}   { cout << "erro: inteiro com tamanho excessivo: " << yytext << endl; }
[0-9]+[a-zA-Z0-9_]*   { cout << "erro: identificador iniciou com numero: " << yytext << " linha: " << lines+1 << endl; }
[a-zA-Z_][a-zA-Z0-9_]* { return ID; }
.                { cout << "erro :" << yytext << " linha: " << lines+1 << endl; }
%%
int main(int, char**) {
	
	// open a file handle to a particular file:
	FILE *myfile = fopen("texto.txt", "r");
	// make sure it's valid:
	if (!myfile) {
		cout << "I can't open a.snazzle.file!" << endl;
		return -1;
	}
	// set lex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	
	// lex through the input:
	while(yylex());
	cout << "Total de linhas: " << lines << endl;
}
