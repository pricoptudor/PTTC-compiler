/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    PROG_BEGIN = 258,
    PROG_END = 259,
    GLOBAL_BEGIN = 260,
    GLOBAL_END = 261,
    FNC_STR_BEGIN = 262,
    FNC_STR_END = 263,
    MAIN_BEGIN = 264,
    MAIN_END = 265,
    CONST = 266,
    INT = 267,
    FLOAT = 268,
    CHAR = 269,
    STRING = 270,
    BOOL = 271,
    ARRAY = 272,
    ARRAY_INSERT = 273,
    ARRAY_DELETE = 274,
    ARRAY_GET = 275,
    ARRAY_SIZE = 276,
    ADUNARE = 277,
    SCADERE = 278,
    INMULTIRE = 279,
    IMPARTIRE = 280,
    INCREMENT = 281,
    DECREMENT = 282,
    EQUAL = 283,
    NEQUAL = 284,
    LOWER = 285,
    LEQ = 286,
    GREATER = 287,
    GEQ = 288,
    AND = 289,
    OR = 290,
    ASSIGN = 291,
    PRINT = 292,
    STRUCT_BEGIN = 293,
    STRUCT_END = 294,
    STRUCT_TYPE = 295,
    FUNCTION_BEGIN = 296,
    FUNCTION_END = 297,
    FUNCTION_TYPE = 298,
    RETURN = 299,
    COMMENT = 300,
    IF_BEGIN = 301,
    IF_END = 302,
    ELSE_BEGIN = 303,
    ELSE_END = 304,
    WHILE_BEGIN = 305,
    WHILE_END = 306,
    FOR_BEGIN = 307,
    FOR_END = 308,
    NUMBER = 309,
    NUMBER_FLOAT = 310,
    ID = 311,
    ANYTHING = 312,
    VALUE_CHR = 313
  };
#endif
/* Tokens.  */
#define PROG_BEGIN 258
#define PROG_END 259
#define GLOBAL_BEGIN 260
#define GLOBAL_END 261
#define FNC_STR_BEGIN 262
#define FNC_STR_END 263
#define MAIN_BEGIN 264
#define MAIN_END 265
#define CONST 266
#define INT 267
#define FLOAT 268
#define CHAR 269
#define STRING 270
#define BOOL 271
#define ARRAY 272
#define ARRAY_INSERT 273
#define ARRAY_DELETE 274
#define ARRAY_GET 275
#define ARRAY_SIZE 276
#define ADUNARE 277
#define SCADERE 278
#define INMULTIRE 279
#define IMPARTIRE 280
#define INCREMENT 281
#define DECREMENT 282
#define EQUAL 283
#define NEQUAL 284
#define LOWER 285
#define LEQ 286
#define GREATER 287
#define GEQ 288
#define AND 289
#define OR 290
#define ASSIGN 291
#define PRINT 292
#define STRUCT_BEGIN 293
#define STRUCT_END 294
#define STRUCT_TYPE 295
#define FUNCTION_BEGIN 296
#define FUNCTION_END 297
#define FUNCTION_TYPE 298
#define RETURN 299
#define COMMENT 300
#define IF_BEGIN 301
#define IF_END 302
#define ELSE_BEGIN 303
#define ELSE_END 304
#define WHILE_BEGIN 305
#define WHILE_END 306
#define FOR_BEGIN 307
#define FOR_END 308
#define NUMBER 309
#define NUMBER_FLOAT 310
#define ID 311
#define ANYTHING 312
#define VALUE_CHR 313

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 86 "limbaj.y"

	double num; 
	char nume_var[1000]; 
     char sir_var[1000];
	int type_id;
     struct var* strct;
     struct parametri* strct_param;
     struct fun* fnc;

#line 183 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
