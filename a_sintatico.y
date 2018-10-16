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
%token	<s> ADD
%token	<s> SUB
%token	<s> MUL
%token	<s> DIV
%token	WHILE
%token	<s> VAR
%token	<s> DEF
%token  <s> INT
%token	<s> BOOL
%token	FOR
%token	IF
%token	ELSE
%token	WRITE
%token	READ
%token	<s> STRING_TYPE
%token	<s> STRING
%token	<s> O_PARENTHESIS
%token	<s> C_PARENTHESIS
%token	<s> O_BRACKETS
%token	<s> C_BRACKETS
%token	<s> O_BRACES
%token	<s> C_BRACES
%token	<s> SEMICOLON
%token	<s> COLON
%token  <s> COMMA
%token	<s> ID
%token  <s> TRUE_
%token  <s> FALSE_
%token  RETURN
%token  SKIP
%token  STOP
%token  PERCENT
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
%token <s> ENDOFFILE

%type <s> listaSpecVars
%type <s> specVar
%type <s> specVarSimplesIni
%type <s> specVarSimples
%type <s> decVar
%type <s> error
%type <s> type
%type <s> Exp
%type <s> Factor
%type <s> Term
%type <s> specVarArranjo
%type <s> specVarArranjoIni
%type <s> arranjo
%type <s> decProc
%type <s> listaParam
%type <s> specParams
%type <s> bloco
%type <s> param
%type <s> listaDec
%type <s> dec
%type <s> decSub

%start programa

%%
// This is the actual grammar that bison will parse

programa  : listaDec
		  ;


decSub  : decProc 
		/*| decFunc*/
		;


listaDec : {$$="";}
		 |dec
		 | listaDec dec {char * str3 = (char *) malloc(1 + strlen($1)+ strlen($2));
      strcpy(str3, $1);
      strcat(str3, $2);
      $$ = str3;}
		 ;

dec : decVar
	| decSub
	;

decVar : VAR listaSpecVars COLON type SEMICOLON 
	   | error SEMICOLON { cout << "declaracao invalida" << endl; }
       ;

listaSpecVars: specVar { }
	| listaSpecVars COMMA specVar {char * str3 = (char *) malloc(1 + strlen($1)+ strlen($2)+ strlen($3) );
      strcpy(str3, $1);
      strcat(str3, $2);
      strcat(str3, $3);
      $$ = str3;}
	| listaSpecVars specVar {char * str3 = (char *) malloc(1 + strlen($1)+ strlen($2) );
      strcpy(str3, $1);
      strcat(str3, $2);
      $$ = str3; cout << "aviso! voce esqueceu uma virgula, mas ok..." << endl; } 
	;

specVar: specVarSimples { cout << "declaracao de variavel simples: " << $1 << endl; }
	| specVarSimplesIni { cout << "declaracao de variavel simples: " << $1 << endl; }
	| specVarArranjo { cout << "declaracao de variavel arranjo: " << $1 << endl; }
	| specVarArranjoIni { cout << "declaracao de variavel arranjo: " << $1 << endl; }
	;

specVarSimples: ID
	;

specVarSimplesIni: ID ATR Exp {char * str3 = (char *) malloc(1 + strlen($1)+ strlen($2)+ strlen($3) );
      strcpy(str3, $1);
      strcat(str3, $2);
      strcat(str3, $3);
      $$ = str3;}
	;

specVarArranjo: ID O_BRACKETS NUMBER C_BRACKETS {char * str3 = (char *) malloc(1 + strlen($1)+ strlen($2)+ strlen($3)+ strlen($4));
      strcpy(str3, $1);
      strcat(str3, $2);
      strcat(str3, $3);
      strcat(str3, $4);
      $$ = str3;}

specVarArranjoIni: ID O_BRACKETS NUMBER C_BRACKETS ATR O_BRACES arranjo C_BRACES {char * str3 = (char *) malloc(1 + strlen($1)+ strlen($2)+ strlen($3)+ strlen($4)+ strlen($5)+ strlen($6)+ strlen($7)+ strlen($8));
      strcpy(str3, $1);
      strcat(str3, $2);
      strcat(str3, $3);
      strcat(str3, $4);
      strcat(str3, $5);
      strcat(str3, $6);
      strcat(str3, $7);
      strcat(str3, $8);
      $$ = str3;}

