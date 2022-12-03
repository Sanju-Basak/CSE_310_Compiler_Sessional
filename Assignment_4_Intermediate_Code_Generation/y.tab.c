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


#include<bits/stdc++.h>
#include "1805064_SymbolTable.h"

using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;
extern int line_count;
extern int error;
int mainFlag= 0;

FILE *logout, *errout;
FILE *dataout, *codeout;
FILE *resultout;

SymbolTable st;
SymbolInfo *symb= NULL; //current func

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


//for newLabel newLabel and newTemp
int label_count = 0;
int temp_count = 0;



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

//////newLabel newTemp

string newLabel() {
    string str = "L", temp;
    stringstream ss;
    ss << label_count;
    ss >> temp;
    str += temp;
    label_count++;
    return str;
}

string newTemp()   {
    string str = "t", temp;
    stringstream ss;
    ss << temp_count;
    ss >> temp;
    str += temp;
    temp_count++;
    return str;
}

void MergeFile(){
    fstream f1,f2,f3; 
    string str1,str2; //str1 for fetching string line from file 1 and str2 for fetching string from file2
  
    f1.open("dataout.txt",ios::in);//opening file in reading mode
    f2.open("codeout.txt",ios::in);
    f3.open("code.asm",ios::out);//opening file in writing mode
    cout<< "Hello\n";
    while(getline(f1, str1)){ //read lines from file object and put it into string and push back to file 3.
         f3<<str1; // inserting the fetched string inside file3
         f3<<endl;
      }

    while(getline(f2, str2)){ //Same step for file 2 to file 3 fetching
         f3<<str2;
         f3<<endl;
      }

    f1.close();
    f2.close();
    f3.close();
}



#line 322 "y.tab.c"

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

#line 441 "y.tab.c"

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
  YYSYMBOL_RETURN = 9,                     /* RETURN  */
  YYSYMBOL_PRINTLN = 10,                   /* PRINTLN  */
  YYSYMBOL_INCOP = 11,                     /* INCOP  */
  YYSYMBOL_DECOP = 12,                     /* DECOP  */
  YYSYMBOL_ASSIGNOP = 13,                  /* ASSIGNOP  */
  YYSYMBOL_NOT = 14,                       /* NOT  */
  YYSYMBOL_LPAREN = 15,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 16,                    /* RPAREN  */
  YYSYMBOL_LCURL = 17,                     /* LCURL  */
  YYSYMBOL_RCURL = 18,                     /* RCURL  */
  YYSYMBOL_LTHIRD = 19,                    /* LTHIRD  */
  YYSYMBOL_RTHIRD = 20,                    /* RTHIRD  */
  YYSYMBOL_COMMA = 21,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 22,                 /* SEMICOLON  */
  YYSYMBOL_ADDOP = 23,                     /* ADDOP  */
  YYSYMBOL_MULOP = 24,                     /* MULOP  */
  YYSYMBOL_RELOP = 25,                     /* RELOP  */
  YYSYMBOL_LOGICOP = 26,                   /* LOGICOP  */
  YYSYMBOL_CONST_INT = 27,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 28,               /* CONST_FLOAT  */
  YYSYMBOL_ID = 29,                        /* ID  */
  YYSYMBOL_WHILE = 30,                     /* WHILE  */
  YYSYMBOL_LOWER_THAN_ELSE = 31,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_start = 33,                     /* start  */
  YYSYMBOL_34_1 = 34,                      /* $@1  */
  YYSYMBOL_program = 35,                   /* program  */
  YYSYMBOL_unit = 36,                      /* unit  */
  YYSYMBOL_func_declaration = 37,          /* func_declaration  */
  YYSYMBOL_func_definition = 38,           /* func_definition  */
  YYSYMBOL_39_2 = 39,                      /* $@2  */
  YYSYMBOL_40_3 = 40,                      /* $@3  */
  YYSYMBOL_41_4 = 41,                      /* $@4  */
  YYSYMBOL_dummy_func1 = 42,               /* dummy_func1  */
  YYSYMBOL_dummy_func1_dec = 43,           /* dummy_func1_dec  */
  YYSYMBOL_dummy_func1_def = 44,           /* dummy_func1_def  */
  YYSYMBOL_parameter_list = 45,            /* parameter_list  */
  YYSYMBOL_compound_statement = 46,        /* compound_statement  */
  YYSYMBOL_dummy_func = 47,                /* dummy_func  */
  YYSYMBOL_var_declaration = 48,           /* var_declaration  */
  YYSYMBOL_type_specifier = 49,            /* type_specifier  */
  YYSYMBOL_id = 50,                        /* id  */
  YYSYMBOL_declaration_list = 51,          /* declaration_list  */
  YYSYMBOL_statements = 52,                /* statements  */
  YYSYMBOL_statement = 53,                 /* statement  */
  YYSYMBOL_54_5 = 54,                      /* $@5  */
  YYSYMBOL_55_6 = 55,                      /* $@6  */
  YYSYMBOL_56_7 = 56,                      /* $@7  */
  YYSYMBOL_57_8 = 57,                      /* $@8  */
  YYSYMBOL_58_9 = 58,                      /* $@9  */
  YYSYMBOL_59_10 = 59,                     /* $@10  */
  YYSYMBOL_if_cond = 60,                   /* if_cond  */
  YYSYMBOL_61_11 = 61,                     /* $@11  */
  YYSYMBOL_dummy_func2_type = 62,          /* dummy_func2_type  */
  YYSYMBOL_dummy_func2_void = 63,          /* dummy_func2_void  */
  YYSYMBOL_expression_statement = 64,      /* expression_statement  */
  YYSYMBOL_variable = 65,                  /* variable  */
  YYSYMBOL_expression = 66,                /* expression  */
  YYSYMBOL_logic_expression = 67,          /* logic_expression  */
  YYSYMBOL_rel_expression = 68,            /* rel_expression  */
  YYSYMBOL_simple_expression = 69,         /* simple_expression  */
  YYSYMBOL_term = 70,                      /* term  */
  YYSYMBOL_unary_expression = 71,          /* unary_expression  */
  YYSYMBOL_factor = 72,                    /* factor  */
  YYSYMBOL_argument_list = 73,             /* argument_list  */
  YYSYMBOL_arguments = 74                  /* arguments  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   173

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

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
       0,   274,   274,   274,   290,   296,   306,   312,   318,   326,
     337,   347,   347,   362,   370,   362,   388,   396,   409,   454,
     466,   478,   490,   505,   514,   525,   549,   575,   583,   591,
     601,   607,   627,   650,   669,   692,   698,   706,   712,   718,
     724,   731,   745,   724,   759,   766,   765,   815,   822,   814,
     837,   855,   877,   876,   887,   896,   905,   916,   928,   974,
    1022,  1032,  1068,  1076,  1114,  1122,  1168,  1176,  1213,  1221,
    1278,  1296,  1317,  1327,  1357,  1429,  1447,  1468,  1489,  1537,
    1569,  1576,  1583,  1600
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
  "FLOAT", "VOID", "ELSE", "RETURN", "PRINTLN", "INCOP", "DECOP",
  "ASSIGNOP", "NOT", "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD",
  "RTHIRD", "COMMA", "SEMICOLON", "ADDOP", "MULOP", "RELOP", "LOGICOP",
  "CONST_INT", "CONST_FLOAT", "ID", "WHILE", "LOWER_THAN_ELSE", "$accept",
  "start", "$@1", "program", "unit", "func_declaration", "func_definition",
  "$@2", "$@3", "$@4", "dummy_func1", "dummy_func1_dec", "dummy_func1_def",
  "parameter_list", "compound_statement", "dummy_func", "var_declaration",
  "type_specifier", "id", "declaration_list", "statements", "statement",
  "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "if_cond", "$@11",
  "dummy_func2_type", "dummy_func2_void", "expression_statement",
  "variable", "expression", "logic_expression", "rel_expression",
  "simple_expression", "term", "unary_expression", "factor",
  "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-111)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-19)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -111,    16,    56,  -111,  -111,  -111,  -111,    56,  -111,  -111,
    -111,  -111,    -4,  -111,  -111,     4,    34,     7,    24,    -4,
    -111,    22,    53,    32,  -111,    47,     6,    -4,    44,    64,
    -111,    47,    56,  -111,    74,  -111,    92,    95,  -111,    -4,
    -111,  -111,  -111,  -111,    92,  -111,    73,  -111,  -111,    99,
     122,    98,   125,    98,    98,  -111,  -111,    98,  -111,  -111,
    -111,  -111,  -111,    -4,    25,   101,  -111,   133,  -111,    54,
     120,  -111,   119,    97,   123,  -111,  -111,    98,    70,   126,
      -4,    63,  -111,   134,  -111,   138,   130,    98,    98,  -111,
    -111,  -111,  -111,  -111,    98,  -111,    98,    98,    98,    98,
    -111,  -111,  -111,   139,  -111,    98,  -111,   144,   140,   142,
     129,  -111,  -111,   123,   131,  -111,   147,  -111,   143,  -111,
    -111,    98,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
      70,   148,   129,  -111,  -111,  -111,  -111,   129,  -111,  -111,
      98,  -111,  -111,   150,  -111,   129,  -111
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,    27,    28,    29,     3,     5,     7,
       8,     6,     0,     4,    30,    33,     0,     0,     0,     0,
      26,     0,     0,    31,    34,    17,     0,    22,     0,     0,
      13,    17,     0,    21,     0,    10,     0,     0,    11,    20,
      32,    25,    14,     9,     0,    19,     0,    15,    12,     0,
       0,     0,     0,     0,     0,    24,    56,     0,    76,    77,
      47,    39,    37,     0,    58,     0,    35,    44,    38,    73,
       0,    60,    62,    64,    66,    68,    72,     0,     0,     0,
       0,    73,    71,     0,    70,     0,    33,    81,     0,    23,
      36,    45,    78,    79,     0,    57,     0,     0,     0,     0,
      54,    40,    51,     0,    75,     0,    83,     0,    80,     0,
       0,    61,    63,    67,    65,    69,     0,    54,     0,    48,
      74,     0,    59,    46,    55,    55,    50,    54,    82,    52,
       0,     0,     0,    41,    55,    53,    54,     0,    55,    49,
       0,    54,    55,     0,    42,     0,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,  -111,  -111,   160,  -111,  -111,  -111,  -111,  -111,
    -111,   137,   141,  -111,   -24,  -111,    29,    11,   -10,  -111,
    -111,   -64,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -106,  -110,   -73,   -49,   -51,   -80,    75,    71,    76,   -47,
    -111,  -111,  -111
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     7,     8,     9,    10,    44,    36,    47,
      18,    29,    30,    26,    61,    46,    62,    63,    64,    16,
      65,    66,   117,   136,   145,   110,    85,   127,    67,   132,
     116,   129,    68,    69,    70,    71,    72,    73,    74,    75,
      76,   107,   108
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      79,    90,    15,    83,    81,   101,    82,   106,    81,    23,
      84,   125,    42,    12,   111,   130,     3,    33,    12,   -16,
      48,   131,    31,    17,   137,    14,   100,    32,   140,    45,
     138,    11,   143,    27,    21,   142,    11,   109,    81,    22,
      87,   128,    24,    39,    88,    81,   123,    81,    81,    81,
      81,    28,   115,    86,   119,    19,    20,   133,     4,     5,
       6,     4,     5,     6,   -18,    92,    93,    94,   135,    25,
     103,    34,    81,   139,    92,    93,    49,    50,     4,     5,
       6,   146,    51,    52,    53,    54,    35,    53,    54,   141,
      41,    55,    56,    57,    40,    56,    57,    58,    59,    14,
      58,    59,    14,    60,    49,    50,     4,     5,     6,    41,
      51,    52,    53,    54,    77,    53,    54,    43,    41,    89,
      97,    57,    98,    56,    57,    58,    59,    14,    58,    59,
      14,    60,    49,    50,     4,     5,     6,    78,    51,    52,
      80,    91,    95,    53,    54,    96,    41,    99,   102,    17,
     104,    56,    57,   105,    97,   118,    58,    59,    14,    60,
     120,   121,   122,   124,   134,   126,   144,    13,    37,   114,
       0,   112,    38,   113
};

static const yytype_int16 yycheck[] =
{
      51,    65,    12,    54,    53,    78,    53,    87,    57,    19,
      57,   117,    36,     2,    94,   125,     0,    27,     7,    15,
      44,   127,    16,    19,   134,    29,    77,    21,   138,    39,
     136,     2,   142,    22,    27,   141,     7,    88,    87,    15,
      15,   121,    20,    32,    19,    94,   110,    96,    97,    98,
      99,    19,    99,    63,   105,    21,    22,   130,     5,     6,
       7,     5,     6,     7,    17,    11,    12,    13,   132,    16,
      80,    27,   121,   137,    11,    12,     3,     4,     5,     6,
       7,   145,     9,    10,    14,    15,    22,    14,    15,   140,
      17,    18,    22,    23,    20,    22,    23,    27,    28,    29,
      27,    28,    29,    30,     3,     4,     5,     6,     7,    17,
       9,    10,    14,    15,    15,    14,    15,    22,    17,    18,
      23,    23,    25,    22,    23,    27,    28,    29,    27,    28,
      29,    30,     3,     4,     5,     6,     7,    15,     9,    10,
      15,     8,    22,    14,    15,    26,    17,    24,    22,    19,
      16,    22,    23,    15,    23,    16,    27,    28,    29,    30,
      16,    21,    20,    16,    16,    22,    16,     7,    31,    98,
      -1,    96,    31,    97
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    33,    34,     0,     5,     6,     7,    35,    36,    37,
      38,    48,    49,    36,    29,    50,    51,    19,    42,    21,
      22,    27,    15,    50,    20,    16,    45,    49,    19,    43,
      44,    16,    21,    50,    27,    22,    40,    43,    44,    49,
      20,    17,    46,    22,    39,    50,    47,    41,    46,     3,
       4,     9,    10,    14,    15,    18,    22,    23,    27,    28,
      30,    46,    48,    49,    50,    52,    53,    60,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    15,    15,    66,
      15,    65,    71,    66,    71,    58,    50,    15,    19,    18,
      53,     8,    11,    12,    13,    22,    26,    23,    25,    24,
      66,    64,    22,    50,    16,    15,    67,    73,    74,    66,
      57,    67,    68,    70,    69,    71,    62,    54,    16,    66,
      16,    21,    20,    53,    16,    62,    22,    59,    67,    63,
      63,    62,    61,    64,    16,    53,    55,    63,    62,    53,
      63,    66,    62,    63,    16,    56,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    34,    33,    35,    35,    36,    36,    36,    37,
      37,    39,    38,    40,    41,    38,    42,    43,    44,    45,
      45,    45,    45,    46,    46,    47,    48,    49,    49,    49,
      50,    51,    51,    51,    51,    52,    52,    53,    53,    53,
      54,    55,    56,    53,    53,    57,    53,    58,    59,    53,
      53,    53,    61,    60,    62,    63,    64,    64,    65,    65,
      66,    66,    67,    67,    68,    68,    69,    69,    70,    70,
      71,    71,    71,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    74,    74
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     1,     1,     8,
       7,     0,     9,     0,     0,     9,     0,     0,     0,     4,
       3,     2,     1,     4,     3,     0,     3,     1,     1,     1,
       1,     3,     6,     1,     4,     1,     2,     1,     1,     1,
       0,     0,     0,    16,     1,     0,     4,     0,     0,     9,
       5,     3,     0,     8,     0,     0,     1,     2,     1,     4,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       2,     2,     1,     1,     4,     3,     1,     1,     2,     2,
       1,     0,     3,     1
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
  case 2: /* $@1: %empty  */
