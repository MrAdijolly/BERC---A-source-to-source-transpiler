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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "parser.y"

    #include<stdbool.h>
     #include"AST.H"
     

#line 55 "parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT_LITERAL = 258,             /* INT_LITERAL  */
    FLOAT_LITERAL = 259,           /* FLOAT_LITERAL  */
    STRING = 260,                  /* STRING  */
    CHARACTER = 261,               /* CHARACTER  */
    IDENTIFIER = 262,              /* IDENTIFIER  */
    LABEL = 263,                   /* LABEL  */
    BOOLEAN = 264,                 /* BOOLEAN  */
    ADD_ASSIGN = 265,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 266,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 267,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 268,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 269,              /* MOD_ASSIGN  */
    AND_ASSIGN = 270,              /* AND_ASSIGN  */
    OR_ASSIGN = 271,               /* OR_ASSIGN  */
    XOR_ASSIGN = 272,              /* XOR_ASSIGN  */
    LEFT_ASSIGN = 273,             /* LEFT_ASSIGN  */
    RIGHT_ASSIGN = 274,            /* RIGHT_ASSIGN  */
    OR = 275,                      /* OR  */
    AND = 276,                     /* AND  */
    EQ = 277,                      /* EQ  */
    NE = 278,                      /* NE  */
    LE = 279,                      /* LE  */
    GE = 280,                      /* GE  */
    LEFT_SHIFT = 281,              /* LEFT_SHIFT  */
    RIGHT_SHIFT = 282,             /* RIGHT_SHIFT  */
    INC = 283,                     /* INC  */
    DEC = 284,                     /* DEC  */
    SIZEOF = 285,                  /* SIZEOF  */
    CAST_OP = 286,                 /* CAST_OP  */
    DEREF = 287,                   /* DEREF  */
    ADDR_OF = 288,                 /* ADDR_OF  */
    IF = 289,                      /* IF  */
    OR_ELSE = 290,                 /* OR_ELSE  */
    DO = 291,                      /* DO  */
    WHEN = 292,                    /* WHEN  */
    FROM = 293,                    /* FROM  */
    TO = 294,                      /* TO  */
    CHOICE = 295,                  /* CHOICE  */
    CASE = 296,                    /* CASE  */
    DEFAULT = 297,                 /* DEFAULT  */
    BREAK = 298,                   /* BREAK  */
    SKIP = 299,                    /* SKIP  */
    JUMP_TO = 300,                 /* JUMP_TO  */
    FOPEN = 301,                   /* FOPEN  */
    FCLOSE = 302,                  /* FCLOSE  */
    FREAD = 303,                   /* FREAD  */
    FWRITE = 304,                  /* FWRITE  */
    PRINT = 305,                   /* PRINT  */
    FPRINT = 306,                  /* FPRINT  */
    SPRINT = 307,                  /* SPRINT  */
    SNPRINT = 308,                 /* SNPRINT  */
    VPRINT = 309,                  /* VPRINT  */
    VFPRINT = 310,                 /* VFPRINT  */
    VSPRINT = 311,                 /* VSPRINT  */
    VSNPRINT = 312,                /* VSNPRINT  */
    SCAN = 313,                    /* SCAN  */
    FSCAN = 314,                   /* FSCAN  */
    SSCAN = 315,                   /* SSCAN  */
    SNSCAN = 316,                  /* SNSCAN  */
    VSCAN = 317,                   /* VSCAN  */
    VFSCAN = 318,                  /* VFSCAN  */
    VSSCAN = 319,                  /* VSSCAN  */
    VSNSCAN = 320,                 /* VSNSCAN  */
    PUTCHAR = 321,                 /* PUTCHAR  */
    FPUTC = 322,                   /* FPUTC  */
    PUTC = 323,                    /* PUTC  */
    PUTS = 324,                    /* PUTS  */
    FPUTS = 325,                   /* FPUTS  */
    GETCHAR = 326,                 /* GETCHAR  */
    FGETC = 327,                   /* FGETC  */
    GETC = 328,                    /* GETC  */
    GETS = 329,                    /* GETS  */
    FGETS = 330,                   /* FGETS  */
    FSEEK = 331,                   /* FSEEK  */
    FTELL = 332,                   /* FTELL  */
    REWIND = 333,                  /* REWIND  */
    SETBUFF = 334,                 /* SETBUFF  */
    SETVBUFF = 335,                /* SETVBUFF  */
    PERROR = 336,                  /* PERROR  */
    TMPFILE = 337,                 /* TMPFILE  */
    TMPNAM = 338,                  /* TMPNAM  */
    REMOVE = 339,                  /* REMOVE  */
    RENAME = 340,                  /* RENAME  */
    CLEARERR = 341,                /* CLEARERR  */
    FEOF = 342,                    /* FEOF  */
    FERROR = 343,                  /* FERROR  */
    MALLOC = 344,                  /* MALLOC  */
    CALLOC = 345,                  /* CALLOC  */
    REALLOC = 346,                 /* REALLOC  */
    FREE = 347,                    /* FREE  */
    ABS = 348,                     /* ABS  */
    LABS = 349,                    /* LABS  */
    LLABS = 350,                   /* LLABS  */
    DIV = 351,                     /* DIV  */
    LDIV = 352,                    /* LDIV  */
    LLDIV = 353,                   /* LLDIV  */
    EXIT = 354,                    /* EXIT  */
    ATEXIT = 355,                  /* ATEXIT  */
    SYSTEM = 356,                  /* SYSTEM  */
    ATOL = 357,                    /* ATOL  */
    ATOI = 358,                    /* ATOI  */
    ATOF = 359,                    /* ATOF  */
    STRTOUL = 360,                 /* STRTOUL  */
    STRTOL = 361,                  /* STRTOL  */
    STRTOF = 362,                  /* STRTOF  */
    RAND = 363,                    /* RAND  */
    SRAND = 364,                   /* SRAND  */
    SIN = 365,                     /* SIN  */
    COS = 366,                     /* COS  */
    TAN = 367,                     /* TAN  */
    ASIN = 368,                    /* ASIN  */
    ACOS = 369,                    /* ACOS  */
    ATAN = 370,                    /* ATAN  */
    ATAN2 = 371,                   /* ATAN2  */
    SINH = 372,                    /* SINH  */
    COSH = 373,                    /* COSH  */
    TANH = 374,                    /* TANH  */
    EXP = 375,                     /* EXP  */
    LOG = 376,                     /* LOG  */
    LOG10 = 377,                   /* LOG10  */
    POW = 378,                     /* POW  */
    SQRT = 379,                    /* SQRT  */
    CEIL = 380,                    /* CEIL  */
    FLOOR = 381,                   /* FLOOR  */
    FABS = 382,                    /* FABS  */
    FMOD = 383,                    /* FMOD  */
    MEMCPY = 384,                  /* MEMCPY  */
    MEMMOVE = 385,                 /* MEMMOVE  */
    MEMCHR = 386,                  /* MEMCHR  */
    MEMCMP = 387,                  /* MEMCMP  */
    STRCPY = 388,                  /* STRCPY  */
    STRNCPY = 389,                 /* STRNCPY  */
    STRCAT = 390,                  /* STRCAT  */
    STRNCAT = 391,                 /* STRNCAT  */
    STRCHR = 392,                  /* STRCHR  */
    STRRCHR = 393,                 /* STRRCHR  */
    STRCMP = 394,                  /* STRCMP  */
    STRNCMP = 395,                 /* STRNCMP  */
    STRLEN = 396,                  /* STRLEN  */
    STRPBRK = 397,                 /* STRPBRK  */
    STRSPN = 398,                  /* STRSPN  */
    STRCSPN = 399,                 /* STRCSPN  */
    STRSTR = 400,                  /* STRSTR  */
    STRTOK = 401,                  /* STRTOK  */
    LOWER_THAN_OR_ELSE = 402,      /* LOWER_THAN_OR_ELSE  */
    BLOCK_ERROR = 403,             /* BLOCK_ERROR  */
    UMINUS = 404                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "parser.y"

    long idval; // for int_list
    double fval;    // for float_list
    char* str;  // for identifiers
   char cval; // for single characters
    bool bval; //boolean value holder
    AST_NODE* node;// for nodes
    

#line 231 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