arranjo: Exp 
	   |arranjo COMMA Exp {char * str3 = (char *) malloc(1 + strlen($1)+ strlen($2)+ strlen($3) );
      	strcpy(str3, $1);
      	strcat(str3, $2);
      	strcat(str3, $3);
      	$$ = str3;}
	   	;


Exp : Exp ADD Term {char * str3 = (char *) malloc(1 + strlen($1)+ strlen($2)+ strlen($3) );
      strcpy(str3, $1);
      strcat(str3, $2);
      strcat(str3, $3);
      $$ = str3;}
	|Exp SUB Term {char * str3 = (char *) malloc(1 + strlen($1)+ strlen($2)+ strlen($3) );
      strcpy(str3, $1);
      strcat(str3, $2);
      strcat(str3, $3);
      $$ = str3;}
	|Term

Term : Term MUL Factor {char * str3 = (char *) malloc(1 + strlen($1)+ strlen($2)+ strlen($3) );
      strcpy(str3, $1);
      strcat(str3, $2);
      strcat(str3, $3);
      $$ = str3;}
	 | Term DIV Factor {char * str3 = (char *) malloc(1 + strlen($1)+ strlen($2)+ strlen($3) );
      strcpy(str3, $1);
      strcat(str3, $2);
      strcat(str3, $3);
      $$ = str3;}
	 | Factor

Factor : ID 
	   | NUMBER
	   | TRUE_
	   | FALSE_
	   | STRING
	   |O_PARENTHESIS Exp C_PARENTHESIS {char * str3 = (char *) malloc(1 + strlen($1)+ strlen($2)+ strlen($3));
      strcpy(str3, $1);
      strcat(str3, $2);
      strcat(str3, $3);
      $$ = str3;}
	   |SUB Factor {char * str3 = (char *) malloc(1 + strlen($1)+ strlen($2));
      strcpy(str3, $1);
      strcat(str3, $2);
      $$ = str3;}


decProc : DEF ID O_PARENTHESIS listaParam C_PARENTHESIS bloco {cout << "Procedimento: " << $1 << " " << $2 << " " << $3 << " " << $4 << " " << $5
<< " " << $6;}
		;

listaParam 	: {$$="";} 
			|specParams { }
			| listaParam SEMICOLON specParams {char * str3 = (char *) malloc(1 + strlen($1)+ strlen($2)+ strlen($3));
      strcpy(str3, $1);
      strcat(str3, $2);
      strcat(str3, $3);
      $$ = str3; }
			;

specParams  : param COLON type {char * str3 = (char *) malloc(1 + strlen($1)+ strlen($2)+ strlen($3));
      strcpy(str3, $1);
      strcat(str3, $2);
      strcat(str3, $3);
      $$ = str3;} 
			| specParams COMMA param COLON type { char * str3 = (char *) malloc(1 + strlen($1)+ strlen($2)+ strlen($3)+ strlen($4)+ strlen($5));
      strcpy(str3, $1);
      strcat(str3, $2);
      strcat(str3, $3);
      strcat(str3, $4);
      strcat(str3, $5);
      $$ = str3;}
			;

param   : ID { }
		| ID O_BRACKETS C_BRACKETS {char * str3 = (char *) malloc(1 + strlen($1)+ strlen($2)+ strlen($3));
      strcpy(str3, $1);
      strcat(str3, $2);
      strcat(str3, $3);
      $$ = str3;}
		;

bloco : O_BRACES listaDec C_BRACES {char * str3 = (char *) malloc(1 + strlen($1)+ strlen($2)+ strlen($3));
      strcpy(str3, $1);
      strcat(str3, $2);
      strcat(str3, $3);
      $$ = str3;}

type: INT {cout << "TIPO: " << $1 << endl;}
	| STRING_TYPE {cout << "TIPO: " << $1 << endl;}
	| BOOL {cout << "TIPO: " << $1 << endl;}
	;
%%

int main(int, char**) {
	// Open a file handle to a particular file:
	FILE *myfile = fopen("teste1.txt", "r");
	// Make sure it is valid:
	if (!myfile) {
		cout << "I can't open the file!" << endl;
		return -1;
	}
	// Set Flex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	
	// Parse through the input:
	yyparse();
	
	
}

void yyerror(const char *s) {
	cout << "erro sintatico" << endl;
}
