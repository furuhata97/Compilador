%{
#include <cstdio>
#include <iostream>
using namespace std;

// Declare stuff from Flex that Bison needs to know about:
extern int yylex();
extern int yyparse();
extern FILE *yyin;
 
void yyerror(const char *s);
%}


%token NUMBER
%token	ADD
%token	SUB
%token	MUL
%token	DIV
%token	WHILE
%token	VAR
%token	DEF
%token 	INT
%token	BOOL
%token	FOR
%token	IF
%token	ELSE
%token	WRITE
%token	READ
%token	STRING
%token	O_PARENTHESIS
%token	C_PARENTHESIS
%token	O_BRACKETS
%token	C_BRACKETS
%token	O_BRACES
%token	C_BRACES
%token	SEMICOLON
%token	COLON
%token	COMMA
%token	ID
%token  TRUE_
%token  FALSE_
%token  RETURN
%token  SKIP
%token  STOP
%token PERCENT
%token EQUAL
%token NOT_EQUAL
%token GREATER
%token GREATER_EQUAL
%token LESS
%token LESS_EQUAL
%token OR
%token AND
%token NOT
%token ATR
%token P_EQUAL
%token M_EQUAL
%token T_EQUAL
%token D_EQUAL
%token R_EQUAL
%token INTERROGATION

%%
// This is the actual grammar that bison will parse, but for right now it's just
// something silly to echo to the screen what bison gets from flex.  We'll
// make a real one shortly:


decVar: VAR listaSpecVars COLON INT SEMICOLON { cout << "declaracao de variavel: " << $1 << endl;}
	;

listaSpecVars: specVar
	| listaSpecVars COMMA specVar
	;

specVar: specVarSimples
	| specVarSimplesIni
	;

specVarSimples: ID
	;

specVarSimplesIni: ID ATR NUMBER
	;
%%

int main(int, char**) {
	// Open a file handle to a particular file:
	FILE *myfile = fopen("texto.txt", "r");
	// Make sure it is valid:
	if (!myfile) {
		cout << "I can't open a.snazzle.file!" << endl;
		return -1;
	}
	// Set Flex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	
	// Parse through the input:
	yyparse();
	
	
}

void yyerror(const char *s) {
	cout << "EEK, parse error!  Message: " << s << endl;
	// might as well halt now:
	exit(-1);
}
