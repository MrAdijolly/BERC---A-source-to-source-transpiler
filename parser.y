%code requires {
    #include<stdbool.h>
     #include"AST.H"
     }
%{ //prologue (headers, globals, prototypes)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h> 
#include"AST.H"
int yylex(void);
AST_NODE* ast_root;
extern int yylineno;
void yyerror(const char *s);
%}
//Bison declarations  Section 2: tokens, %union, precedence
%define parse.error verbose
%start program
%union {
    long idval; // for int_list
    double fval;    // for float_list
    char* str;  // for identifiers
   char cval; // for single characters
    bool bval; //boolean value holder
    AST_NODE* node;// for nodes
    
};
// Tokens

 // DATA TYPES
%token <idval> INT_LITERAL
%token <fval> FLOAT_LITERAL
%token <str> STRING
%token <cval> CHARACTER// didn't check in flex
%token <str> IDENTIFIER 
%token <str> LABEL // didn't check in flex
%token <bval> BOOLEAN // didn't check in flex
%type <node> expression statement compound_statement  if_statement do_statement when_statement from_statement stdio_statement string_statement math_statement jump_statement  argument_list nonempty_argument_list statement_list assignment_statement
%type <str> stdlib_alloc_ops stdlib_abs_div_ops stdlib_process_ops stdlib_convert_ops stdlib_random_ops stdlib_function
%type <str> math_trig_ops math_hyperbolic_ops math_exp_log_ops math_pow_root_ops math_misc_ops math_function
%type <str> string_copy_ops string_concat_ops string_search_ops string_compare_ops string_misc_ops string_function
%type <str> output_ops input_ops file_ops error_ops stdio_function
%type <node> choice_statement case_statement label_statement stdlib_statement
%type <node> program
 
 
 // PRECEDENCE TOKENS
 // single operators don't need seperate tokens like BAND BOR XOR BNOT  G L ASSIGN LNOT
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token AND_ASSIGN OR_ASSIGN XOR_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN

%token OR AND 

%token EQ NE 

%token LE GE

%token  LEFT_SHIFT RIGHT_SHIFT

%token INC DEC SIZEOF CAST_OP DEREF ADDR_OF
// operand
 // KEYWORDS
// CUSTOM LANGUAGES
%token IF  OR_ELSE
%token DO WHEN
%token FROM TO 
%token CHOICE CASE DEFAULT // didn't create lex,parser and AST
%token BREAK
%token SKIP
%token JUMP_TO
// for input output


// STDIO.H functions
%token FOPEN FCLOSE FREAD FWRITE 
%token PRINT FPRINT SPRINT SNPRINT VPRINT VFPRINT VSPRINT VSNPRINT
%token SCAN FSCAN SSCAN SNSCAN VSCAN VFSCAN VSSCAN VSNSCAN
%token PUTCHAR FPUTC PUTC PUTS FPUTS GETCHAR FGETC GETC GETS FGETS
%token FSEEK FTELL REWIND SETBUFF SETVBUFF PERROR
%token TMPFILE TMPNAM REMOVE RENAME
%token CLEARERR FEOF FERROR
// stdlib.h FUNCTIONS
%token MALLOC CALLOC REALLOC FREE
%token ABS LABS LLABS DIV LDIV LLDIV
%token EXIT ATEXIT SYSTEM
%token ATOL ATOI ATOF STRTOUL STRTOL STRTOF 
%token RAND SRAND
// math.h FUNCTIONS
%token SIN COS TAN ASIN ACOS ATAN ATAN2
%token SINH COSH TANH EXP LOG LOG10 POW SQRT CEIL FLOOR
%token FABS FMOD
// string.h FUNCTIONS
%token MEMCPY MEMMOVE MEMCHR MEMCMP
%token STRCPY STRNCPY STRCAT STRNCAT STRCHR STRRCHR STRCMP STRNCMP
%token STRLEN STRPBRK STRSPN STRCSPN STRSTR STRTOK 




