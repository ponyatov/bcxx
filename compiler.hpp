/// @file
/// @brief bytecode compiler headers

/// @defgroup bc bytecode compiler
/// @{

#ifndef _H_COMPILER
#define _H_COMPILER

#include <iostream>
#include <vector>
#include <map>
#include <stack>

#include "bcx.h"

/// @defgroup stab symbol table
/// @ingroup compiler
/// @{

/// @brief known labels
extern std::map<std::string,CELL> label;
/// @brief forward references
extern std::map<std::string,std::vector<CELL>> forward;

/// @brief compile label
extern void Lcompile(std::string *name);
/// @brief define label
extern void Ldefine(std::string *name);

/// @}

/// @defgroup cstack control structure compiler stack
/// @{

/// @brief control structure compiler stack
extern std::stack<WORD> Cstack;

/// @brief push compiler position
extern void Cpush(WORD ptr);

/// @brief pop position
extern WORD Cpop(void);

/// @}

/// @defgroup parser lexer/parser interface
/// @{
										/// fetch next token from lexer
extern int yylex();
										/// current line in source file
extern int yylineno;
										/// last matched string in lexer
extern char *yytext;
										/// run parser
extern int yyparse();
										/// error callback
extern void yyerror(std::string msg);
#include "compiler.parser.hpp"

/// @}

/// @}

#endif // _H_COMPILER
