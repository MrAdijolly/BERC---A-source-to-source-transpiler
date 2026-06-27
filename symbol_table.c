#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include "AST.h"

typedef enum {
    SYM_VAR,
    SYM_FUNC,
    SYM_LABEL
} SymbolKind;

// ---------- Symbol Structure ----------
typedef struct Symbol {
    char *name;
    DataType type;
    SymbolKind kind;
    int scope;
    bool generated;
    struct Symbol *next;
} Symbol;

// ---------- Symbol Table ----------
typedef struct {
    Symbol *head;
} SymbolTable;

SymbolTable symtab = { NULL };
int current_scope = 0;

// ---------- Scope Management ----------
void enter_scope() {
    current_scope++;
}

void exit_scope() {
    // Remove all symbols in the current scope
    Symbol **temp = &symtab.head;
    while (*temp) {
        if ((*temp)->scope == current_scope) {
            Symbol *to_delete = *temp;
            *temp = (*temp)->next;
            free(to_delete->name);
            free(to_delete);
        } else {
            temp = &(*temp)->next;
        }
    }
    current_scope--;
}

// ---------- Symbol Operations ----------
void insert_symbol(char *name, DataType type, SymbolKind kind) {
    Symbol *s = malloc(sizeof(Symbol));
    s->name = strdup(name);
    s->type = type;
    s->kind = kind;
    s->scope = current_scope;
    s->generated = false;
    // Insert at the head
    s->next = symtab.head;
    symtab.head = s;
}

Symbol* lookup_symbol(char *name) {
    Symbol *temp = symtab.head;
    Symbol *best = NULL;

    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            if (!best || temp->scope >= best->scope)
                best = temp; // prefer innermost scope
        }
        temp = temp->next;
    }
    return best;
}