// Precedence to handle the error in the if statement
 %nonassoc LOWER_THAN_OR_ELSE
%nonassoc OR_ELSE
%nonassoc BLOCK_ERROR
%nonassoc ';'

// PRECEDENCE
/* Operators are listed below in order of INCREASING precedence */

/* Level 15: Comma operator (lowest precedence) */
%left ','

/* Level 14: Assignment operators (right-associative) */
%right '=' ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%right AND_ASSIGN OR_ASSIGN XOR_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN

/* Level 13: Conditional operator (right-associative) */
%right '?' ':'

/* Level 12: Logical OR */
%left OR

/* Level 11: Logical AND */
%left AND

/* Level 10: Bitwise inclusive OR */
%left '|'

/* Level 9: Bitwise exclusive OR */
%left '^'

/* Level 8: Bitwise AND */
%left '&'

/* Level 7: Equality operators */
%left EQ NE

/* Level 6: Relational operators */
%left '<' LE '>' GE

/* Level 5: Bitwise shift operators */
%left LEFT_SHIFT RIGHT_SHIFT

/* Level 4: Addition and Subtraction */
%left '+' '-'

/* Level 3: Multiplication, Division, Modulus */
%left '*' '/' '%'

/* Level 2: Unary operators, etc. (right-associative, highest precedence for simple expressions) */
%right '!' UMINUS '~' INC DEC SIZEOF CAST_OP DEREF ADDR_OF

/* Level 1: Postfix operators (handled by grammar rules, not precedence declarations) */
%left ')'   /* NEW: Highest, resolves paren conflicts */
/* Function calls, array subscripting, member access are generally handled by specific, unambiguous grammar rules */



%%
// Grammar rules Section 3: THIS IS WHERE YOUR RULES GO
program : 
  statement_list
  { 
     $$ = $1;
     ast_root = $1;
  }
  ;

 statement:
     assignment_statement ';'    { $$ = $1; }
   |  expression ';'              { $$ = $1; }
   | compound_statement          { $$ = $1; }
   | if_statement            { $$ = $1; }
   | when_statement           { $$ = $1; }
   | do_statement ';'            { $$ = $1; }
   | from_statement           { $$ = $1; }
   | jump_statement ';'          { $$ = $1; }
   | stdio_statement ';'         { $$ = $1; }
   | stdlib_statement ';'        { $$ = $1; }
   | math_statement ';'          { $$ = $1; }
   | string_statement ';'        { $$ = $1; }
   | choice_statement ';'        { $$ = $1; }
   | label_statement ';'         { $$ = $1; }

// error messages



 
    | '(' expression error  ';'
{
    printf("Missing closing ')' in expression at Line : %d\n", yylineno);
    yyerrok;
    $$ = $2;
}
| '(' error ')' 
{
    printf("Invalid expression usage inside parentheses at Line : %d\n", yylineno);
    yyerrok;
    $$ = NULL;
}
;



// IF condition 
if_statement : 
   IF '(' expression ')' statement 
    %prec LOWER_THAN_OR_ELSE
        { $$ = make_if_node($3, $5, NULL); }

    | IF '(' expression ')' statement OR_ELSE statement
          { $$ = make_if_node($3, $5, $7); }
          
    
    //if

   | IF '(' error ')' statement
    %prec LOWER_THAN_OR_ELSE
{
    printf("Condition logic is wrong in IF statement at Line : %d\n", yylineno);
    yyerrok;
      $$ = make_if_node(NULL, $5, NULL); 
}
    | IF '(' expression error statement
    %prec LOWER_THAN_OR_ELSE
 {
    printf("Missing closing ')' in IF statement at Line : %d\n", yylineno);
    yyerrok;
     $$ = make_if_node($3, $5, NULL);
 }

;


