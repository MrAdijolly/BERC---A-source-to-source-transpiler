/**
 * @file semantic_analysis.h
 * @brief Header for the semantic analysis phase.
 */

#ifndef SEMANTIC_ANALYSIS_H
#define SEMANTIC_ANALYSIS_H

#include "AST.h"
#include <stdbool.h>



bool semantic_check(AST_NODE *root);

#endif /* SEMANTIC_ANALYSIS_H */

