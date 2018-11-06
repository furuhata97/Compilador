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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "comp.yacc" /* yacc.c:1909  */

      #include <list>
      using namespace std;

#line 49 "y.tab.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ADD_EQUAL = 258,
    SUB_EQUAL = 259,
    MUL_EQUAL = 260,
    DIV_EQUAL = 261,
    RES_EQUAL = 262,
    OR = 263,
    AND = 264,
    EQUAL = 265,
    NOT_EQUAL = 266,
    LESS_EQUAL = 267,
    GREATER_EQUAL = 268,
    NEG = 269,
    NUMBER = 270,
    WHILE = 271,
    VAR = 272,
    DEF = 273,
    INT = 274,
    BOOL = 275,
    FOR = 276,
    IF = 277,
    ELSE = 279,
    WRITE = 280,
    READ = 281,
    STRING_TYPE = 282,
    STRING = 283,
    ID = 284,
    TRUE = 285,
    FALSE = 286,
    RETURN = 287,
    SKIP = 288,
    STOP = 289,
    ENDOFFILE = 290
  };
#endif
/* Tokens.  */
#define ADD_EQUAL 258
#define SUB_EQUAL 259
#define MUL_EQUAL 260
#define DIV_EQUAL 261
#define RES_EQUAL 262
#define OR 263
#define AND 264
#define EQUAL 265
#define NOT_EQUAL 266
#define LESS_EQUAL 267
#define GREATER_EQUAL 268
#define NEG 269
#define NUMBER 270
#define WHILE 271
#define VAR 272
#define DEF 273
#define INT 274
#define BOOL 275
#define FOR 276
#define IF 277
#define ELSE 279
#define WRITE 280
#define READ 281
#define STRING_TYPE 282
#define STRING 283
#define ID 284
#define TRUE 285
#define FALSE 286
#define RETURN 287
#define SKIP 288
#define STOP 289
#define ENDOFFILE 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 24 "comp.yacc" /* yacc.c:1909  */

	char *sval;
      int   ival;
      list<int*> *stmts;

#line 135 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