// FROM loop - analogous to for loop jn c
from_statement :
   FROM expression TO expression ':' statement
      { $$ = make_from_node($2,$4,NULL,$6); }
        // from

   | FROM error TO expression ':' statement
{
    printf("Seems like the initial expression is invalid in FROM at Line : %d\n", yylineno);
    yyerrok;
    $$ = make_from_node(NULL,$4,NULL,$6);
}
  | FROM expression TO error ':' statement
{
    printf("Seems like the ending expression is invalid in FROM at Line : %d\n", yylineno);
    yyerrok;
    $$ = make_from_node($2,NULL,NULL,$6);
}
  | FROM expression TO expression '(' expression ')' ':' statement
      { $$ = make_from_node($2,$4,$6,$9); }
        // from

   | FROM error TO expression '(' expression ')' ':' statement
{
    printf("Seems like the initial expression is invalid in FROM at Line : %d\n", yylineno);
    yyerrok;
    $$ = make_from_node(NULL,$4,$6,$9);
}
  | FROM expression TO error '(' expression ')' ':' statement
{
    printf("Seems like the ending expression is invalid in FROM at Line : %d\n", yylineno);
    yyerrok;
    $$ = make_from_node($2,NULL,$6,$9);
}    
   | FROM expression TO expression '(' error ')' ':' statement
{
    printf("You entered the wrong modifyer condition in FROM at Line : %d\n", yylineno);
    yyerrok;
    $$ = make_from_node($2,$4,NULL,$9);
}
  | FROM expression TO expression error expression ')' ':' statement
{
    printf("You forgot the starting paranthesis for modifying the incrementer in FROM at Line : %d\n", yylineno);
    yyerrok;
    $$ = make_from_node($2,$4,$6,$9);
}    
  | FROM expression TO expression '(' expression error ':' statement
{
    printf("You forgot the ending paranthesis for modifying the incrementer in FROM at Line : %d\n", yylineno);
    yyerrok;
    $$ = make_from_node($2,$4,$6,$9);
}    
;

//When Statement -analogous to while in c
when_statement :
    WHEN '(' expression ')' statement
        { $$ = make_when_node($3, $5); }
        
  
  // when_statement
    | WHEN '('error  ')' statement
        {
            printf("Invalid condition in WHEN at Line : %d\n", yylineno);
            yyerrok;
            $$ = make_when_node(NULL, $5);
        }

  | WHEN '(' expression error  statement
        {
            printf("Missing closing ')' in WHEN statement at Line : %d\n", yylineno);
            yyerrok;
            $$ = make_when_node($3, $5);
        }


;


do_statement :
  DO statement WHEN '(' expression ')'
    { $$ = make_do_when_node($2, $5); }
    // do when_statement

| DO statement WHEN '('error ')'
    {
        printf("Invalid condition in DO-WHEN at Line : %d\n", yylineno);
        yyerrok;
        $$ = make_do_when_node($2, NULL);
    }


| DO statement WHEN '(' expression error 
    {
        printf("Missing closing ')' in DO-WHEN at Line : %d\n", yylineno);
        yyerrok;
        $$ = make_do_when_node($2, $5);
    }
      ;


choice_statement :
 CHOICE '(' IDENTIFIER ')' ':' '{' case_statement '}'
 { $$ = make_choice_node(make_identifier_node ($3),$7,NULL);}

| CHOICE '(' IDENTIFIER ')' ':' '{' case_statement '}' DEFAULT ':' statement
 { $$ = make_choice_node(make_identifier_node($3),$7,$11);}
 // choice_statement

| CHOICE '(' error ')' ':' '{' case_statement '}'
 {
    printf("Incorrect identifier usage in CHOICE at Line : %d\n", yylineno);
    yyerrok;
    $$ = make_choice_node(NULL, $7, NULL);
 }

| CHOICE '(' IDENTIFIER error ':' '{' case_statement '}'
 {
    printf("Missing ')' in CHOICE statement at Line : %d\n", yylineno);
    yyerrok;
    $$ = make_choice_node(make_identifier_node($3), $7, NULL);
 }

