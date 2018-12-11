

%{
#include "nodes.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>
#include <cstdlib>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;

pgm *root;





// Declare stuff from Flex that Bison needs to know about:
extern int yylex();
extern int yyparse();
extern FILE *yyin;
 
void yyerror(const char *s);
%}

%define parse.error verbose
%locations

%union{
  int *num;
  std::string *id;
  Dec *dec;
  list<Dec *> *decs;
  list<Var *> *vars;
  Var *var;
  DecVar *decVar;
  pgm *prog;
  Type *t;
  Exp *exp;
  list<Exp *> *exps;
  Params *pars;
  list<Params *> *params;
  Param *param;
  list<Param *> *par;
  Bloco *bloco;
  Cmd *cmd;
  list<Cmd *> *cmds;

}

%token	    '('
%token	    ')'
%token	    '['
%token	    ']'
%token	    '{'
%token	    '}'
%token	    ';'
%token      ','
%token      <id> '='
%token      <id> ADD_EQUAL "+="
%token      <id> SUB_EQUAL "-="
%token      <id> MUL_EQUAL "*="
%token      <id> DIV_EQUAL "/="
%token      <id> RES_EQUAL "%="
%right      '?' ':'
%token      <id> OR "||"
%left       "||"
%token      <id> AND "&&"
%left       "&&"
%token      <id> EQUAL "==" NOT_EQUAL "!="
%left       "==" "!="
%token      <id> '<' LESS_EQUAL "<=" '>' GREATER_EQUAL ">="
%left       '<' "<=" '>' ">="
%left 	    <id> '+' '-'
%left 	    <id> '*' '/' '%'
%right      '!'
%precedence NEG
%token      <id> NUMBER
%token	    WHILE
%token	    <id> VAR
%token	    DEF
%token      <id> INT
%token	    <id> BOOL
%token	    FOR
%token	    IF
%nonassoc   "then"
%nonassoc   ELSE
%token	    WRITE
%token	    READ
%token	    <id> STRING_TYPE
%token	    <id> STRING
%token	    <id> ID
%token      <id> TRUE
%token      <id> FALSE
%token      RETURN
%token      SKIP
%token      STOP
%token      ENDOFFILE
%token      <id> T_INV

%type <decs> listaDec
%type <dec> dec decSub decProc decFunc
%type <decVar> decVar
%type <vars> listaSpecVars
%type <var> specVar specVarSimples specVarSimplesIni specVarArranjo specVarArranjoIni
%type <prog> programa
%type <t> type
%type <exp> variavel Exp cmdChamadaFunc
%type <exps> listaExp
%type <params> listaParam
%type <pars> specParams
%type <par> listaParams
%type <param> param
%type <bloco> bloco
%type <cmds> listaCmd
%type <cmd> cmd cmdSimples cmdAtrib atrib cmdIf cmdFor cmdWhile cmdStop cmdSkip cmdReturn cmdRead cmdWrite cmdChamadaProc
%type <id> error


%start programa

%%
// Gramática

programa    : listaDec {root = new pgm($1);}
	          ;


listaDec    : dec {$$ = new list<Dec *>(); $$->push_back($1);}
		        | listaDec dec {$$ = $1; $1->push_back($2);}
		        ;

dec         : decVar { $$ = $1;}
	          | decSub { $$ = $1; }
            | error { $$ = nullptr;}
	          ;

decVar      : VAR listaSpecVars ':' type ';' {$$ = new DecVar($2, $4);}
            | error ';' { cout << "declaração de variável inválida na linha " << @1.first_line << endl; }
            | VAR listaSpecVars ':' error ';' {cout << "\x1B[35mErro sintático - \x1B[37m foi declarado o tipo " << *$4 << " que não existe na linha " << yylloc.first_line << " e coluna " << yylloc.first_column << endl;}
            ;

decSub      : decProc { $$ = $1; }
		        | decFunc { $$ = $1; }
		        ;

