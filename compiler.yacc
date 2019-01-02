%{
#include "compiler.hpp"
%}

%defines %union { uint8_t op; uint32_t hex; std::string *s;}

%token       pEND pVM pDUMP
%token       DB DW DD
%token <op>  CMD0 CMD1
%token <hex> HEX
%token       COLON
%token <s>   SYM
%token       cBEGIN cAGAIN

%%
REPL :
REPL : REPL pVM			{ VM(); }
REPL : REPL pEND		{ DUMP(); BYE(); }
REPL : REPL pDUMP		{ DUMP(); }
REPL : REPL CMD0		{ Bcompile($2); }
REPL : REPL CMD1 HEX	{ Bcompile($2); Wcompile($3); }
REPL : REPL CMD1 SYM	{ Bcompile($2); Lcompile($3); }
REPL : REPL SYM COLON	{ Ldefine($2);  }
REPL : REPL DB HEX		{ Bcompile($3); }
REPL : REPL DW HEX		{ Wcompile($3); }
REPL : REPL DW SYM		{ Lcompile($3); }
REPL : REPL DD HEX		{  compile($3); }
REPL : REPL cBEGIN		{ Cpush(Cp);	}
REPL : REPL cAGAIN		{ Bcompile(op_JMP); Wcompile(Cpop()); }