| CHOICE '(' IDENTIFIER ')' ':' error  case_statement '}'
 {
    printf("Missing '{' in CHOICE statement at Line : %d\n", yylineno);
    yyerrok;
    $$ = make_choice_node(make_identifier_node($3), NULL, NULL);
 }

| CHOICE '(' IDENTIFIER ')' ':' '{' case_statement error
 {
    printf("Missing '}' in CHOICE block at Line : %d\n", yylineno);
    yyerrok;
    $$ = make_choice_node(make_identifier_node($3), $7, NULL);
 }
 | CHOICE '(' IDENTIFIER ')' ':' '{' case_statement '}' DEFAULT error statement
{
    printf("Missing ':' after DEFAULT at Line : %d\n", yylineno);
    yyerrok;
    $$ = make_choice_node(make_identifier_node($3),$7,NULL);
}

;

case_statement :
 CASE IDENTIFIER ':' statement 
 { $$ = make_case_node(make_identifier_node($2),$4,NULL);}

| CASE IDENTIFIER ':' statement case_statement
 { $$ = make_case_node(make_identifier_node($2),$4,$5);}

 // case_statement

 
| CASE error ':' statement
 {
    printf("Incorrect identifier usage in CASE at Line : %d\n", yylineno);
    yyerrok;
    $$ = make_case_node(NULL, $4, NULL);
 }

| CASE IDENTIFIER error statement
 {
    printf("Missing ':' in CASE statement at Line : %d\n", yylineno);
    yyerrok;
    $$ = make_case_node(make_identifier_node($2), $4, NULL);
 }

| CASE IDENTIFIER ':' error
 {
    printf("Incorrect statement in CASE at Line : %d\n", yylineno);
    yyerrok;
    $$ = make_case_node(make_identifier_node($2), NULL, NULL);
 }



;
//EXPRESSION 
expression :
// DATATYPES AND IDENTIFIERS
     IDENTIFIER  { $$ = make_identifier_node($1); }

    | INT_LITERAL   { $$ = make_int_literals_node($1);}
    | FLOAT_LITERAL { $$ = make_float_literals_node($1);}
    | STRING  { $$ = make_string_node($1);}
    | BOOLEAN   { $$ = make_boolean_node($1);}
    |CHARACTER { $$ = make_character_node($1);}


         /* Parentheses */
    | '(' expression ')'  { $$ = $2 ;}

 | '-' expression %prec UMINUS { $$ = make_unary_operator("-",$2); }
| '!' expression %prec '!' { $$ = make_unary_operator("!",$2); }
| '~' expression %prec '~' { $$ = make_unary_operator("~",$2); }

  // 4. BINARY *LAST* (lowest precedence, follow your %left order)
| expression '*' expression  { $$ = make_binary_operator_node("*",$1,$3); }
| expression '/' expression  { $$ = make_binary_operator_node("/",$1,$3); }
| expression '%' expression  { $$ = make_binary_operator_node("%",$1,$3); }
| expression '+' expression  { $$ = make_binary_operator_node("+",$1,$3); }
| expression '-' expression  { $$ = make_binary_operator_node("-",$1,$3); }
| expression '<' expression  { $$ = make_binary_operator_node("<",$1,$3); }
| expression '>' expression  { $$ = make_binary_operator_node(">",$1,$3); }
| expression LE expression   { $$ = make_binary_operator_node("<=",$1,$3); }
| expression GE expression   { $$ = make_binary_operator_node(">=",$1,$3); }
| expression EQ expression   { $$ = make_binary_operator_node("==",$1,$3); }
| expression NE expression   { $$ = make_binary_operator_node("!=",$1,$3); }
| expression '&' expression  { $$ = make_binary_operator_node("&",$1,$3); }
| expression '^' expression  { $$ = make_binary_operator_node("^",$1,$3); }
| expression '|' expression  { $$ = make_binary_operator_node("|",$1,$3); }
| expression AND expression  { $$ = make_binary_operator_node("AND",$1,$3); }
| expression OR expression  { $$ = make_binary_operator_node("OR",$1,$3); }
;
    