listaSpecVars : specVar {$$ =  new list<Var *>(); $$->push_back($1);}
	            | listaSpecVars ',' specVar {$$ = $1; $1->push_back($3);}
	            | listaSpecVars specVar { cout << "Aviso: Linha " << @1.first_line << " coluna " << @1.first_column << ". Era esperado uma ',' mas ok" << endl; $$ = $1; $1->push_back($2);}
	            ;

specVar       : specVarSimples {$$ = $1;}
	            | specVarSimplesIni {$$ = $1;}
	            | specVarArranjo {$$ = $1;}
	            | specVarArranjoIni {$$ = $1;}
	            ;

specVarSimples    : ID {$$ = new VarSimples($1, @1.first_line);}
                  | error {$$ = nullptr; cout << "\x1B[35mErro sintático - \x1B[37m: Era esperado um identificador de variável na linha " << @1.first_line << " e coluna " << @1.first_column << endl;}
	                ;

specVarSimplesIni : ID '=' Exp {$$ = new VarSimplesIni($1, $3, @1.first_line);}
                  | ID '=' error {cout << "\x1B[35mErro sintático - \x1B[37m: Era esperado uma expressão na linha " << @1.first_line << " e coluna " << @1.first_column << endl;}
                  | error '=' Exp {cout << "\x1B[35mErro sintático - \x1B[37m: Era esperado um identificador na linha " << @1.first_line << " e coluna " << @1.first_column << endl;}
	                ;

specVarArranjo    : ID '[' NUMBER ']' {$$ = new VarArranjo($1, atoi($3->c_str()), @1.first_line);}
                  | ID '[' error ']' {cout << "\x1B[35mErro sintático - \x1B[37m: tamanho de um arranjo deve ser um literal numérico. " << @1.first_line << " e coluna " << @1.first_column << endl;}
                  | error '[' NUMBER ']' {cout << "\x1B[35mErro sintático - \x1B[37m: Era esperado um identificador na linha " << @1.first_line << " e coluna " << @1.first_column << endl;}
                  ;

specVarArranjoIni : ID '[' NUMBER ']' '=' '{' listaExp '}' {$$ = new VarArranjoIni($1, atoi($3->c_str()), $7, @1.first_line);}
                  | ID '[' error ']' '=' '{' listaExp '}' {cout << "\x1B[35mErro sintático - \x1B[37m: tamanho de um arranjo deve ser um literal numérico. " << @1.first_line << " e coluna " << @1.first_column << endl;}
                  | error '[' NUMBER ']' '=' '{' listaExp '}' {cout << "\x1B[35mErro sintático - \x1B[37m: Era esperado um identificador na linha " << @1.first_line << " e coluna " << @1.first_column << endl;}
                  | ID '[' NUMBER ']' '=' '{' error '}' {cout << "\x1B[35mErro sintático - \x1B[37m: Era esperado um identificador na linha " << @1.first_line << " e coluna " << @1.first_column << endl;}
                  ;

listaExp          : Exp {$$ =  new list<Exp *>(); $$->push_back($1);}
                  | listaExp ',' Exp {$$ = $1; $1->push_back($3);}
                  ;

variavel          : ID {$$ = new VarDecSimples($1);}
                  | ID '[' Exp ']' {$$ = new VarDecArranjo($1, $3);}


