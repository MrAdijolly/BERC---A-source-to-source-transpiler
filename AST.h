#ifndef AST_H
#define AST_H
#include<stdbool.h>

typedef enum { // define type of node
    // datatype
   int_literals,
    float_literals,
    identifiers,
    string,
    characters,
   boolean,
   // operators
   unary_operator,
   binary_operator,
   // arbitrary
   compound_node,
   break_node,
   skip_node,
   jumpTo_node,
   label_node,
   assign_node,
   // KEYWORDS
    if_statement,
    when_statement,
    do_when_statement,
    from_statement,
    choice_statement,
    case_statement,
    //FUNCTION 
    stdio_function,
    string_function,
    math_function,
    stdlib_function
}NODETYPE;

typedef enum {
    TYPE_BOOL,
    TYPE_CHAR,
    TYPE_INT,
    TYPE_LONG_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_STRING,
    TYPE_LABEL,
    TYPE_UNKNOWN
}DataType;

typedef struct AST_NODE {
    NODETYPE type; // for defining the type of node being created
    struct AST_NODE* left; // for left child of tree
    struct  AST_NODE* right; // for right child of tree
    struct  AST_NODE* next; // to point to next node
    struct AST_NODE* label;
    struct AST_NODE* incrementer;// used in the from loop 
    long int idval; // for int_list
    float fval;    // for float_list
    char* str;  // for identifiers
    char cval; //for alphabet literals
    bool bval; //boolean value holder
    char* operator; // for storing operators
    DataType inferred;
    int line_no;
}AST_NODE ;

AST_NODE* make_int_literals_node(int a);
AST_NODE*  make_float_literals_node(float a);
AST_NODE* make_identifier_node(char* a);
AST_NODE*  make_string_node(char* a);
AST_NODE* make_character_node(char a);
AST_NODE* make_boolean_node(bool a);
AST_NODE*  make_unary_operator(char* a,AST_NODE* expression);
AST_NODE* make_binary_operator_node(char* a,AST_NODE* left_exp, AST_NODE* right_exp);
AST_NODE* make_compound_node(AST_NODE* statement);
AST_NODE* make_break_node();
AST_NODE* make_jumpTo_node(AST_NODE* LABEL);
AST_NODE* make_label_node(AST_NODE* LABEL,AST_NODE* exp);
AST_NODE* make_skip_node();
AST_NODE* make_assign_node (char* oper,AST_NODE* identifier,AST_NODE* exp);
AST_NODE* make_if_node(AST_NODE* exp,AST_NODE* statement,AST_NODE* else_stmt);
AST_NODE* make_from_node(AST_NODE* left_exp , AST_NODE* right_exp,AST_NODE* mod_condition,AST_NODE* stmt);
AST_NODE* make_when_node(AST_NODE* exp, AST_NODE* stmt);
AST_NODE* make_do_when_node(AST_NODE* statement,AST_NODE* exp);
AST_NODE* make_choice_node(AST_NODE* identifier,AST_NODE* case_statement, AST_NODE* default_) ;
AST_NODE* make_case_node(AST_NODE* identifier,AST_NODE* statement,AST_NODE* case_stmt);
AST_NODE* make_stdio_call_node(AST_NODE*  function_name,AST_NODE* exp);
AST_NODE* make_string_call_node(AST_NODE*  function_name,AST_NODE* arg);
AST_NODE*  make_math_call_node(AST_NODE*  function_name    ,AST_NODE* arg1);
AST_NODE* make_stdlib_call_node(AST_NODE*  function_name,AST_NODE* arg);
#endif