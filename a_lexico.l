%option noyywrap
%{
#include "a_sintatico.tab.h"
int lines = 0;
%}


%%
while    { return WHILE; }
var      { yylval.s = strdup(yytext);
		   return VAR; }
def      {  yylval.s = strdup(yytext);
			return DEF; }
int      { yylval.s = strdup(yytext);
		   return INT; }
bool     { yylval.s = strdup(yytext);
		   return BOOL; }
true     {  yylval.s = strdup(yytext);
			return FALSE_; }
false    {  yylval.s = strdup(yytext);
			return TRUE_; }
for      { return FOR; }
if       { return IF; }
else     { return ELSE; }
write    { return WRITE; }
read     { return READ; }
return   { return RETURN; }
skip     { return SKIP; }
stop     { return STOP; }
string   { yylval.s = strdup(yytext);
		   return STRING_TYPE; }
"("      {  yylval.s = strdup(yytext);
			return O_PARENTHESIS; }
")"      {  yylval.s = strdup(yytext);
			return C_PARENTHESIS; }
"["      {  yylval.s = strdup(yytext);
			return O_BRACKETS; }
"]"      {  yylval.s = strdup(yytext);
			return C_BRACKETS; }
"{"      {  yylval.s = strdup(yytext);
			return O_BRACES; }
"}"      {  yylval.s = strdup(yytext);
			return C_BRACES; }
","      { yylval.s = strdup(yytext);
		   return COMMA; }
";"      {  yylval.s = strdup(yytext);
			return SEMICOLON; }
"-"      {  yylval.s = strdup(yytext);
			return SUB; }
"+"      {  yylval.s = strdup(yytext);
			return ADD; }
"*"      {  yylval.s = strdup(yytext);
			return MUL; }
"/"      {  yylval.s = strdup(yytext);
			return DIV; }
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
":"      {  yylval.s = strdup(yytext);
			return COLON; }
\/\/.*   			   { }
\"(\\.|[^"\\])*\"      {yylval.s = strdup(yytext); 
						return STRING; }
\"(\\.|[^"\\])*$ 	   { perror( "erro: string nao fechada "); }
[ \t]                  { };
[\r\n|\n]              {lines++;}
[0-9]{1,10}            { yylval.s = strdup(yytext);
				         return NUMBER;}
[0-9]{10,}             { perror( "erro: inteiro com tamanho excessivo: "); }
[0-9]+[a-zA-Z0-9_]*    { perror( "erro: identificador iniciou com numero: "); }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.s = strdup(yytext);
						 return ID; }
<<EOF>>    			   {   
						 yyterminate();
						 //yylval.s = strdup(yytext);
						 //return ENDOFFILE;
					   }
.                      { 
			             perror( "erro: alguma coisa");
		               }
%%