Exp               : variavel {$$ = $1;}
	                | NUMBER { $$ = new Number_node(atoi($1->c_str())); }
	                | TRUE {$$ = new Literal($1);}
	                | FALSE {$$ = new Literal($1);}
	                | STRING {$$ = new Literal($1);}
                  | Exp '+' Exp        {$$ = new BinaryExpression($1, $3, $2);}
                  | Exp '-' Exp        {$$ = new BinaryExpression($1, $3, $2);}
                  | Exp '*' Exp        {$$ = new BinaryExpression($1, $3, $2);}
                  | Exp '/' Exp        {$$ = new BinaryExpression($1, $3, $2);}
                  | Exp '%' Exp        {$$ = new BinaryExpression($1, $3, $2);}
                  | '-' Exp  %prec NEG {$$ = new NegExpression($2);}
                  | '!' Exp        {$$ = new NotExpression($2);}
                  | '(' Exp ')'        { $$ = $2;}
                  | Exp '?' Exp ':' Exp {$$ = new TernaryExpression($1, $3, $5);}
                  | Exp '<' Exp        {$$ = new BinaryExpression($1, $3, $2);}
                  | Exp "<=" Exp        {$$ = new BinaryExpression($1, $3, $2);}
                  | Exp '>' Exp        {$$ = new BinaryExpression($1, $3, $2);}
                  | Exp ">=" Exp        {$$ = new BinaryExpression($1, $3, $2);}
                  | Exp "==" Exp        {$$ = new BinaryExpression($1, $3, $2);}
                  | Exp "!=" Exp        {$$ = new BinaryExpression($1, $3, $2);}
                  | Exp "&&" Exp        {$$ = new BinaryExpression($1, $3, $2);}
                  | Exp "||" Exp        {$$ = new BinaryExpression($1, $3, $2);}
                  | cmdChamadaFunc {$$ = $1;}
                  ;

decProc           : DEF ID '(' ')' bloco { $$ = new ProcSimples($2, $5); }
                  | DEF ID '(' listaParam ')' bloco { $$ = new ProcIni($2, $4, $6); }
                  | DEF ID '(' error ')' bloco { cout << "Erro sintático: Parâmetros inválidos na linha " << @4.first_line << " e coluna " << @4.first_column << endl; }
		              ;

decFunc           : DEF ID '(' ')' ':' type bloco { $$ = new FuncSimples($2, $6, $7); }
                  | DEF ID '(' listaParam ')' ':' type bloco { $$ = new FuncIni($2, $4, $7, $8); }
                  | DEF ID '(' error ')' type bloco { cout << "Erro sintático: Parâmetros inválidos na linha " << @4.first_line << " e coluna " << @4.first_column << endl; }
		              ;

listaParam 	      : specParams {$$ =  new list<Params *>(); $$->push_back($1);}
			            | listaParam ';' specParams {$$ = $1; $1->push_back($3);}
			            ;


specParams        : listaParams ':' type {$$ = new Params($1, $3);} 
			            ;


listaParams       : param {$$ =  new list<Param *>(); $$->push_back($1);}
		              | listaParams ',' param {$$ = $1; $1->push_back($3);}
		              ;

param             : ID {$$ = new ParamSimples($1);}
		              | ID '[' ']' {$$ = new ParamArranjo($1);}
		              ;

bloco             : '{' listaDec listaCmd '}' {$$ = new Bloco($2, $3);}
                  | '{' listaDec '}' {$$ = new Bloco($2, NULL);}
                  | '{' listaCmd '}' {$$ = new Bloco(NULL, $2);}
                  | '{' '}' {$$ = new Bloco(NULL, NULL);}
                  ;
                  

listaCmd          : cmd {$$ =  new list<Cmd *>(); $$->push_back($1);}
                  | listaCmd cmd {$$ = $1; $1->push_back($2);}
                  ;

cmd               : cmdSimples {$$ = $1;}
                  | bloco {$$ = $1;}
                  ;


cmdSimples        : cmdAtrib {$$ = $1;}
                  | cmdIf {$$ = $1;}
                  | cmdWhile {$$ = $1;}
                  | cmdFor {$$ = $1;}
                  | cmdStop {$$ = $1;}
                  | cmdSkip {$$ = $1;}
                  | cmdReturn {$$ = $1;}
                  | cmdChamadaProc {$$ = $1;}
                  | cmdRead {$$ = $1;}
                  | cmdWrite {$$ = $1;}
                  ;

cmdAtrib          : atrib ';' {$$ = $1;}
                  ;

