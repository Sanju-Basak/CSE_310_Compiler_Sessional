/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "1805064.y"


#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include "1805064_SymbolTable.h"

using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;
extern int line_count;
extern int error;

FILE *logout, *errout;

SymbolTable st;


///////for variable dec //////

struct var{
    string var_name;
    int var_size;
}temp_var;

vector<var> var_list;

///////// for parameter dec    //////////

struct param{
    string par_name;
    string par_type;
}temp_par;

vector<param> param_list;

vector<string> arg_list;

//for function dec-def
string type, type_final;
string name, name_final;

//for testing will be commented out
int x=  0;
int y=  0;
int sz= 0;



void insertVar(var vin, string retType){
    SymbolInfo* sf= new SymbolInfo(vin.var_name, "ID");
    sf->setRetType(retType);
    sf->setSize(vin.var_size);

    st.insert(*sf);
}

void insertFunc(string name, string type, int size){
    SymbolInfo *sf= new SymbolInfo(name, "ID");
    sf->setRetType(type);
    sf->setSize(size);

    if(param_list.size()>0){
        string nm= param_list[0].par_name;
        for(int i=1; i< param_list.size(); i++){
            if(nm== param_list[i].par_name){
            fprintf(logout, "Error at line %d: Multiple declaration of %s in parameter \n\n", line_count, param_list[i].par_name.c_str());
            fprintf(errout, "Error at line %d: Multiple declaration of %s in parameter  \n\n", line_count, param_list[i].par_name.c_str());
            error++;            
        }
    }
    }


    for(int i=0; i< param_list.size(); i++){
        sf->addParamList(param_list[i].par_name, param_list[i].par_type);
    }

    st.insert(*sf);
}


//////////////////      Error Handling      /////////////////////

void error_undeclared_var(string v){
    error++;
    fprintf(logout, "Error at line %d: Undeclared variable %s\n\n", line_count, v.c_str());
    fprintf(errout, "Error at line %d: Undeclared variable %s\n\n", line_count, v.c_str());
    
}

void error_multiple_dec(string v){
    error++;
    fprintf(logout, "Error at line %d: Multiple declaration of %s\n\n", line_count, v.c_str());
    fprintf(errout, "Error at line %d: Multiple declaration of %s\n\n", line_count, v.c_str());
    
}

void error_varType(){
    error++;
    fprintf(logout, "Error at line %d: Variable type can not be void \n\n", line_count);
    fprintf(errout, "Error at line %d: Variable type can not be void \n\n", line_count);
    
}

void error_undeclared_func(string v){
    fprintf(logout, "Error at line %d: Undeclared Function %s\n\n", line_count, v.c_str());
    fprintf(errout, "Error at line %d: Undeclared Function  %s\n\n", line_count, v.c_str());
    error++;
}

void error_function_return_conflict(string v){
    error++; 
    fprintf(logout, "Error at line %d: Return type mismatch with function declaration in function  %s\n\n", line_count, v.c_str());
    fprintf(errout, "Error at line %d: Return type mismatch with function declaration in function  %s\n\n", line_count, v.c_str());
       
}

void error_not_function(string v){
    error++; 
    fprintf(logout, "Error at line %d: %s not a function\n\n", line_count, v.c_str());
    fprintf(errout, "Error at line %d: %s not a function \n\n", line_count, v.c_str());
 
}


void error_inconsistent_func_size(string v){
    error++; 
    fprintf(logout, "Error at line %d: Total number of arguments mismatch in function %s\n\n", line_count, v.c_str());
    fprintf(errout, "Error at line %d: Total number of arguments mismatch in function %s\n\n", line_count, v.c_str());
        
}

void error_inconsistent_func_type(int i, string v){
    error++; 
    fprintf(logout, "Error at line %d: %dth argument mismatch in function func %s\n\n", line_count, i, v.c_str());
    fprintf(errout, "Error at line %d: %dth argument mismatch in function func %s\n\n", line_count, i, v.c_str());
     
}


void error_function_paramSize(string v){
    error++; 
    fprintf(logout, "Error at line %d: Total number of arguments mismatch with declaration in function  %s\n\n", line_count, v.c_str());
    fprintf(errout, "Error at line %d: Total number of arguments mismatch with declaration in function %s\n\n", line_count, v.c_str());
       
}

void error_function_paramType(string v){
    error++; 
    fprintf(logout, "Error at line %d: arguments type mismatch with declaration in function  %s\n\n", line_count, v.c_str());
    fprintf(errout, "Error at line %d: arguments type mismatch with declaration in function %s\n\n", line_count, v.c_str());
    
}

void error_typecast_void(){
    error++; 
    fprintf(logout, "Error at line %d: Void function used in expression  \n\n", line_count);
    fprintf(errout, "Error at line %d: Void function used in expression  \n\n", line_count);
}

void error_type_cast_mod()
{
    error++; 
    fprintf(logout, "Error at line %d: Non-Integer operand on modulus operator \n\n", line_count);
    fprintf(errout, "Error at line %d: Non-Integer operand on modulus operator \n\n", line_count);
}


void error_modzero()
{
    error++; 
    fprintf(logout, "Error at line %d: Modulus by Zero \n\n", line_count);
    fprintf(errout, "Error at line %d: Modulus by Zero \n\n", line_count);
}

void error_type_mismatch(string v="")
{
    error++; 
    fprintf(logout, "Error at line %d: Type mismatch %s\n\n", line_count, v.c_str());
    fprintf(errout, "Error at line %d: Type mismatch %s\n\n", line_count, v.c_str());
}

void error_array_index_invalid(){
    error++; 
    fprintf(logout, "Error at line %d: Expression inside third brackets not an integer \n\n", line_count);
    fprintf(errout, "Error at line %d: Expression inside third brackets not an integer \n\n", line_count);   
}



void yyerror(string v)
{
	//write your code
    error++; 
    fprintf(logout, "Error at line %d: %s\n\n", line_count, v.c_str());
    fprintf(errout, "Error at line %d: %s\n\n", line_count, v.c_str());

}



#line 278 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    WHILE = 264,                   /* WHILE  */
    RETURN = 265,                  /* RETURN  */
    PRINTLN = 266,                 /* PRINTLN  */
    INCOP = 267,                   /* INCOP  */
    DECOP = 268,                   /* DECOP  */
    ASSIGNOP = 269,                /* ASSIGNOP  */
    NOT = 270,                     /* NOT  */
    LPAREN = 271,                  /* LPAREN  */
    RPAREN = 272,                  /* RPAREN  */
    LCURL = 273,                   /* LCURL  */
    RCURL = 274,                   /* RCURL  */
    LTHIRD = 275,                  /* LTHIRD  */
    RTHIRD = 276,                  /* RTHIRD  */
    COMMA = 277,                   /* COMMA  */
    SEMICOLON = 278,               /* SEMICOLON  */
    ADDOP = 279,                   /* ADDOP  */
    MULOP = 280,                   /* MULOP  */
    RELOP = 281,                   /* RELOP  */
    LOGICOP = 282,                 /* LOGICOP  */
    CONST_INT = 283,               /* CONST_INT  */
    CONST_FLOAT = 284,             /* CONST_FLOAT  */
    ID = 285,                      /* ID  */
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
#define WHILE 264
#define RETURN 265
#define PRINTLN 266
#define INCOP 267
#define DECOP 268
#define ASSIGNOP 269
#define NOT 270
#define LPAREN 271
#define RPAREN 272
#define LCURL 273
#define RCURL 274
#define LTHIRD 275
#define RTHIRD 276
#define COMMA 277
#define SEMICOLON 278
#define ADDOP 279
#define MULOP 280
#define RELOP 281
#define LOGICOP 282
#define CONST_INT 283
#define CONST_FLOAT 284
#define ID 285
#define LOWER_THAN_ELSE 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 209 "1805064.y"

    SymbolInfo* symbolInfo;

