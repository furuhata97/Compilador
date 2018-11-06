%code requires {
      #include <list>
      using namespace std;
}

%{
#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>


// Declare stuff from Flex that Bison needs to know about:
int yylex(void);
extern int yyparse();
extern FILE *yyin;
 
void yyerror(const char *s);
%}

%define parse.error verbose
%locations

%union{
	char *sval;
      int   ival;
      list<int*> *stmts;
}

%token	'('
%token	')'
%token	'['
%token	']'
%token	'{'
%token	'}'
%token	';'
%token      ','
%token      '='
%token      ADD_EQUAL "+="
%token      SUB_EQUAL "-="
%token      MUL_EQUAL "*="
%token      DIV_EQUAL "/="
%token      RES_EQUAL "%="
%right      '?' ':'
%token      OR "||"
%left       "||"
%token      AND "&&"
%left       "&&"
%token      EQUAL "==" NOT_EQUAL "!="
%left       "==" "!="
%token      '<' LESS_EQUAL "<=" '>' GREATER_EQUAL ">="
%left       '<' "<=" '>' ">="
%left 	'+' '-'
%left 	'*' '/' '%'
%right      '!'
%precedence NEG
%token      <ival> NUMBER
%token	WHILE
%token	VAR
%token	DEF
%token      INT
%token	BOOL
%token	FOR
%token	IF
%nonassoc   "then"
%nonassoc   ELSE
%token	WRITE
%token	READ
%token	STRING_TYPE
%token	<sval> STRING
%token	<sval> ID
%token      TRUE
%token      FALSE
%token      RETURN
%token      SKIP
%token      STOP
%token      ENDOFFILE


%start programa

%%
// This is the actual grammar that bison will parse

programa    : listaDec { }
	      ;


decSub      : decProc { }
		| decFunc { }
		;


listaDec    : dec { }
		| listaDec dec { }
		;

dec         : decVar { }
	      | decSub { }
	      ;

decVar      : VAR listaSpecVars ':' type ';' { }
	      | error ';' { cout << "declaração de variável inválida na linha " << @1.first_line << endl; }
            ;

listaSpecVars     : specVar { }
	            | listaSpecVars ',' specVar { }
	            | listaSpecVars specVar { } 
	            ;

specVar           : specVarSimples { }
	            | specVarSimplesIni { }
	            | specVarArranjo { }
	            | specVarArranjoIni { }
	            ;

specVarSimples    : ID
                  | error {cout << "Era esperado um identificador de variável na linha " << @1.first_line << " e coluna " << @1.first_column << endl;}
	            ;

specVarSimplesIni : ID '=' Exp { }
	            ;

specVarArranjo    : ID '[' Exp ']' { }
                  ;

specVarArranjoIni : ID '[' Exp ']' '=' '{' arranjo '}' { }
                  ;

arranjo           : Exp 
	            |arranjo ',' Exp { }
	   	      ;

variavel       : ID { }
                  | ID '[' Exp ']' { }

listaExp          : Exp
                  | listaExp ',' Exp { }
                  ;


Exp               : variavel { }
	            | NUMBER { }
	            | TRUE { }
	            | FALSE { }
	            | STRING { }
                  | Exp '+' Exp        { }
                  | Exp '-' Exp        { }
                  | Exp '*' Exp        { }
                  | Exp '/' Exp        { }
                  | Exp '%' Exp        { }
                  | '-' Exp  %prec NEG { }
                  | '!' Exp        { }
                  | '(' Exp ')'        { }
                  | Exp '?' Exp ':' Exp { }
                  | Exp '<' Exp        { }
                  | Exp "<=" Exp        { }
                  | Exp '>' Exp        { }
                  | Exp ">=" Exp        { }
                  | Exp "==" Exp        { }
                  | Exp "!=" Exp        { }
                  | Exp "&&" Exp        { }
                  | Exp "||" Exp        { }
                  | cmdChamadaFunc { }
                  ;



decProc           : DEF ID '(' ')' bloco { }
                  | DEF ID '(' listaParam ')' bloco { }
		      ;

decFunc           : DEF ID '(' ')' ':' type bloco { }
                  | DEF ID '(' listaParam ')' ':' type bloco { }
		      ;

listaParam 	      : specParams { }
			| listaParam ';' specParams { }
			;


specParams        : listaParams ':' type { } 
			;


listaParams       : param {}
		      | listaParams ',' param { }
		      ;

param             : ID { }
		      | ID '[' ']' { }
		      ;

bloco             : '{' listaDec listaCmd '}' { }
                  | '{' listaDec '}' { }
                  | '{' listaCmd '}' { }
                  | '{' '}' { }
                  ;
                  

listaCmd          : cmd {}
                  | listaCmd cmd { }
                  ;

cmd               : cmdSimples {}
                  | bloco {}
                  ;


cmdSimples        : cmdAtrib { }
                  | cmdIf { }
                  | cmdWhile { }
                  | cmdFor { }
                  | cmdStop { }
                  | cmdSkip { }
                  | cmdReturn { }
                  | cmdChamadaProc { }
                  | cmdRead { }
                  | cmdWrite { }
                  ;

cmdAtrib          : atrib ';' { }
                  ;

atrib             : variavel '=' Exp { }
                  | variavel "+=" Exp { }
                  | variavel "-=" Exp { }
                  | variavel "*=" Exp { }
                  |variavel "/=" Exp { }
                  | variavel "%=" Exp { }

cmdIf             : IF '(' Exp ')' cmd %prec "then" { }
                  | IF '(' Exp ')' cmd ELSE cmd { }
                  ;

cmdWhile          : WHILE '(' Exp ')' cmd { }
                  ;

cmdFor            : FOR '(' atrib ';' Exp ';' atrib ')' cmd { }
                  ;

cmdStop           : STOP ';' { }
                  ;

cmdSkip           : SKIP ';' { }
                  ;

cmdReturn         : RETURN ';' { }
                  | RETURN Exp ';' { }
                  ;

cmdChamadaProc    : ID '(' ')' ';' { }
                  | ID '(' listaExp ')' ';' { }
                  ;

cmdChamadaFunc    : ID '(' ')' { }
                  | ID '(' listaExp ')' { }
                  ;

cmdRead           : READ variavel ';' { }
                  ;

cmdWrite          : WRITE listaExp ';' { }
                  ;

type:             INT { } 
	            | STRING_TYPE { }
	            | BOOL { }
                  | STRING_TYPE '[' NUMBER ']' { }
	            ;
%%

int main(int, char**) {
	// Open a file handle to a particular file:
	FILE *myfile = fopen("teste1.grc", "r");
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

void yyerror (char const *msg) {
      cout << "\x1B[35mErro sintático - \x1B[37m " << msg << " na linha " << yylloc.first_line << " e coluna " << yylloc.first_column << endl;
      //fprintf(stderr,"\x1B[35mErro sintático : \x1B[37m%s Linha %d Coluna %d\n",msg, yylloc.first_line, yylloc.first_column);
}
