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
#line 5 "parser.y"
 //prologue (headers, globals, prototypes)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h> 
#include"AST.H"
int yylex(void);
AST_NODE* ast_root;
extern int yylineno;
void yyerror(const char *s);

#line 83 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT_LITERAL = 3,                /* INT_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 4,              /* FLOAT_LITERAL  */
  YYSYMBOL_STRING = 5,                     /* STRING  */
  YYSYMBOL_CHARACTER = 6,                  /* CHARACTER  */
  YYSYMBOL_IDENTIFIER = 7,                 /* IDENTIFIER  */
  YYSYMBOL_LABEL = 8,                      /* LABEL  */
  YYSYMBOL_BOOLEAN = 9,                    /* BOOLEAN  */
  YYSYMBOL_ADD_ASSIGN = 10,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 11,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 12,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 13,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 14,                /* MOD_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 15,                /* AND_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 16,                 /* OR_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 17,                /* XOR_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 18,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 19,              /* RIGHT_ASSIGN  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_AND = 21,                       /* AND  */
  YYSYMBOL_EQ = 22,                        /* EQ  */
  YYSYMBOL_NE = 23,                        /* NE  */
  YYSYMBOL_LE = 24,                        /* LE  */
  YYSYMBOL_GE = 25,                        /* GE  */
  YYSYMBOL_LEFT_SHIFT = 26,                /* LEFT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT = 27,               /* RIGHT_SHIFT  */
  YYSYMBOL_INC = 28,                       /* INC  */
  YYSYMBOL_DEC = 29,                       /* DEC  */
  YYSYMBOL_SIZEOF = 30,                    /* SIZEOF  */
  YYSYMBOL_CAST_OP = 31,                   /* CAST_OP  */
  YYSYMBOL_DEREF = 32,                     /* DEREF  */
  YYSYMBOL_ADDR_OF = 33,                   /* ADDR_OF  */
  YYSYMBOL_IF = 34,                        /* IF  */
  YYSYMBOL_OR_ELSE = 35,                   /* OR_ELSE  */
  YYSYMBOL_DO = 36,                        /* DO  */
  YYSYMBOL_WHEN = 37,                      /* WHEN  */
  YYSYMBOL_FROM = 38,                      /* FROM  */
  YYSYMBOL_TO = 39,                        /* TO  */
  YYSYMBOL_CHOICE = 40,                    /* CHOICE  */
  YYSYMBOL_CASE = 41,                      /* CASE  */
  YYSYMBOL_DEFAULT = 42,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 43,                     /* BREAK  */
  YYSYMBOL_SKIP = 44,                      /* SKIP  */
  YYSYMBOL_JUMP_TO = 45,                   /* JUMP_TO  */
  YYSYMBOL_FOPEN = 46,                     /* FOPEN  */
  YYSYMBOL_FCLOSE = 47,                    /* FCLOSE  */
  YYSYMBOL_FREAD = 48,                     /* FREAD  */
  YYSYMBOL_FWRITE = 49,                    /* FWRITE  */
  YYSYMBOL_PRINT = 50,                     /* PRINT  */
  YYSYMBOL_FPRINT = 51,                    /* FPRINT  */
  YYSYMBOL_SPRINT = 52,                    /* SPRINT  */
  YYSYMBOL_SNPRINT = 53,                   /* SNPRINT  */
  YYSYMBOL_VPRINT = 54,                    /* VPRINT  */
  YYSYMBOL_VFPRINT = 55,                   /* VFPRINT  */
  YYSYMBOL_VSPRINT = 56,                   /* VSPRINT  */
  YYSYMBOL_VSNPRINT = 57,                  /* VSNPRINT  */
  YYSYMBOL_SCAN = 58,                      /* SCAN  */
  YYSYMBOL_FSCAN = 59,                     /* FSCAN  */
  YYSYMBOL_SSCAN = 60,                     /* SSCAN  */
  YYSYMBOL_SNSCAN = 61,                    /* SNSCAN  */
  YYSYMBOL_VSCAN = 62,                     /* VSCAN  */
  YYSYMBOL_VFSCAN = 63,                    /* VFSCAN  */
  YYSYMBOL_VSSCAN = 64,                    /* VSSCAN  */
  YYSYMBOL_VSNSCAN = 65,                   /* VSNSCAN  */
  YYSYMBOL_PUTCHAR = 66,                   /* PUTCHAR  */
  YYSYMBOL_FPUTC = 67,                     /* FPUTC  */
  YYSYMBOL_PUTC = 68,                      /* PUTC  */
  YYSYMBOL_PUTS = 69,                      /* PUTS  */
  YYSYMBOL_FPUTS = 70,                     /* FPUTS  */
  YYSYMBOL_GETCHAR = 71,                   /* GETCHAR  */
  YYSYMBOL_FGETC = 72,                     /* FGETC  */
  YYSYMBOL_GETC = 73,                      /* GETC  */
  YYSYMBOL_GETS = 74,                      /* GETS  */
  YYSYMBOL_FGETS = 75,                     /* FGETS  */
  YYSYMBOL_FSEEK = 76,                     /* FSEEK  */
  YYSYMBOL_FTELL = 77,                     /* FTELL  */
  YYSYMBOL_REWIND = 78,                    /* REWIND  */
  YYSYMBOL_SETBUFF = 79,                   /* SETBUFF  */
  YYSYMBOL_SETVBUFF = 80,                  /* SETVBUFF  */
  YYSYMBOL_PERROR = 81,                    /* PERROR  */
  YYSYMBOL_TMPFILE = 82,                   /* TMPFILE  */
  YYSYMBOL_TMPNAM = 83,                    /* TMPNAM  */
  YYSYMBOL_REMOVE = 84,                    /* REMOVE  */
  YYSYMBOL_RENAME = 85,                    /* RENAME  */
  YYSYMBOL_CLEARERR = 86,                  /* CLEARERR  */
  YYSYMBOL_FEOF = 87,                      /* FEOF  */
  YYSYMBOL_FERROR = 88,                    /* FERROR  */
  YYSYMBOL_MALLOC = 89,                    /* MALLOC  */
  YYSYMBOL_CALLOC = 90,                    /* CALLOC  */
  YYSYMBOL_REALLOC = 91,                   /* REALLOC  */
  YYSYMBOL_FREE = 92,                      /* FREE  */
  YYSYMBOL_ABS = 93,                       /* ABS  */
  YYSYMBOL_LABS = 94,                      /* LABS  */
  YYSYMBOL_LLABS = 95,                     /* LLABS  */
  YYSYMBOL_DIV = 96,                       /* DIV  */
  YYSYMBOL_LDIV = 97,                      /* LDIV  */
  YYSYMBOL_LLDIV = 98,                     /* LLDIV  */
  YYSYMBOL_EXIT = 99,                      /* EXIT  */
  YYSYMBOL_ATEXIT = 100,                   /* ATEXIT  */
  YYSYMBOL_SYSTEM = 101,                   /* SYSTEM  */
  YYSYMBOL_ATOL = 102,                     /* ATOL  */
  YYSYMBOL_ATOI = 103,                     /* ATOI  */
  YYSYMBOL_ATOF = 104,                     /* ATOF  */
  YYSYMBOL_STRTOUL = 105,                  /* STRTOUL  */
  YYSYMBOL_STRTOL = 106,                   /* STRTOL  */
  YYSYMBOL_STRTOF = 107,                   /* STRTOF  */
  YYSYMBOL_RAND = 108,                     /* RAND  */
  YYSYMBOL_SRAND = 109,                    /* SRAND  */
  YYSYMBOL_SIN = 110,                      /* SIN  */
  YYSYMBOL_COS = 111,                      /* COS  */
  YYSYMBOL_TAN = 112,                      /* TAN  */
  YYSYMBOL_ASIN = 113,                     /* ASIN  */
  YYSYMBOL_ACOS = 114,                     /* ACOS  */
  YYSYMBOL_ATAN = 115,                     /* ATAN  */
  YYSYMBOL_ATAN2 = 116,                    /* ATAN2  */
  YYSYMBOL_SINH = 117,                     /* SINH  */
  YYSYMBOL_COSH = 118,                     /* COSH  */
  YYSYMBOL_TANH = 119,                     /* TANH  */
  YYSYMBOL_EXP = 120,                      /* EXP  */
  YYSYMBOL_LOG = 121,                      /* LOG  */
  YYSYMBOL_LOG10 = 122,                    /* LOG10  */
  YYSYMBOL_POW = 123,                      /* POW  */
  YYSYMBOL_SQRT = 124,                     /* SQRT  */
  YYSYMBOL_CEIL = 125,                     /* CEIL  */
  YYSYMBOL_FLOOR = 126,                    /* FLOOR  */
  YYSYMBOL_FABS = 127,                     /* FABS  */
  YYSYMBOL_FMOD = 128,                     /* FMOD  */
  YYSYMBOL_MEMCPY = 129,                   /* MEMCPY  */
  YYSYMBOL_MEMMOVE = 130,                  /* MEMMOVE  */
  YYSYMBOL_MEMCHR = 131,                   /* MEMCHR  */
  YYSYMBOL_MEMCMP = 132,                   /* MEMCMP  */
  YYSYMBOL_STRCPY = 133,                   /* STRCPY  */
  YYSYMBOL_STRNCPY = 134,                  /* STRNCPY  */
  YYSYMBOL_STRCAT = 135,                   /* STRCAT  */
  YYSYMBOL_STRNCAT = 136,                  /* STRNCAT  */
  YYSYMBOL_STRCHR = 137,                   /* STRCHR  */
  YYSYMBOL_STRRCHR = 138,                  /* STRRCHR  */
  YYSYMBOL_STRCMP = 139,                   /* STRCMP  */
  YYSYMBOL_STRNCMP = 140,                  /* STRNCMP  */
  YYSYMBOL_STRLEN = 141,                   /* STRLEN  */
  YYSYMBOL_STRPBRK = 142,                  /* STRPBRK  */
  YYSYMBOL_STRSPN = 143,                   /* STRSPN  */
  YYSYMBOL_STRCSPN = 144,                  /* STRCSPN  */
  YYSYMBOL_STRSTR = 145,                   /* STRSTR  */
  YYSYMBOL_STRTOK = 146,                   /* STRTOK  */
  YYSYMBOL_LOWER_THAN_OR_ELSE = 147,       /* LOWER_THAN_OR_ELSE  */
  YYSYMBOL_BLOCK_ERROR = 148,              /* BLOCK_ERROR  */
  YYSYMBOL_149_ = 149,                     /* ';'  */
  YYSYMBOL_150_ = 150,                     /* ','  */
  YYSYMBOL_151_ = 151,                     /* '='  */
  YYSYMBOL_152_ = 152,                     /* '?'  */
  YYSYMBOL_153_ = 153,                     /* ':'  */
  YYSYMBOL_154_ = 154,                     /* '|'  */
  YYSYMBOL_155_ = 155,                     /* '^'  */
  YYSYMBOL_156_ = 156,                     /* '&'  */
  YYSYMBOL_157_ = 157,                     /* '<'  */
  YYSYMBOL_158_ = 158,                     /* '>'  */
  YYSYMBOL_159_ = 159,                     /* '+'  */
  YYSYMBOL_160_ = 160,                     /* '-'  */
  YYSYMBOL_161_ = 161,                     /* '*'  */
  YYSYMBOL_162_ = 162,                     /* '/'  */
  YYSYMBOL_163_ = 163,                     /* '%'  */
  YYSYMBOL_164_ = 164,                     /* '!'  */
  YYSYMBOL_UMINUS = 165,                   /* UMINUS  */
  YYSYMBOL_166_ = 166,                     /* '~'  */
  YYSYMBOL_167_ = 167,                     /* ')'  */
  YYSYMBOL_168_ = 168,                     /* '('  */
  YYSYMBOL_169_ = 169,                     /* '{'  */
  YYSYMBOL_170_ = 170,                     /* '}'  */
  YYSYMBOL_YYACCEPT = 171,                 /* $accept  */
  YYSYMBOL_program = 172,                  /* program  */
  YYSYMBOL_statement = 173,                /* statement  */
  YYSYMBOL_if_statement = 174,             /* if_statement  */
  YYSYMBOL_from_statement = 175,           /* from_statement  */
  YYSYMBOL_when_statement = 176,           /* when_statement  */
  YYSYMBOL_do_statement = 177,             /* do_statement  */
  YYSYMBOL_choice_statement = 178,         /* choice_statement  */
  YYSYMBOL_case_statement = 179,           /* case_statement  */
  YYSYMBOL_expression = 180,               /* expression  */
  YYSYMBOL_compound_statement = 181,       /* compound_statement  */
  YYSYMBOL_statement_list = 182,           /* statement_list  */
  YYSYMBOL_jump_statement = 183,           /* jump_statement  */
  YYSYMBOL_label_statement = 184,          /* label_statement  */
  YYSYMBOL_argument_list = 185,            /* argument_list  */
  YYSYMBOL_nonempty_argument_list = 186,   /* nonempty_argument_list  */
  YYSYMBOL_assignment_statement = 187,     /* assignment_statement  */
  YYSYMBOL_output_ops = 188,               /* output_ops  */
  YYSYMBOL_input_ops = 189,                /* input_ops  */
  YYSYMBOL_file_ops = 190,                 /* file_ops  */
  YYSYMBOL_error_ops = 191,                /* error_ops  */
  YYSYMBOL_stdio_function = 192,           /* stdio_function  */
  YYSYMBOL_stdio_statement = 193,          /* stdio_statement  */
  YYSYMBOL_string_copy_ops = 194,          /* string_copy_ops  */
  YYSYMBOL_string_concat_ops = 195,        /* string_concat_ops  */
  YYSYMBOL_string_search_ops = 196,        /* string_search_ops  */
  YYSYMBOL_string_compare_ops = 197,       /* string_compare_ops  */
  YYSYMBOL_string_misc_ops = 198,          /* string_misc_ops  */
  YYSYMBOL_string_function = 199,          /* string_function  */
  YYSYMBOL_string_statement = 200,         /* string_statement  */
  YYSYMBOL_math_trig_ops = 201,            /* math_trig_ops  */
  YYSYMBOL_math_hyperbolic_ops = 202,      /* math_hyperbolic_ops  */
  YYSYMBOL_math_exp_log_ops = 203,         /* math_exp_log_ops  */
  YYSYMBOL_math_pow_root_ops = 204,        /* math_pow_root_ops  */
  YYSYMBOL_math_misc_ops = 205,            /* math_misc_ops  */
  YYSYMBOL_math_function = 206,            /* math_function  */
  YYSYMBOL_math_statement = 207,           /* math_statement  */
  YYSYMBOL_stdlib_alloc_ops = 208,         /* stdlib_alloc_ops  */
  YYSYMBOL_stdlib_abs_div_ops = 209,       /* stdlib_abs_div_ops  */
  YYSYMBOL_stdlib_process_ops = 210,       /* stdlib_process_ops  */
  YYSYMBOL_stdlib_convert_ops = 211,       /* stdlib_convert_ops  */
  YYSYMBOL_stdlib_random_ops = 212,        /* stdlib_random_ops  */
  YYSYMBOL_stdlib_function = 213,          /* stdlib_function  */
  YYSYMBOL_stdlib_statement = 214          /* stdlib_statement  */
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
typedef yytype_int16 yy_state_t;

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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  171
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1734

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  171
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  213
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  364

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   404


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   164,     2,     2,     2,   163,   156,     2,
     168,   167,   161,   159,   150,   160,     2,   162,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   153,   149,
     157,   151,   158,   152,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   155,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   169,   154,   170,   166,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   165
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   161,   161,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   189,   195,   207,
     211,   217,   224,   237,   241,   247,   253,   257,   263,   269,
     275,   281,   291,   296,   303,   315,   319,   327,   337,   340,
     344,   351,   358,   365,   371,   381,   384,   390,   397,   404,
     417,   419,   420,   421,   422,   423,   427,   429,   430,   431,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   457,   461,   469,   482,
     484,   494,   503,   504,   505,   508,   518,   522,   536,   537,
     542,   545,   561,   564,   566,   569,   572,   575,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   594,   595,   596,
     597,   598,   599,   600,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   621,   622,   623,
     624,   628,   629,   630,   631,   637,   640,   647,   662,   663,
     666,   667,   671,   672,   673,   677,   678,   682,   683,   684,
     685,   686,   690,   691,   692,   693,   694,   698,   703,   709,
     723,   724,   725,   726,   727,   728,   729,   732,   733,   734,
     737,   738,   739,   742,   743,   746,   747,   750,   751,   752,
     753,   754,   758,   764,   772,   784,   785,   786,   787,   790,
     791,   792,   793,   794,   795,   798,   799,   800,   803,   804,
     805,   806,   807,   808,   811,   812,   815,   816,   817,   818,
     819,   822,   826,   833
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT_LITERAL",
  "FLOAT_LITERAL", "STRING", "CHARACTER", "IDENTIFIER", "LABEL", "BOOLEAN",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "AND_ASSIGN", "OR_ASSIGN", "XOR_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN",
  "OR", "AND", "EQ", "NE", "LE", "GE", "LEFT_SHIFT", "RIGHT_SHIFT", "INC",
  "DEC", "SIZEOF", "CAST_OP", "DEREF", "ADDR_OF", "IF", "OR_ELSE", "DO",
  "WHEN", "FROM", "TO", "CHOICE", "CASE", "DEFAULT", "BREAK", "SKIP",
  "JUMP_TO", "FOPEN", "FCLOSE", "FREAD", "FWRITE", "PRINT", "FPRINT",
  "SPRINT", "SNPRINT", "VPRINT", "VFPRINT", "VSPRINT", "VSNPRINT", "SCAN",
  "FSCAN", "SSCAN", "SNSCAN", "VSCAN", "VFSCAN", "VSSCAN", "VSNSCAN",
  "PUTCHAR", "FPUTC", "PUTC", "PUTS", "FPUTS", "GETCHAR", "FGETC", "GETC",
  "GETS", "FGETS", "FSEEK", "FTELL", "REWIND", "SETBUFF", "SETVBUFF",
  "PERROR", "TMPFILE", "TMPNAM", "REMOVE", "RENAME", "CLEARERR", "FEOF",
  "FERROR", "MALLOC", "CALLOC", "REALLOC", "FREE", "ABS", "LABS", "LLABS",
  "DIV", "LDIV", "LLDIV", "EXIT", "ATEXIT", "SYSTEM", "ATOL", "ATOI",
  "ATOF", "STRTOUL", "STRTOL", "STRTOF", "RAND", "SRAND", "SIN", "COS",
  "TAN", "ASIN", "ACOS", "ATAN", "ATAN2", "SINH", "COSH", "TANH", "EXP",
  "LOG", "LOG10", "POW", "SQRT", "CEIL", "FLOOR", "FABS", "FMOD", "MEMCPY",
  "MEMMOVE", "MEMCHR", "MEMCMP", "STRCPY", "STRNCPY", "STRCAT", "STRNCAT",
  "STRCHR", "STRRCHR", "STRCMP", "STRNCMP", "STRLEN", "STRPBRK", "STRSPN",
  "STRCSPN", "STRSTR", "STRTOK", "LOWER_THAN_OR_ELSE", "BLOCK_ERROR",
  "';'", "','", "'='", "'?'", "':'", "'|'", "'^'", "'&'", "'<'", "'>'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UMINUS", "'~'", "')'", "'('",
  "'{'", "'}'", "$accept", "program", "statement", "if_statement",
  "from_statement", "when_statement", "do_statement", "choice_statement",
  "case_statement", "expression", "compound_statement", "statement_list",
  "jump_statement", "label_statement", "argument_list",
  "nonempty_argument_list", "assignment_statement", "output_ops",
  "input_ops", "file_ops", "error_ops", "stdio_function",
  "stdio_statement", "string_copy_ops", "string_concat_ops",
  "string_search_ops", "string_compare_ops", "string_misc_ops",
  "string_function", "string_statement", "math_trig_ops",
  "math_hyperbolic_ops", "math_exp_log_ops", "math_pow_root_ops",
  "math_misc_ops", "math_function", "math_statement", "stdlib_alloc_ops",
  "stdlib_abs_div_ops", "stdlib_process_ops", "stdlib_convert_ops",
  "stdlib_random_ops", "stdlib_function", "stdlib_statement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-303)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-90)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1104,  -303,  -303,  -303,  -303,    11,     4,  -303,  -137,  1104,
    -123,    31,  -119,  -303,  -303,    12,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  1315,  1315,  1315,    56,   621,    19,  -303,  -303,  -303,
    -303,   -91,   -85,  1420,  -303,   329,   -83,   -82,   -81,  -303,
    -303,  -303,  -303,   -99,   -72,  -303,  -303,  -303,  -303,  -303,
     -78,   -66,  -303,  -303,  -303,  -303,  -303,   -76,   -56,  -303,
    -303,  -303,  -303,  -303,   -73,   -55,  1315,  1315,  1315,  1315,
    1315,  1315,  1104,  1104,   117,    -7,   225,    58,  -303,  1315,
    1531,    32,  -303,  -303,  -303,  -303,  -303,   -69,  1144,   -71,
     475,  -303,  -303,  -303,  1315,  1315,  1315,  1315,  1315,  1315,
    -303,  1315,  1315,  1315,  1315,  1315,  1315,  1315,  1315,  1315,
    1315,   -49,  -303,  -303,  -303,  -303,    75,  -303,   108,  -303,
     790,  -303,   913,  -303,  1508,  1508,  1508,  1508,  1508,  1508,
    -303,  -303,   -62,  1232,   -61,   -59,  1257,  1315,  1346,   938,
     -57,     6,  -303,   -33,  -303,  -303,   -49,  -303,  1563,   874,
     899,   899,   -74,   -74,  1473,  1571,   143,   -74,   -74,  -108,
    -108,  -303,  -303,  -303,  -303,   -48,  1508,  -149,     2,   -42,
    -141,    13,   -40,  -140,    90,   -39,  -138,    95,  1104,  1104,
    1104,   958,  1104,  1104,  1104,  1331,  -125,    50,   -24,   -23,
     -22,  -303,  -303,  1315,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,    97,   -34,  1292,
    -303,  -303,  -303,  1104,  1315,  1104,  1315,  1315,  1104,   965,
     -35,   -32,     3,  1508,  1104,  -303,  -303,  -303,  -303,  1360,
    -303,  1380,  1405,  -303,   -31,  1307,    94,    94,    94,    94,
    -303,   -15,   -14,   -13,   -12,   -11,    -8,    40,   -17,    -6,
      22,     1,  1104,  1104,  1104,  1104,  1104,  1104,    17,     5,
    -303,  -303,  -303,  -303,   113,  -303,  -303,  -303,  -303,  -303,
    -303,  1104,  1104,   767,     7,  -303,  -303,  -303,    94,  1104,
    1104,  -303,  -303,  -303
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    51,    52,    53,    55,    50,     0,    54,     0,     0,
       0,     0,     0,    82,    83,     0,   114,   115,   116,   117,
      98,    99,   100,   101,   107,   108,   102,   105,   103,   104,
     106,   109,   111,   110,   112,   113,   118,   119,   120,   121,
     122,   130,   123,   124,   125,   126,   127,   128,   129,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   138,   139,   140,
     141,   142,   143,   145,   146,   147,   148,   150,   149,   144,
     151,     0,     0,     0,     0,     0,     0,    79,     6,     9,
       7,     0,     0,     0,     5,     0,     0,     0,     0,   131,
     132,   133,   134,     0,     0,   152,   153,   154,   155,   156,
       0,     0,   177,   178,   179,   180,   181,     0,     0,   206,
     207,   208,   209,   210,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,     0,
       0,     0,    85,    84,    57,    58,    59,     0,     0,     0,
       0,     1,     8,    15,     0,     0,     0,     0,     0,     0,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,    10,    16,     3,     0,    11,     0,    14,
       0,    13,     0,    12,    93,    94,    95,    96,    97,    92,
      87,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,     0,    56,    78,    77,    76,    75,    74,
      69,    70,    67,    68,    73,    72,    71,    65,    66,    63,
      64,    60,    61,    62,    81,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,   137,     0,   135,   136,   159,   157,   158,   184,
     182,   183,   213,   211,   212,    21,    22,    19,     0,     0,
      33,    34,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,     0,    36,    37,    35,    24,     0,
      25,     0,     0,    23,     0,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      40,    41,    42,    43,    38,    27,    28,    30,    29,    31,
      26,     0,     0,     0,     0,    47,    48,    49,    45,     0,
       0,    46,    44,    39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -303,  -303,    -9,  -303,  -303,  -303,  -303,  -303,  -302,     0,
    -303,    88,  -303,  -303,  -156,  -150,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   106,   107,   108,   109,   110,   111,   112,   328,   113,
     114,   115,   116,   117,   247,   248,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     155,   273,   343,   275,   318,   152,   352,   269,   359,   273,
     273,   160,   273,   162,   278,   329,   330,   331,   274,   171,
     163,   146,   147,   148,   149,   150,   277,   280,   295,   283,
     214,   154,   157,   220,     1,     2,     3,     4,   158,   221,
       7,   338,   250,   296,   253,   156,   256,   339,   251,   161,
     254,   297,   257,   188,   189,   190,   361,   167,   172,     1,
       2,     3,     4,   158,   173,     7,   193,   194,   195,   196,
     174,   175,   176,   177,   178,   179,   245,   197,     1,     2,
       3,     4,   158,   199,     7,   186,   187,   188,   189,   190,
     198,   281,   200,   201,   203,   202,   284,   217,   222,   225,
     244,   164,   165,   166,   168,   258,   192,   261,   262,   249,
     268,     1,     2,     3,     4,   158,   271,     7,   212,   272,
       1,     2,     3,     4,   158,   276,     7,   279,   282,   300,
     301,   302,   304,   305,   316,   327,   324,   317,   332,   333,
     334,   335,   336,   210,   211,   337,   204,   205,   206,   207,
     208,   209,   -89,   340,   213,   354,   216,   153,   353,   218,
     360,   192,   151,   -89,   341,   176,   177,   178,   179,   -89,
     351,   344,   319,   270,   228,   229,   230,   231,   232,   233,
     -89,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   101,   342,   170,     0,   102,   246,   103,   246,   159,
     246,     0,   246,   298,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,     0,   101,   265,   299,   267,
     102,     0,   103,     0,   159,   -88,   215,     0,     1,     2,
       3,     4,   158,     0,     7,   101,     0,     0,     0,   102,
     -89,   103,   -88,   159,     0,   -89,     0,     0,     0,   285,
     286,   287,     0,   290,   291,   292,     0,   -89,   -88,     0,
       0,   289,   -89,     0,     0,     0,     0,     0,   101,     0,
       0,     0,   102,   303,   103,   -88,   159,   101,     0,     0,
       0,   102,     0,   103,   308,   159,   310,     0,     0,   313,
       0,     0,     0,     0,   309,   320,   311,   312,     0,   315,
     184,   185,   186,   187,   188,   189,   190,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   345,   346,   347,   348,   349,   350,    -2,
     191,     0,     1,     2,     3,     4,     5,     6,     7,     0,
       0,     0,   355,   356,   358,     0,     0,     0,     0,     0,
     362,   363,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     0,     9,    10,    11,     0,    12,
       0,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     0,     0,   101,     0,    24,    25,   102,
       0,   103,     0,   159,     0,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     0,     0,    85,    86,     0,     0,
       0,     0,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   226,     0,     1,     2,
       3,     4,     5,     6,     7,     0,     0,     0,     0,   101,
       0,     0,     0,   102,     0,   103,     0,   104,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       0,     9,    10,    11,     0,    12,     0,     0,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,     0,
       0,     0,     0,    24,    25,     0,     0,     0,     0,     0,
       0,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,     0,    85,    86,     0,     0,     0,     0,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   169,     0,     1,     2,     3,     4,     5,     6,
       7,     0,     0,     0,     0,   101,     0,     0,     0,   102,
       0,   103,     0,   104,   105,   227,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     8,     0,     9,    10,    11,
       0,    12,     0,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     0,     0,     0,     0,    24,
      25,     0,     0,     0,     0,     0,     0,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,     0,    85,    86,
       0,     0,     0,     0,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   357,     0,
       1,     2,     3,     4,     5,     6,     7,     0,     0,     0,
       0,   101,     0,     0,     0,   102,     0,   103,     0,   104,
     105,   252,     0,     1,     2,     3,     4,   158,     0,     7,
       0,     8,     0,     9,    10,    11,     0,    12,     0,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     0,     0,     0,     0,    24,    25,     0,     0,     0,
       0,     0,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,     0,     0,    85,    86,   176,   177,   178,   179,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   255,     0,     1,     2,     3,     4,
     158,     0,     7,   178,   179,     0,     0,   101,     0,     0,
       0,   102,     0,   103,     0,   104,   105,     0,     0,   266,
     -88,     1,     2,     3,     4,   158,     0,     7,     0,     0,
     101,     0,     0,     0,   102,     0,   103,   -88,   159,   288,
       0,     1,     2,     3,     4,   158,   314,     7,     1,     2,
       3,     4,   158,     0,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   184,   185,   186,   187,
     188,   189,   190,   -88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   101,     0,     0,     0,   102,     0,   103,
     -88,   159,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   101,     0,
       0,     0,   102,     0,   103,     0,   159,     1,     2,     3,
       4,     5,     6,     7,     0,     0,     0,     0,   101,     0,
       0,     0,   102,     0,   103,   101,   159,     0,     0,   102,
       0,   103,     0,   159,     0,     0,     0,     0,     8,     0,
       9,    10,    11,     0,    12,   223,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     0,     0,
       0,     0,    24,    25,   174,   175,   176,   177,   178,   179,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
       0,    85,    86,   259,     0,     0,     0,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,     0,   174,   175,   176,   177,   178,   179,   263,     0,
       0,     0,     0,     0,   101,     0,     0,     0,   102,     0,
     103,     0,   104,   105,     0,     0,     0,   174,   175,   176,
     177,   178,   179,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   306,     0,     0,     0,     0,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   325,     0,
       0,   224,   174,   175,   176,   177,   178,   179,     1,     2,
       3,     4,   158,     0,     7,     0,     0,   174,   175,   176,
     177,   178,   179,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   174,   175,   176,   177,   178,   179,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   174,   175,   176,   177,
     178,   179,     0,     0,     0,     0,     0,     0,     0,     0,
     174,   175,   176,   177,   178,   179,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,     0,     0,   260,
     174,   175,   176,   177,   178,   179,     0,     0,     0,     0,
       0,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,     0,     0,   264,   174,   175,   176,   177,   178,
     179,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     174,   175,   176,   177,   178,   179,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,     0,     0,   307,
       0,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,     0,     0,   326,   101,     0,     0,     0,   102,
       0,   103,     0,   159,   293,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   176,   177,   178,   179,   294,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,     0,     0,   224,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,     0,     0,   321,   174,   175,
     176,   177,   178,   179,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,     0,     0,   322,     0,     0,
       0,   174,   175,   176,   177,   178,   179,     0,     0,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   180,
     219,     0,   323,     0,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   175,   176,   177,   178,   179,     0,
       0,     0,     0,   176,   177,   178,   179,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   183,   184,   185,
     186,   187,   188,   189,   190
};