#line 397 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_FOR = 4,                        /* FOR  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_FLOAT = 6,                      /* FLOAT  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_PRINTLN = 11,                   /* PRINTLN  */
  YYSYMBOL_INCOP = 12,                     /* INCOP  */
  YYSYMBOL_DECOP = 13,                     /* DECOP  */
  YYSYMBOL_ASSIGNOP = 14,                  /* ASSIGNOP  */
  YYSYMBOL_NOT = 15,                       /* NOT  */
  YYSYMBOL_LPAREN = 16,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 17,                    /* RPAREN  */
  YYSYMBOL_LCURL = 18,                     /* LCURL  */
  YYSYMBOL_RCURL = 19,                     /* RCURL  */
  YYSYMBOL_LTHIRD = 20,                    /* LTHIRD  */
  YYSYMBOL_RTHIRD = 21,                    /* RTHIRD  */
  YYSYMBOL_COMMA = 22,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 23,                 /* SEMICOLON  */
  YYSYMBOL_ADDOP = 24,                     /* ADDOP  */
  YYSYMBOL_MULOP = 25,                     /* MULOP  */
  YYSYMBOL_RELOP = 26,                     /* RELOP  */
  YYSYMBOL_LOGICOP = 27,                   /* LOGICOP  */
  YYSYMBOL_CONST_INT = 28,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 29,               /* CONST_FLOAT  */
  YYSYMBOL_ID = 30,                        /* ID  */
  YYSYMBOL_LOWER_THAN_ELSE = 31,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_start = 33,                     /* start  */
  YYSYMBOL_program = 34,                   /* program  */
  YYSYMBOL_unit = 35,                      /* unit  */
  YYSYMBOL_func_declaration = 36,          /* func_declaration  */
  YYSYMBOL_func_definition = 37,           /* func_definition  */
  YYSYMBOL_dummy_func1 = 38,               /* dummy_func1  */
  YYSYMBOL_dummy_func1_dec = 39,           /* dummy_func1_dec  */
  YYSYMBOL_dummy_func1_def = 40,           /* dummy_func1_def  */
  YYSYMBOL_parameter_list = 41,            /* parameter_list  */
  YYSYMBOL_compound_statement = 42,        /* compound_statement  */
  YYSYMBOL_dummy_func = 43,                /* dummy_func  */
  YYSYMBOL_var_declaration = 44,           /* var_declaration  */
  YYSYMBOL_type_specifier = 45,            /* type_specifier  */
  YYSYMBOL_id = 46,                        /* id  */
  YYSYMBOL_declaration_list = 47,          /* declaration_list  */
  YYSYMBOL_statements = 48,                /* statements  */
  YYSYMBOL_statement = 49,                 /* statement  */
  YYSYMBOL_dummy_func2_type = 50,          /* dummy_func2_type  */
  YYSYMBOL_dummy_func2_void = 51,          /* dummy_func2_void  */
  YYSYMBOL_expression_statement = 52,      /* expression_statement  */
  YYSYMBOL_variable = 53,                  /* variable  */
  YYSYMBOL_expression = 54,                /* expression  */
  YYSYMBOL_logic_expression = 55,          /* logic_expression  */
  YYSYMBOL_rel_expression = 56,            /* rel_expression  */
  YYSYMBOL_simple_expression = 57,         /* simple_expression  */
  YYSYMBOL_term = 58,                      /* term  */
  YYSYMBOL_unary_expression = 59,          /* unary_expression  */
  YYSYMBOL_factor = 60,                    /* factor  */
  YYSYMBOL_argument_list = 61,             /* argument_list  */
  YYSYMBOL_arguments = 62                  /* arguments  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   173

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   230,   230,   239,   245,   255,   261,   267,   275,   283,
     293,   299,   307,   321,   334,   387,   399,   411,   423,   438,
     447,   458,   489,   515,   523,   531,   541,   547,   566,   588,
     606,   628,   634,   642,   648,   654,   660,   666,   672,   678,
     684,   694,   706,   721,   729,   740,   751,   782,   820,   830,
     851,   859,   880,   888,   909,   917,   943,   951,   986,  1000,
    1012,  1022,  1031,  1090,  1106,  1114,  1122,  1130,  1140,  1147,
    1154,  1168
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "FOR", "INT",
  "FLOAT", "VOID", "ELSE", "WHILE", "RETURN", "PRINTLN", "INCOP", "DECOP",
  "ASSIGNOP", "NOT", "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD",
  "RTHIRD", "COMMA", "SEMICOLON", "ADDOP", "MULOP", "RELOP", "LOGICOP",
  "CONST_INT", "CONST_FLOAT", "ID", "LOWER_THAN_ELSE", "$accept", "start",
  "program", "unit", "func_declaration", "func_definition", "dummy_func1",
  "dummy_func1_dec", "dummy_func1_def", "parameter_list",
  "compound_statement", "dummy_func", "var_declaration", "type_specifier",
  "id", "declaration_list", "statements", "statement", "dummy_func2_type",
  "dummy_func2_void", "expression_statement", "variable", "expression",
  "logic_expression", "rel_expression", "simple_expression", "term",
  "unary_expression", "factor", "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-105)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-15)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      52,  -105,  -105,  -105,    19,    52,  -105,  -105,  -105,  -105,
     -14,  -105,  -105,  -105,    16,    42,    -6,    25,   -14,  -105,
      41,    23,    46,  -105,    56,     3,   -14,    58,    66,    76,
      56,    52,  -105,    87,  -105,  -105,  -105,    91,    76,   -14,
    -105,    72,  -105,  -105,  -105,   101,   104,   106,    97,   120,
      97,    97,  -105,  -105,    97,  -105,  -105,  -105,  -105,   -14,
      36,   100,  -105,  -105,   135,   117,  -105,   114,    29,   125,
    -105,  -105,    97,    69,    97,   119,   -14,    59,  -105,   136,
    -105,   134,    97,    97,  -105,  -105,  -105,  -105,    97,  -105,
      97,    97,    97,    97,  -105,  -105,  -105,  -105,   138,  -105,
    -105,   142,   123,   139,  -105,  -105,   125,   137,  -105,   145,
    -105,   146,   141,  -105,    97,  -105,  -105,    69,  -105,  -105,
    -105,   128,  -105,   128,   157,  -105,  -105,   128,    97,  -105,
    -105,  -105,   149,   128,  -105
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    23,    24,    25,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    26,    29,     0,     0,     0,     0,    22,
       0,     0,    27,    30,    13,     0,    18,     0,     0,     0,
      13,     0,    17,     0,     9,    21,    11,     0,     0,    16,
      28,     0,     8,    10,    15,     0,     0,     0,     0,     0,
       0,     0,    20,    44,     0,    64,    65,    35,    33,     0,
      46,     0,    31,    34,    61,     0,    48,    50,    52,    54,
      56,    60,     0,     0,     0,     0,     0,    61,    59,     0,
      58,    29,    69,     0,    19,    32,    66,    67,     0,    45,
       0,     0,     0,     0,    42,    42,    42,    41,     0,    63,
      71,     0,    68,     0,    49,    51,    55,    53,    57,     0,
      43,     0,     0,    62,     0,    47,    43,     0,    43,    40,
      70,     0,    42,     0,    37,    43,    39,     0,     0,    38,
      42,    43,     0,     0,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -105,  -105,  -105,   162,  -105,  -105,  -105,   140,   143,  -105,
     -25,  -105,    33,    39,    -8,  -105,  -105,   -60,   -88,  -104,
     -67,   -45,   -48,   -65,    78,    77,    80,   -39,  -105,  -105,
    -105
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    17,    28,    29,    25,
      57,    41,    58,    59,    60,    15,    61,    62,   109,   117,
      63,    64,    65,    66,    67,    68,    69,    70,    71,   101,
     102
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      75,    85,    14,    79,    36,    77,    95,   110,   111,    77,
      22,    78,   121,    43,   123,    80,    13,   100,    32,    11,
      30,   128,    20,   104,    94,    31,    96,   132,     1,     2,
       3,    44,   -12,     9,   125,   103,    16,    77,     9,    10,
      24,    21,   131,    77,    10,    77,    77,    77,    77,   120,
     122,    81,    82,    91,   108,    92,    83,     1,     2,     3,
      26,   124,    23,   126,    18,    19,    27,   129,    98,    77,
      39,    86,    87,   134,   -14,    45,    46,     1,     2,     3,
     130,    47,    48,    49,    50,    51,    33,    50,    51,    34,
      35,    52,    53,    54,    35,    53,    54,    55,    56,    13,
      55,    56,    13,    45,    46,     1,     2,     3,    40,    47,
      48,    49,    50,    51,    42,    50,    51,    72,    35,    84,
      73,    54,    74,    53,    54,    55,    56,    13,    55,    56,
      13,    45,    46,     1,     2,     3,    76,    47,    48,    49,
      89,    90,    97,    50,    51,   114,    35,    86,    87,    88,
      93,    53,    54,    99,    16,   112,    55,    56,    13,   113,
     115,    91,   116,   118,   119,   127,   133,    12,   105,   107,
      37,   106,     0,    38
};

static const yytype_int16 yycheck[] =
{
      48,    61,    10,    51,    29,    50,    73,    95,    96,    54,
      18,    50,   116,    38,   118,    54,    30,    82,    26,     0,
      17,   125,    28,    88,    72,    22,    74,   131,     5,     6,
       7,    39,    16,     0,   122,    83,    20,    82,     5,     0,
      17,    16,   130,    88,     5,    90,    91,    92,    93,   114,
     117,    59,    16,    24,    93,    26,    20,     5,     6,     7,
      21,   121,    21,   123,    22,    23,    20,   127,    76,   114,
      31,    12,    13,   133,    18,     3,     4,     5,     6,     7,
     128,     9,    10,    11,    15,    16,    28,    15,    16,    23,
      18,    19,    23,    24,    18,    23,    24,    28,    29,    30,
      28,    29,    30,     3,     4,     5,     6,     7,    21,     9,
      10,    11,    15,    16,    23,    15,    16,    16,    18,    19,
      16,    24,    16,    23,    24,    28,    29,    30,    28,    29,
      30,     3,     4,     5,     6,     7,    16,     9,    10,    11,
      23,    27,    23,    15,    16,    22,    18,    12,    13,    14,
      25,    23,    24,    17,    20,    17,    28,    29,    30,    17,
      21,    24,    17,    17,    23,     8,    17,     5,    90,    92,
      30,    91,    -1,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,     7,    33,    34,    35,    36,    37,    44,
      45,     0,    35,    30,    46,    47,    20,    38,    22,    23,
      28,    16,    46,    21,    17,    41,    45,    20,    39,    40,
      17,    22,    46,    28,    23,    18,    42,    39,    40,    45,
      21,    43,    23,    42,    46,     3,     4,     9,    10,    11,
      15,    16,    19,    23,    24,    28,    29,    42,    44,    45,
      46,    48,    49,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    16,    16,    16,    54,    16,    53,    59,    54,
      59,    46,    16,    20,    19,    49,    12,    13,    14,    23,
      27,    24,    26,    25,    54,    52,    54,    23,    46,    17,
      55,    61,    62,    54,    55,    56,    58,    57,    59,    50,
      50,    50,    17,    17,    22,    21,    17,    51,    17,    23,
      55,    51,    52,    51,    49,    50,    49,     8,    51,    49,
      54,    50,    51,    17,    49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    36,    36,
      37,    37,    38,    39,    40,    41,    41,    41,    41,    42,
      42,    43,    44,    45,    45,    45,    46,    47,    47,    47,
      47,    48,    48,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    50,    51,    52,    52,    53,    53,    54,    54,
      55,    55,    56,    56,    57,    57,    58,    58,    59,    59,
      59,    60,    60,    60,    60,    60,    60,    60,    61,    61,
      62,    62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     8,     7,
       8,     7,     0,     0,     0,     4,     3,     2,     1,     4,
       3,     0,     3,     1,     1,     1,     1,     3,     6,     1,
       4,     1,     2,     1,     1,     1,    13,     7,     9,     7,
       5,     3,     0,     0,     1,     2,     1,     4,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     2,     2,
       1,     1,     4,     3,     1,     1,     2,     2,     1,     0,
       3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* start: program  */