atrib             : variavel '=' Exp {$$ = new Atrib($1, $3, $2, @1.first_line);}
                  | variavel "+=" Exp {$$ = new Atrib($1, $3, $2, @1.first_line);}
                  | variavel "-=" Exp {$$ = new Atrib($1, $3, $2, @1.first_line);}
                  | variavel "*=" Exp {$$ = new Atrib($1, $3, $2, @1.first_line);}
                  |variavel "/=" Exp {$$ = new Atrib($1, $3, $2, @1.first_line);}
                  | variavel "%=" Exp {$$ = new Atrib($1, $3, $2, @1.first_line);}

cmdIf             : IF '(' Exp ')' cmd %prec "then" {$$ = new CmdIf($3, $5, @3.first_line);}
                  | IF '(' Exp ')' cmd ELSE cmd {$$ = new CmdIfElse($3, $5, $7, @3.first_line);}
                  | IF '(' error ')' cmd %prec "then" { cout << "Erro no if" << endl; }
                  | IF '(' error ')' cmd ELSE cmd { cout << "Erro no if" << endl; }
                  ;

cmdWhile          : WHILE '(' Exp ')' cmd {$$ = new CmdWhile($3, $5, @3.first_line);}
                  | WHILE '(' error ')' cmd { cout << "Erro no while" << endl;}
                  ;

cmdFor            : FOR '(' atrib ';' Exp ';' atrib ')' cmd {$$ = new CmdFor($3, $5, $7, $9, @1.first_line);}
                  | FOR '(' error ')' cmd { cout << "Erro no for" << endl;}
                  ;

cmdStop           : STOP ';' {$$ = new CmdStop(@1.first_line);}
                  ;

cmdSkip           : SKIP ';' {$$ = new CmdSkip(@1.first_line);}
                  ;

cmdReturn         : RETURN ';' {$$ = new CmdReturn(NULL, @1.first_line);}
                  | RETURN Exp ';' {$$ = new CmdReturn($2, @3.first_line);}
                  ;

cmdChamadaProc    : ID '(' ')' ';' {$$ = new ChamadaProc($1, nullptr, @1.first_line);}
                  | ID '(' listaExp ')' ';' {$$ = new ChamadaProc($1, $3, @1.first_line);}
                  ;

cmdChamadaFunc    : ID '(' ')' {$$ = new ChamadaFunc($1, nullptr);}
                  | ID '(' listaExp ')' {$$ = new ChamadaFunc($1, $3);}
                  ;

cmdRead           : READ variavel ';' {$$ = new CmdRead($2, @2.first_line);}
                  ;

cmdWrite          : WRITE listaExp ';' {$$ = new CmdWrite($2, @2.first_line);}
                  ;

type              : INT { $$ = new TypeInt($1);} 
	                | STRING_TYPE { $$ = new TypeString($1);}
	                | BOOL {$$ = new TypeBool($1);}
                  | STRING_TYPE '[' NUMBER ']' { $$ = new TypeString($1, atoi($3->c_str()));}
	            ;
%%


main(int argc, char** argv) {
  char* fileName = argv[1];

  if (argc <= 1) {
    cout << "Please, define a file name in the first parameter.\n" << endl;
  }

  //tabelaDeSimbolos->push(global);

	// Open a file handle to a particular file:
	FILE *myfile = fopen(fileName, "r");
	// Make sure it is valid:
	if (!myfile) {
		cout << "Não eh possivel abrir o arquivo!" << endl;
		return -1;
	}
	// Set Flex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	
	// Parse through the input:
	yyparse();
  
  //for_each (root->listDec->begin(), root->listDec->end(), decVerification);

  root->traducao();
}

void yyerror (char const *msg) {
      cout << "\x1B[35mErro sintático - \x1B[37m " << msg << " na linha " << yylloc.first_line << " e coluna " << yylloc.first_column << endl;
      //fprintf(stderr,"\x1B[35mErro sintático : \x1B[37m%s Linha %d Coluna %d\n",msg, yylloc.first_line, yylloc.first_column);
}