//COMPOUND STATEMENT used to create a block i.e group code into single group as a single executable statement
compound_statement :
      '{' statement_list '}'
        { $$ = make_compound_node($2); }
        //compound_statement

  | '{' statement_list error
        %prec BLOCK_ERROR
        {
            printf("Missing closing '}' in block at Line : %d\n", yylineno);
            yyerrok;
            $$ = make_compound_node($2);
        }

    | '{' error '}'
        {
            printf("Invalid statements inside block at Line : %d\n", yylineno);
            yyerrok;
            $$ = make_compound_node(NULL);
        }


  
;

// used to tell the block of code can have more than one line of code
statement_list:
      statement
      { $$ = $1;} 
    | statement_list statement
     {  AST_NODE* stmt = $1;
     if (stmt) {
          while(stmt->next)
          stmt=stmt->next;
          if ($2) {
    stmt->next = $2;
}
     }
          $$ =$1;}
    | statement_list error ';'
  {
   printf("Looks like there is an Invalid Syntax usage in line : %d\n", yylineno);
   yyerrok;
   $$ = $1 ;
  }
  ;
// For break,skip and jump_to
jump_statement :
  BREAK  { $$ = make_break_node(); } 
 | SKIP    { $$ = make_skip_node(); }
 |JUMP_TO  LABEL { $$ = make_jumpTo_node(make_identifier_node($2));}
   // jump_statement

  | JUMP_TO error 
{
    printf("LABEL not specified to were the jump to takes place, Line : %d\n", yylineno);
    yyerrok;
    $$ = make_jumpTo_node(NULL);
}

;
// LABEL STATEMENT
label_statement :
 LABEL ':' statement
 { $$ = make_label_node(make_identifier_node($1),$3);}
 //label_statement

| LABEL error statement
{
    printf("Missing ':' after label at Line : %d\n", yylineno);
    yyerrok;
    $$ = make_label_node(make_identifier_node($1), $3);
}



;

//for caling input output function
argument_list:
     /* empty */
        { $$ = NULL; }
    | nonempty_argument_list
     { $$ = $1;}
;

nonempty_argument_list :
   expression
        { $$ = $1; }

    | argument_list ',' expression
        {
            AST_NODE* stmt = $1;
            if (stmt) {
                while (stmt->next)
                    stmt = stmt->next;

                if ($3)
                    stmt->next = $3;
            }
            $$ = $1;
        }
;    

    assignment_statement : 
 
   IDENTIFIER '=' expression
      { $$ = make_assign_node("=", make_identifier_node($1), $3); }

    | IDENTIFIER ADD_ASSIGN expression
        { $$ = make_assign_node("+=",  make_identifier_node($1), $3); }
    | IDENTIFIER SUB_ASSIGN expression
        { $$ = make_assign_node("-=", make_identifier_node($1), $3); }

    | IDENTIFIER MUL_ASSIGN expression
        { $$ = make_assign_node("*=", make_identifier_node($1), $3); }

    | IDENTIFIER DIV_ASSIGN expression
        { $$ = make_assign_node("/=", make_identifier_node($1), $3); }

    | IDENTIFIER MOD_ASSIGN expression
        { $$ = make_assign_node("%=" , make_identifier_node($1), $3); }
  
     ;

// stdio.h
output_ops:
      PRINT   { $$ = "print"; }
    | FPRINT  { $$ = "fprint"; }
    | SPRINT  { $$ = "sprint"; }
    | SNPRINT { $$ = "snprint"; }
    | PUTCHAR { $$ = "putchar"; }
    | PUTC    { $$ = "putc"; }
    | PUTS    { $$ = "puts"; }
    | FPUTC   { $$ = "fputc"; }
    | FPUTS   { $$ = "fputs"; }
