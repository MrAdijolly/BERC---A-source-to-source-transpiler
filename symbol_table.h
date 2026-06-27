/**
 * @file symbol_table.h
 * @brief Header for the symbol table management.
 */

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include "AST.h"




typedef enum {
  SYM_VAR, /**< A variable symbol. */
  SYM_FUNC, /**< A function symbol. */
  SYM_LABEL
} SymbolKind;


typedef struct Symbol {
    char *name;
    DataType type;
    SymbolKind kind;
    int scope;
    bool generated ;
    struct Symbol *next;
} Symbol;


void enter_scope(void);

void exit_scope(void);


void insert_symbol(char *name, DataType type, SymbolKind kind);


Symbol *lookup_symbol(char *name);

#endif

