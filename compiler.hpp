/// @file
/// @brief bytecode compiler

/// @defgroup bc bytecode compiler

#ifndef _H_COMPILER
#define _H_COMPILER

#include <iostream>
#include <vector>
#include <map>

#include "bcx.h"
									// lexer/parser interface
extern int yylex();
extern int yylineno;
extern char *yytext;
extern int yyparse();
extern void yyerror(std::string msg);
#include "compiler.parser.hpp"

#endif // _H_COMPILER
