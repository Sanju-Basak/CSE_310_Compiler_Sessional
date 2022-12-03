/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    FOR = 259,                     /* FOR  */
    INT = 260,                     /* INT  */
    FLOAT = 261,                   /* FLOAT  */
    VOID = 262,                    /* VOID  */
    ELSE = 263,                    /* ELSE  */
    RETURN = 264,                  /* RETURN  */
    PRINTLN = 265,                 /* PRINTLN  */
    INCOP = 266,                   /* INCOP  */
    DECOP = 267,                   /* DECOP  */
    ASSIGNOP = 268,                /* ASSIGNOP  */
    NOT = 269,                     /* NOT  */
    LPAREN = 270,                  /* LPAREN  */
    RPAREN = 271,                  /* RPAREN  */
    LCURL = 272,                   /* LCURL  */
    RCURL = 273,                   /* RCURL  */
    LTHIRD = 274,                  /* LTHIRD  */
    RTHIRD = 275,                  /* RTHIRD  */
    COMMA = 276,                   /* COMMA  */
    SEMICOLON = 277,               /* SEMICOLON  */
    ADDOP = 278,                   /* ADDOP  */
    MULOP = 279,                   /* MULOP  */
    RELOP = 280,                   /* RELOP  */
    LOGICOP = 281,                 /* LOGICOP  */
    CONST_INT = 282,               /* CONST_INT  */
    CONST_FLOAT = 283,             /* CONST_FLOAT  */
    ID = 284,                      /* ID  */
    WHILE = 285,                   /* WHILE  */
    LOWER_THAN_ELSE = 286          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define FOR 259
#define INT 260
#define FLOAT 261
#define VOID 262
#define ELSE 263
#define RETURN 264
#define PRINTLN 265
#define INCOP 266
#define DECOP 267
#define ASSIGNOP 268
#define NOT 269
#define LPAREN 270
#define RPAREN 271
#define LCURL 272
#define RCURL 273
#define LTHIRD 274
#define RTHIRD 275
#define COMMA 276
#define SEMICOLON 277
#define ADDOP 278
#define MULOP 279
#define RELOP 280
#define LOGICOP 281
#define CONST_INT 282
#define CONST_FLOAT 283
#define ID 284
#define WHILE 285
#define LOWER_THAN_ELSE 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 253 "1805064.y"

    SymbolInfo* symbolInfo;

#line 133 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