;

input_ops:
      SCAN    { $$ = "scan"; }
    | FSCAN   { $$ = "fscan"; }
    | GETCHAR { $$ = "getchar"; }
    | GETC    { $$ = "getc"; }
    | FGETC   { $$ = "fgetc"; }
    | GETS    { $$ = "gets"; }
    | FGETS   { $$ = "fgets"; }
;

file_ops:
      FOPEN   { $$ = "fopen"; }
    | FCLOSE  { $$ = "fclose"; }
    | FREAD   { $$ = "fread"; }
    | FWRITE  { $$ = "fwrite"; }
    | FSEEK   { $$ = "fseek"; }
    | FTELL   { $$ = "ftell"; }
    | REWIND  { $$ = "rewind"; }
    | SETBUFF { $$ = "setbuf"; }
    | SETVBUFF{ $$ = "setvbuf"; }
    | TMPFILE { $$ = "tmpfile"; }
    | TMPNAM  { $$ = "tmpnam"; }
    | REMOVE  { $$ = "remove"; }
    | RENAME  { $$ = "rename"; }
;


error_ops:
      CLEARERR { $$ = "clearerr"; }
    | FEOF     { $$ = "feof"; }
    | FERROR   { $$ = "ferror"; }
    | PERROR   { $$ = "perror"; }
;

stdio_function:
      output_ops
    | input_ops
    | file_ops
    | error_ops
;



stdio_statement:
      stdio_function '(' argument_list ')'
          { $$ = make_stdio_call_node(make_identifier_node($1), $3); }
          //stdio_function
    | stdio_function '(' nonempty_argument_list error
          {
              printf("Missing closing ')' in function call at Line : %d\n", yylineno);
              yyerrok;
              $$ = make_stdio_call_node(make_identifier_node($1), $3);
          }
          
    | stdio_function '('  error ')'
          {
              printf("Invalid arguments  at Line : %d\n", yylineno);
              yyerrok;
              $$ = make_stdio_call_node(make_identifier_node($1), NULL);
          }


   

 
;

// string.h
string_copy_ops:
      STRCPY   { $$ = "strcpy"; }
    | STRNCPY  { $$ = "strncpy"; }
;
string_concat_ops:
      STRCAT   { $$ = "strcat"; }
    | STRNCAT  { $$ = "strncat"; }
;

string_search_ops:
      STRCHR   { $$ = "strchr"; }
    | STRRCHR  { $$ = "strrchr"; }
    | STRSTR   { $$ = "strstr"; }
;

string_compare_ops:
      STRCMP   { $$ = "strcmp"; }
    | STRNCMP  { $$ = "strncmp"; }
;

string_misc_ops:
      STRLEN   { $$ = "strlen"; }
    | STRPBRK  { $$ = "strpbrk"; }
    | STRCSPN  { $$ = "strcspn"; }
    | STRSPN   { $$ = "strspn"; }
    | STRTOK   { $$ = "strtok"; }
;

string_function:
      string_copy_ops
    | string_concat_ops
    | string_search_ops
    | string_compare_ops
    | string_misc_ops
;

string_statement:
    string_function '(' argument_list ')'  
      { $$ = make_string_call_node(make_identifier_node($1), $3); }
      
//string_function

  | string_function '(' nonempty_argument_list error
      {
          printf("Missing closing ')' in string function call at Line : %d\n", yylineno);
          yyerrok;
          $$ = make_string_call_node(make_identifier_node($1), $3);
      }
    | string_function '(' error ')'
      {
          printf("Invalid function argument at Line : %d\n", yylineno);
          yyerrok;
          $$ = make_string_call_node(make_identifier_node($1), NULL);
      }





