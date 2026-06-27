/**
 * @file semantic_analysis.c
 * @brief Implementation of semantic analysis logic.
 */

#include "semantic_analysis.h"
#include "symbol_table.h"
#include "AST.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int INT_MAX = 2147483647;
int semantic_errors = 0;

static void check_node(AST_NODE *node);


 static void check_condition(AST_NODE *condition, const char *stmt)
{
    check_node(condition);

    if(condition->inferred == TYPE_UNKNOWN)
    {
        printf("Semantic Error ( Line no : %d ) : Incorrect condition in %s statement due to unknown datatype.\n",condition->line_no, stmt);
        semantic_errors++;
    }
    else if(condition->type == assign_node)
    {
        printf("Semantic Error ( Line no : %d ) : Assignment cannot be used as a %s condition.\n",condition->line_no, stmt);
        semantic_errors++;
    }
    else if(condition->inferred == TYPE_STRING)
    {
        printf("Semantic Error ( Line no : %d ) : STRING cannot be used as a %s condition.\n",condition->line_no, stmt);
        semantic_errors++;
    }
}


static void check_node(AST_NODE *node)
{
    if(!node)
        return;

 switch(node->type)
 {

    //1. Integer literals
   case int_literals:
       if (node->idval > INT_MAX)
        { node->inferred = TYPE_LONG_INT;}
       else 
           node->inferred = TYPE_INT;
     break;

    //2. Float literals
    case float_literals:
     node->inferred = TYPE_FLOAT;
     
     break;

    //3. String literals
    case string:
      node->inferred = TYPE_STRING;
        break;

    //4. Character literals
    case characters:
     node->inferred = TYPE_CHAR;
       
     break;

    //5. Boolean literals
    case boolean:
      node->inferred = TYPE_BOOL;
       
      break;

    //6. Identifiers
    case identifiers:
    {
      Symbol *s = lookup_symbol(node->str);

        if( s == NULL )
        {
            printf("Semantic Error ( Line no : %d ) : Undeclared identifier '%s'\n",node->line_no,node->str);
        }
        else 
         node->inferred = s->type;

        break;
    }
    //7. Assignment
    case assign_node:
    {
        check_node(node->right);
        if(node->right->inferred == TYPE_LABEL)
         {
           printf("Semantic Error ( Line no : %d ) : Label '%s' cannot be assigned to a variable.\n",node->line_no,node->right->str);
           semantic_errors++;
           break;
          }
        else if(node->left->inferred == TYPE_LABEL)
        {
           printf("Semantic Error ( Line no : %d ) : Cannot assign a value to label '%s'.\n",node->line_no,node->left->str);
           semantic_errors++;
           break;
        }
        Symbol *s = lookup_symbol(node->left->str);
        if(s == NULL)
        {
            insert_symbol(node->left->str, node->right->inferred,SYM_VAR);
        }
        else
        {
            s->type = node->right->inferred;
        }
      break;
    }


    //8. Binary Operators
    case binary_operator:

        check_node(node->left);
        check_node(node->right);
         DataType left  = node->left->inferred;
         DataType right = node->right->inferred;
        if(left == TYPE_LABEL || right == TYPE_LABEL)
        {
            printf("Semantic Error ( Line no : %d ) : Label cannot be used as an operand of '%s'.\n",node->line_no,node->operator);
           semantic_errors++;
           break;
        }
        if(left == TYPE_UNKNOWN || right == TYPE_UNKNOWN)
        {
            printf("Semantic Error ( Line no : %d ) : Arithmetic operator '%s' has unknown operand type.\n",node->line_no,node->operator);
            semantic_errors++;
            break;
        }
        //Arithmetic operator
        if(strcmp(node->operator,"+")==0 || strcmp(node->operator,"-")==0 || strcmp(node->operator,"*")==0 || strcmp(node->operator,"/")==0 )
        {
           if(left == TYPE_STRING || right == TYPE_STRING)
           {
             printf("Semantic Error ( Line no : %d ) : '%s' cannot be applied between Strings.\n",node->line_no,node->operator);
             semantic_errors++;
             break;
            }
            if(left == TYPE_DOUBLE || right == TYPE_DOUBLE)
              node->inferred = TYPE_DOUBLE;
            else if(left == TYPE_FLOAT || right == TYPE_FLOAT)
             node->inferred = TYPE_FLOAT;
            else if(left == TYPE_LONG_INT || right == TYPE_LONG_INT)
             node->inferred = TYPE_LONG_INT;
            else
             node->inferred = TYPE_INT;
        }   
      // Modulus
        else if(strcmp(node->operator,"%")==0)
        {
          if(left == TYPE_FLOAT ||  left == TYPE_DOUBLE || right == TYPE_FLOAT || right == TYPE_DOUBLE || left == TYPE_STRING || right == TYPE_STRING)
          {
              printf("Semantic Error ( Line no : %d ) : Modulus operator '%%' requires integral operands.\n", node->line_no);
             semantic_errors++;
              break;
          }
          if(left == TYPE_LONG_INT || right == TYPE_LONG_INT)
              node->inferred = TYPE_LONG_INT;
          else
              node->inferred = TYPE_INT;
        }
        //Relational Operator
        else if(strcmp(node->operator,"<")==0 ||strcmp(node->operator,">")==0 || strcmp(node->operator,"<=")==0 || strcmp(node->operator,">=")==0)
        {
          if(left == TYPE_STRING || right == TYPE_STRING)
          {
              printf("Semantic Error ( Line no : %d ) : Comparison operator '%s' cannot compare Strings.\n",node->line_no,node->operator);
              semantic_errors++;
              break;
          }
          node->inferred = TYPE_BOOL;
        }
        //Equality Operator
        else if(strcmp(node->operator,"==")==0 || strcmp(node->operator,"!=")==0)
        {
          if((left == TYPE_STRING && right != TYPE_STRING) || (left != TYPE_STRING && right == TYPE_STRING))
          {
            printf("Semantic Error ( Line no : %d ) : You used distinct datatype in the equality operator '%s'.\n",node->line_no,node->operator);
            semantic_errors++;
            break;
          }
        node->inferred = TYPE_BOOL;
        }
        // Bitwise Operator
        else if(strcmp(node->operator,"&")==0 ||strcmp(node->operator,"|")==0 || strcmp(node->operator,"^")==0)
        {
          if(!(left == TYPE_INT || left == TYPE_LONG_INT || left == TYPE_CHAR || left == TYPE_BOOL))
          {
             printf("Semantic Error ( Line no : %d ) : Left operand of '%s' must be an integral type.\n",node->line_no,node->operator);
             semantic_errors++;
             break;
          }
          if(!(right == TYPE_INT ||right == TYPE_LONG_INT || right == TYPE_CHAR || right == TYPE_BOOL))
          {
             printf("Semantic Error ( Line no : %d ) : Right operand of '%s' must be an integral type.\n",node->line_no,node->operator);
             semantic_errors++;
             break;
          }
          if(left == TYPE_LONG_INT || right == TYPE_LONG_INT)
            node->inferred = TYPE_LONG_INT;
          else
            node->inferred = TYPE_INT;
        }
      else if(strcmp(node->operator,"AND")==0 || strcmp(node->operator,"OR")==0)
      {
        if(left == TYPE_STRING || right == TYPE_STRING)
        {
            printf("Semantic Error ( Line no : %d ) : Logical operator '%s' cannot be applied to STRING operands.\n",node->line_no, node->operator);
            semantic_errors++;
            break;
        }
        else if(left != TYPE_BOOL || right != TYPE_BOOL)
        {
            printf("Semantic Error ( Line no : %d ) : Logical operator '%s' requires BOOLEAN operands.\n",node->line_no,node->operator);
            semantic_errors++;
            break;
        }
        node->inferred = TYPE_BOOL;
      }
        break;

    //9. Unary Operator
     case unary_operator:
     {
      check_node(node->left);
      DataType operand = node->left->inferred;
      if(operand == TYPE_LABEL)
      {
         printf("Semantic Error ( Line no : %d ) : Unary operator '%s' cannot be applied to a label.\n",node->line_no,node->operator);
         semantic_errors++;
         break;
      }
      if(operand == TYPE_UNKNOWN)
      {
          printf("Semantic Error ( Line no : %d ) : Unknown operand for unary operator '%s'.\n",node->line_no,node->operator);
          semantic_errors++;
          break;
      }
      if(strcmp(node->operator, "-") == 0)
      {
        if(operand == TYPE_STRING)
        {
          printf("Semantic Error ( Line no : %d ) : Unary '-' cannot be applied to STRING.\n",node->line_no);
          semantic_errors++;
          break;
        }
       node->inferred = operand;
      }
      else if(strcmp(node->operator, "!") == 0)
      {
        if(operand == TYPE_STRING)
        {
          printf("Semantic Error ( Line no : %d ) : Logical NOT '!' cannot be applied to STRING.\n",node->line_no);
          semantic_errors++;
          break;
        }
        node->inferred = TYPE_BOOL;
      }
      else if(strcmp(node->operator, "~") == 0)
      {
        if(operand == TYPE_FLOAT)
        {
           printf("Semantic Error ( Line no : %d ) : Bitwise NOT '~' cannot be applied to FLOAT.\n",node->line_no);
        }
        else if(operand == TYPE_DOUBLE)
        {
           printf("Semantic Error ( Line no : %d ) : Bitwise NOT '~' cannot be applied to DOUBLE.\n",node->line_no);
        }
        else if(operand == TYPE_STRING)
        {
           printf("Semantic Error ( Line no : %d ) : Bitwise NOT '~' cannot be applied to STRING.\n",node->line_no);
        }
        else if(operand == TYPE_LABEL)
        {
           printf("Semantic Error ( Line no : %d ) : Bitwise NOT '~' cannot be applied to LABEL.\n",node->line_no);
        }
        else
        {
           printf("Semantic Error ( Line no : %d ) : Bitwise NOT '~' cannot be applied to this datatype.\n",node->line_no);
        }
        semantic_errors++;
        break;
        if(operand == TYPE_LONG_INT)
          node->inferred = TYPE_LONG_INT;
        else
          node->inferred = TYPE_INT;
      }
      break;
     }

    //10. IF Statement
    case if_statement:

        check_condition(node->left,"IF");
        check_node(node->right);
        break;

    //11.  WHEN Statement
    case when_statement:

        check_condition(node->left,"WHEN");
        check_node(node->right);
        break;
 
    //12. DO WHEN Statement
    case do_when_statement:
        check_condition(node->left,"DO WHEN");
        check_node(node->right);
        break;


    //13. FROM Statement
    case from_statement:
        check_node(node->left);
        check_node(node->right);
        check_node(node->incrementer);
        check_node(node->next);
        if(node->left->inferred == TYPE_UNKNOWN)
         {
           printf("Semantic Error ( Line no : %d ) : Incorrect initial value in FROM statement due to unknown datatype.\n",node->line_no);
           semantic_errors++;
         }
        else if(node->left->type == assign_node)
         {
           printf("Semantic Error ( Line no : %d ) : Assignment cannot be used as a initial value in FROM condition.\n",node->line_no);
           semantic_errors++;
          }
        else if(node->left->inferred == TYPE_STRING)
         {
           printf("Semantic Error ( Line no : %d ) : STRING cannot be used as a initial value in FROM condition.\n",node->line_no);
           semantic_errors++;
          }
        else if(node->right->inferred == TYPE_UNKNOWN)
         {
           printf("Semantic Error ( Line no : %d ) : Incorrect terminal value in FROM statement due to unknown datatype.\n",node->line_no);
           semantic_errors++;
         }
        else if(node->right->type == assign_node)
         {
           printf("Semantic Error ( Line no : %d ) : Assignment cannot be used as a terminal value in FROM condition.\n",node->line_no);
           semantic_errors++;
          }
        else if(node->right->inferred == TYPE_STRING)
         {
           printf("Semantic Error ( Line no : %d ) : STRING cannot be used as a terminal value in FROM condition.\n",node->line_no);
           semantic_errors++;
          }
        else if(node->incrementer)
          {
              if(node->incrementer->type != assign_node)
              {
                  printf("Semantic Error ( Line no : %d ) : FROM incrementer must be an assignment expression.\n",node->line_no);
                  semantic_errors++;
              }
          }
        break;


    //14. Compound Statement
    case compound_node :

        enter_scope();

        check_node(node->left);

        exit_scope();

        break;

    //15. CHOICE Statement
    case choice_statement :
     check_node(node->left);      
     check_node(node->right);     
     if(node->left->inferred == TYPE_UNKNOWN)
       {
          printf("Semantic Error ( Line no : %d ) : CHOICE expression has unknown datatype.\n",node->line_no);
          semantic_errors++;
       }
      else if(node->left->type == assign_node)
       {
          printf("Semantic Error ( Line no : %d ) : Assignment cannot be used as a CHOICE expression.\n",node->line_no);
          semantic_errors++;
       }

      break;
    
    //16. CASE Statement 
    case case_statement :
      check_node(node->left);      
      check_node(node->right);     
      check_node(node->next);      
      if(node->left->inferred == TYPE_UNKNOWN)
       {
          printf("Semantic Error ( Line no : %d ) : CASE value has unknown datatype.\n",node->line_no);
          semantic_errors++;
      }
      break;
    
    //17. BREAK Statement 
    case break_node :
      break;

    //18. CONTINUE Statement
    case skip_node :
      break;

    //19. LABEL Statement
    case label_node :
      if(node->label->type != identifiers)
        {
         printf("Semantic Error ( Line no : %d ) : Label must be an identifier.\n",node->line_no);
         semantic_errors++;
        }
      else
        {
          if(lookup_symbol(node->label->str) != NULL)
           {
             printf("Semantic Error ( Line no : %d ) : Duplicate label '%s'.\n",node->line_no,node->label->str);
             semantic_errors++;
           }
          else
           {
             insert_symbol(node->label->str,TYPE_LABEL,SYM_LABEL);
            }
        }
      check_node(node->right);
      break;

    //20. JUMP TO Statement
    case jumpTo_node :
      {
      if(node->label->type != identifiers)
      {
          printf("Semantic Error ( Line no : %d ) : jumpTo requires a label identifier.\n",node->line_no);
          semantic_errors++;
      }
      Symbol *s = lookup_symbol(node->label->str);
      if(s == NULL)
      {
          printf("Semantic Error ( Line no : %d ) : Undefined label '%s'.\n",node->line_no,node->label->str);
          semantic_errors++;
      }
      else if(s->kind != SYM_LABEL)
      {
          printf("Semantic Error ( Line no : %d ) : '%s' is not a label.\n",node->line_no,node->label->str);
          semantic_errors++;
      }
        break;
      }

    //21. STDIO Functions
    case stdio_function:
      check_node(node->next);
      if(node->label->type != identifiers)
      {
          printf("Semantic Error ( Line no : %d ) : Invalid stdio function name.\n",node->line_no);
          semantic_errors++;
          break;
      }
      break;


    //22. STRING Functions
    case string_function:
      check_node(node->left);
      if(node->label->type != identifiers)
      {
          printf("Semantic Error ( Line no : %d ) : Invalid string function name.\n",node->line_no);
          semantic_errors++;
          break;
      }
      /* strlen() */
      if(strcmp(node->label->str,"strlen")==0)
      {
          if(node->left->inferred != TYPE_STRING)
          {
              printf("Semantic Error ( Line no : %d ) : strlen() expects a STRING argument.\n",node->line_no);
              semantic_errors++;
          }

          node->inferred = TYPE_INT;
      }
      /* strcmp() */
      else if(strcmp(node->label->str,"strcmp")==0)
      {
          node->inferred = TYPE_INT;
      }
      /* strcpy(), strcat() */
      else if(strcmp(node->label->str,"strcpy")==0 ||strcmp(node->label->str,"strcat")==0)
      {
          node->inferred = TYPE_STRING;
      }
      else
      {
          printf("Semantic Error ( Line no : %d ) : Unknown string function '%s'.\n",node->line_no,node->label->str);
          semantic_errors++;
      }

      break;


    //23.  MATH Functions
    case math_function:
      check_node(node->left);
      if(node->label->type != identifiers)
      {
          printf("Semantic Error ( Line no : %d ) : Invalid math function name.\n",node->line_no);
          semantic_errors++;
          break;
      }
      if(!(node->left->inferred == TYPE_INT ||
          node->left->inferred == TYPE_LONG_INT ||
          node->left->inferred == TYPE_FLOAT ||
          node->left->inferred == TYPE_DOUBLE))
      {
          printf("Semantic Error ( Line no : %d ) : Math function '%s' requires a numeric argument.\n",node->line_no,node->label->str);
          semantic_errors++;
      }
      node->inferred = TYPE_DOUBLE;
      break;


    //24. LIBRARY Functions
    case stdlib_function:
      check_node(node->left);
      if(node->label->type != identifiers)
      {
          printf("Semantic Error ( Line no : %d ) : Invalid stdlib function name.\n",node->line_no);
          semantic_errors++;
          break;
      }
      if(strcmp(node->label->str,"atoi")==0)
      {
          if(node->left->inferred != TYPE_STRING)
          {
              printf("Semantic Error ( Line no : %d ) : atoi() expects a STRING argument.\n",node->line_no);
              semantic_errors++;
          }

          node->inferred = TYPE_INT;
      }
      else if(strcmp(node->label->str,"atof")==0)
      {
          if(node->left->inferred != TYPE_STRING)
          {
              printf("Semantic Error ( Line no : %d ) : atof() expects a STRING argument.\n",node->line_no);
              semantic_errors++;
          }

          node->inferred = TYPE_DOUBLE;
      }
      else
      {
          printf("Semantic Error ( Line no : %d ) : Unknown stdlib function '%s'.\n",node->line_no,node->label->str);
          semantic_errors++;
      }
      break;
   
   
   default:

        check_node(node->left);
        check_node(node->right);
        

        break;
    }
    check_node(node->next);

}
bool semantic_check(AST_NODE *root)
{
    semantic_errors = 0;

    check_node(root);

    if(semantic_errors == 0)
    {
        printf("\nSemantic Analysis Successful.\n");
        return true;
    }

    printf("\nSemantic Analysis Failed with %d error(s).\n",semantic_errors);

    return false;
}

