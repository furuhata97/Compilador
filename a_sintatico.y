%{
#include <cstdio>
#include <iostream>
#include <string>
#include <list>
#include <stdio.h>
#include <memory.h>
using namespace std;

// Declare stuff from Flex that Bison needs to know about:
int yylex(void);
extern int yyparse();
extern FILE *yyin;
 
void yyerror(const char *s);
%}


%union{
	char *s;
}

%token  <s> NUMBER
%token	ADD
%token	SUB
%token	MUL
%token	DIV
%token	WHILE
%token	<s> VAR
%token	DEF
%token  INT
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
%token  <s> COMMA
%token	<s> ID
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
%token <s> ATR
%token P_EQUAL
%token M_EQUAL
%token T_EQUAL
%token D_EQUAL
%token R_EQUAL
%token INTERROGATION

%type <s> listaSpecVars
%type <s> specVar
%type <s> specVarSimplesIni
%type <s> specVarSimples


%%
// This is the actual grammar that bison will parse, but for right now it's just
// something silly to echo to the screen what bison gets from flex.  We'll
// make a real one shortly:


decVar: VAR listaSpecVars COLON INT SEMICOLON {cout << "declaracao de variavel: " << $2 << endl;}
		| VAR listaSpecVars COLON INT SEMICOLON decVar {cout << "declaracao de variavel: " << $2 << endl;}
		|error decVar { yyerrok; yyclearin;printf("set error abourt!");}
	;

listaSpecVars: specVar {}
	| listaSpecVars COMMA specVar {char * str3 = (char *) malloc(1 + strlen($1)+ strlen($2)+ strlen($3) );
      strcpy(str3, $1);
      strcat(str3, $2);
      strcat(str3, $3);
      $$ = str3;}
	;

specVar: specVarSimples {}
	| specVarSimplesIni {}
	;

specVarSimples: ID {}
	;

specVarSimplesIni: ID ATR NUMBER {char * str3 = (char *) malloc(1 + strlen($1)+ strlen($2)+ strlen($3) );
      strcpy(str3, $1);
      strcat(str3, $2);
      strcat(str3, $3);
      $$ = str3;}
	;
%%

int main(int, char**) {
	// Open a file handle to a particular file:
	FILE *myfile = fopen("teste1.txt", "r");
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
	
}