;
//math.h
math_trig_ops:
      SIN    { $$ = "sin"; }
    | COS    { $$ = "cos"; }
    | TAN    { $$ = "tan"; }
    | ASIN   { $$ = "asin"; }
    | ACOS   { $$ = "acos"; }
    | ATAN   { $$ = "atan"; }
    | ATAN2  { $$ = "atan2"; }
;
math_hyperbolic_ops:
      SINH   { $$ = "sinh"; }
    | COSH   { $$ = "cosh"; }
    | TANH   { $$ = "tanh"; }
;
math_exp_log_ops:
      EXP    { $$ = "exp"; }
    | LOG    { $$ = "log"; }
    | LOG10  { $$ = "log10"; }
;
math_pow_root_ops:
      POW    { $$ = "pow"; }
    | SQRT   { $$ = "sqrt"; }
;
math_misc_ops:
      FABS   { $$ = "fabs"; }
    | FMOD   { $$ = "fmod"; }
;
math_function:
      math_trig_ops
    | math_hyperbolic_ops
    | math_exp_log_ops
    | math_pow_root_ops
    | math_misc_ops
;

math_statement:
      math_function '(' argument_list ')'
        { $$ = make_math_call_node(make_identifier_node($1), $3); }
        //math_function



    | math_function '(' nonempty_argument_list error
        {
            printf("Missing closing ')' in math function call at Line : %d\n", yylineno);
            yyerrok;
            $$ = make_math_call_node(make_identifier_node($1), $3);
        }

    
    | math_function '(' error ')'
        {
            printf("Invalid function arguments at Line : %d\n", yylineno);
            yyerrok;
            $$ = make_math_call_node(make_identifier_node($1), NULL);
        }


;
// STDLIB FUNCTION

stdlib_alloc_ops:
      MALLOC   { $$ = "malloc"; }
    | CALLOC   { $$ = "calloc"; }
    | REALLOC  { $$ = "realloc"; }
    | FREE     { $$ = "free"; }
;
stdlib_abs_div_ops:
      ABS    { $$ = "abs"; }
    | LABS   { $$ = "labs"; }
    | LLABS  { $$ = "llabs"; }
    | DIV    { $$ = "div"; }
    | LDIV   { $$ = "ldiv"; }
    | LLDIV  { $$ = "lldiv"; }
;
stdlib_process_ops:
      EXIT    { $$ = "exit"; }
    | ATEXIT  { $$ = "atexit"; }
    | SYSTEM  { $$ = "system"; }
;
stdlib_convert_ops:
      ATOL     { $$ = "atol"; }
    | ATOI     { $$ = "atoi"; }
    | ATOF     { $$ = "atof"; }
    | STRTOUL  { $$ = "strtoul"; }
    | STRTOL   { $$ = "strtol"; }
    | STRTOF   { $$ = "strtof"; }
;
stdlib_random_ops:
      RAND   { $$ = "rand"; }
    | SRAND  { $$ = "srand"; }
;
stdlib_function:
      stdlib_alloc_ops
    | stdlib_abs_div_ops
    | stdlib_process_ops
    | stdlib_convert_ops
    | stdlib_random_ops
;
stdlib_statement:
      stdlib_function '(' argument_list ')'
          { $$ = make_stdlib_call_node(make_identifier_node($1), $3); }
          //stdlib_function

    | stdlib_function '(' nonempty_argument_list error
          {
              printf("Missing closing ')' in stdlib function call at Line : %d\n", yylineno);
              yyerrok;
              $$ = make_stdlib_call_node(make_identifier_node($1), $3);
          }
    
    | stdlib_function '('  error ')'
          {
              printf("Invalid function arguments at Line : %d\n", yylineno);
              yyerrok;
              $$ = make_stdlib_call_node(make_identifier_node($1), NULL);
          }




;

%%
//User subroutines (C code) 
//Section 4: helper functions (yyerror, main, etc.)
extern int yylineno;
 void yyerror(const char* s){
   fprintf(stderr,"Syntax error at line %d : %s\n",yylineno, s);
 }