#line 274 "1805064.y"
       {
    fprintf(dataout, ".MODEL SMALL\n.STACK 100H\n.DATA\n");
    fprintf(codeout, ".CODE\n");
    fprintf(dataout, "NUMBER_STRING DB '00000$'\n");
}
#line 1607 "y.tab.c"
    break;

  case 3: /* start: $@1 program  */
#line 279 "1805064.y"
        {
        fprintf(codeout, "println proc\n\tLEA SI, NUMBER_STRING\n\tADD SI, 5\n\tCMP AX, 0\n\tJNGE NEG_AX\n\tPRINT_LOOP:\n\tDEC SI\n\tMOV DX, 0\n\t; DX:AX = 0000:AX\n\tMOV BX, 10\n\tDIV BX\n\tADD DL, '0'\n\tMOV [SI], DL\n\tCMP AX, 0\n\tJNE PRINT_LOOP\n\tMOV DX, SI\n\tMOV AH, 9\n\tINT 21H\n\tRET\n\tNEG_AX:\n\tMOV BX, AX\n\tMOV DX, '-'\n\tMOV AH, 2\n\tINT 21H\n\tMOV AX, BX\n\tNEG AX\n\tJMP PRINT_LOOP\n\tprintln endp\n");
        fprintf(codeout, "END MAIN\n");
		//write your code in this block in all the similar blocks below
        // $$= new SymbolInfo($1->getName(), "NON-TERMINAL");
        fprintf(logout, "Line %d: start : program\n\n", line_count);
        //fprintf(logout, "%s \n\n", $1->getName().c_str());
        //MergeFile();
	}
#line 1621 "y.tab.c"
    break;

  case 4: /* program: program unit  */