#line 231 "1805064.y"
        {
		//write your code in this block in all the similar blocks below
        (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
        fprintf(logout, "Line %d: start : program\n\n", line_count);
        //fprintf(logout, "%s \n\n", $1->getName().c_str());
	}
#line 1542 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 240 "1805064.y"
    {
        (yyval.symbolInfo)= new SymbolInfo((yyvsp[-1].symbolInfo)->getName()+ (yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
        fprintf(logout, "Line %d: program : program unit\n\n", line_count);
        fprintf(logout, "%s%s\n\n", (yyvsp[-1].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());
    }
#line 1552 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 246 "1805064.y"
    {
        (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
        fprintf(logout, "Line %d: program : unit\n\n", line_count);
        fprintf(logout, "%s \n\n", (yyvsp[0].symbolInfo)->getName().c_str());
    }
#line 1562 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 256 "1805064.y"
    {
        (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
        fprintf(logout, "Line %d: unit : var_declaration\n\n", line_count);
        fprintf(logout, "%s \n\n", (yyvsp[0].symbolInfo)->getName().c_str());
    }
#line 1572 "y.tab.c"
    break;

  case 6: /* unit: func_declaration  */
#line 262 "1805064.y"
     {
        (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
        fprintf(logout, "Line %d: unit : func_declaration\n\n", line_count);
        fprintf(logout, "%s \n\n", (yyvsp[0].symbolInfo)->getName().c_str());
     }
#line 1582 "y.tab.c"
    break;

  case 7: /* unit: func_definition  */
#line 268 "1805064.y"
     {
        (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
        fprintf(logout, "Line %d: unit : func_definition\n\n", line_count);
        fprintf(logout, "%s \n\n", (yyvsp[0].symbolInfo)->getName().c_str());
     }
#line 1592 "y.tab.c"
    break;

  case 8: /* func_declaration: type_specifier id dummy_func1 LPAREN parameter_list RPAREN dummy_func1_dec SEMICOLON  */
#line 276 "1805064.y"
                {
                    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-7].symbolInfo)->getName()+" "+(yyvsp[-6].symbolInfo)->getName()+"("+(yyvsp[-3].symbolInfo)->getName()+")"+";\n", "NON_TERMINAL");
                    fprintf(logout, "Line %d: func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n", line_count);
                    fprintf(logout, "%s %s(%s); \n\n", (yyvsp[-7].symbolInfo)->getName().c_str(), (yyvsp[-6].symbolInfo)->getName().c_str(), (yyvsp[-3].symbolInfo)->getName().c_str());

                    param_list.clear();
                }
#line 1604 "y.tab.c"
    break;

  case 9: /* func_declaration: type_specifier id dummy_func1 LPAREN RPAREN dummy_func1_dec SEMICOLON  */
#line 284 "1805064.y"
        {
                (yyval.symbolInfo) = new SymbolInfo((yyvsp[-6].symbolInfo)->getName()+" "+(yyvsp[-5].symbolInfo)->getName()+"();\n", "NON_TERMINAL");
                fprintf(logout, "Line %d: func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n", line_count);
                fprintf(logout, "%s %s(); \n\n", (yyvsp[-6].symbolInfo)->getName().c_str(), (yyvsp[-5].symbolInfo)->getName().c_str()); 

                param_list.clear();           
        }
#line 1616 "y.tab.c"
    break;

  case 10: /* func_definition: type_specifier id dummy_func1 LPAREN parameter_list RPAREN dummy_func1_def compound_statement  */
#line 294 "1805064.y"
                {
                    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-7].symbolInfo)->getName()+" "+(yyvsp[-6].symbolInfo)->getName()+"("+(yyvsp[-3].symbolInfo)->getName()+") "+(yyvsp[0].symbolInfo)->getName()+ "\n", "NON_TERMINAL");
                    fprintf(logout, "Line %d: func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n", line_count);
                    fprintf(logout, "%s %s(%s) %s \n\n", (yyvsp[-7].symbolInfo)->getName().c_str(), (yyvsp[-6].symbolInfo)->getName().c_str(), (yyvsp[-3].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());
                }
#line 1626 "y.tab.c"
    break;

  case 11: /* func_definition: type_specifier id dummy_func1 LPAREN RPAREN dummy_func1_def compound_statement  */
#line 300 "1805064.y"
        {
                (yyval.symbolInfo) = new SymbolInfo((yyvsp[-6].symbolInfo)->getName()+" "+(yyvsp[-5].symbolInfo)->getName()+"() "+(yyvsp[0].symbolInfo)->getName()+ "\n", "NON_TERMINAL");
                fprintf(logout, "Line %d: func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n", line_count);
                fprintf(logout, "%s %s() %s \n\n", (yyvsp[-6].symbolInfo)->getName().c_str(), (yyvsp[-6].symbolInfo)->getName().c_str(), (yyvsp[-5].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());
        }
#line 1636 "y.tab.c"
    break;

  case 12: /* dummy_func1: %empty  */
#line 307 "1805064.y"
             {
    type_final= type;
    name_final= name;

    //for testing will be commented out
    sz= 5;
    for(int j= 0; j< sz; j++){
        x= x+j;
        y= x;
    }
    //for testing
}
#line 1653 "y.tab.c"
    break;

  case 13: /* dummy_func1_dec: %empty  */
#line 321 "1805064.y"
                 {

    ////Insert func name to symboTable
    if(st.lookUpAll(name_final)!= NULL){
        error_multiple_dec(name_final);
    }else{
        insertFunc(name_final, type_final, -2);
    }


}
#line 1669 "y.tab.c"
    break;

  case 14: /* dummy_func1_def: %empty  */
#line 334 "1805064.y"
                 {
    ////Insert funcName if not inserted

    SymbolInfo* temp= st.lookUpAll(name_final);
    if(temp == NULL){
        insertFunc(name_final, type_final, -3);
    } else if(temp->getSize() != -2){
        error_multiple_dec(name_final);
    }

    else{
        ///function dec & def matching check
        if(temp->getRetType() != type_final){
            error_function_return_conflict(temp->getName());
        }else if(temp->getParamSize()==1 && param_list.size()== 0 && temp->getParam(0).par_type== "void"){
            temp->setSize(-3);
        }else if(temp->getParamSize()==0 && param_list.size()== 1 && param_list[0].par_type== "void"){
            temp->setSize(-3);
        }else if(temp->getParamSize() != param_list.size()){
            error_function_paramSize(temp->getName());

            //for testing will comment out
            sz= 5;
            for(int j= 0; j< sz; j++){
            y= y+j;
            x= y;
            }
            //for testing

        }else{
            ///size same, type checking

            int i=0;
            while(i< param_list.size()){
                if(temp->getParam(i).par_type != param_list[i].par_type){
                    break;
                }
                i++;
            }

            if(i== param_list.size()){
                temp->setSize(-3);
            }else{
                error_function_paramType(name_final);
            }
        }

    }

}
#line 1724 "y.tab.c"
    break;

  case 15: /* parameter_list: parameter_list COMMA type_specifier id  */
#line 388 "1805064.y"
        {
                (yyval.symbolInfo) = new SymbolInfo((yyvsp[-3].symbolInfo)->getName()+","+(yyvsp[-1].symbolInfo)->getName()+ " "+ (yyvsp[0].symbolInfo)->getName(), "NON_TERMINAL");
                fprintf(logout, "Line %d: parameter_list  : parameter_list COMMA type_specifier ID\n\n", line_count);
                fprintf(logout, "%s, %s %s \n\n", (yyvsp[-3].symbolInfo)->getName().c_str(), (yyvsp[-1].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());

                ///updating parameter list
                temp_par.par_type = (yyvsp[-1].symbolInfo)->getName();
                temp_par.par_name = (yyvsp[0].symbolInfo)->getName();

                param_list.push_back(temp_par);
        }
#line 1740 "y.tab.c"
    break;

  case 16: /* parameter_list: parameter_list COMMA type_specifier  */
#line 400 "1805064.y"
        {
                (yyval.symbolInfo) = new SymbolInfo((yyvsp[-2].symbolInfo)->getName()+","+(yyvsp[0].symbolInfo)->getName(), "NON_TERMINAL");
                fprintf(logout, "Line %d: parameter_list  : parameter_list COMMA type_specifier\n\n", line_count);
                fprintf(logout, "%s, %s \n\n", (yyvsp[-2].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());

                ///updating parameter list
                temp_par.par_type = (yyvsp[0].symbolInfo)->getName();
                temp_par.par_name = "";

                param_list.push_back(temp_par);
        }
#line 1756 "y.tab.c"
    break;

  case 17: /* parameter_list: type_specifier id  */
#line 412 "1805064.y"
        {
                (yyval.symbolInfo) = new SymbolInfo((yyvsp[-1].symbolInfo)->getName()+" "+(yyvsp[0].symbolInfo)->getName(), "NON_TERMINAL");
                fprintf(logout, "Line %d: parameter_list  : type_specifier ID\n\n", line_count);
                fprintf(logout, "%s %s \n\n", (yyvsp[-1].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());

                ///updating parameter list
                temp_par.par_type = (yyvsp[-1].symbolInfo)->getName();
                temp_par.par_name = (yyvsp[0].symbolInfo)->getName();

                param_list.push_back(temp_par);
        }
#line 1772 "y.tab.c"
    break;

  case 18: /* parameter_list: type_specifier  */
#line 424 "1805064.y"
        {
                (yyval.symbolInfo) = new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON_TERMINAL");
                fprintf(logout, "Line %d: parameter_list  : type_specifier\n\n", line_count);
                fprintf(logout, "%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());

                ///updating parameter list
                temp_par.par_type = (yyvsp[0].symbolInfo)->getName();
                temp_par.par_name = "";

                param_list.push_back(temp_par);
        }
#line 1788 "y.tab.c"
    break;

  case 19: /* compound_statement: LCURL dummy_func statements RCURL  */
#line 439 "1805064.y"
        {
                (yyval.symbolInfo) = new SymbolInfo("{\n"+ (yyvsp[-1].symbolInfo)->getName()+ "}\n" , "NON_TERMINAL");
                fprintf(logout, "Line %d: compound_statement : LCURL statements RCURL\n\n", line_count);
                fprintf(logout, "{\n%s\n}\n\n", (yyvsp[-1].symbolInfo)->getName().c_str());

                st.printAll(logout);
                st.ExitScope();
        }
#line 1801 "y.tab.c"
    break;

  case 20: /* compound_statement: LCURL dummy_func RCURL  */
#line 448 "1805064.y"
             {
                (yyval.symbolInfo) = new SymbolInfo("{\n}\n" , "NON_TERMINAL");
                fprintf(logout, "Line %d: compound_statement : LCURL RCURL\n\n", line_count);
                fprintf(logout, "{\n\n}\n\n");

                st.printAll(logout);
                st.ExitScope();
             }
#line 1814 "y.tab.c"
    break;

  case 21: /* dummy_func: %empty  */
#line 458 "1805064.y"
            {

            //for testing will be commented out
            sz= 5;
            for(int j= 0; j< sz; j++){
                y= y+j;
                x= y;
            }
            //for testing

            st.EnterScope();

            //ScopeTable enter param_list

            if(param_list.size()== 1 && param_list[0].par_type== "void"){

            }else{
                int i=0;
                while(i< param_list.size()){
                    temp_var.var_name= param_list[i].par_name;
                    temp_var.var_size= -1;

                    insertVar(temp_var, param_list[i].par_type);
                    i++;
                }
            }

            param_list.clear();
}
#line 1848 "y.tab.c"
    break;

  case 22: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 490 "1805064.y"
                {
                    (yyval.symbolInfo)= new SymbolInfo((yyvsp[-2].symbolInfo)->getName()+ " "+ (yyvsp[-1].symbolInfo)->getName()+ ";\n", "NON-TERMINAL");
                    fprintf(logout, "Line %d: var_declaration : type_specifier declaration_list SEMICOLON\n\n", line_count);
                    fprintf(logout, "%s %s; \n\n", (yyvsp[-2].symbolInfo)->getName().c_str(), (yyvsp[-1].symbolInfo)->getName().c_str());

                    //insert to SymbolTable
                    if((yyvsp[-2].symbolInfo)->getName()== "void"){
                        error_varType();

                        for(int i=0; i< var_list.size(); i++){
                            insertVar(var_list[i], "float");
                        }

                    }
                    else{
                         for(int i=0; i< var_list.size(); i++){
                            insertVar(var_list[i], (yyvsp[-2].symbolInfo)->getName());
                        }

                    }
                    
                    var_list.clear();
                }
#line 1876 "y.tab.c"
    break;

  case 23: /* type_specifier: INT  */
#line 516 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo("int", "NON-TERMINAL");
            fprintf(logout, "Line %d: type_specifier : INT\n\n", line_count);
            fprintf(logout, "int \n\n");

            type= "int";
        }
#line 1888 "y.tab.c"
    break;

  case 24: /* type_specifier: FLOAT  */
#line 524 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo("float", "NON-TERMINAL");
            fprintf(logout, "Line %d: type_specifier : FLOAT\n\n", line_count);
            fprintf(logout, "float \n\n");

            type= "float";
        }
#line 1900 "y.tab.c"
    break;

  case 25: /* type_specifier: VOID  */
#line 532 "1805064.y"
         {
            (yyval.symbolInfo)= new SymbolInfo("void", "NON-TERMINAL");
            fprintf(logout, "Line %d: type_specifier : VOID\n\n", line_count);
            fprintf(logout, "void \n\n");

            type= "void";
         }
#line 1912 "y.tab.c"
    break;

  case 26: /* id: ID  */
#line 541 "1805064.y"
       {
            (yyval.symbolInfo) = new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON_TERMINAL");
            name = (yyvsp[0].symbolInfo)->getName();
    }
#line 1921 "y.tab.c"
    break;

  case 27: /* declaration_list: declaration_list COMMA id  */
#line 548 "1805064.y"
                {
                    (yyval.symbolInfo)= new SymbolInfo((yyvsp[-2].symbolInfo)->getName()+ ","+  (yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
                    fprintf(logout, "Line %d: declaration_list : declaration_list COMMA ID\n\n", line_count);
                    fprintf(logout, "%s,%s \n\n", (yyvsp[-2].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());

                    //updating variable list
                    temp_var.var_name= (yyvsp[0].symbolInfo)->getName();
                    temp_var.var_size= -1;

                    var_list.push_back(temp_var);

                    //Looking if already existed

                    if(st.lookUp((yyvsp[0].symbolInfo)->getName()) != NULL){
                        error_multiple_dec((yyvsp[0].symbolInfo)->getName());
                    }

                }
#line 1944 "y.tab.c"
    break;

  case 28: /* declaration_list: declaration_list COMMA id LTHIRD CONST_INT RTHIRD  */
#line 567 "1805064.y"
           {    
                (yyval.symbolInfo)= new SymbolInfo((yyvsp[-5].symbolInfo)->getName()+ ","+  (yyvsp[-3].symbolInfo)->getName()+ "["+ (yyvsp[-1].symbolInfo)->getName()+ "]", "NON-TERMINAL");
                fprintf(logout, "Line %d: declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n\n", line_count);
                fprintf(logout, "%s,%s[%s] \n\n", (yyvsp[-5].symbolInfo)->getName().c_str(), (yyvsp[-3].symbolInfo)->getName().c_str(), (yyvsp[-1].symbolInfo)->getName().c_str());

                //updating variable list
                temp_var.var_name= (yyvsp[-3].symbolInfo)->getName();
                int temp;
                temp= stoi((yyvsp[-1].symbolInfo)->getName());
                temp_var.var_size= temp;   

                var_list.push_back(temp_var);

                //Looking if already existed

                if(st.lookUp((yyvsp[-3].symbolInfo)->getName()) != NULL){
                    error_multiple_dec((yyvsp[-3].symbolInfo)->getName());
                }


           }
#line 1970 "y.tab.c"
    break;

  case 29: /* declaration_list: id  */
#line 589 "1805064.y"
           {
                (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
                fprintf(logout, "Line %d: declaration_list : ID\n\n", line_count);
                fprintf(logout, "%s \n\n", (yyvsp[0].symbolInfo)->getName().c_str());

                //updating variable list
                temp_var.var_name= (yyvsp[0].symbolInfo)->getName();
                temp_var.var_size= -1;

                var_list.push_back(temp_var);

                //Looking if already existed

                if(st.lookUp((yyvsp[0].symbolInfo)->getName()) != NULL){
                    error_multiple_dec((yyvsp[0].symbolInfo)->getName());
                }
           }
#line 1992 "y.tab.c"
    break;

  case 30: /* declaration_list: id LTHIRD CONST_INT RTHIRD  */
#line 607 "1805064.y"
           {
                (yyval.symbolInfo)= new SymbolInfo((yyvsp[-3].symbolInfo)->getName()+ "["+ (yyvsp[-1].symbolInfo)->getName()+ "]", "NON-TERMINAL");
                fprintf(logout, "Line %d: declaration_list : ID LTHIRD CONST_INT RTHIRD\n\n", line_count);
                fprintf(logout, "%s[%s] \n\n", (yyvsp[-3].symbolInfo)->getName().c_str(), (yyvsp[-1].symbolInfo)->getName().c_str());

                //updating variable list
                temp_var.var_name= (yyvsp[-3].symbolInfo)->getName();
                int temp;
                temp= stoi((yyvsp[-1].symbolInfo)->getName());
                temp_var.var_size= temp;

                var_list.push_back(temp_var);

                //Looking if already existed

                if(st.lookUp((yyvsp[-3].symbolInfo)->getName()) != NULL){
                    error_multiple_dec((yyvsp[-3].symbolInfo)->getName());
                }
           }
#line 2016 "y.tab.c"
    break;

  case 31: /* statements: statement  */
#line 629 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: statements : statement\n\n", line_count);
            fprintf(logout, "%s \n\n", (yyvsp[0].symbolInfo)->getName().c_str());
        }
#line 2026 "y.tab.c"
    break;

  case 32: /* statements: statements statement  */
#line 635 "1805064.y"
       {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[-1].symbolInfo)->getName()+ (yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: statements : statements statement\n\n", line_count);
            fprintf(logout, "%s%s\n\n", (yyvsp[-1].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());
       }
#line 2036 "y.tab.c"
    break;

  case 33: /* statement: var_declaration  */
#line 643 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: statement : var_declaration\n\n", line_count);
            fprintf(logout, "%s \n\n", (yyvsp[0].symbolInfo)->getName().c_str());
        }
#line 2046 "y.tab.c"
    break;

  case 34: /* statement: expression_statement  */
#line 649 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: statement : expression_statement\n\n", line_count);
            fprintf(logout, "%s \n\n", (yyvsp[0].symbolInfo)->getName().c_str());
        }
#line 2056 "y.tab.c"
    break;

  case 35: /* statement: compound_statement  */
#line 655 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: statement : compound_statement\n\n", line_count);
            fprintf(logout, "%s \n\n", (yyvsp[0].symbolInfo)->getName().c_str());
        }
#line 2066 "y.tab.c"
    break;

  case 36: /* statement: FOR LPAREN expression_statement dummy_func2_type dummy_func2_void expression_statement dummy_func2_type dummy_func2_void expression dummy_func2_type dummy_func2_void RPAREN statement  */
#line 661 "1805064.y"
      {
            (yyval.symbolInfo)= new SymbolInfo("for("+(yyvsp[-10].symbolInfo)->getName()+ (yyvsp[-7].symbolInfo)->getName()+ (yyvsp[-4].symbolInfo)->getName()+ ")"+ (yyvsp[0].symbolInfo)->getName()+ "\n", "NON-TERMINAL");
            fprintf(logout, "Line %d: statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n", line_count);
            fprintf(logout, "for(%s%s%s)%s \n\n", (yyvsp[-10].symbolInfo)->getName().c_str(), (yyvsp[-7].symbolInfo)->getName().c_str(), (yyvsp[-4].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());
      }
#line 2076 "y.tab.c"
    break;

  case 37: /* statement: IF LPAREN expression dummy_func2_type RPAREN dummy_func2_void statement  */
#line 667 "1805064.y"
      {
            (yyval.symbolInfo)= new SymbolInfo("if("+ (yyvsp[-4].symbolInfo)->getName()+ ")"+ (yyvsp[0].symbolInfo)->getName()+ "\n", "NON-TERMINAL");
            fprintf(logout, "Line %d: statement : IF LPAREN expression RPAREN statement\n\n", line_count);
            fprintf(logout, "if(%s)%s \n\n", (yyvsp[-4].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());
      }
#line 2086 "y.tab.c"
    break;

  case 38: /* statement: IF LPAREN expression dummy_func2_type RPAREN dummy_func2_void statement ELSE statement  */
#line 673 "1805064.y"
      {
            (yyval.symbolInfo)= new SymbolInfo("if("+ (yyvsp[-6].symbolInfo)->getName()+ ")"+ (yyvsp[-2].symbolInfo)->getName()+ " else"+ (yyvsp[0].symbolInfo)->getName()+ "\n", "NON-TERMINAL");
            fprintf(logout, "Line %d: statement : IF LPAREN expression RPAREN statement ELSE statement\n\n", line_count);
            fprintf(logout, "if(%s)%s else%s\n\n", (yyvsp[-6].symbolInfo)->getName().c_str(), (yyvsp[-2].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());
      }
#line 2096 "y.tab.c"
    break;

  case 39: /* statement: WHILE LPAREN expression dummy_func2_type RPAREN dummy_func2_void statement  */
#line 679 "1805064.y"
      {
            (yyval.symbolInfo)= new SymbolInfo("while("+ (yyvsp[-4].symbolInfo)->getName()+ ")"+ (yyvsp[0].symbolInfo)->getName()+ "\n", "NON-TERMINAL");
            fprintf(logout, "Line %d: statement : WHILE LPAREN expression RPAREN statement\n\n", line_count);
            fprintf(logout, "while(%s)%s\n\n", (yyvsp[-4].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());
      }
#line 2106 "y.tab.c"
    break;

  case 40: /* statement: PRINTLN LPAREN id RPAREN SEMICOLON  */
#line 685 "1805064.y"
      {
            (yyval.symbolInfo)= new SymbolInfo("printf("+ (yyvsp[-2].symbolInfo)->getName()+ ");\n", "NON-TERMINAL");
            fprintf(logout, "Line %d: statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n", line_count);
            fprintf(logout, "printf(%s);\n\n", (yyvsp[-2].symbolInfo)->getName().c_str());

            if(st.lookUp((yyvsp[-2].symbolInfo)->getName())== NULL){
                error_undeclared_var((yyvsp[-2].symbolInfo)->getName());
            }
      }
#line 2120 "y.tab.c"
    break;

  case 41: /* statement: RETURN expression SEMICOLON  */
#line 695 "1805064.y"
      {
            (yyval.symbolInfo)= new SymbolInfo("return "+ (yyvsp[-1].symbolInfo)->getName()+ ";\n", "NON-TERMINAL");
            fprintf(logout, "Line %d: statement : RETURN expression SEMICOLON\n\n", line_count);
            fprintf(logout, "return %s;\n\n", (yyvsp[-1].symbolInfo)->getName().c_str());

            if((yyvsp[-1].symbolInfo)->getRetType()== "void"){
                error_typecast_void();
            }
      }
#line 2134 "y.tab.c"
    break;

  case 42: /* dummy_func2_type: %empty  */
#line 706 "1805064.y"
                    {

    type_final= type;

    //for testing will comment out
    sz= 5;
    for(int j= 0; j< sz; j++){
    x= x+j;
    y= x;
    }
    //for testing

}
#line 2152 "y.tab.c"
    break;

  case 43: /* dummy_func2_void: %empty  */
#line 721 "1805064.y"
                    {

    if(type_final== "void"){
        error_typecast_void();
    }
}
#line 2163 "y.tab.c"
    break;

  case 44: /* expression_statement: SEMICOLON  */
#line 730 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo(";\n", "NON-TERMINAL");
            fprintf(logout, "Line %d: expression_statement 	: SEMICOLON	\n\n", line_count);
            fprintf(logout, ";\n\n");


            (yyval.symbolInfo)->setRetType("int");
            type= "int";

        }
#line 2178 "y.tab.c"
    break;

  case 45: /* expression_statement: expression SEMICOLON  */
#line 741 "1805064.y"
            {
                (yyval.symbolInfo)= new SymbolInfo((yyvsp[-1].symbolInfo)->getName()+ ";\n", "NON-TERMINAL");
                fprintf(logout, "Line %d: expression_statement 	: expression SEMICOLON \n\n", line_count);
                fprintf(logout, "%s;\n\n", (yyvsp[-1].symbolInfo)->getName().c_str());

                (yyval.symbolInfo)->setRetType((yyvsp[-1].symbolInfo)->getRetType());
                type= (yyvsp[-1].symbolInfo)->getRetType();
            }
#line 2191 "y.tab.c"
    break;

  case 46: /* variable: id  */
#line 752 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: variable : ID\n\n", line_count);
            fprintf(logout, "%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());

            SymbolInfo *temp= st.lookUpAll((yyvsp[0].symbolInfo)->getName());

            if(temp != NULL && temp->getSize() != -1){
                if(temp->getSize() > -1){
                    error_type_mismatch( (yyvsp[0].symbolInfo)->getName()+ " is an array ");
                }else{
                    error_type_mismatch( (yyvsp[0].symbolInfo)->getName()+ " not a variable");
                }
                
            }

            if(temp == NULL){
                error_undeclared_var((yyvsp[0].symbolInfo)->getName());

                (yyval.symbolInfo)->setRetType("float");
            }else{
                if(temp->getRetType() != "void"){
                    (yyval.symbolInfo)->setRetType(temp->getRetType());
                }else{
                    (yyval.symbolInfo)->setRetType("float");
                }
            }


        }
#line 2226 "y.tab.c"
    break;

  case 47: /* variable: id LTHIRD expression RTHIRD  */
#line 783 "1805064.y"
     {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[-3].symbolInfo)->getName()+ "["+ (yyvsp[-1].symbolInfo)->getName()+ "]", "NON-TERMINAL");
            fprintf(logout, "Line %d: variable : ID LTHIRD expression RTHIRD \n\n", line_count);
            fprintf(logout, "%s[%s]\n\n", (yyvsp[-3].symbolInfo)->getName().c_str(), (yyvsp[-1].symbolInfo)->getName().c_str());
     
            SymbolInfo *temp= st.lookUpAll((yyvsp[-3].symbolInfo)->getName());

            if(temp != NULL && temp->getSize() <= -1){
                if(temp->getSize() == -1){
                    error_type_mismatch( (yyvsp[-3].symbolInfo)->getName()+ " is a variable ");
                }else{
                    error_type_mismatch( (yyvsp[-3].symbolInfo)->getName()+ " not an array ");
                }
            }

            if((yyvsp[-1].symbolInfo)->getRetType()== "void"){
                error_typecast_void();
            }

            if((yyvsp[-1].symbolInfo)->getRetType() != "int"){
                error_array_index_invalid();
            }

            if(temp == NULL){
                error_undeclared_var((yyvsp[-3].symbolInfo)->getName());

                (yyval.symbolInfo)->setRetType("float");
            }else{
                if(temp->getRetType() != "void"){
                    (yyval.symbolInfo)->setRetType(temp->getRetType());
                }else{
                    (yyval.symbolInfo)->setRetType("float");
                }
            }
     }
#line 2266 "y.tab.c"
    break;

  case 48: /* expression: logic_expression  */
#line 821 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: expression : logic_expression \n\n", line_count);
            fprintf(logout, "%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());

            (yyval.symbolInfo)->setRetType((yyvsp[0].symbolInfo)->getRetType());
            type= (yyvsp[0].symbolInfo)->getRetType();

        }
#line 2280 "y.tab.c"
    break;

  case 49: /* expression: variable ASSIGNOP logic_expression  */
#line 831 "1805064.y"
       {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[-2].symbolInfo)->getName()+ "="+ (yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: expression : variable ASSIGNOP logic_expression \n\n", line_count);
            fprintf(logout, "%s=%s\n\n", (yyvsp[-2].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());

            if((yyvsp[0].symbolInfo)->getRetType()== "void"){
                error_typecast_void();

                (yyvsp[0].symbolInfo)->setType("float");
            }

            if((yyvsp[-2].symbolInfo)->getRetType() == "int" && (yyvsp[0].symbolInfo)->getRetType()== "float"){
                error_type_mismatch();
            }

            (yyval.symbolInfo)->setRetType((yyvsp[-2].symbolInfo)->getRetType());
            type= (yyvsp[-2].symbolInfo)->getRetType();
       }
#line 2303 "y.tab.c"
    break;

  case 50: /* logic_expression: rel_expression  */
#line 852 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: logic_expression : rel_expression \n\n", line_count);
            fprintf(logout, "%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());

            (yyval.symbolInfo)->setRetType((yyvsp[0].symbolInfo)->getRetType());
        }
#line 2315 "y.tab.c"
    break;

  case 51: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 860 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[-2].symbolInfo)->getName()+ (yyvsp[-1].symbolInfo)->getName()+ (yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: logic_expression : rel_expression LOGICOP rel_expression \n\n", line_count);
            fprintf(logout, "%s%s%s\n\n", (yyvsp[-2].symbolInfo)->getName().c_str(), (yyvsp[-1].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());
        
            if((yyvsp[-2].symbolInfo)->getRetType()== "void"){
                error_typecast_void();

            }

            if((yyvsp[0].symbolInfo)->getRetType()== "void"){
                error_typecast_void();

            }

            (yyval.symbolInfo)->setRetType("int");

        }
#line 2338 "y.tab.c"
    break;

  case 52: /* rel_expression: simple_expression  */
#line 881 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: rel_expression : simple_expression \n\n", line_count);
            fprintf(logout, "%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());

            (yyval.symbolInfo)->setRetType((yyvsp[0].symbolInfo)->getRetType());
        }
#line 2350 "y.tab.c"
    break;

  case 53: /* rel_expression: simple_expression RELOP simple_expression  */
#line 889 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[-2].symbolInfo)->getName()+ (yyvsp[-1].symbolInfo)->getName()+ (yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: rel_expression : simple_expression RELOP simple_expression \n\n", line_count);
            fprintf(logout, "%s%s%s\n\n", (yyvsp[-2].symbolInfo)->getName().c_str(), (yyvsp[-1].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());

            if((yyvsp[-2].symbolInfo)->getRetType()== "void"){
                error_typecast_void();

            }

            if((yyvsp[0].symbolInfo)->getRetType()== "void"){
                error_typecast_void();

            }

            (yyval.symbolInfo)->setRetType("int");

        }
#line 2373 "y.tab.c"
    break;

  case 54: /* simple_expression: term  */
#line 910 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: simple_expression : term \n\n", line_count);
            fprintf(logout, "%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());

            (yyval.symbolInfo)->setRetType((yyvsp[0].symbolInfo)->getRetType());
        }
#line 2385 "y.tab.c"
    break;

  case 55: /* simple_expression: simple_expression ADDOP term  */
#line 918 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[-2].symbolInfo)->getName()+ (yyvsp[-1].symbolInfo)->getName()+ (yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: simple_expression : simple_expression ADDOP term  \n\n", line_count);
            fprintf(logout, "%s%s%s\n\n", (yyvsp[-2].symbolInfo)->getName().c_str(), (yyvsp[-1].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());
        
            if((yyvsp[-2].symbolInfo)->getRetType()== "void"){
                error_typecast_void();

                (yyvsp[-2].symbolInfo)->setRetType("float"); //default type
            }

            if((yyvsp[0].symbolInfo)->getRetType()== "void"){
                error_typecast_void();

                (yyvsp[0].symbolInfo)->setRetType("float"); //default type
            }

            if((yyvsp[-2].symbolInfo)->getRetType()== "float" || (yyvsp[0].symbolInfo)->getRetType()== "float"){
                (yyval.symbolInfo)->setRetType("float");
            }else{
                (yyval.symbolInfo)->setRetType("int");
            }
        }
#line 2413 "y.tab.c"
    break;

  case 56: /* term: unary_expression  */
#line 944 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: term :unary_expression\n\n", line_count);
            fprintf(logout, "%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());

            (yyval.symbolInfo)->setRetType((yyvsp[0].symbolInfo)->getRetType());
        }
#line 2425 "y.tab.c"
    break;

  case 57: /* term: term MULOP unary_expression  */
#line 952 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[-2].symbolInfo)->getName()+ (yyvsp[-1].symbolInfo)->getName()+ (yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: term : term MULOP unary_expression  \n\n", line_count);
            fprintf(logout, "%s%s%s\n\n", (yyvsp[-2].symbolInfo)->getName().c_str(), (yyvsp[-1].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());

            if((yyvsp[-2].symbolInfo)->getRetType()== "void"){
                error_typecast_void();

                (yyvsp[-2].symbolInfo)->setRetType("float"); //default type
            }

            if((yyvsp[0].symbolInfo)->getRetType()== "void"){
                error_typecast_void();

                (yyvsp[0].symbolInfo)->setRetType("float"); //default type
            }

            if((yyvsp[-1].symbolInfo)->getName() != "%" && ((yyvsp[-2].symbolInfo)->getRetType()== "float" || (yyvsp[0].symbolInfo)->getRetType()== "float" )){
                (yyval.symbolInfo)->setRetType("float");
            }else if((yyvsp[-1].symbolInfo)->getName() == "%" ){
                if(((yyvsp[-2].symbolInfo)->getRetType()== "float" || (yyvsp[0].symbolInfo)->getRetType()== "float" )){
                    error_type_cast_mod();

                    (yyval.symbolInfo)->setRetType("int");
                }if((yyvsp[0].symbolInfo)->getName()== "0"){
                    error_modzero();
                }

            }else{
                (yyval.symbolInfo)->setRetType((yyvsp[-2].symbolInfo)->getRetType());
            }
        }
#line 2462 "y.tab.c"
    break;

  case 58: /* unary_expression: ADDOP unary_expression  */
#line 987 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[-1].symbolInfo)->getName()+ (yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: unary_expression : ADDOP unary_expression  \n\n", line_count);
            fprintf(logout, "%s%s\n\n", (yyvsp[-1].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());

            if((yyvsp[0].symbolInfo)->getRetType()== "void"){
                error_typecast_void();

            (yyvsp[0].symbolInfo)->setRetType("float"); //default type
            }

            (yyval.symbolInfo)->setRetType((yyvsp[0].symbolInfo)->getRetType());
        }
#line 2480 "y.tab.c"
    break;

  case 59: /* unary_expression: NOT unary_expression  */
#line 1001 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo("!"+ (yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: unary_expression : NOT unary_expression  \n\n", line_count);
            fprintf(logout, "!%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());

            if((yyvsp[0].symbolInfo)->getRetType()== "void"){
                error_typecast_void();
            }

            (yyval.symbolInfo)->setRetType("int");
        }
#line 2496 "y.tab.c"
    break;

  case 60: /* unary_expression: factor  */
#line 1013 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: unary_expression : factor  \n\n", line_count);
            fprintf(logout, "%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());

            (yyval.symbolInfo)->setRetType((yyvsp[0].symbolInfo)->getRetType());
        }
#line 2508 "y.tab.c"
    break;

  case 61: /* factor: variable  */
#line 1023 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: factor: variable   \n\n", line_count);
            fprintf(logout, "%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());

            (yyval.symbolInfo)->setRetType((yyvsp[0].symbolInfo)->getRetType());

        }
#line 2521 "y.tab.c"
    break;

  case 62: /* factor: id LPAREN argument_list RPAREN  */
#line 1032 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[-3].symbolInfo)->getName()+ "("+ (yyvsp[-1].symbolInfo)->getName()+ ")", "NON-TERMINAL");
            fprintf(logout, "Line %d: factor:  ID LPAREN argument_list RPAREN  \n\n", line_count);
            fprintf(logout, "%s(%s)\n\n", (yyvsp[-3].symbolInfo)->getName().c_str(), (yyvsp[-1].symbolInfo)->getName().c_str());

            //check argument list with parameter list
            SymbolInfo* temp= st.lookUpAll((yyvsp[-3].symbolInfo)->getName());
            if(temp == NULL){
               error_undeclared_func((yyvsp[-3].symbolInfo)->getName());

               (yyval.symbolInfo)->setRetType("float");
            } else if(temp->getSize() != -3){
                error_not_function((yyvsp[-3].symbolInfo)->getName());

                (yyval.symbolInfo)->setRetType("float");

                //for testing will comment out
                sz= 5;
                for(int j= 0; j< sz; j++){
                y= y+j;
                x= y;
                }
                //for testing
            }

            else{
                if(temp->getParamSize()==1 && arg_list.size()== 0 && temp->getParam(0).par_type== "void"){
                    
                    (yyval.symbolInfo)->setRetType(temp->getRetType());
                }else if(temp->getParamSize() != arg_list.size()){
                    error_inconsistent_func_size(temp->getName());

                    (yyval.symbolInfo)->setRetType(temp->getRetType());
                }else{
                ///size same, type checking

                    int i=0;
                    while(i< arg_list.size()){
                    if(temp->getParam(i).par_type != arg_list[i]){
                            break;
                        }
                        i++;
                    }

                    if(i== arg_list.size()){
                        (yyval.symbolInfo)->setRetType(temp->getRetType());
                    }else{
                        i++;
                        error_inconsistent_func_type(i, temp->getName());

                        (yyval.symbolInfo)->setRetType(temp->getRetType());
                    }
                }

            }

            arg_list.clear();
        }
#line 2584 "y.tab.c"
    break;

  case 63: /* factor: LPAREN expression RPAREN  */
#line 1091 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo("("+ (yyvsp[-1].symbolInfo)->getName()+ ")", "NON-TERMINAL");
            fprintf(logout, "Line %d: factor: LPAREN expression RPAREN  \n\n", line_count);
            fprintf(logout, "(%s)\n\n", (yyvsp[-1].symbolInfo)->getName().c_str());

            if((yyvsp[-1].symbolInfo)->getRetType()== "void"){
                error_typecast_void();

                (yyval.symbolInfo)->setRetType("float");
            }

            (yyval.symbolInfo)->setRetType((yyvsp[-1].symbolInfo)->getRetType());


        }
#line 2604 "y.tab.c"
    break;

  case 64: /* factor: CONST_INT  */
#line 1107 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: factor : CONST_INT  \n\n", line_count);
            fprintf(logout, "%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());

            (yyval.symbolInfo)->setRetType("int");
        }
#line 2616 "y.tab.c"
    break;

  case 65: /* factor: CONST_FLOAT  */
#line 1115 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: factor : CONST_FLOAT  \n\n", line_count);
            fprintf(logout, "%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());

            (yyval.symbolInfo)->setRetType("float");
        }
#line 2628 "y.tab.c"
    break;

  case 66: /* factor: variable INCOP  */
#line 1123 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[-1].symbolInfo)->getName()+ "++", "NON-TERMINAL");
            fprintf(logout, "Line %d: factor : variable INCOP  \n\n", line_count);
            fprintf(logout, "%s++\n\n", (yyvsp[-1].symbolInfo)->getName().c_str());

            (yyval.symbolInfo)->setRetType((yyvsp[-1].symbolInfo)->getRetType());
        }
#line 2640 "y.tab.c"
    break;

  case 67: /* factor: variable DECOP  */
#line 1131 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[-1].symbolInfo)->getName()+ "--", "NON-TERMINAL");
            fprintf(logout, "Line %d: factor : variable DECOP  \n\n", line_count);
            fprintf(logout, "%s--\n\n", (yyvsp[-1].symbolInfo)->getName().c_str());

            (yyval.symbolInfo)->setRetType((yyvsp[-1].symbolInfo)->getRetType());
        }
#line 2652 "y.tab.c"
    break;

  case 68: /* argument_list: arguments  */
#line 1141 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: argument_list : arguments  \n\n", line_count);
            fprintf(logout, "%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());
        }
#line 2662 "y.tab.c"
    break;

  case 69: /* argument_list: %empty  */
#line 1147 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo("", "NON-TERMINAL");
            fprintf(logout, "Line %d: argument_list : epsilon  \n\n", line_count);
            fprintf(logout, "\n\n");
        }
#line 2672 "y.tab.c"
    break;

  case 70: /* arguments: arguments COMMA logic_expression  */
#line 1155 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[-2].symbolInfo)->getName()+ ","+ (yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: arguments : arguments COMMA logic_expression  \n\n", line_count);
            fprintf(logout, "%s,%s\n\n", (yyvsp[-2].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());

            if((yyvsp[0].symbolInfo)->getRetType()== "void"){
                error_typecast_void();

                (yyvsp[0].symbolInfo)->setRetType("float");
            }

            arg_list.push_back((yyvsp[0].symbolInfo)->getRetType());
        }
#line 2690 "y.tab.c"
    break;

  case 71: /* arguments: logic_expression  */
#line 1169 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: arguments : logic_expression \n\n", line_count);
            fprintf(logout, "%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());

            if((yyvsp[0].symbolInfo)->getRetType()== "void"){
                error_typecast_void();

                (yyvsp[0].symbolInfo)->setRetType("float");
            }

            arg_list.push_back((yyvsp[0].symbolInfo)->getRetType());
        
        }
#line 2709 "y.tab.c"
    break;


#line 2713 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1185 "1805064.y"

int main(int argc,char *argv[])
{
    if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	
	logout= fopen("1805064_log.txt","w");
	errout= fopen("1805064_error.txt","w");

	yyin= fin;
	yyparse();
    st.printAll(logout);
    fprintf(logout, "Total lines: %d\n", line_count);
    fprintf(logout, "Total errors: %d", error);
	fclose(yyin);
	fclose(logout);
	fclose(errout);
 
}
