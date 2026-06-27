#include "symbol_table.h"
#include "AST.h"
#include "code_generation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



extern AST_NODE *ast_root;
extern char output_name[256];
char loop_name[32];
static int generated_loop_id=0;



static void generate_node(AST_NODE *node) ;


static int indent = 0;
FILE *fp = NULL;

static void print_indent(void)
{
    for(int i = 0; i < indent; i++)
    {
        fprintf(fp,"    ");
    }
}


void generate_code()
 {
     fp = fopen(output_name,"w");

    if(fp == NULL)
    {
        fprintf(stderr,"Cannot open output file.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(fp,"#include<stdio.h>\n");
    fprintf(fp,"#include<stdlib.h>\n");
    fprintf(fp,"#include<string.h>\n");
    fprintf(fp,"#include<math.h>\n");
    fprintf(fp,"#include<stdbool.h>\n");
    fprintf(fp,"\n  int main()\n        {");
    indent++;
     
    generate_node(ast_root);
    
    indent--;
    fprintf(fp,"     return 0;\n");
    fprintf(fp,"}");
     fclose(fp);
 }


 static void generate_expression(AST_NODE *node)
{
    if(node == NULL)
        return;

    switch(node->type)
    {
        case int_literals:
            if ( node->inferred == TYPE_INT)
             fprintf(fp,"%d",(int)node->idval);
            else 
              fprintf(fp,"%ld",node->idval);
            break;

        case float_literals :
             fprintf(fp,"%f",node->fval);
             break;

        case identifiers:

             fprintf(fp,"%s",node->str);
             break;

        case characters : 
             fprintf(fp,"'%c'",node->cval);
             break;

        case string : 
             fprintf(fp,"\"%s\"",node->str);
             break;

        case boolean :
             fprintf(fp,"%s",node->bval?  "true" : "false" );
             break;

        case unary_operator :
        fprintf(fp,"(");
             fprintf(fp,"%s",node->operator);
             generate_expression(node->left);
             fprintf(fp,")");
             break;

        case binary_operator:

            fprintf(fp,"(");

            generate_expression(node->left);

            fprintf(fp," %s ",node->operator);

            generate_expression(node->right);

            fprintf(fp,")");

            break;

        case string_function :
             fprintf(fp,"%s",node->label->str);
             fprintf(fp,"(");
             generate_expression(node->left);
             fprintf(fp,")");
             break;

        case math_function :
             fprintf(fp,"%s",node->label->str);
             fprintf(fp,"(");
             generate_expression(node->left);
             fprintf(fp,")");
             break;

        case stdlib_function :
             fprintf(fp,"%s",node->label->str);
             fprintf(fp,"(");
             generate_expression(node->left);
             fprintf(fp,")");
             break;

        default:
             fprintf(stderr,"Code Generation Error: Unknown expression node.\n");
             break;

    }
}


static void generate_for_header(AST_NODE *node)
 {
    sprintf(loop_name, "__berc_loop%d", generated_loop_id++);
    fprintf(fp,"for ( int  %s = ",loop_name);
    if (node->left->idval < node->right->idval)
        {
            generate_expression(node->left);
            fprintf(fp,"; %s <",loop_name);
            generate_expression(node->right);
            fprintf(fp," ; %s = ",loop_name);
        }
    else 
        {
            generate_expression(node->right);
            fprintf(fp,"; %s >",loop_name);
            generate_expression(node->left);
            fprintf(fp," ; %s = ",loop_name);
        }    
 }

 static void generate_for_incrementer(AST_NODE *node)
 {
    
        if(node->incrementer != NULL)
         {
              generate_expression(node->incrementer);
         }
        else 
          {
            if(node->left->idval < node->right->idval)
             {
                 fprintf(fp,"%s + 1",loop_name);
             }
            else 
            {
                 fprintf(fp,"%s - 1",loop_name);
            }
          }
         fprintf(fp,";)\n");
 }


static void generate_node(AST_NODE *node) 
{
     if(!node)
        return;

  switch(node->type)
   {
      case assign_node:
            {
                print_indent();
                
                Symbol *sym = lookup_symbol(node->left->str);

                if(sym != NULL && !sym->generated)
                    {
                        switch(sym->type)
                        {
                            case TYPE_INT:
                                fprintf(fp,"int ");
                                break;

                            case TYPE_LONG_INT:
                                fprintf(fp,"long int ");
                                break;

                            case TYPE_FLOAT:
                                fprintf(fp,"float ");
                                break;

                            case TYPE_CHAR:
                                fprintf(fp,"char ");
                                break;

                            case TYPE_BOOL:
                                fprintf(fp,"bool ");
                                break;
                        }

                        sym->generated = true;
                    }
                
                generate_expression(node->left);
            
                fprintf(fp," %s ",node->operator);
            
                generate_expression(node->right);
            
                fprintf(fp,";\n");
                if(node->next != NULL)
                generate_node(node->next);

                break;
            }
        
        case if_statement :
            print_indent();
            fprintf(fp,"if (");
            generate_expression(node->left);
            fprintf(fp,")\n");
            indent++;
            generate_node(node->right);
            indent--;
            if (node->next != NULL )
                {
                    print_indent();
                    fprintf(fp,"else \n");
                    generate_node(node->next);
                }
            break;

        case when_statement :
            print_indent();
            fprintf(fp,"while (");
            generate_expression(node->left);
            fprintf(fp,")\n");
            indent++;
            generate_node(node->right);
            indent--;
            if(node->next != NULL)
                generate_node(node->next);
            break;

        case do_when_statement :
            print_indent();
            fprintf(fp,"do\n");
            indent++;
            generate_node(node->left);
            indent++;
            print_indent();
            fprintf(fp,"while (");
            generate_expression(node->right);
            fprintf(fp,");\n");
            indent-=2;
            if(node->next != NULL)
                generate_node(node->next);
            break;

        case from_statement :
                print_indent();
                generate_for_header(node);
                generate_for_incrementer(node);
                indent++;
                generate_node(node->next);
                indent--; 
                if(node->next != NULL)
                    generate_node(node->next);  
            break;

        case choice_statement:

            print_indent();

            fprintf(fp,"switch(");

            generate_expression(node->left);

            fprintf(fp,")\n");

            indent++;

            generate_node(node->right);

            if(node->next != NULL)
                generate_node(node->next);

            indent--;

            break;
        
        case skip_node :
            print_indent();
            fprintf(fp,"continue;\n");
            if(node->next != NULL)
                generate_node(node->next);
            break;

        case break_node :
            print_indent();
            fprintf(fp,"break;\n");
            if(node->next != NULL)
                generate_node(node->next);
            break;

        case case_statement :
            print_indent();

            fprintf(fp,"case ");

            generate_expression(node->left);

            fprintf(fp,":\n");

            indent++;

            generate_node(node->right);

            print_indent();

            fprintf(fp,"break;\n");

            indent--;

            if(node->next != NULL)
                generate_node(node->next);

            break;

        case label_node :

                fprintf(fp,"%s:\n", node->label->str);
                indent++;
                generate_node(node->right);
                indent--;
                if(node->next != NULL)
                    generate_node(node->next);
                break;

        case jumpTo_node :
                print_indent();
                fprintf(fp,"goto %s;\n", node->label->str);
                if(node->next != NULL)
                    generate_node(node->next);
                break;

        case compound_node :
             print_indent();
             fprintf(fp,"{\n");

             indent++;

             generate_node(node->left);

             indent--;

             print_indent();
             fprintf(fp,"}\n");
            break;

        case stdio_function:

            print_indent();

            fprintf(fp,"%s(", node->label->str);

            AST_NODE *arg = node->next;

            while(arg != NULL)
            {
                generate_expression(arg);

                if(arg->next != NULL)
                    fprintf(fp,", ");

                arg = arg->next;
            }

            fprintf(fp,");\n");
            generate_node(node->next);

            break;
        
        default: 
             fprintf(stderr,"Code Generation Error: Unknown node type %d at line %d.\n",
             node->type,
             node->line_no);
             exit(EXIT_FAILURE);
             break;
    
    }
    
   

}