#line 291 "1805064.y"
    {
        (yyval.symbolInfo)= new SymbolInfo((yyvsp[-1].symbolInfo)->getName()+ (yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
        fprintf(logout, "Line %d: program : program unit\n\n", line_count);
        fprintf(logout, "%s%s\n\n", (yyvsp[-1].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());
    }
#line 1631 "y.tab.c"
    break;

  case 5: /* program: unit  */
#line 297 "1805064.y"
    {
        (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
        fprintf(logout, "Line %d: program : unit\n\n", line_count);
        fprintf(logout, "%s \n\n", (yyvsp[0].symbolInfo)->getName().c_str());
    }
#line 1641 "y.tab.c"
    break;

  case 6: /* unit: var_declaration  */
#line 307 "1805064.y"
    {
        (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
        fprintf(logout, "Line %d: unit : var_declaration\n\n", line_count);
        fprintf(logout, "%s \n\n", (yyvsp[0].symbolInfo)->getName().c_str());
    }
#line 1651 "y.tab.c"
    break;

  case 7: /* unit: func_declaration  */
#line 313 "1805064.y"
     {
        (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
        fprintf(logout, "Line %d: unit : func_declaration\n\n", line_count);
        fprintf(logout, "%s \n\n", (yyvsp[0].symbolInfo)->getName().c_str());
     }
#line 1661 "y.tab.c"
    break;

  case 8: /* unit: func_definition  */
#line 319 "1805064.y"
     {
        (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
        fprintf(logout, "Line %d: unit : func_definition\n\n", line_count);
        fprintf(logout, "%s \n\n", (yyvsp[0].symbolInfo)->getName().c_str());
     }
#line 1671 "y.tab.c"
    break;

  case 9: /* func_declaration: type_specifier id dummy_func1 LPAREN parameter_list RPAREN dummy_func1_dec SEMICOLON  */
#line 327 "1805064.y"
                {
                    if((yyvsp[-6].symbolInfo)->getName()== "main"){
                        mainFlag= 1;
                    }
                    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-7].symbolInfo)->getName()+" "+(yyvsp[-6].symbolInfo)->getName()+"("+(yyvsp[-3].symbolInfo)->getName()+")"+";\n", "NON_TERMINAL");
                    fprintf(logout, "Line %d: func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n", line_count);
                    fprintf(logout, "%s %s(%s); \n\n", (yyvsp[-7].symbolInfo)->getName().c_str(), (yyvsp[-6].symbolInfo)->getName().c_str(), (yyvsp[-3].symbolInfo)->getName().c_str());

                    param_list.clear();
                }
#line 1686 "y.tab.c"
    break;

  case 10: /* func_declaration: type_specifier id dummy_func1 LPAREN RPAREN dummy_func1_dec SEMICOLON  */
#line 338 "1805064.y"
        {
                (yyval.symbolInfo) = new SymbolInfo((yyvsp[-6].symbolInfo)->getName()+" "+(yyvsp[-5].symbolInfo)->getName()+"();\n", "NON_TERMINAL");
                fprintf(logout, "Line %d: func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n", line_count);
                fprintf(logout, "%s %s(); \n\n", (yyvsp[-6].symbolInfo)->getName().c_str(), (yyvsp[-5].symbolInfo)->getName().c_str()); 

                param_list.clear();           
        }
#line 1698 "y.tab.c"
    break;

  case 11: /* $@2: %empty  */
#line 347 "1805064.y"
                                                                                            {
    symb= st.lookUpAll((yyvsp[-5].symbolInfo)->getName());
    //pair<string, SymbolInfo*>pr= st.lookUpAll2($2->getName());
    //cout<< pr.first<<endl;
    //cout<< pr.second->getName()<< endl;
    fprintf(codeout, "\n%s_PROCEDURE PROC\nPUSH BP\nMOV BP, SP\n", (yyvsp[-5].symbolInfo)->getName().c_str());}
#line 1709 "y.tab.c"
    break;

  case 12: /* func_definition: type_specifier id dummy_func1 LPAREN parameter_list RPAREN dummy_func1_def $@2 compound_statement  */
#line 353 "1805064.y"
                {
                    fprintf(codeout, "%s: \n", symb->retLabel.c_str());
                    fprintf(codeout, "\nPOP BP\nRET %d\n",symb->getParamSize()*2);
                    
                    symb= NULL;
                    //$$ = new SymbolInfo($1->getName()+" "+$2->getName()+"("+$5->getName()+") "+$9->getName()+ "\n", "NON_TERMINAL");
                    //fprintf(logout, "Line %d: func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n", line_count);
                    //fprintf(logout, "%s %s(%s) %s \n\n", $1->getName().c_str(), $2->getName().c_str(), $5->getName().c_str(), $9->getName().c_str());
                }
#line 1723 "y.tab.c"
    break;

  case 13: /* $@3: %empty  */
#line 362 "1805064.y"
                                                                             {
            symb= st.lookUpAll((yyvsp[-4].symbolInfo)->getName());
            if ((yyvsp[-4].symbolInfo)->getName()== "main"){
                fprintf(codeout, "\nMAIN PROC\nMOV AX, @DATA\nMOV DS, AX\n");
            }
            else{
                fprintf(codeout, "\n%s_PROCEDURE PROC\nPUSH BP\nMOV BP, SP\n", (yyvsp[-4].symbolInfo)->getName().c_str());
            }
            }
#line 1737 "y.tab.c"
    break;

  case 14: /* $@4: %empty  */
#line 370 "1805064.y"
                                 {
                fprintf(codeout, "%s: \n", symb->retLabel.c_str());
                symb= NULL;
            }
#line 1746 "y.tab.c"
    break;

  case 15: /* func_definition: type_specifier id dummy_func1 LPAREN RPAREN dummy_func1_def $@3 compound_statement $@4  */
#line 374 "1805064.y"
        {
            if ((yyvsp[-7].symbolInfo)->getName()== "main"){
                fprintf(codeout, "\nMOV AH, 4CH\nINT 21H\nmain ENDP\n");
            }
            else{
                fprintf(codeout, "\nPOP BP\nRET\n");
            }            
                /*$$ = new SymbolInfo($1->getName()+" "+$2->getName()+"() "+$8->getName()+ "\n", "NON_TERMINAL");
                fprintf(logout, "Line %d: func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n", line_count);
                fprintf(logout, "%s %s() %s \n\n", $1->getName().c_str(), $2->getName().c_str(), $8->getName().c_str());*/
        }
#line 1762 "y.tab.c"
    break;

  case 16: /* dummy_func1: %empty  */
#line 388 "1805064.y"
             {
    type_final= type;
    name_final= name;


}
#line 1773 "y.tab.c"
    break;

  case 17: /* dummy_func1_dec: %empty  */
#line 396 "1805064.y"
                 {

    ////Insert func name to symboTable
    if(st.lookUpAll(name_final)!= NULL){
        error_multiple_dec(name_final);
    }else{
        insertFunc(name_final, type_final, -2);
    }


}
#line 1789 "y.tab.c"
    break;

  case 18: /* dummy_func1_def: %empty  */
#line 409 "1805064.y"
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
#line 1836 "y.tab.c"
    break;

  case 19: /* parameter_list: parameter_list COMMA type_specifier id  */
#line 455 "1805064.y"
        {
                (yyval.symbolInfo) = new SymbolInfo((yyvsp[-3].symbolInfo)->getName()+","+(yyvsp[-1].symbolInfo)->getName()+ " "+ (yyvsp[0].symbolInfo)->getName(), "NON_TERMINAL");
                fprintf(logout, "Line %d: parameter_list  : parameter_list COMMA type_specifier ID\n\n", line_count);
                fprintf(logout, "%s, %s %s \n\n", (yyvsp[-3].symbolInfo)->getName().c_str(), (yyvsp[-1].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());

                ///updating parameter list
                temp_par.par_type = (yyvsp[-1].symbolInfo)->getName();
                temp_par.par_name = (yyvsp[0].symbolInfo)->getName();

                param_list.push_back(temp_par);
        }
#line 1852 "y.tab.c"
    break;

  case 20: /* parameter_list: parameter_list COMMA type_specifier  */
#line 467 "1805064.y"
        {
                (yyval.symbolInfo) = new SymbolInfo((yyvsp[-2].symbolInfo)->getName()+","+(yyvsp[0].symbolInfo)->getName(), "NON_TERMINAL");
                fprintf(logout, "Line %d: parameter_list  : parameter_list COMMA type_specifier\n\n", line_count);
                fprintf(logout, "%s, %s \n\n", (yyvsp[-2].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());

                ///updating parameter list
                temp_par.par_type = (yyvsp[0].symbolInfo)->getName();
                temp_par.par_name = "";

                param_list.push_back(temp_par);
        }
#line 1868 "y.tab.c"
    break;

  case 21: /* parameter_list: type_specifier id  */
#line 479 "1805064.y"
        {
                (yyval.symbolInfo) = new SymbolInfo((yyvsp[-1].symbolInfo)->getName()+" "+(yyvsp[0].symbolInfo)->getName(), "NON_TERMINAL");
                fprintf(logout, "Line %d: parameter_list  : type_specifier ID\n\n", line_count);
                fprintf(logout, "%s %s \n\n", (yyvsp[-1].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());

                ///updating parameter list
                temp_par.par_type = (yyvsp[-1].symbolInfo)->getName();
                temp_par.par_name = (yyvsp[0].symbolInfo)->getName();

                param_list.push_back(temp_par);
        }
#line 1884 "y.tab.c"
    break;

  case 22: /* parameter_list: type_specifier  */
#line 491 "1805064.y"
        {
                (yyval.symbolInfo) = new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON_TERMINAL");
                fprintf(logout, "Line %d: parameter_list  : type_specifier\n\n", line_count);
                fprintf(logout, "%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());

                ///updating parameter list
                temp_par.par_type = (yyvsp[0].symbolInfo)->getName();
                temp_par.par_name = "";

                param_list.push_back(temp_par);
        }
#line 1900 "y.tab.c"
    break;

  case 23: /* compound_statement: LCURL dummy_func statements RCURL  */
#line 506 "1805064.y"
        {
                (yyval.symbolInfo) = new SymbolInfo("{\n"+ (yyvsp[-1].symbolInfo)->getName()+ "}\n" , "NON_TERMINAL");
                fprintf(logout, "Line %d: compound_statement : LCURL statements RCURL\n\n", line_count);
                fprintf(logout, "{\n%s\n}\n\n", (yyvsp[-1].symbolInfo)->getName().c_str());

                st.printAll(logout);
                st.ExitScope();
        }
#line 1913 "y.tab.c"
    break;

  case 24: /* compound_statement: LCURL dummy_func RCURL  */
#line 515 "1805064.y"
             {
                (yyval.symbolInfo) = new SymbolInfo("{\n}\n" , "NON_TERMINAL");
                fprintf(logout, "Line %d: compound_statement : LCURL RCURL\n\n", line_count);
                fprintf(logout, "{\n\n}\n\n");

                st.printAll(logout);
                st.ExitScope();
             }
#line 1926 "y.tab.c"
    break;

  case 25: /* dummy_func: %empty  */
#line 525 "1805064.y"
            {


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
#line 1953 "y.tab.c"
    break;

  case 26: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 550 "1805064.y"
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
#line 1981 "y.tab.c"
    break;

  case 27: /* type_specifier: INT  */
#line 576 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo("int", "NON-TERMINAL");
            fprintf(logout, "Line %d: type_specifier : INT\n\n", line_count);
            fprintf(logout, "int \n\n");

            type= "int";
        }
#line 1993 "y.tab.c"
    break;

  case 28: /* type_specifier: FLOAT  */
#line 584 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo("float", "NON-TERMINAL");
            fprintf(logout, "Line %d: type_specifier : FLOAT\n\n", line_count);
            fprintf(logout, "float \n\n");

            type= "float";
        }
#line 2005 "y.tab.c"
    break;

  case 29: /* type_specifier: VOID  */
#line 592 "1805064.y"
         {
            (yyval.symbolInfo)= new SymbolInfo("void", "NON-TERMINAL");
            fprintf(logout, "Line %d: type_specifier : VOID\n\n", line_count);
            fprintf(logout, "void \n\n");

            type= "void";
         }
#line 2017 "y.tab.c"
    break;

  case 30: /* id: ID  */
#line 601 "1805064.y"
       {
            (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
            name = (yyvsp[0].symbolInfo)->getName();
    }
#line 2026 "y.tab.c"
    break;

  case 31: /* declaration_list: declaration_list COMMA id  */
#line 608 "1805064.y"
                {
                    fprintf(dataout, "  %s%s DW 0\n", (yyvsp[0].symbolInfo)->getName().c_str(), st.getScopeID().c_str());
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
#line 2050 "y.tab.c"
    break;

  case 32: /* declaration_list: declaration_list COMMA id LTHIRD CONST_INT RTHIRD  */
#line 628 "1805064.y"
           { 
                fprintf(dataout, "  %s%s DW %s DUP(0)\n", (yyvsp[-3].symbolInfo)->getName().c_str(), st.getScopeID().c_str(), (yyvsp[-1].symbolInfo)->getName().c_str());  
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
#line 2077 "y.tab.c"
    break;

  case 33: /* declaration_list: id  */
#line 651 "1805064.y"
           {
                fprintf(dataout, "  %s%s DW 0\n", (yyvsp[0].symbolInfo)->getName().c_str(), st.getScopeID().c_str());
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
#line 2100 "y.tab.c"
    break;

  case 34: /* declaration_list: id LTHIRD CONST_INT RTHIRD  */
#line 670 "1805064.y"
           {
                fprintf(dataout, "  %s%s DW %s DUP(0)\n", (yyvsp[-3].symbolInfo)->getName().c_str(), st.getScopeID().c_str(), (yyvsp[-1].symbolInfo)->getName().c_str());
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
#line 2125 "y.tab.c"
    break;

  case 35: /* statements: statement  */
#line 693 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: statements : statement\n\n", line_count);
            fprintf(logout, "%s \n\n", (yyvsp[0].symbolInfo)->getName().c_str());
        }
#line 2135 "y.tab.c"
    break;

  case 36: /* statements: statements statement  */
#line 699 "1805064.y"
       {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[-1].symbolInfo)->getName()+ (yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: statements : statements statement\n\n", line_count);
            fprintf(logout, "%s%s\n\n", (yyvsp[-1].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());
       }
#line 2145 "y.tab.c"
    break;

  case 37: /* statement: var_declaration  */
#line 707 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: statement : var_declaration\n\n", line_count);
            fprintf(logout, "%s \n\n", (yyvsp[0].symbolInfo)->getName().c_str());
        }
#line 2155 "y.tab.c"
    break;

  case 38: /* statement: expression_statement  */
#line 713 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: statement : expression_statement\n\n", line_count);
            fprintf(logout, "%s \n\n", (yyvsp[0].symbolInfo)->getName().c_str());
        }
#line 2165 "y.tab.c"
    break;

  case 39: /* statement: compound_statement  */
#line 719 "1805064.y"
        {
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: statement : compound_statement\n\n", line_count);
            fprintf(logout, "%s \n\n", (yyvsp[0].symbolInfo)->getName().c_str());
        }
#line 2175 "y.tab.c"
    break;

  case 40: /* $@5: %empty  */
#line 724 "1805064.y"
                                            {
        string l1= newLabel();
        //cout<< l1<< endl;
        (yyvsp[0].symbolInfo)->forLabel1= l1;
        fprintf(codeout, "%s:\n", l1.c_str());
        }
#line 2186 "y.tab.c"
    break;

  case 41: /* $@6: %empty  */
#line 731 "1805064.y"
      {
          string l4= newLabel();
          (yyvsp[0].symbolInfo)->forLabel3= l4;
          cout<< (yyvsp[0].symbolInfo)->getAName()<< endl;
          fprintf(codeout, "CMP %s, 0\n", (yyvsp[0].symbolInfo)->getAName().c_str());
          fprintf(codeout, "JE %s\n", l4.c_str());
          string l2= newLabel();
          (yyvsp[0].symbolInfo)->forLabel1= l2;
          fprintf(codeout, "\tJMP %s\n", l2.c_str());
          string l3= newLabel();
          (yyvsp[0].symbolInfo)->forLabel2= l3;
          fprintf(codeout, "%s:\n", l3.c_str());

    }
#line 2205 "y.tab.c"
    break;

  case 42: /* $@7: %empty  */
#line 745 "1805064.y"
    {
        fprintf(codeout, "JMP %s\n", (yyvsp[-11].symbolInfo)->forLabel1.c_str());
        fprintf(codeout, "%s:\n", (yyvsp[-7].symbolInfo)->forLabel1.c_str());

    }
#line 2215 "y.tab.c"
    break;

  case 43: /* statement: FOR LPAREN expression_statement $@5 dummy_func2_type dummy_func2_void expression_statement $@6 dummy_func2_type dummy_func2_void expression dummy_func2_type dummy_func2_void RPAREN $@7 statement  */
#line 751 "1805064.y"
      {
            fprintf(codeout, "JMP %s\n", (yyvsp[-9].symbolInfo)->forLabel2.c_str());
            fprintf(codeout, "%s:\n", (yyvsp[-9].symbolInfo)->forLabel3.c_str());
            //$$= new SymbolInfo("for("+$3->getName()+ $6->getName()+ $9->getName()+ ")"+ $13->getName()+ "\n", "NON-TERMINAL");
            fprintf(logout, "Line %d: statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n", line_count);
            //fprintf(logout, "for(%s%s%s)%s \n\n", $3->getName().c_str(), $6->getName().c_str(), $9->getName().c_str(), $13->getName().c_str());
      }
#line 2227 "y.tab.c"
    break;

  case 44: /* statement: if_cond  */
#line 759 "1805064.y"
                                     {
            fprintf(codeout, "%s:\n", (yyvsp[0].symbolInfo)->forLabel1.c_str());
            //$$= new SymbolInfo("if("+ $3->getName()+ ")"+ $7->getName()+ "\n", "NON-TERMINAL");
            fprintf(logout, "Line %d: statement : IF LPAREN expression RPAREN statement\n\n", line_count);
            //fprintf(logout, "if(%s)%s \n\n", $3->getName().c_str(), $7->getName().c_str());          
      }
#line 2238 "y.tab.c"
    break;

  case 45: /* $@8: %empty  */
#line 766 "1805064.y"
      {
          string temp2= newLabel();
          (yyvsp[-1].symbolInfo)->forLabel2= temp2;
          fprintf(codeout, "JMP %s\n", temp2.c_str());         
          fprintf(codeout, "%s:\n", (yyvsp[-1].symbolInfo)->forLabel1.c_str());
      }
#line 2249 "y.tab.c"
    break;

  case 46: /* statement: if_cond ELSE $@8 statement  */
#line 773 "1805064.y"
      {
            fprintf(codeout, "%s:\n", (yyvsp[-3].symbolInfo)->forLabel2.c_str());
            //$$= new SymbolInfo("if("+ $3->getName()+ ")"+ $7->getName()+ " else"+ $9->getName()+ "\n", "NON-TERMINAL");
            fprintf(logout, "Line %d: statement : IF LPAREN expression RPAREN statement ELSE statement\n\n", line_count);
            //fprintf(logout, "if(%s)%s else%s\n\n", $3->getName().c_str(), $7->getName().c_str(), $9->getName().c_str());         
      }
#line 2260 "y.tab.c"
    break;

  case 47: /* $@9: %empty  */
#line 815 "1805064.y"
      {
          string temp= newLabel();
          (yyvsp[0].symbolInfo)->forLabel1= temp;
          fprintf(codeout, "%s:\n", temp.c_str());

      }
#line 2271 "y.tab.c"
    break;

  case 48: /* $@10: %empty  */
#line 822 "1805064.y"
      {
        string temp2= newLabel();
        (yyvsp[-3].symbolInfo)->forLabel2= temp2;
        fprintf(codeout, "CMP %s, 0\n", (yyvsp[0].symbolInfo)->getAName().c_str());
        fprintf(codeout, "JE %s\n", temp2.c_str());

      }
#line 2283 "y.tab.c"
    break;

  case 49: /* statement: WHILE $@9 LPAREN expression $@10 dummy_func2_type RPAREN dummy_func2_void statement  */
#line 830 "1805064.y"
      {
            //$$= new SymbolInfo("while("+ $3->getName()+ ")"+ $7->getName()+ "\n", "NON-TERMINAL");
            fprintf(codeout, "JMP %s\n", (yyvsp[-8].symbolInfo)->forLabel1.c_str());
            fprintf(codeout, "%s:\n", (yyvsp[-8].symbolInfo)->forLabel2.c_str());
            fprintf(logout, "Line %d: statement : WHILE LPAREN expression RPAREN statement\n\n", line_count);
            //fprintf(logout, "while(%s)%s\n\n", $3->getName().c_str(), $7->getName().c_str());
      }
#line 2295 "y.tab.c"
    break;

  case 50: /* statement: PRINTLN LPAREN id RPAREN SEMICOLON  */
#line 838 "1805064.y"
      {
            //$$= new SymbolInfo("printf("+ $3->getName()+ ");\n", "NON-TERMINAL");
            pair<string, SymbolInfo*>pr= st.lookUpAll2((yyvsp[-2].symbolInfo)->getName());
            fprintf(logout, "Line %d: statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n", line_count);
             string str= pr.second->getName();
             str.append(pr.first);
            fprintf(logout, "printf(%s);\n\n", pr.second->getAName().c_str());

            if(st.lookUp((yyvsp[-2].symbolInfo)->getName())== NULL){
                error_undeclared_var((yyvsp[-2].symbolInfo)->getName());
            }

            fprintf(codeout, "\n;println(%s)\n", (yyvsp[-2].symbolInfo)->getName().c_str());
            fprintf(codeout, "MOV AX, %s\n",str.c_str());
            fprintf(codeout, "CALL println\n");
            fprintf(codeout, "\n;printing new line\nmov ah,2\nmov dl,10\nint 21h\nmov dl,13\nint 21h\n");
      }
#line 2317 "y.tab.c"
    break;

  case 51: /* statement: RETURN expression SEMICOLON  */
#line 856 "1805064.y"
      {

            fprintf(codeout, "\n;return %s\n\n", (yyvsp[-1].symbolInfo)->getName().c_str());
            fprintf(codeout, "MOV CX, %s\n", (yyvsp[-1].symbolInfo)->getAName().c_str());
            string temp= newLabel();
            fprintf(codeout, "JMP %s\n", temp.c_str());
            symb->retLabel= temp;

            //$$= new SymbolInfo("return "+ $2->getName()+ ";\n", "NON-TERMINAL");
            fprintf(logout, "Line %d: statement : RETURN expression SEMICOLON\n\n", line_count);
            fprintf(logout, "return %s;\n\n", (yyvsp[-1].symbolInfo)->getName().c_str());

            if((yyvsp[-1].symbolInfo)->getRetType()== "void"){
                error_typecast_void();
            }
      }
#line 2338 "y.tab.c"
    break;

  case 52: /* $@11: %empty  */
#line 877 "1805064.y"
        {
            string temp= newLabel();  
            fprintf(codeout, "CMP %s, 0\nJE %s\n", (yyvsp[-3].symbolInfo)->getAName().c_str(), temp.c_str());
            (yyvsp[-3].symbolInfo)->forLabel1= temp;
        }
#line 2348 "y.tab.c"
    break;

  case 53: /* if_cond: IF LPAREN expression dummy_func2_type RPAREN dummy_func2_void $@11 statement  */
#line 882 "1805064.y"
          {
           (yyval.symbolInfo)= (yyvsp[-5].symbolInfo);
}
#line 2356 "y.tab.c"
    break;

  case 54: /* dummy_func2_type: %empty  */
#line 887 "1805064.y"
                    {

    type_final= type;



}
#line 2368 "y.tab.c"
    break;

  case 55: /* dummy_func2_void: %empty  */
#line 896 "1805064.y"
                    {

    if(type_final== "void"){
        error_typecast_void();
    }
}
#line 2379 "y.tab.c"
    break;

  case 56: /* expression_statement: SEMICOLON  */
#line 906 "1805064.y"
        {
            //$$= new SymbolInfo(";\n", "NON-TERMINAL");
            fprintf(logout, "Line %d: expression_statement 	: SEMICOLON	\n\n", line_count);
            fprintf(logout, ";\n\n");


            (yyval.symbolInfo)->setRetType("int");
            type= "int";

        }
#line 2394 "y.tab.c"
    break;

  case 57: /* expression_statement: expression SEMICOLON  */
#line 917 "1805064.y"
            {
                (yyval.symbolInfo)= (yyvsp[-1].symbolInfo);
                //$$= new SymbolInfo($1->getName()+ ";\n", "NON-TERMINAL");
                fprintf(logout, "Line %d: expression_statement 	: expression SEMICOLON \n\n", line_count);
                fprintf(logout, "%s;\n\n", (yyvsp[-1].symbolInfo)->getName().c_str());

                (yyval.symbolInfo)->setRetType((yyvsp[-1].symbolInfo)->getRetType());
                type= (yyvsp[-1].symbolInfo)->getRetType();
            }
#line 2408 "y.tab.c"
    break;

  case 58: /* variable: id  */
#line 929 "1805064.y"
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

            ///intermidiate code
            pair<string, SymbolInfo*>pr= st.lookUpAll2((yyvsp[0].symbolInfo)->getName());
            string str= (yyvsp[0].symbolInfo)->getName();
            str.append(pr.first);
            (yyval.symbolInfo)->setAName(str);
            if(symb != NULL && symb->getParamSize()>0){
                if(symb->getParamIndex((yyvsp[0].symbolInfo)->getName())!= -1){
                     (yyval.symbolInfo)->setBpOff((symb->getParamSize()- symb->getParamIndex((yyvsp[0].symbolInfo)->getName()))*2 +2);      
                }  
            }




        }
#line 2458 "y.tab.c"
    break;

  case 59: /* variable: id LTHIRD expression RTHIRD  */
#line 975 "1805064.y"
     {

            ///baki
            fprintf(codeout, "\n;%s[%s]\n\n", (yyvsp[-3].symbolInfo)->getName().c_str(), (yyvsp[-1].symbolInfo)->getName().c_str());
            fprintf(codeout, "MOV BX, %s\nADD BX, BX\nMOV %s, BX\n", (yyvsp[-1].symbolInfo)->getAName().c_str(), (yyvsp[-1].symbolInfo)->getAName().c_str());
            (yyval.symbolInfo)= (yyvsp[-3].symbolInfo);
            (yyval.symbolInfo)->setTemp((yyvsp[-1].symbolInfo)->getAName());
            pair<string, SymbolInfo*>pr= st.lookUpAll2((yyvsp[-3].symbolInfo)->getName());
            string str= (yyvsp[-3].symbolInfo)->getName();
            str.append(pr.first);
            (yyval.symbolInfo)->setAName(str);
            //$$= new SymbolInfo($1->getName()+ "["+ $3->getName()+ "]", "NON-TERMINAL");
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
#line 2508 "y.tab.c"
    break;

  case 60: /* expression: logic_expression  */
#line 1023 "1805064.y"
        {
            //$$= new SymbolInfo($1->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: expression : logic_expression \n\n", line_count);
            fprintf(logout, "%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());

            //$$->setRetType($1->getRetType());
            type= (yyvsp[0].symbolInfo)->getRetType();

        }
#line 2522 "y.tab.c"
    break;

  case 61: /* expression: variable ASSIGNOP logic_expression  */
#line 1033 "1805064.y"
       {
            // $$= new SymbolInfo($1->getName()+ "="+ $3->getName(), "NON-TERMINAL");
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


            ///inter code 
            fprintf(codeout, "\n;%s=%s\n", (yyvsp[-2].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());
            if((yyvsp[-2].symbolInfo)->getTemp() != ""){
                fprintf(codeout, "MOV BX, %s\nMOV AX, %s\nMOV %s[BX], AX\n", (yyvsp[-2].symbolInfo)->getTemp().c_str(), (yyvsp[0].symbolInfo)->getAName().c_str(), (yyvsp[-2].symbolInfo)->getAName().c_str());
            }else if((yyvsp[-2].symbolInfo)->getBpOff()!= -1){
                fprintf(codeout, "MOV AX, %s\nMOV [BP+%d], AX\n", (yyvsp[0].symbolInfo)->getAName().c_str(), (yyvsp[-2].symbolInfo)->getBpOff());

            }else{
                fprintf(codeout, "MOV AX, %s\nMOV %s, AX\n", (yyvsp[0].symbolInfo)->getAName().c_str(), (yyvsp[-2].symbolInfo)->getAName().c_str());

            }

            //fprintf(codeout, "MOV AX, %s\nMOV %s, AX\n", $3->getAName().c_str(), $1->getAName().c_str());
       }
#line 2560 "y.tab.c"
    break;

  case 62: /* logic_expression: rel_expression  */
#line 1069 "1805064.y"
        {
            // $$= new SymbolInfo($1->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: logic_expression : rel_expression \n\n", line_count);
            fprintf(logout, "%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());

            // $$->setRetType($1->getRetType());
        }
#line 2572 "y.tab.c"
    break;

  case 63: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 1077 "1805064.y"
        {
            fprintf(codeout, "\n;%s%s%s\n\n", (yyvsp[-2].symbolInfo)->getName().c_str(), (yyvsp[-1].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str()); 

            string label1= newLabel();
            string label2= newLabel();
            //Inter Code
            fprintf(codeout, "MOV AX, %s\nMOV BX, %s\n", (yyvsp[-2].symbolInfo)->getAName().c_str(), (yyvsp[0].symbolInfo)->getAName().c_str());
            if((yyvsp[-1].symbolInfo)->getName()== "||"){
                fprintf(codeout, "CMP AX, 0\nJNE %s\nCMP BX, 0\nJNE %s\nMOV %s, 0\nJMP %s\n", label1.c_str(), label1.c_str(),(yyvsp[-2].symbolInfo)->getAName().c_str(), label2.c_str());
                fprintf(codeout, "%s:\n\tMOV %s, 1\n%s:\n",label1.c_str(), (yyvsp[-2].symbolInfo)->getAName().c_str(), label2.c_str());
            }
            else if((yyvsp[-1].symbolInfo)->getName()== "&&"){
                fprintf(codeout, "CMP AX, 0\nJE %s\nCMP BX, 0\nJE %s\nMOV %s, 1\nJMP %s\n", label1.c_str(), label1.c_str(),(yyvsp[-2].symbolInfo)->getAName().c_str(), label2.c_str());
                fprintf(codeout, "%s:\n\tMOV %s, 0\n%s:\n",label1.c_str(), (yyvsp[-2].symbolInfo)->getAName().c_str(), label2.c_str());
            }
            
            (yyval.symbolInfo)= (yyvsp[-2].symbolInfo);

            //$$= new SymbolInfo($1->getName()+ $2->getName()+ $3->getName(), "NON-TERMINAL");
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
#line 2612 "y.tab.c"
    break;

  case 64: /* rel_expression: simple_expression  */
#line 1115 "1805064.y"
        {
            // $$= new SymbolInfo($1->getName(), "NON-TERMINAL");
             fprintf(logout, "Line %d: rel_expression : simple_expression \n\n", line_count);
             fprintf(logout, "%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());

            // $$->setRetType($1->getRetType());
        }
#line 2624 "y.tab.c"
    break;

  case 65: /* rel_expression: simple_expression RELOP simple_expression  */
#line 1123 "1805064.y"
        {

            fprintf(codeout, "\n;%s%s%s\n\n", (yyvsp[-2].symbolInfo)->getName().c_str(), (yyvsp[-1].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());    
            string label1= newLabel();
            string label2= newLabel();
            fprintf(codeout, "MOV AX, %s\nMOV BX, %s\nCMP AX, BX\n", (yyvsp[-2].symbolInfo)->getAName().c_str(), (yyvsp[0].symbolInfo)->getAName().c_str());
            if((yyvsp[-1].symbolInfo)->getName()== "<"){
                fprintf(codeout, "jl %s\n", label1.c_str());
            }else if((yyvsp[-1].symbolInfo)->getName()== "<="){
                fprintf(codeout, "jle %s\n", label1.c_str());
            }else if((yyvsp[-1].symbolInfo)->getName()== ">"){
                fprintf(codeout, "jg %s\n", label1.c_str());
            }
            else if((yyvsp[-1].symbolInfo)->getName()== ">="){
                fprintf(codeout, "jge %s\n", label1.c_str());
            }else if((yyvsp[-1].symbolInfo)->getName()== "=="){
                fprintf(codeout, "je %s\n", label1.c_str());
            }else if((yyvsp[-1].symbolInfo)->getName()== "!="){
                fprintf(codeout, "jne %s\n", label1.c_str());
            }
            fprintf(codeout, "MOV %s, 0\n", (yyvsp[-2].symbolInfo)->getAName().c_str());
            fprintf(codeout, "jmp %s\n", label2.c_str());
            fprintf(codeout, "%s:\n\tMOV %s, 1\n%s:\n", label1.c_str(), (yyvsp[-2].symbolInfo)->getAName().c_str(), label2.c_str());

            (yyval.symbolInfo)= (yyvsp[-2].symbolInfo);

           // $$= new SymbolInfo($1->getName()+ $2->getName()+ $3->getName(), "NON-TERMINAL");
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
#line 2672 "y.tab.c"
    break;

  case 66: /* simple_expression: term  */
#line 1169 "1805064.y"
        {
            // $$= new SymbolInfo($1->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: simple_expression : term \n\n", line_count);
            fprintf(logout, "%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());

            // $$->setRetType($1->getRetType());
        }
#line 2684 "y.tab.c"
    break;

  case 67: /* simple_expression: simple_expression ADDOP term  */
#line 1177 "1805064.y"
        {

            fprintf(codeout, "\n;%s%s%s\n\n", (yyvsp[-2].symbolInfo)->getName().c_str(), (yyvsp[-1].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());
            fprintf(codeout, "MOV AX, %s\n", (yyvsp[-2].symbolInfo)->getAName().c_str());
            if((yyvsp[-1].symbolInfo)->getName()== "+"){
                fprintf(codeout, "ADD AX, %s\n", (yyvsp[0].symbolInfo)->getAName().c_str());
            }else{
                fprintf(codeout, "SUB AX, %s\n", (yyvsp[0].symbolInfo)->getAName().c_str());
            }
            fprintf(codeout, "MOV %s, AX\n", (yyvsp[-2].symbolInfo)->getAName().c_str());
            (yyval.symbolInfo)= (yyvsp[-2].symbolInfo);

            //$$= new SymbolInfo($1->getName()+ $2->getName()+ $3->getName(), "NON-TERMINAL");
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
#line 2723 "y.tab.c"
    break;

  case 68: /* term: unary_expression  */
#line 1214 "1805064.y"
        {
            // $$= new SymbolInfo($1->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: term :unary_expression\n\n", line_count);
            fprintf(logout, "%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());

            //$$->setRetType($1->getRetType());
        }
#line 2735 "y.tab.c"
    break;

  case 69: /* term: term MULOP unary_expression  */
#line 1222 "1805064.y"
        {
            fprintf(codeout, "\n;%s%s%s\n", (yyvsp[-2].symbolInfo)->getName().c_str(), (yyvsp[-1].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());

            fprintf(codeout, "MOV AX, %s\nMOV BX, %s\n", (yyvsp[-2].symbolInfo)->getAName().c_str(), (yyvsp[0].symbolInfo)->getAName().c_str());
            if((yyvsp[-1].symbolInfo)->getName()== "*"){
                fprintf(codeout, "MUL BX\n");
                fprintf(codeout, "MOV %s, AX\n", (yyvsp[-2].symbolInfo)->getAName().c_str());
            }
            else if((yyvsp[-1].symbolInfo)->getName()== "/"){
                fprintf(codeout, "XOR DX, DX\n");
                fprintf(codeout, "DIV BX\n");
                fprintf(codeout, "MOV %s, AX\n", (yyvsp[-2].symbolInfo)->getAName().c_str());
            }
            else{
                fprintf(codeout, "XOR DX, DX\n");
                fprintf(codeout, "DIV BX\n");
                fprintf(codeout, "MOV %s, DX\n", (yyvsp[-2].symbolInfo)->getAName().c_str());
            }
            

            
            (yyval.symbolInfo)= (yyvsp[-2].symbolInfo);

            //$$= new SymbolInfo($1->getName()+ $2->getName()+ $3->getName(), "NON-TERMINAL");
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
#line 2794 "y.tab.c"
    break;

  case 70: /* unary_expression: ADDOP unary_expression  */
#line 1279 "1805064.y"
        {
            //$$= new SymbolInfo($1->getName()+ $2->getName(), "NON-TERMINAL");
            if((yyvsp[-1].symbolInfo)->getName()== "-"){
                fprintf(codeout, "NEG %s\n", (yyvsp[0].symbolInfo)->getAName().c_str());
            }
            (yyval.symbolInfo)= (yyvsp[0].symbolInfo);
            fprintf(logout, "Line %d: unary_expression : ADDOP unary_expression  \n\n", line_count);
            fprintf(logout, "%s%s\n\n", (yyvsp[-1].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());

            if((yyvsp[0].symbolInfo)->getRetType()== "void"){
                error_typecast_void();

            (yyvsp[0].symbolInfo)->setRetType("float"); //default type
            }

            (yyval.symbolInfo)->setRetType((yyvsp[0].symbolInfo)->getRetType());
        }
#line 2816 "y.tab.c"
    break;

  case 71: /* unary_expression: NOT unary_expression  */
#line 1297 "1805064.y"
        {
            string label1= newLabel();
            string label2= newLabel();

            fprintf(codeout, "\n;!%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());
            fprintf(codeout, "CMP %s, 0\nje %s\nMOV %s, 1\nJMP %s\n", (yyvsp[0].symbolInfo)->getAName().c_str(), label1.c_str(), (yyvsp[0].symbolInfo)->getAName().c_str(), label2.c_str());
            fprintf(codeout, "%s:\n\tMOV %s, 0\n%s:\n", label1.c_str(), (yyvsp[0].symbolInfo)->getAName().c_str(), label2.c_str());


            (yyval.symbolInfo)= (yyvsp[0].symbolInfo);
            //$$= new SymbolInfo("!"+ $2->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: unary_expression : NOT unary_expression  \n\n", line_count);
            fprintf(logout, "!%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());

            if((yyvsp[0].symbolInfo)->getRetType()== "void"){
                error_typecast_void();
            }

            (yyval.symbolInfo)->setRetType("int");
        }
#line 2841 "y.tab.c"
    break;

  case 72: /* unary_expression: factor  */
#line 1318 "1805064.y"
        {
            // $$= new SymbolInfo($1->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: unary_expression : factor  \n\n", line_count);
            fprintf(logout, "%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());

            (yyval.symbolInfo)->setRetType((yyvsp[0].symbolInfo)->getRetType());
        }
#line 2853 "y.tab.c"
    break;

  case 73: /* factor: variable  */
#line 1328 "1805064.y"
        {

            string temp= newTemp();
            fprintf(dataout,"\t%s DW 0\n", temp.c_str());
            
            
            if((yyvsp[0].symbolInfo)->getTemp()!= ""){
                fprintf(codeout, "\n;%s\nMOV BX, %s\nMOV AX, %s[BX]\nMOV %s, AX\n", (yyvsp[0].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getTemp().c_str(), (yyvsp[0].symbolInfo)->getAName().c_str(), temp.c_str());
            }
            else if((yyvsp[0].symbolInfo)->getBpOff()!= -1){
                fprintf(codeout, "\n;%s\nMOV AX, [BP+%d]\nMOV %s, AX\n",(yyvsp[0].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getBpOff(), temp.c_str());
            }
            else{
                fprintf(codeout, "\n;%s\nMOV AX, %s\nMOV %s, AX\n",(yyvsp[0].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getAName().c_str(),temp.c_str());
            }
            ///new symbolInfo instance passed
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            (yyval.symbolInfo)->setAName(temp);
            (yyval.symbolInfo)->setSize((yyvsp[0].symbolInfo)->getSize());
            (yyval.symbolInfo)->setRetType((yyvsp[0].symbolInfo)->getRetType());
            for(int i=0; i<(yyvsp[0].symbolInfo)->getParamSize(); i++){
                (yyval.symbolInfo)->addParam((yyvsp[0].symbolInfo)->getParam(i));
            }
            (yyval.symbolInfo)->setTemp((yyvsp[0].symbolInfo)->getTemp());
            (yyval.symbolInfo)->setBpOff((yyvsp[0].symbolInfo)->getBpOff());
            // fprintf(logout, "Line %d: factor: variable   \n\n", line_count);
            // fprintf(logout, "%s\n\n", $1->getName().c_str());

        }
#line 2887 "y.tab.c"
    break;

  case 74: /* factor: id LPAREN argument_list RPAREN  */
#line 1358 "1805064.y"
        {

            string temp1= newTemp();
            fprintf(dataout,"\t%s DW 0\n", temp1.c_str());

            fprintf(codeout, "\n;%s(%s)\n", (yyvsp[-3].symbolInfo)->getName().c_str(), (yyvsp[-1].symbolInfo)->getName().c_str());

            fprintf(codeout, "CALL %s_PROCEDURE\n", (yyvsp[-3].symbolInfo)->getName().c_str());
            fprintf(codeout, "MOV %s, CX\n", temp1.c_str());
            
            
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[-3].symbolInfo)->getName(), "NON-TERMINAL");
            (yyval.symbolInfo)->setAName(temp1);
            (yyval.symbolInfo)->setSize((yyvsp[-3].symbolInfo)->getSize());
            (yyval.symbolInfo)->setRetType((yyvsp[-3].symbolInfo)->getRetType());
            for(int i=0; i<(yyvsp[-3].symbolInfo)->getParamSize(); i++){
                (yyval.symbolInfo)->addParam((yyvsp[-3].symbolInfo)->getParam(i));
            }
            (yyval.symbolInfo)->setTemp((yyvsp[-3].symbolInfo)->getTemp());
            (yyval.symbolInfo)->setBpOff((yyvsp[-3].symbolInfo)->getBpOff()); 

            //$$= new SymbolInfo($1->getName()+ "("+ $3->getName()+ ")", "NON-TERMINAL");
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
#line 2963 "y.tab.c"
    break;

  case 75: /* factor: LPAREN expression RPAREN  */
#line 1430 "1805064.y"
        {
            fprintf(codeout, "\n;(%s)\n", (yyvsp[-1].symbolInfo)->getName().c_str());
            (yyval.symbolInfo)= (yyvsp[-1].symbolInfo);
            //$$= new SymbolInfo("("+ $2->getName()+ ")", "NON-TERMINAL");
            fprintf(logout, "Line %d: factor: LPAREN expression RPAREN  \n\n", line_count);
            fprintf(logout, "(%s)\n\n", (yyvsp[-1].symbolInfo)->getName().c_str());

            if((yyvsp[-1].symbolInfo)->getRetType()== "void"){
                error_typecast_void();

                (yyval.symbolInfo)->setRetType("float");
            }

            (yyval.symbolInfo)->setRetType((yyvsp[-1].symbolInfo)->getRetType());


        }
#line 2985 "y.tab.c"
    break;

  case 76: /* factor: CONST_INT  */
#line 1448 "1805064.y"
        {
            string temp= newTemp();
            fprintf(dataout,"\t%s DW 0\n", temp.c_str());

            fprintf(codeout, "\n;%s\nMOV AX, %s\nMOV %s, AX\n",(yyvsp[0].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str(),temp.c_str());
            ///new symbolInfo instance passed
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            (yyval.symbolInfo)->setAName(temp);
            (yyval.symbolInfo)->setSize((yyvsp[0].symbolInfo)->getSize());
            (yyval.symbolInfo)->setRetType((yyvsp[0].symbolInfo)->getRetType());
            for(int i=0; i<(yyvsp[0].symbolInfo)->getParamSize(); i++){
                (yyval.symbolInfo)->addParam((yyvsp[0].symbolInfo)->getParam(i));
            }
            
            //$$= new SymbolInfo($1->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: factor : CONST_INT  \n\n", line_count);
            fprintf(logout, "%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());

            (yyval.symbolInfo)->setRetType("int");
        }
#line 3010 "y.tab.c"
    break;

  case 77: /* factor: CONST_FLOAT  */
#line 1469 "1805064.y"
        {

            string temp= newTemp();
            fprintf(dataout,"\t%s DW 0\n", temp.c_str());

            fprintf(codeout, "\n;%s\nMOV AX, %s\nMOV %s, AX\n",(yyvsp[0].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str(),temp.c_str());
            ///new symbolInfo instance passed
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            (yyval.symbolInfo)->setAName(temp);
            (yyval.symbolInfo)->setSize((yyvsp[0].symbolInfo)->getSize());
            (yyval.symbolInfo)->setRetType((yyvsp[0].symbolInfo)->getRetType());
            for(int i=0; i<(yyvsp[0].symbolInfo)->getParamSize(); i++){
                (yyval.symbolInfo)->addParam((yyvsp[0].symbolInfo)->getParam(i));
            }
            //$$= new SymbolInfo($1->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: factor : CONST_FLOAT  \n\n", line_count);
            fprintf(logout, "%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());

            //$$->setRetType("float");
        }
#line 3035 "y.tab.c"
    break;

  case 78: /* factor: variable INCOP  */
#line 1490 "1805064.y"
        {


            // if($1->getTemp() != ""){    
            //     fprintf(codeout, "MOV BX, %s\nMOV AX, %s\nMOV %s[BX], AX\n", $1->getTemp().c_str(), $3->getAName().c_str(), $1->getAName().c_str());
            // }else if($1->getBpOff()!= -1){
            //     fprintf(codeout, "MOV AX, %s\nMOV [BP+%d], AX\n", $3->getAName().c_str(), $1->getBpOff());

            // }else{
            //     fprintf(codeout, "MOV AX, %s\nMOV %s, AX\n", $3->getAName().c_str(), $1->getAName().c_str());

            // }





            fprintf(codeout, "\n;%s++\n", (yyvsp[-1].symbolInfo)->getName().c_str());

            string temp= newTemp();
            fprintf(dataout,"\t%s DW 0\n", temp.c_str());


            if((yyvsp[-1].symbolInfo)->getBpOff() != -1){
                fprintf(codeout, "\nMOV AX, [BP+ %d]\nMOV %s,AX\nINC [BP+ %d]\n", (yyvsp[-1].symbolInfo)->getBpOff(), temp.c_str(), (yyvsp[-1].symbolInfo)->getBpOff());
            }else{
                fprintf(codeout, "\nMOV AX, %s\nMOV %s, AX\nINC %s\n", (yyvsp[-1].symbolInfo)->getAName().c_str(),temp.c_str(), (yyvsp[-1].symbolInfo)->getAName().c_str());

            }
            ///new symbolInfo instance passed
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[-1].symbolInfo)->getName(), "NON-TERMINAL");
            (yyval.symbolInfo)->setAName(temp);
            (yyval.symbolInfo)->setSize((yyvsp[-1].symbolInfo)->getSize());
            (yyval.symbolInfo)->setRetType((yyvsp[-1].symbolInfo)->getRetType());
            (yyval.symbolInfo)->setBpOff((yyvsp[-1].symbolInfo)->getBpOff());
            for(int i=0; i<(yyvsp[-1].symbolInfo)->getParamSize(); i++){
                (yyval.symbolInfo)->addParam((yyvsp[-1].symbolInfo)->getParam(i));
            }



            //$$= new SymbolInfo($1->getName()+ "++", "NON-TERMINAL");
            fprintf(logout, "Line %d: factor : variable INCOP  \n\n", line_count);
            fprintf(logout, "%s++\n\n", (yyvsp[-1].symbolInfo)->getName().c_str());

            //$$->setRetType($1->getRetType());
        }
#line 3087 "y.tab.c"
    break;

  case 79: /* factor: variable DECOP  */
#line 1538 "1805064.y"
        {
            fprintf(codeout, "\n;%s--\n", (yyvsp[-1].symbolInfo)->getName().c_str());

            string temp= newTemp();
            fprintf(dataout,"\t%s DW 0\n", temp.c_str());

            if((yyvsp[-1].symbolInfo)->getBpOff() != -1){
                fprintf(codeout, "\nMOV AX, [BP+ %d]\nMOV %s,AX\nDEC [BP+ %d]\n", (yyvsp[-1].symbolInfo)->getBpOff(), temp.c_str(), (yyvsp[-1].symbolInfo)->getBpOff());
            }else{
                fprintf(codeout, "\nMOV AX, %s\nMOV %s, AX\nDEC %s\n", (yyvsp[-1].symbolInfo)->getAName().c_str(),temp.c_str(), (yyvsp[-1].symbolInfo)->getAName().c_str());

            }
            ///new symbolInfo instance passed
            (yyval.symbolInfo)= new SymbolInfo((yyvsp[-1].symbolInfo)->getName(), "NON-TERMINAL");
            (yyval.symbolInfo)->setAName(temp);
            (yyval.symbolInfo)->setSize((yyvsp[-1].symbolInfo)->getSize());
            (yyval.symbolInfo)->setRetType((yyvsp[-1].symbolInfo)->getRetType());
            (yyval.symbolInfo)->setBpOff((yyvsp[-1].symbolInfo)->getBpOff());
            for(int i=0; i<(yyvsp[-1].symbolInfo)->getParamSize(); i++){
                (yyval.symbolInfo)->addParam((yyvsp[-1].symbolInfo)->getParam(i));
            }
            //fprintf(codeout, "DEC %s\n", $1->getAName().c_str());            
            
            //$$= new SymbolInfo($1->getName()+ "--", "NON-TERMINAL");
            fprintf(logout, "Line %d: factor : variable DECOP  \n\n", line_count);
            fprintf(logout, "%s--\n\n", (yyvsp[-1].symbolInfo)->getName().c_str());

            //$$->setRetType($1->getRetType());
        }
#line 3121 "y.tab.c"
    break;

  case 80: /* argument_list: arguments  */
#line 1570 "1805064.y"
        {
            //$$= new SymbolInfo($1->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: argument_list : arguments  \n\n", line_count);
            fprintf(logout, "%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());
        }
#line 3131 "y.tab.c"
    break;

  case 81: /* argument_list: %empty  */
#line 1576 "1805064.y"
        {
            //$$= new SymbolInfo("", "NON-TERMINAL");
            fprintf(logout, "Line %d: argument_list : epsilon  \n\n", line_count);
            fprintf(logout, "\n\n");
        }
#line 3141 "y.tab.c"
    break;

  case 82: /* arguments: arguments COMMA logic_expression  */
#line 1584 "1805064.y"
        {
            fprintf(codeout, "PUSH %s\n", (yyvsp[0].symbolInfo)->getAName().c_str());
       

            (yyval.symbolInfo)= new SymbolInfo((yyvsp[-2].symbolInfo)->getName()+ ","+ (yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: arguments : arguments COMMA logic_expression  \n\n", line_count);
            fprintf(logout, "%s,%s\n\n", (yyvsp[-2].symbolInfo)->getName().c_str(), (yyvsp[0].symbolInfo)->getName().c_str());

            if((yyvsp[0].symbolInfo)->getRetType()== "void"){
                error_typecast_void();

                (yyvsp[0].symbolInfo)->setRetType("float");
            }

            arg_list.push_back((yyvsp[0].symbolInfo)->getRetType());
        }
#line 3162 "y.tab.c"
    break;

  case 83: /* arguments: logic_expression  */
#line 1601 "1805064.y"
        {
            fprintf(codeout, "PUSH %s\n", (yyvsp[0].symbolInfo)->getAName().c_str());

            (yyval.symbolInfo)= new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "NON-TERMINAL");
            fprintf(logout, "Line %d: arguments : logic_expression \n\n", line_count);
            fprintf(logout, "%s\n\n", (yyvsp[0].symbolInfo)->getName().c_str());

            if((yyvsp[0].symbolInfo)->getRetType()== "void"){
                error_typecast_void();

                (yyvsp[0].symbolInfo)->setRetType("float");
            }

            arg_list.push_back((yyvsp[0].symbolInfo)->getRetType());
        
        }
#line 3183 "y.tab.c"
    break;


#line 3187 "y.tab.c"

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

#line 1619 "1805064.y"

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
    dataout= fopen("dataout.txt","w");
    codeout= fopen("codeout.txt","w");
	//resultout= fopen("resultout.asm","w");

	yyin= fin;
	yyparse();
    st.printAll(logout);
    fprintf(logout, "Total lines: %d\n", line_count);
    fprintf(logout, "Total errors: %d", error);
	fclose(yyin);
	fclose(logout);
	fclose(errout);
    fclose(dataout);
	fclose(codeout);
	//fclose(resultout);
    MergeFile();
	
 
}



