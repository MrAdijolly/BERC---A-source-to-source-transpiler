%option noyywrap
%option yylineno
%option nodefault

%{
    #include "parser.tab.h"
    #include<string.h>
    #include<stdbool.h>
    #include<stdio.h>
    #include"AST.h"


char process_char(const char* text) {
    if (text[1] == '\\') {
        switch (text[2]) {
            case 'n': return '\n';
            case 't': return '\t';
            case '\\': return '\\';
            case '\'': return '\'';
            default: return text[2];
        }
    }
    return text[1];
}
%}



/* simplified regex */
DIGIT [0-9]
IDNT_START [a-zA-Z]
IDNT_BODY [a-zA-Z0-9_]
STRING ([^"\\]|\\.) 
LONG_ID {IDNT_START}{IDNT_BODY}{49,}



%%



"if" {  return IF; }


"or" { return OR_ELSE; }

"when" { return WHEN; }

"do" { return DO; }
 
"from"  { return FROM; }

"to" { return TO ; }
 
"break" { return BREAK; }

"skip" { return SKIP ; }

"jump_to" { return JUMP_TO; }

"label" { return LABEL;}

"choice" { return CHOICE; }

"case" { return CASE; }

"default" { return DEFAULT; }


 /* WHEN STATEMENT 
 ----------OPERATORS---------------*/
"||" { return OR ; }

"&&" { return AND; }

"=="  { return EQ ; }

"!=" { return NE; }

"+=" { return ADD_ASSIGN; }

"-=" { return  SUB_ASSIGN; }

"*=" { return MUL_ASSIGN; } 

"/=" { return DIV_ASSIGN; } 

"%=" { return MOD_ASSIGN; }

"&=" { return AND_ASSIGN; }

"|=" { return OR_ASSIGN; }

"^=" { return XOR_ASSIGN; }

">>=" { return RIGHT_ASSIGN; }

"<<=" { return LEFT_ASSIGN; }

">=" { return GE; }

"<=" { return LE ; }

">>" { return RIGHT_SHIFT; }

"<<" { return LEFT_SHIFT; }

"+" { return '+'; }

"-" { return '-'; }

"*" { return '*'; }

"/" { return '/'; }
 
"%" { return '%'; }

"!" { return '!'; }

"~" { return '~'; }

"&" { return '&'; }

"|" { return '|'; }

"^" { return '^'; }

">" { return '>'; }

"<" { return '<'; }

"=" { return '='; }

"(" { return '('; }

")" { return ')'; }

";" { return ';'; }

":" { return ':'; }

"{" { return '{'; }

"}" { return '}'; } 

"===" { printf("Invalid operator '===' at line %d\n", yylineno); }
"&&&" { printf("Invalid operator '&&&' at line %d\n", yylineno); }


  /*---------------FUNCTIONS-------------
  ---------- stdio.h ---------- */
"fopen"        { return FOPEN; }
"fclose"       { return FCLOSE; }
"fread"        { return FREAD; }
"fwrite"       { return FWRITE; }

"print"       { return PRINT; }
"fprint"      { return FPRINT;}
"sprint"      { return SPRINT;}
"vprint"      { return VPRINT; }
"vfprint"     { return VFPRINT;}
"vsprint"     { return VSPRINT;}


"scan"        { return SCAN; }
"fscan"       { return FSCAN; }
"sscan"       { return SSCAN; }
"vscan"       { return VSCAN; }
"vfscan"      { return VFSCAN; }
"vsscan"      { return VSSCAN; }

"putchar"      { return PUTCHAR; }
"fputc"        { return FPUTC; }
"putc"         { return PUTC; }
"puts"         { return PUTS; }
"fputs"        { return FPUTS; }

"getchar"      { return GETCHAR; }
"fgetc"        { return FGETC; }
"getc"         { return GETC; }
"gets"         { return GETS; }
"fgets"        { return FGETS; }

"fseek"        { return FSEEK; }
"ftell"        { return FTELL; }
"rewind"       { return REWIND; }
"perror"       {return PERROR;}

"tmpfile"      { return TMPFILE;}
"tmpnam"       { return TMPNAM; }
"remove"       { return REMOVE; }
"rename"       { return RENAME; }
 
"clearerr"     { return CLEARERR; }
"feof"         { return FEOF; }
"ferror"       { return FERROR; }


 /* ---------- stdlib.h ---------- */
"malloc"       { return MALLOC;}
"calloc"       { return CALLOC;}
"realloc"      { return REALLOC;}
"free"         {return FREE;}

"abs"          {return ABS;}
"labs"         {return LABS;}
"llabs"        {return LLABS;}
"div"          {return DIV;}
"ldiv"         {return LDIV;}
"lldiv"        {return LLDIV;}

"exit"         {return EXIT;}
"atexit"       {return ATEXIT;}
"system"       {return SYSTEM;}

"atol"         {return ATOL;}
"atoi"         {return ATOI;}
"atof"         {return ATOF;}
"strtoul"      {return STRTOUL;}
"strtol"       {return STRTOL;}
"strtof"       {return STRTOF;}

"rand"         { return RAND;}
"srand"        { return SRAND;}


 /* ---------- math.h ---------- */
"sin"          {return SIN;}
"cos"          {return COS;}
"tan"          {return TAN;}
"asin"         {return ASIN;}
"acos"         {return ACOS;}
"atan"         {return ATAN;}
"atan2"        {return ATAN2;}

"sinh"         {return SINH;}
"cosh"         {return COSH;}
"tanh"         {return TANH;}

"exp"          {return EXP;}
"log"          {return LOG;}
"log10"        {return LOG10;}

"pow"          {return POW;}
"sqrt"         {return SQRT;}

"ceil"         {return CEIL;}
"floor"        {return FLOOR;}

"fabs"         {return FABS;}
"fmod"         {return FMOD;}


 /* ---------- string.h ---------- */
"memcpy"       {return MEMCPY;}
"memmove"      {return MEMMOVE;}
"memchr"       {return MEMCHR;}
"memcmp"       {return MEMCMP;}

"strcpy"       {return STRCPY;}
"strncpy"      {return STRNCPY;}
"strcat"       {return STRCAT;}
"strncat"      {return STRNCAT;}

"strchr"       {return STRCHR;}
"strrchr"      {return STRRCHR;}
"strcmp"       {return STRCMP;}
"strncmp"      {return STRNCMP;}

"strlen"       {return STRLEN;}
"strpbrk"      {return STRPBRK;}
"strspn"       {return STRSPN;}
"strcspn"      {return STRCSPN;}
"strstr"       {return STRSTR;}
"strtok"       {return STRTOK;}
 

 /* BOOLEAN */
 
"true" {
    yylval.bval = true;
    return BOOLEAN;
}

"false" {
    yylval.bval = false;
    return BOOLEAN;
}
 /*  DECIMAL NUMBERS */
 {DIGIT}+\.{DIGIT}+\.{DIGIT}+ {
    printf("Invalid number '%s' at line %d\n", yytext, yylineno);
}

{DIGIT}+"."{DIGIT}+ {
    yylval.fval = atof(yytext);
    return FLOAT_LITERAL;
}

{DIGIT}+  { yylval.idval = atoi(yytext);  return INT_LITERAL;}

{DIGIT}+{IDNT_BODY}+ { printf("\n Invalid identifier '%s': identifier start with characters. Check line %d ",yytext,yylineno);}



{IDNT_START}{IDNT_BODY}*  { 
yylval.str = strdup(yytext);
 return IDENTIFIER; }
 '(\\.|[^'\\])' {   yylval.cval = process_char(yytext);   return CHARACTER; }

'[^']{2,}' {
    printf("Multi-char '%s' at line %d\n", yytext, yylineno);
}


   
\"([^"\\]|\\.)*\n  { printf("Unterminated string at line %d\n", yylineno); }


 /* STRING */

\"([^"\\]|\\.)*\" {  yylval.str = strdup(yytext);   return STRING; }
[ \t\r]+    { /* ignore spaces and tabs */ }
\n          { /* newline handled automatically */ }


. {
    printf("Lexical error at line %d near '%s'\n", yylineno, yytext);
}
%%