static const yytype_int16 yycheck[] =
{
       9,   150,     1,     1,     1,     1,     1,     1,     1,   150,
     150,    11,   150,     1,     1,   317,   318,   319,   167,     0,
       8,    10,    11,    12,    13,    14,   167,   167,   153,   167,
      37,   168,     1,     1,     3,     4,     5,     6,     7,     7,
       9,     1,   198,   168,   200,   168,   202,     7,   198,   168,
     200,     1,   202,   161,   162,   163,   358,     1,   149,     3,
       4,     5,     6,     7,   149,     9,   149,   149,   149,   168,
      20,    21,    22,    23,    24,    25,     1,   149,     3,     4,
       5,     6,     7,   149,     9,   159,   160,   161,   162,   163,
     168,     1,   168,   149,   149,   168,     1,    39,   167,   170,
     149,   101,   102,   103,   104,   167,   115,   168,   167,     1,
     167,     3,     4,     5,     6,     7,   149,     9,     1,   167,
       3,     4,     5,     6,     7,   167,     9,   167,   167,   153,
     153,   153,    35,   167,   169,    41,   167,   169,   153,   153,
     153,   153,   153,   152,   153,   153,   146,   147,   148,   149,
     150,   151,   150,   170,   154,    42,   156,   153,   153,   159,
     153,   170,   151,   150,   170,    22,    23,    24,    25,   167,
     153,   170,   169,   167,   174,   175,   176,   177,   178,   179,
     167,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   160,   170,   105,    -1,   164,   196,   166,   198,   168,
     200,    -1,   202,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,    -1,    -1,   160,   217,   168,   219,
     164,    -1,   166,    -1,   168,   150,     1,    -1,     3,     4,
       5,     6,     7,    -1,     9,   160,    -1,    -1,    -1,   164,
     150,   166,   167,   168,    -1,   150,    -1,    -1,    -1,   258,
     259,   260,    -1,   262,   263,   264,    -1,   167,   150,    -1,
      -1,   261,   167,    -1,    -1,    -1,    -1,    -1,   160,    -1,
      -1,    -1,   164,   273,   166,   167,   168,   160,    -1,    -1,
      -1,   164,    -1,   166,   293,   168,   295,    -1,    -1,   298,
      -1,    -1,    -1,    -1,   294,   304,   296,   297,    -1,   299,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   332,   333,   334,   335,   336,   337,     0,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    -1,   351,   352,   353,    -1,    -1,    -1,    -1,    -1,
     359,   360,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    -1,    36,    37,    38,    -1,    40,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,   160,    -1,    58,    59,   164,
      -1,   166,    -1,   168,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,   127,   128,    -1,    -1,
      -1,    -1,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,   160,
      -1,    -1,    -1,   164,    -1,   166,    -1,   168,   169,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    36,    37,    38,    -1,    40,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    -1,    -1,    58,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,   127,   128,    -1,    -1,    -1,    -1,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,   164,
      -1,   166,    -1,   168,   169,   170,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    36,    37,    38,
      -1,    40,    -1,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,    58,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,   127,   128,
      -1,    -1,    -1,    -1,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,   160,    -1,    -1,    -1,   164,    -1,   166,    -1,   168,
     169,     1,    -1,     3,     4,     5,     6,     7,    -1,     9,
      -1,    34,    -1,    36,    37,    38,    -1,    40,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    -1,    58,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,   127,   128,    22,    23,    24,    25,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     1,    -1,     3,     4,     5,     6,
       7,    -1,     9,    24,    25,    -1,    -1,   160,    -1,    -1,
      -1,   164,    -1,   166,    -1,   168,   169,    -1,    -1,     1,
     150,     3,     4,     5,     6,     7,    -1,     9,    -1,    -1,
     160,    -1,    -1,    -1,   164,    -1,   166,   167,   168,     1,
      -1,     3,     4,     5,     6,     7,     1,     9,     3,     4,
       5,     6,     7,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
     161,   162,   163,   150,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   160,    -1,    -1,    -1,   164,    -1,   166,
     167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,    -1,
      -1,    -1,   164,    -1,   166,    -1,   168,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,   160,    -1,
      -1,    -1,   164,    -1,   166,   160,   168,    -1,    -1,   164,
      -1,   166,    -1,   168,    -1,    -1,    -1,    -1,    34,    -1,
      36,    37,    38,    -1,    40,     1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    -1,    58,    59,    20,    21,    22,    23,    24,    25,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
      -1,   127,   128,     1,    -1,    -1,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    20,    21,    22,    23,    24,    25,     1,    -1,
      -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,   164,    -1,
     166,    -1,   168,   169,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,     1,    -1,
      -1,   167,    20,    21,    22,    23,    24,    25,     3,     4,
       5,     6,     7,    -1,     9,    -1,    -1,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,    -1,    -1,    -1,   167,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,   167,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,    -1,    -1,    -1,   167,
      -1,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,   167,   160,    -1,    -1,    -1,   164,
      -1,   166,    -1,   168,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    22,    23,    24,    25,   168,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
      -1,    -1,    -1,   167,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,    -1,    -1,    -1,   167,    20,    21,
      22,    23,    24,    25,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,    -1,    -1,    -1,   167,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    -1,    -1,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   149,
      39,    -1,   167,    -1,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   156,   157,   158,
     159,   160,   161,   162,   163
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    34,    36,
      37,    38,    40,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    58,    59,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   127,   128,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   160,   164,   166,   168,   169,   172,   173,   174,   175,
     176,   177,   178,   180,   181,   182,   183,   184,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,    10,    11,    12,    13,
      14,   151,     1,   153,   168,   173,   168,     1,     7,   168,
     180,   168,     1,     8,   180,   180,   180,     1,   180,     1,
     182,     0,   149,   149,    20,    21,    22,    23,    24,    25,
     149,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,     1,   173,   149,   149,   149,   168,   149,   168,   149,
     168,   149,   168,   149,   180,   180,   180,   180,   180,   180,
     173,   173,     1,   180,    37,     1,   180,    39,   180,    39,
       1,     7,   167,     1,   167,   170,     1,   170,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   149,     1,   180,   185,   186,     1,
     185,   186,     1,   185,   186,     1,   185,   186,   167,     1,
     167,   168,   167,     1,   167,   180,     1,   180,   167,     1,
     167,   149,   167,   150,   167,     1,   167,   167,     1,   167,
     167,     1,   167,   167,     1,   173,   173,   173,     1,   180,
     173,   173,   173,   153,   168,   153,   168,     1,   153,   168,
     153,   153,   153,   180,    35,   167,     1,   167,   173,   180,
     173,   180,   180,   173,     1,   180,   169,   169,     1,   169,
     173,   167,   167,   167,   167,     1,   167,    41,   179,   179,
     179,   179,   153,   153,   153,   153,   153,   153,     1,     7,
     170,   170,   170,     1,   170,   173,   173,   173,   173,   173,
     173,   153,     1,   153,    42,   173,   173,     1,   173,     1,
     153,   179,   173,   173
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   171,   172,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   174,
     174,   174,   174,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   176,   176,   176,   177,   177,   177,   178,   178,
     178,   178,   178,   178,   178,   179,   179,   179,   179,   179,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   181,   181,   181,   182,
     182,   182,   183,   183,   183,   183,   184,   184,   185,   185,
     186,   186,   187,   187,   187,   187,   187,   187,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   189,   189,   189,
     189,   189,   189,   189,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   191,   191,   191,
     191,   192,   192,   192,   192,   193,   193,   193,   194,   194,
     195,   195,   196,   196,   196,   197,   197,   198,   198,   198,
     198,   198,   199,   199,   199,   199,   199,   200,   200,   200,
     201,   201,   201,   201,   201,   201,   201,   202,   202,   202,
     203,   203,   203,   204,   204,   205,   205,   206,   206,   206,
     206,   206,   207,   207,   207,   208,   208,   208,   208,   209,
     209,   209,   209,   209,   209,   210,   210,   210,   211,   211,
     211,   211,   211,   211,   212,   212,   213,   213,   213,   213,
     213,   214,   214,   214
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     1,     2,     1,
       2,     2,     2,     2,     2,     2,     2,     4,     3,     5,
       7,     5,     5,     6,     6,     6,     9,     9,     9,     9,
       9,     9,     5,     5,     5,     6,     6,     6,     8,    11,
       8,     8,     8,     8,    11,     4,     5,     4,     4,     4,
       1,     1,     1,     1,     1,     1,     3,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       2,     3,     1,     1,     2,     2,     3,     3,     0,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* program: statement_list  */
#line 162 "parser.y"
  { 
     (yyval.node) = (yyvsp[0].node);
     ast_root = (yyvsp[0].node);
  }
#line 2117 "parser.tab.c"
    break;

  case 3: /* statement: assignment_statement ';'  */
#line 169 "parser.y"
                                 { (yyval.node) = (yyvsp[-1].node); }
#line 2123 "parser.tab.c"
    break;

  case 4: /* statement: expression ';'  */
#line 170 "parser.y"
                                  { (yyval.node) = (yyvsp[-1].node); }
#line 2129 "parser.tab.c"
    break;

  case 5: /* statement: compound_statement  */
#line 171 "parser.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 2135 "parser.tab.c"
    break;

  case 6: /* statement: if_statement  */
#line 172 "parser.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 2141 "parser.tab.c"
    break;

  case 7: /* statement: when_statement  */
#line 173 "parser.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 2147 "parser.tab.c"
    break;

  case 8: /* statement: do_statement ';'  */
#line 174 "parser.y"
                                 { (yyval.node) = (yyvsp[-1].node); }
#line 2153 "parser.tab.c"
    break;

  case 9: /* statement: from_statement  */
#line 175 "parser.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 2159 "parser.tab.c"
    break;

  case 10: /* statement: jump_statement ';'  */
#line 176 "parser.y"
                                 { (yyval.node) = (yyvsp[-1].node); }
#line 2165 "parser.tab.c"
    break;

  case 11: /* statement: stdio_statement ';'  */
#line 177 "parser.y"
                                 { (yyval.node) = (yyvsp[-1].node); }
#line 2171 "parser.tab.c"
    break;

  case 12: /* statement: stdlib_statement ';'  */
#line 178 "parser.y"
                                 { (yyval.node) = (yyvsp[-1].node); }
#line 2177 "parser.tab.c"
    break;

  case 13: /* statement: math_statement ';'  */
#line 179 "parser.y"
                                 { (yyval.node) = (yyvsp[-1].node); }
#line 2183 "parser.tab.c"
    break;

  case 14: /* statement: string_statement ';'  */
#line 180 "parser.y"
                                 { (yyval.node) = (yyvsp[-1].node); }
#line 2189 "parser.tab.c"
    break;

  case 15: /* statement: choice_statement ';'  */
#line 181 "parser.y"
                                 { (yyval.node) = (yyvsp[-1].node); }
#line 2195 "parser.tab.c"
    break;

  case 16: /* statement: label_statement ';'  */
#line 182 "parser.y"
                                 { (yyval.node) = (yyvsp[-1].node); }
#line 2201 "parser.tab.c"
    break;

  case 17: /* statement: '(' expression error ';'  */
#line 190 "parser.y"
{
    printf("Missing closing ')' in expression at Line : %d\n", yylineno);
    yyerrok;
    (yyval.node) = (yyvsp[-2].node);
}
#line 2211 "parser.tab.c"
    break;

  case 18: /* statement: '(' error ')'  */
#line 196 "parser.y"
{
    printf("Invalid expression usage inside parentheses at Line : %d\n", yylineno);
    yyerrok;
    (yyval.node) = NULL;
}
#line 2221 "parser.tab.c"
    break;

  case 19: /* if_statement: IF '(' expression ')' statement  */
#line 209 "parser.y"
        { (yyval.node) = make_if_node((yyvsp[-2].node), (yyvsp[0].node), NULL); }
#line 2227 "parser.tab.c"
    break;

  case 20: /* if_statement: IF '(' expression ')' statement OR_ELSE statement  */
#line 212 "parser.y"
          { (yyval.node) = make_if_node((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2233 "parser.tab.c"
    break;

  case 21: /* if_statement: IF '(' error ')' statement  */
#line 219 "parser.y"
{
    printf("Condition logic is wrong in IF statement at Line : %d\n", yylineno);
    yyerrok;
      (yyval.node) = make_if_node(NULL, (yyvsp[0].node), NULL); 
}
#line 2243 "parser.tab.c"
    break;

  case 22: /* if_statement: IF '(' expression error statement  */
#line 226 "parser.y"
 {
    printf("Missing closing ')' in IF statement at Line : %d\n", yylineno);
    yyerrok;
     (yyval.node) = make_if_node((yyvsp[-2].node), (yyvsp[0].node), NULL);
 }
#line 2253 "parser.tab.c"
    break;

  case 23: /* from_statement: FROM expression TO expression ':' statement  */
#line 238 "parser.y"
      { (yyval.node) = make_from_node((yyvsp[-4].node),(yyvsp[-2].node),NULL,(yyvsp[0].node)); }
#line 2259 "parser.tab.c"
    break;

  case 24: /* from_statement: FROM error TO expression ':' statement  */
#line 242 "parser.y"
{
    printf("Seems like the initial expression is invalid in FROM at Line : %d\n", yylineno);
    yyerrok;
    (yyval.node) = make_from_node(NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
}
#line 2269 "parser.tab.c"
    break;

  case 25: /* from_statement: FROM expression TO error ':' statement  */
#line 248 "parser.y"
{
    printf("Seems like the ending expression is invalid in FROM at Line : %d\n", yylineno);
    yyerrok;
    (yyval.node) = make_from_node((yyvsp[-4].node),NULL,NULL,(yyvsp[0].node));
}
#line 2279 "parser.tab.c"
    break;

  case 26: /* from_statement: FROM expression TO expression '(' expression ')' ':' statement  */
#line 254 "parser.y"
      { (yyval.node) = make_from_node((yyvsp[-7].node),(yyvsp[-5].node),(yyvsp[-3].node),(yyvsp[0].node)); }
#line 2285 "parser.tab.c"
    break;

  case 27: /* from_statement: FROM error TO expression '(' expression ')' ':' statement  */
#line 258 "parser.y"
{
    printf("Seems like the initial expression is invalid in FROM at Line : %d\n", yylineno);
    yyerrok;
    (yyval.node) = make_from_node(NULL,(yyvsp[-5].node),(yyvsp[-3].node),(yyvsp[0].node));
}
#line 2295 "parser.tab.c"
    break;

  case 28: /* from_statement: FROM expression TO error '(' expression ')' ':' statement  */
#line 264 "parser.y"
{
    printf("Seems like the ending expression is invalid in FROM at Line : %d\n", yylineno);
    yyerrok;
    (yyval.node) = make_from_node((yyvsp[-7].node),NULL,(yyvsp[-3].node),(yyvsp[0].node));
}
#line 2305 "parser.tab.c"
    break;

  case 29: /* from_statement: FROM expression TO expression '(' error ')' ':' statement  */
#line 270 "parser.y"
{
    printf("You entered the wrong modifyer condition in FROM at Line : %d\n", yylineno);
    yyerrok;
    (yyval.node) = make_from_node((yyvsp[-7].node),(yyvsp[-5].node),NULL,(yyvsp[0].node));
}
#line 2315 "parser.tab.c"
    break;

  case 30: /* from_statement: FROM expression TO expression error expression ')' ':' statement  */
#line 276 "parser.y"
{
    printf("You forgot the starting paranthesis for modifying the incrementer in FROM at Line : %d\n", yylineno);
    yyerrok;
    (yyval.node) = make_from_node((yyvsp[-7].node),(yyvsp[-5].node),(yyvsp[-3].node),(yyvsp[0].node));
}
#line 2325 "parser.tab.c"
    break;

  case 31: /* from_statement: FROM expression TO expression '(' expression error ':' statement  */
#line 282 "parser.y"
{
    printf("You forgot the ending paranthesis for modifying the incrementer in FROM at Line : %d\n", yylineno);
    yyerrok;
    (yyval.node) = make_from_node((yyvsp[-7].node),(yyvsp[-5].node),(yyvsp[-3].node),(yyvsp[0].node));
}
#line 2335 "parser.tab.c"
    break;

  case 32: /* when_statement: WHEN '(' expression ')' statement  */
#line 292 "parser.y"
        { (yyval.node) = make_when_node((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2341 "parser.tab.c"
    break;

  case 33: /* when_statement: WHEN '(' error ')' statement  */
#line 297 "parser.y"
        {
            printf("Invalid condition in WHEN at Line : %d\n", yylineno);
            yyerrok;
            (yyval.node) = make_when_node(NULL, (yyvsp[0].node));
        }
#line 2351 "parser.tab.c"
    break;

  case 34: /* when_statement: WHEN '(' expression error statement  */
#line 304 "parser.y"
        {
            printf("Missing closing ')' in WHEN statement at Line : %d\n", yylineno);
            yyerrok;
            (yyval.node) = make_when_node((yyvsp[-2].node), (yyvsp[0].node));
        }
#line 2361 "parser.tab.c"
    break;

  case 35: /* do_statement: DO statement WHEN '(' expression ')'  */
#line 316 "parser.y"
    { (yyval.node) = make_do_when_node((yyvsp[-4].node), (yyvsp[-1].node)); }
#line 2367 "parser.tab.c"
    break;

  case 36: /* do_statement: DO statement WHEN '(' error ')'  */
#line 320 "parser.y"
    {
        printf("Invalid condition in DO-WHEN at Line : %d\n", yylineno);
        yyerrok;
        (yyval.node) = make_do_when_node((yyvsp[-4].node), NULL);
    }
#line 2377 "parser.tab.c"
    break;

  case 37: /* do_statement: DO statement WHEN '(' expression error  */
#line 328 "parser.y"
    {
        printf("Missing closing ')' in DO-WHEN at Line : %d\n", yylineno);
        yyerrok;
        (yyval.node) = make_do_when_node((yyvsp[-4].node), (yyvsp[-1].node));
    }
#line 2387 "parser.tab.c"
    break;

  case 38: /* choice_statement: CHOICE '(' IDENTIFIER ')' ':' '{' case_statement '}'  */
#line 338 "parser.y"
 { (yyval.node) = make_choice_node(make_identifier_node ((yyvsp[-5].str)),(yyvsp[-1].node),NULL);}
#line 2393 "parser.tab.c"
    break;

  case 39: /* choice_statement: CHOICE '(' IDENTIFIER ')' ':' '{' case_statement '}' DEFAULT ':' statement  */
#line 341 "parser.y"
 { (yyval.node) = make_choice_node(make_identifier_node((yyvsp[-8].str)),(yyvsp[-4].node),(yyvsp[0].node));}
#line 2399 "parser.tab.c"
    break;

  case 40: /* choice_statement: CHOICE '(' error ')' ':' '{' case_statement '}'  */
#line 345 "parser.y"
 {
    printf("Incorrect identifier usage in CHOICE at Line : %d\n", yylineno);
    yyerrok;
    (yyval.node) = make_choice_node(NULL, (yyvsp[-1].node), NULL);
 }
#line 2409 "parser.tab.c"
    break;

  case 41: /* choice_statement: CHOICE '(' IDENTIFIER error ':' '{' case_statement '}'  */
#line 352 "parser.y"
 {
    printf("Missing ')' in CHOICE statement at Line : %d\n", yylineno);
    yyerrok;
    (yyval.node) = make_choice_node(make_identifier_node((yyvsp[-5].str)), (yyvsp[-1].node), NULL);
 }
#line 2419 "parser.tab.c"
    break;

  case 42: /* choice_statement: CHOICE '(' IDENTIFIER ')' ':' error case_statement '}'  */
#line 359 "parser.y"
 {
    printf("Missing '{' in CHOICE statement at Line : %d\n", yylineno);
    yyerrok;
    (yyval.node) = make_choice_node(make_identifier_node((yyvsp[-5].str)), NULL, NULL);
 }
#line 2429 "parser.tab.c"
    break;

  case 43: /* choice_statement: CHOICE '(' IDENTIFIER ')' ':' '{' case_statement error  */
#line 366 "parser.y"
 {
    printf("Missing '}' in CHOICE block at Line : %d\n", yylineno);
    yyerrok;
    (yyval.node) = make_choice_node(make_identifier_node((yyvsp[-5].str)), (yyvsp[-1].node), NULL);
 }
#line 2439 "parser.tab.c"
    break;

  case 44: /* choice_statement: CHOICE '(' IDENTIFIER ')' ':' '{' case_statement '}' DEFAULT error statement  */
#line 372 "parser.y"
{
    printf("Missing ':' after DEFAULT at Line : %d\n", yylineno);
    yyerrok;
    (yyval.node) = make_choice_node(make_identifier_node((yyvsp[-8].str)),(yyvsp[-4].node),NULL);
}
#line 2449 "parser.tab.c"
    break;

  case 45: /* case_statement: CASE IDENTIFIER ':' statement  */
#line 382 "parser.y"
 { (yyval.node) = make_case_node(make_identifier_node((yyvsp[-2].str)),(yyvsp[0].node),NULL);}
#line 2455 "parser.tab.c"
    break;

  case 46: /* case_statement: CASE IDENTIFIER ':' statement case_statement  */
#line 385 "parser.y"
 { (yyval.node) = make_case_node(make_identifier_node((yyvsp[-3].str)),(yyvsp[-1].node),(yyvsp[0].node));}
#line 2461 "parser.tab.c"
    break;

  case 47: /* case_statement: CASE error ':' statement  */
#line 391 "parser.y"
 {
    printf("Incorrect identifier usage in CASE at Line : %d\n", yylineno);
    yyerrok;
    (yyval.node) = make_case_node(NULL, (yyvsp[0].node), NULL);
 }
#line 2471 "parser.tab.c"
    break;

  case 48: /* case_statement: CASE IDENTIFIER error statement  */
#line 398 "parser.y"
 {
    printf("Missing ':' in CASE statement at Line : %d\n", yylineno);
    yyerrok;
    (yyval.node) = make_case_node(make_identifier_node((yyvsp[-2].str)), (yyvsp[0].node), NULL);
 }
#line 2481 "parser.tab.c"
    break;

  case 49: /* case_statement: CASE IDENTIFIER ':' error  */
#line 405 "parser.y"
 {
    printf("Incorrect statement in CASE at Line : %d\n", yylineno);
    yyerrok;
    (yyval.node) = make_case_node(make_identifier_node((yyvsp[-2].str)), NULL, NULL);
 }
#line 2491 "parser.tab.c"
    break;

  case 50: /* expression: IDENTIFIER  */
#line 417 "parser.y"
                 { (yyval.node) = make_identifier_node((yyvsp[0].str)); }
#line 2497 "parser.tab.c"
    break;

  case 51: /* expression: INT_LITERAL  */
#line 419 "parser.y"
                    { (yyval.node) = make_int_literals_node((yyvsp[0].idval));}
#line 2503 "parser.tab.c"
    break;

  case 52: /* expression: FLOAT_LITERAL  */
#line 420 "parser.y"
                    { (yyval.node) = make_float_literals_node((yyvsp[0].fval));}
#line 2509 "parser.tab.c"
    break;

  case 53: /* expression: STRING  */
#line 421 "parser.y"
              { (yyval.node) = make_string_node((yyvsp[0].str));}
#line 2515 "parser.tab.c"
    break;

  case 54: /* expression: BOOLEAN  */
#line 422 "parser.y"
                { (yyval.node) = make_boolean_node((yyvsp[0].bval));}
#line 2521 "parser.tab.c"
    break;

  case 55: /* expression: CHARACTER  */
#line 423 "parser.y"
               { (yyval.node) = make_character_node((yyvsp[0].cval));}
#line 2527 "parser.tab.c"
    break;

  case 56: /* expression: '(' expression ')'  */
#line 427 "parser.y"
                          { (yyval.node) = (yyvsp[-1].node) ;}
#line 2533 "parser.tab.c"
    break;

  case 57: /* expression: '-' expression  */
#line 429 "parser.y"
                               { (yyval.node) = make_unary_operator("-",(yyvsp[0].node)); }
#line 2539 "parser.tab.c"
    break;

  case 58: /* expression: '!' expression  */
#line 430 "parser.y"
                           { (yyval.node) = make_unary_operator("!",(yyvsp[0].node)); }
#line 2545 "parser.tab.c"
    break;

  case 59: /* expression: '~' expression  */
#line 431 "parser.y"
                           { (yyval.node) = make_unary_operator("~",(yyvsp[0].node)); }
#line 2551 "parser.tab.c"
    break;

  case 60: /* expression: expression '*' expression  */
#line 434 "parser.y"
                             { (yyval.node) = make_binary_operator_node("*",(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2557 "parser.tab.c"
    break;

  case 61: /* expression: expression '/' expression  */
#line 435 "parser.y"
                             { (yyval.node) = make_binary_operator_node("/",(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2563 "parser.tab.c"
    break;

  case 62: /* expression: expression '%' expression  */
#line 436 "parser.y"
                             { (yyval.node) = make_binary_operator_node("%",(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2569 "parser.tab.c"
    break;

  case 63: /* expression: expression '+' expression  */
#line 437 "parser.y"
                             { (yyval.node) = make_binary_operator_node("+",(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2575 "parser.tab.c"
    break;

  case 64: /* expression: expression '-' expression  */
#line 438 "parser.y"
                             { (yyval.node) = make_binary_operator_node("-",(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2581 "parser.tab.c"
    break;

  case 65: /* expression: expression '<' expression  */
#line 439 "parser.y"
                             { (yyval.node) = make_binary_operator_node("<",(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2587 "parser.tab.c"
    break;

  case 66: /* expression: expression '>' expression  */
#line 440 "parser.y"
                             { (yyval.node) = make_binary_operator_node(">",(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2593 "parser.tab.c"
    break;

  case 67: /* expression: expression LE expression  */
#line 441 "parser.y"
                             { (yyval.node) = make_binary_operator_node("<=",(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2599 "parser.tab.c"
    break;

  case 68: /* expression: expression GE expression  */
#line 442 "parser.y"
                             { (yyval.node) = make_binary_operator_node(">=",(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2605 "parser.tab.c"
    break;

  case 69: /* expression: expression EQ expression  */
#line 443 "parser.y"
                             { (yyval.node) = make_binary_operator_node("==",(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2611 "parser.tab.c"
    break;

  case 70: /* expression: expression NE expression  */
#line 444 "parser.y"
                             { (yyval.node) = make_binary_operator_node("!=",(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2617 "parser.tab.c"
    break;

  case 71: /* expression: expression '&' expression  */
#line 445 "parser.y"
                             { (yyval.node) = make_binary_operator_node("&",(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2623 "parser.tab.c"
    break;

  case 72: /* expression: expression '^' expression  */
#line 446 "parser.y"
                             { (yyval.node) = make_binary_operator_node("^",(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2629 "parser.tab.c"
    break;

  case 73: /* expression: expression '|' expression  */
#line 447 "parser.y"
                             { (yyval.node) = make_binary_operator_node("|",(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2635 "parser.tab.c"
    break;

  case 74: /* expression: expression AND expression  */
#line 448 "parser.y"
                             { (yyval.node) = make_binary_operator_node("AND",(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2641 "parser.tab.c"
    break;

  case 75: /* expression: expression OR expression  */
#line 449 "parser.y"
                            { (yyval.node) = make_binary_operator_node("OR",(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2647 "parser.tab.c"
    break;

  case 76: /* compound_statement: '{' statement_list '}'  */
#line 458 "parser.y"
        { (yyval.node) = make_compound_node((yyvsp[-1].node)); }
#line 2653 "parser.tab.c"
    break;

  case 77: /* compound_statement: '{' statement_list error  */
#line 463 "parser.y"
        {
            printf("Missing closing '}' in block at Line : %d\n", yylineno);
            yyerrok;
            (yyval.node) = make_compound_node((yyvsp[-1].node));
        }
#line 2663 "parser.tab.c"
    break;

  case 78: /* compound_statement: '{' error '}'  */
#line 470 "parser.y"
        {
            printf("Invalid statements inside block at Line : %d\n", yylineno);
            yyerrok;
            (yyval.node) = make_compound_node(NULL);
        }
#line 2673 "parser.tab.c"
    break;

  case 79: /* statement_list: statement  */
#line 483 "parser.y"
      { (yyval.node) = (yyvsp[0].node);}
#line 2679 "parser.tab.c"
    break;

  case 80: /* statement_list: statement_list statement  */
#line 485 "parser.y"
     {  AST_NODE* stmt = (yyvsp[-1].node);
     if (stmt) {
          while(stmt->next)
          stmt=stmt->next;
          if ((yyvsp[0].node)) {
    stmt->next = (yyvsp[0].node);
}
     }
          (yyval.node) =(yyvsp[-1].node);}
#line 2693 "parser.tab.c"
    break;

  case 81: /* statement_list: statement_list error ';'  */
#line 495 "parser.y"
  {
   printf("Looks like there is an Invalid Syntax usage in line : %d\n", yylineno);
   yyerrok;
   (yyval.node) = (yyvsp[-2].node) ;
  }
#line 2703 "parser.tab.c"
    break;

  case 82: /* jump_statement: BREAK  */
#line 503 "parser.y"
         { (yyval.node) = make_break_node(); }
#line 2709 "parser.tab.c"
    break;

  case 83: /* jump_statement: SKIP  */
#line 504 "parser.y"
           { (yyval.node) = make_skip_node(); }
#line 2715 "parser.tab.c"
    break;

  case 84: /* jump_statement: JUMP_TO LABEL  */
#line 505 "parser.y"
                 { (yyval.node) = make_jumpTo_node(make_identifier_node((yyvsp[0].str)));}
#line 2721 "parser.tab.c"
    break;

  case 85: /* jump_statement: JUMP_TO error  */
#line 509 "parser.y"
{
    printf("LABEL not specified to were the jump to takes place, Line : %d\n", yylineno);
    yyerrok;
    (yyval.node) = make_jumpTo_node(NULL);
}
#line 2731 "parser.tab.c"
    break;

  case 86: /* label_statement: LABEL ':' statement  */
#line 519 "parser.y"
 { (yyval.node) = make_label_node(make_identifier_node((yyvsp[-2].str)),(yyvsp[0].node));}
#line 2737 "parser.tab.c"
    break;

  case 87: /* label_statement: LABEL error statement  */
#line 523 "parser.y"
{
    printf("Missing ':' after label at Line : %d\n", yylineno);
    yyerrok;
    (yyval.node) = make_label_node(make_identifier_node((yyvsp[-2].str)), (yyvsp[0].node));
}
#line 2747 "parser.tab.c"
    break;

  case 88: /* argument_list: %empty  */
#line 536 "parser.y"
        { (yyval.node) = NULL; }
#line 2753 "parser.tab.c"
    break;

  case 89: /* argument_list: nonempty_argument_list  */
#line 538 "parser.y"
     { (yyval.node) = (yyvsp[0].node);}
#line 2759 "parser.tab.c"
    break;

  case 90: /* nonempty_argument_list: expression  */
#line 543 "parser.y"
        { (yyval.node) = (yyvsp[0].node); }
#line 2765 "parser.tab.c"
    break;

  case 91: /* nonempty_argument_list: argument_list ',' expression  */
#line 546 "parser.y"
        {
            AST_NODE* stmt = (yyvsp[-2].node);
            if (stmt) {
                while (stmt->next)
                    stmt = stmt->next;

                if ((yyvsp[0].node))
                    stmt->next = (yyvsp[0].node);
            }
            (yyval.node) = (yyvsp[-2].node);
        }
#line 2781 "parser.tab.c"
    break;

  case 92: /* assignment_statement: IDENTIFIER '=' expression  */
#line 562 "parser.y"
      { (yyval.node) = make_assign_node("=", make_identifier_node((yyvsp[-2].str)), (yyvsp[0].node)); }
#line 2787 "parser.tab.c"
    break;

  case 93: /* assignment_statement: IDENTIFIER ADD_ASSIGN expression  */
#line 565 "parser.y"
        { (yyval.node) = make_assign_node("+=",  make_identifier_node((yyvsp[-2].str)), (yyvsp[0].node)); }
#line 2793 "parser.tab.c"
    break;

  case 94: /* assignment_statement: IDENTIFIER SUB_ASSIGN expression  */
#line 567 "parser.y"
        { (yyval.node) = make_assign_node("-=", make_identifier_node((yyvsp[-2].str)), (yyvsp[0].node)); }
#line 2799 "parser.tab.c"
    break;

  case 95: /* assignment_statement: IDENTIFIER MUL_ASSIGN expression  */
#line 570 "parser.y"
        { (yyval.node) = make_assign_node("*=", make_identifier_node((yyvsp[-2].str)), (yyvsp[0].node)); }
#line 2805 "parser.tab.c"
    break;

  case 96: /* assignment_statement: IDENTIFIER DIV_ASSIGN expression  */
#line 573 "parser.y"
        { (yyval.node) = make_assign_node("/=", make_identifier_node((yyvsp[-2].str)), (yyvsp[0].node)); }
#line 2811 "parser.tab.c"
    break;

  case 97: /* assignment_statement: IDENTIFIER MOD_ASSIGN expression  */
#line 576 "parser.y"
        { (yyval.node) = make_assign_node("%=" , make_identifier_node((yyvsp[-2].str)), (yyvsp[0].node)); }
#line 2817 "parser.tab.c"
    break;

  case 98: /* output_ops: PRINT  */
#line 582 "parser.y"
              { (yyval.str) = "print"; }
#line 2823 "parser.tab.c"
    break;

  case 99: /* output_ops: FPRINT  */
#line 583 "parser.y"
              { (yyval.str) = "fprint"; }
#line 2829 "parser.tab.c"
    break;

  case 100: /* output_ops: SPRINT  */
#line 584 "parser.y"
              { (yyval.str) = "sprint"; }
#line 2835 "parser.tab.c"
    break;

  case 101: /* output_ops: SNPRINT  */
#line 585 "parser.y"
              { (yyval.str) = "snprint"; }
#line 2841 "parser.tab.c"
    break;

  case 102: /* output_ops: PUTCHAR  */
#line 586 "parser.y"
              { (yyval.str) = "putchar"; }
#line 2847 "parser.tab.c"
    break;

  case 103: /* output_ops: PUTC  */
#line 587 "parser.y"
              { (yyval.str) = "putc"; }
#line 2853 "parser.tab.c"
    break;

  case 104: /* output_ops: PUTS  */
#line 588 "parser.y"
              { (yyval.str) = "puts"; }
#line 2859 "parser.tab.c"
    break;

  case 105: /* output_ops: FPUTC  */
#line 589 "parser.y"
              { (yyval.str) = "fputc"; }
#line 2865 "parser.tab.c"
    break;

  case 106: /* output_ops: FPUTS  */
#line 590 "parser.y"
              { (yyval.str) = "fputs"; }
#line 2871 "parser.tab.c"
    break;

  case 107: /* input_ops: SCAN  */
#line 594 "parser.y"
              { (yyval.str) = "scan"; }
#line 2877 "parser.tab.c"
    break;

  case 108: /* input_ops: FSCAN  */
#line 595 "parser.y"
              { (yyval.str) = "fscan"; }
#line 2883 "parser.tab.c"
    break;

  case 109: /* input_ops: GETCHAR  */
#line 596 "parser.y"
              { (yyval.str) = "getchar"; }
#line 2889 "parser.tab.c"
    break;

  case 110: /* input_ops: GETC  */
#line 597 "parser.y"
              { (yyval.str) = "getc"; }
#line 2895 "parser.tab.c"
    break;

  case 111: /* input_ops: FGETC  */
#line 598 "parser.y"
              { (yyval.str) = "fgetc"; }
#line 2901 "parser.tab.c"
    break;

  case 112: /* input_ops: GETS  */
#line 599 "parser.y"
              { (yyval.str) = "gets"; }
#line 2907 "parser.tab.c"
    break;

  case 113: /* input_ops: FGETS  */
#line 600 "parser.y"
              { (yyval.str) = "fgets"; }
#line 2913 "parser.tab.c"
    break;

  case 114: /* file_ops: FOPEN  */
#line 604 "parser.y"
              { (yyval.str) = "fopen"; }
#line 2919 "parser.tab.c"
    break;

  case 115: /* file_ops: FCLOSE  */
#line 605 "parser.y"
              { (yyval.str) = "fclose"; }
#line 2925 "parser.tab.c"
    break;

  case 116: /* file_ops: FREAD  */
#line 606 "parser.y"
              { (yyval.str) = "fread"; }
#line 2931 "parser.tab.c"
    break;

  case 117: /* file_ops: FWRITE  */
#line 607 "parser.y"
              { (yyval.str) = "fwrite"; }
#line 2937 "parser.tab.c"
    break;

  case 118: /* file_ops: FSEEK  */
#line 608 "parser.y"
              { (yyval.str) = "fseek"; }
#line 2943 "parser.tab.c"
    break;

  case 119: /* file_ops: FTELL  */
#line 609 "parser.y"
              { (yyval.str) = "ftell"; }
#line 2949 "parser.tab.c"
    break;

  case 120: /* file_ops: REWIND  */
#line 610 "parser.y"
              { (yyval.str) = "rewind"; }
#line 2955 "parser.tab.c"
    break;

  case 121: /* file_ops: SETBUFF  */
#line 611 "parser.y"
              { (yyval.str) = "setbuf"; }
#line 2961 "parser.tab.c"
    break;

  case 122: /* file_ops: SETVBUFF  */
#line 612 "parser.y"
              { (yyval.str) = "setvbuf"; }
#line 2967 "parser.tab.c"
    break;

  case 123: /* file_ops: TMPFILE  */
#line 613 "parser.y"
              { (yyval.str) = "tmpfile"; }
#line 2973 "parser.tab.c"
    break;

  case 124: /* file_ops: TMPNAM  */
#line 614 "parser.y"
              { (yyval.str) = "tmpnam"; }
#line 2979 "parser.tab.c"
    break;

  case 125: /* file_ops: REMOVE  */
#line 615 "parser.y"
              { (yyval.str) = "remove"; }
#line 2985 "parser.tab.c"
    break;

  case 126: /* file_ops: RENAME  */
#line 616 "parser.y"
              { (yyval.str) = "rename"; }
#line 2991 "parser.tab.c"
    break;

  case 127: /* error_ops: CLEARERR  */
#line 621 "parser.y"
               { (yyval.str) = "clearerr"; }
#line 2997 "parser.tab.c"
    break;

  case 128: /* error_ops: FEOF  */
#line 622 "parser.y"
               { (yyval.str) = "feof"; }
#line 3003 "parser.tab.c"
    break;

  case 129: /* error_ops: FERROR  */
#line 623 "parser.y"
               { (yyval.str) = "ferror"; }
#line 3009 "parser.tab.c"
    break;

  case 130: /* error_ops: PERROR  */
#line 624 "parser.y"
               { (yyval.str) = "perror"; }
#line 3015 "parser.tab.c"
    break;

  case 135: /* stdio_statement: stdio_function '(' argument_list ')'  */
#line 638 "parser.y"
          { (yyval.node) = make_stdio_call_node(make_identifier_node((yyvsp[-3].str)), (yyvsp[-1].node)); }
#line 3021 "parser.tab.c"
    break;

  case 136: /* stdio_statement: stdio_function '(' nonempty_argument_list error  */
#line 641 "parser.y"
          {
              printf("Missing closing ')' in function call at Line : %d\n", yylineno);
              yyerrok;
              (yyval.node) = make_stdio_call_node(make_identifier_node((yyvsp[-3].str)), (yyvsp[-1].node));
          }
#line 3031 "parser.tab.c"
    break;

  case 137: /* stdio_statement: stdio_function '(' error ')'  */
#line 648 "parser.y"
          {
              printf("Invalid arguments  at Line : %d\n", yylineno);
              yyerrok;
              (yyval.node) = make_stdio_call_node(make_identifier_node((yyvsp[-3].str)), NULL);
          }
#line 3041 "parser.tab.c"
    break;

  case 138: /* string_copy_ops: STRCPY  */
#line 662 "parser.y"
               { (yyval.str) = "strcpy"; }
#line 3047 "parser.tab.c"
    break;

  case 139: /* string_copy_ops: STRNCPY  */
#line 663 "parser.y"
               { (yyval.str) = "strncpy"; }
#line 3053 "parser.tab.c"
    break;

  case 140: /* string_concat_ops: STRCAT  */
#line 666 "parser.y"
               { (yyval.str) = "strcat"; }
#line 3059 "parser.tab.c"
    break;

  case 141: /* string_concat_ops: STRNCAT  */
#line 667 "parser.y"
               { (yyval.str) = "strncat"; }
#line 3065 "parser.tab.c"
    break;

  case 142: /* string_search_ops: STRCHR  */
#line 671 "parser.y"
               { (yyval.str) = "strchr"; }
#line 3071 "parser.tab.c"
    break;

  case 143: /* string_search_ops: STRRCHR  */
#line 672 "parser.y"
               { (yyval.str) = "strrchr"; }
#line 3077 "parser.tab.c"
    break;

  case 144: /* string_search_ops: STRSTR  */
#line 673 "parser.y"
               { (yyval.str) = "strstr"; }
#line 3083 "parser.tab.c"
    break;

  case 145: /* string_compare_ops: STRCMP  */
#line 677 "parser.y"
               { (yyval.str) = "strcmp"; }
#line 3089 "parser.tab.c"
    break;

  case 146: /* string_compare_ops: STRNCMP  */
#line 678 "parser.y"
               { (yyval.str) = "strncmp"; }
#line 3095 "parser.tab.c"
    break;

  case 147: /* string_misc_ops: STRLEN  */
#line 682 "parser.y"
               { (yyval.str) = "strlen"; }
#line 3101 "parser.tab.c"
    break;

  case 148: /* string_misc_ops: STRPBRK  */
#line 683 "parser.y"
               { (yyval.str) = "strpbrk"; }
#line 3107 "parser.tab.c"
    break;

  case 149: /* string_misc_ops: STRCSPN  */
#line 684 "parser.y"
               { (yyval.str) = "strcspn"; }
#line 3113 "parser.tab.c"
    break;

  case 150: /* string_misc_ops: STRSPN  */
#line 685 "parser.y"
               { (yyval.str) = "strspn"; }
#line 3119 "parser.tab.c"
    break;

  case 151: /* string_misc_ops: STRTOK  */
#line 686 "parser.y"
               { (yyval.str) = "strtok"; }
#line 3125 "parser.tab.c"
    break;

  case 157: /* string_statement: string_function '(' argument_list ')'  */
#line 699 "parser.y"
      { (yyval.node) = make_string_call_node(make_identifier_node((yyvsp[-3].str)), (yyvsp[-1].node)); }
#line 3131 "parser.tab.c"
    break;

  case 158: /* string_statement: string_function '(' nonempty_argument_list error  */
#line 704 "parser.y"
      {
          printf("Missing closing ')' in string function call at Line : %d\n", yylineno);
          yyerrok;
          (yyval.node) = make_string_call_node(make_identifier_node((yyvsp[-3].str)), (yyvsp[-1].node));
      }
#line 3141 "parser.tab.c"
    break;

  case 159: /* string_statement: string_function '(' error ')'  */
#line 710 "parser.y"
      {
          printf("Invalid function argument at Line : %d\n", yylineno);
          yyerrok;
          (yyval.node) = make_string_call_node(make_identifier_node((yyvsp[-3].str)), NULL);
      }
#line 3151 "parser.tab.c"
    break;

  case 160: /* math_trig_ops: SIN  */
#line 723 "parser.y"
             { (yyval.str) = "sin"; }
#line 3157 "parser.tab.c"
    break;

  case 161: /* math_trig_ops: COS  */
#line 724 "parser.y"
             { (yyval.str) = "cos"; }
#line 3163 "parser.tab.c"
    break;

  case 162: /* math_trig_ops: TAN  */
#line 725 "parser.y"
             { (yyval.str) = "tan"; }
#line 3169 "parser.tab.c"
    break;

  case 163: /* math_trig_ops: ASIN  */
#line 726 "parser.y"
             { (yyval.str) = "asin"; }
#line 3175 "parser.tab.c"
    break;

  case 164: /* math_trig_ops: ACOS  */
#line 727 "parser.y"
             { (yyval.str) = "acos"; }
#line 3181 "parser.tab.c"
    break;

  case 165: /* math_trig_ops: ATAN  */
#line 728 "parser.y"
             { (yyval.str) = "atan"; }
#line 3187 "parser.tab.c"
    break;

  case 166: /* math_trig_ops: ATAN2  */
#line 729 "parser.y"
             { (yyval.str) = "atan2"; }
#line 3193 "parser.tab.c"
    break;

  case 167: /* math_hyperbolic_ops: SINH  */
#line 732 "parser.y"
             { (yyval.str) = "sinh"; }
#line 3199 "parser.tab.c"
    break;

  case 168: /* math_hyperbolic_ops: COSH  */
#line 733 "parser.y"
             { (yyval.str) = "cosh"; }
#line 3205 "parser.tab.c"
    break;

  case 169: /* math_hyperbolic_ops: TANH  */
#line 734 "parser.y"
             { (yyval.str) = "tanh"; }
#line 3211 "parser.tab.c"
    break;

  case 170: /* math_exp_log_ops: EXP  */
#line 737 "parser.y"
             { (yyval.str) = "exp"; }
#line 3217 "parser.tab.c"
    break;

  case 171: /* math_exp_log_ops: LOG  */
#line 738 "parser.y"
             { (yyval.str) = "log"; }
#line 3223 "parser.tab.c"
    break;

  case 172: /* math_exp_log_ops: LOG10  */
#line 739 "parser.y"
             { (yyval.str) = "log10"; }
#line 3229 "parser.tab.c"
    break;

  case 173: /* math_pow_root_ops: POW  */
#line 742 "parser.y"
             { (yyval.str) = "pow"; }
#line 3235 "parser.tab.c"
    break;

  case 174: /* math_pow_root_ops: SQRT  */
#line 743 "parser.y"
             { (yyval.str) = "sqrt"; }
#line 3241 "parser.tab.c"
    break;

  case 175: /* math_misc_ops: FABS  */
#line 746 "parser.y"
             { (yyval.str) = "fabs"; }
#line 3247 "parser.tab.c"
    break;

  case 176: /* math_misc_ops: FMOD  */
#line 747 "parser.y"
             { (yyval.str) = "fmod"; }
#line 3253 "parser.tab.c"
    break;

  case 182: /* math_statement: math_function '(' argument_list ')'  */
#line 759 "parser.y"
        { (yyval.node) = make_math_call_node(make_identifier_node((yyvsp[-3].str)), (yyvsp[-1].node)); }
#line 3259 "parser.tab.c"
    break;

  case 183: /* math_statement: math_function '(' nonempty_argument_list error  */
#line 765 "parser.y"
        {
            printf("Missing closing ')' in math function call at Line : %d\n", yylineno);
            yyerrok;
            (yyval.node) = make_math_call_node(make_identifier_node((yyvsp[-3].str)), (yyvsp[-1].node));
        }
#line 3269 "parser.tab.c"
    break;

  case 184: /* math_statement: math_function '(' error ')'  */
#line 773 "parser.y"
        {
            printf("Invalid function arguments at Line : %d\n", yylineno);
            yyerrok;
            (yyval.node) = make_math_call_node(make_identifier_node((yyvsp[-3].str)), NULL);
        }
#line 3279 "parser.tab.c"
    break;

  case 185: /* stdlib_alloc_ops: MALLOC  */
#line 784 "parser.y"
               { (yyval.str) = "malloc"; }
#line 3285 "parser.tab.c"
    break;

  case 186: /* stdlib_alloc_ops: CALLOC  */
#line 785 "parser.y"
               { (yyval.str) = "calloc"; }
#line 3291 "parser.tab.c"
    break;

  case 187: /* stdlib_alloc_ops: REALLOC  */
#line 786 "parser.y"
               { (yyval.str) = "realloc"; }
#line 3297 "parser.tab.c"
    break;

  case 188: /* stdlib_alloc_ops: FREE  */
#line 787 "parser.y"
               { (yyval.str) = "free"; }
#line 3303 "parser.tab.c"
    break;

  case 189: /* stdlib_abs_div_ops: ABS  */
#line 790 "parser.y"
             { (yyval.str) = "abs"; }
#line 3309 "parser.tab.c"
    break;

  case 190: /* stdlib_abs_div_ops: LABS  */
#line 791 "parser.y"
             { (yyval.str) = "labs"; }
#line 3315 "parser.tab.c"
    break;

  case 191: /* stdlib_abs_div_ops: LLABS  */
#line 792 "parser.y"
             { (yyval.str) = "llabs"; }
#line 3321 "parser.tab.c"
    break;

  case 192: /* stdlib_abs_div_ops: DIV  */
#line 793 "parser.y"
             { (yyval.str) = "div"; }
#line 3327 "parser.tab.c"
    break;

  case 193: /* stdlib_abs_div_ops: LDIV  */
#line 794 "parser.y"
             { (yyval.str) = "ldiv"; }
#line 3333 "parser.tab.c"
    break;

  case 194: /* stdlib_abs_div_ops: LLDIV  */
#line 795 "parser.y"
             { (yyval.str) = "lldiv"; }
#line 3339 "parser.tab.c"
    break;

  case 195: /* stdlib_process_ops: EXIT  */
#line 798 "parser.y"
              { (yyval.str) = "exit"; }
#line 3345 "parser.tab.c"
    break;

  case 196: /* stdlib_process_ops: ATEXIT  */
#line 799 "parser.y"
              { (yyval.str) = "atexit"; }
#line 3351 "parser.tab.c"
    break;

  case 197: /* stdlib_process_ops: SYSTEM  */
#line 800 "parser.y"
              { (yyval.str) = "system"; }
#line 3357 "parser.tab.c"
    break;

  case 198: /* stdlib_convert_ops: ATOL  */
#line 803 "parser.y"
               { (yyval.str) = "atol"; }
#line 3363 "parser.tab.c"
    break;

  case 199: /* stdlib_convert_ops: ATOI  */
#line 804 "parser.y"
               { (yyval.str) = "atoi"; }
#line 3369 "parser.tab.c"
    break;

  case 200: /* stdlib_convert_ops: ATOF  */
#line 805 "parser.y"
               { (yyval.str) = "atof"; }
#line 3375 "parser.tab.c"
    break;

  case 201: /* stdlib_convert_ops: STRTOUL  */
#line 806 "parser.y"
               { (yyval.str) = "strtoul"; }
#line 3381 "parser.tab.c"
    break;

  case 202: /* stdlib_convert_ops: STRTOL  */
#line 807 "parser.y"
               { (yyval.str) = "strtol"; }
#line 3387 "parser.tab.c"
    break;

  case 203: /* stdlib_convert_ops: STRTOF  */
#line 808 "parser.y"
               { (yyval.str) = "strtof"; }
#line 3393 "parser.tab.c"
    break;

  case 204: /* stdlib_random_ops: RAND  */
#line 811 "parser.y"
             { (yyval.str) = "rand"; }
#line 3399 "parser.tab.c"
    break;

  case 205: /* stdlib_random_ops: SRAND  */
#line 812 "parser.y"
             { (yyval.str) = "srand"; }
#line 3405 "parser.tab.c"
    break;

  case 211: /* stdlib_statement: stdlib_function '(' argument_list ')'  */
#line 823 "parser.y"
          { (yyval.node) = make_stdlib_call_node(make_identifier_node((yyvsp[-3].str)), (yyvsp[-1].node)); }
#line 3411 "parser.tab.c"
    break;

  case 212: /* stdlib_statement: stdlib_function '(' nonempty_argument_list error  */
#line 827 "parser.y"
          {
              printf("Missing closing ')' in stdlib function call at Line : %d\n", yylineno);
              yyerrok;
              (yyval.node) = make_stdlib_call_node(make_identifier_node((yyvsp[-3].str)), (yyvsp[-1].node));
          }
#line 3421 "parser.tab.c"
    break;

  case 213: /* stdlib_statement: stdlib_function '(' error ')'  */
#line 834 "parser.y"
          {
              printf("Invalid function arguments at Line : %d\n", yylineno);
              yyerrok;
              (yyval.node) = make_stdlib_call_node(make_identifier_node((yyvsp[-3].str)), NULL);
          }
#line 3431 "parser.tab.c"
    break;


#line 3435 "parser.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 845 "parser.y"

//User subroutines (C code) 
//Section 4: helper functions (yyerror, main, etc.)
extern int yylineno;
 void yyerror(const char* s){
   fprintf(stderr,"Syntax error at line %d : %s\n",yylineno, s);
 }
