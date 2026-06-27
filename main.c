/**
 * @file main.c
 * @brief Main entry point for the transpiler.
 */

#include "AST.h"
#include "semantic_analysis.h"
#include <stdio.h>
#include <stdlib.h>
#include "code_generation.h"

#include <string.h>
#include <stdbool.h>

char output_name[256] = "generated.c";


// Externally defined by the parser
extern int yyparse(void);
extern FILE *yyin;
int compile_errors = 0;


// The root of the AST, often set by the parser
extern AST_NODE *ast_root;



bool has_berc_extension(const char *filename)
{
    const char *ext = strrchr(filename, '.');

    if(ext == NULL)
        return false;

    return strcmp(ext, ".berc") == 0;
} 


int main(int argc, char **argv)
{
  if (argc > 1)
   {
      if(!has_berc_extension(argv[1]))
      {
          printf("Error: Input file must have the '.berc' extension.\n");
          return 1;
      }
      if(argc == 4)
      {
          if(strcmp(argv[2], "-n") == 0)
          {
            strcpy(output_name, argv[3]);
            if(strrchr(output_name, '.') == NULL)
            {
              strcat(output_name, ".c");
            }
          }
          else
          {
              printf("Unknown option '%s'\n", argv[2]);
              return 1;
          }
      }
      FILE *file = fopen(argv[1], "r");
      if (!file)
      {
        perror("Error opening file");
        return 1;
      }
      yyin = file;
   }
  else 
   {
     printf("\nError : Please provide a file to compile \n\t Format : berc <filename.berc [-n output_name]");
     return 1;
   }
  


  
  

  printf("Starting Lexical Analysis and  Syntax Analysis...\n");
  if (yyparse() == 0)
  {
    printf("Syntax Analysis Successful.\n");
  } 
  else {
    fprintf(stderr, "Syntax error detected.\n");
    return 1;
  }

  fclose(yyin);


   printf("Starting Semantic Analysis...\n");
    if (semantic_check(ast_root)) {
      printf("Semantic Analysis Successful.\n");
    } else {
      fprintf(stderr, "Semantic error detected.\n");
      return 1;
    }
   
  generate_code();
  return 0;
 }
