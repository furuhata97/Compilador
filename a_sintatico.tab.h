/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_A_SINTATICO_TAB_H_INCLUDED
# define YY_YY_A_SINTATICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    STRING_TYPE = 273,
    STRING = 274,
    O_PARENTHESIS = 275,
    C_PARENTHESIS = 276,
    O_BRACKETS = 277,
    C_BRACKETS = 278,
    O_BRACES = 279,
    C_BRACES = 280,
    SEMICOLON = 281,
    COLON = 282,
    COMMA = 283,
    ID = 284,
    TRUE_ = 285,
    FALSE_ = 286,
    RETURN = 287,
    SKIP = 288,
    STOP = 289,
    PERCENT = 290,
    EQUAL = 291,
    NOT_EQUAL = 292,
    GREATER = 293,
    GREATER_EQUAL = 294,
    LESS = 295,
    LESS_EQUAL = 296,
    OR = 297,
    AND = 298,
    NOT = 299,
    ATR = 300,
    P_EQUAL = 301,
    M_EQUAL = 302,
    T_EQUAL = 303,
    D_EQUAL = 304,
    R_EQUAL = 305,
    INTERROGATION = 306,
    ENDOFFILE = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "a_sintatico.y" /* yacc.c:1909  */

	char *s;

#line 111 "a_sintatico.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_A_SINTATICO_TAB_H_INCLUDED  */
