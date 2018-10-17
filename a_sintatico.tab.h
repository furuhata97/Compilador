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
    INTERROGATION = 263,
    COLON = 264,
    NEG = 265,
    WHILE = 266,
    VAR = 267,
    DEF = 268,
    INT = 269,
    BOOL = 270,
    FOR = 271,
    IF = 272,
    ELSE = 273,
    WRITE = 274,
    READ = 275,
    STRING_TYPE = 276,
    STRING = 277,
    O_PARENTHESIS = 278,
    C_PARENTHESIS = 279,
    O_BRACKETS = 280,
    C_BRACKETS = 281,
    O_BRACES = 282,
    C_BRACES = 283,
    SEMICOLON = 284,
    COMMA = 285,
    ID = 286,
    TRUE_ = 287,
    FALSE_ = 288,
    RETURN = 289,
    SKIP = 290,
    STOP = 291,
    PERCENT = 292,
    EQUAL = 293,
    NOT_EQUAL = 294,
    GREATER = 295,
    GREATER_EQUAL = 296,
    LESS = 297,
    LESS_EQUAL = 298,
    OR = 299,
    AND = 300,
    NOT = 301,
    ATR = 302,
    P_EQUAL = 303,
    M_EQUAL = 304,
    T_EQUAL = 305,
    D_EQUAL = 306,
    R_EQUAL = 307,
    ENDOFFILE = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "a_sintatico.y" /* yacc.c:1909  */

	char *s;

#line 112 "a_sintatico.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_A_SINTATICO_TAB_H_INCLUDED  */
