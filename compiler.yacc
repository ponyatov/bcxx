%{
#include "compiler.hpp"
%}

%defines %union { uint8_t op; uint32_t hex; std::string *s;}

%token pEND  pVM pDUMP
%token <op>  CMD0 CMD1
%token <hex> HEX
%token       COLON
%token <s>   SYM

%%
REPL :
REPL : REPL pVM			{ VM(); }
REPL : REPL pEND		{ DUMP(); BYE(); }
REPL : REPL pDUMP		{ DUMP(); }
REPL : REPL CMD0		{ Bcompile($2); }
REPL : REPL CMD1 HEX	{ Bcompile($2); Wcompile($3); }
REPL : REPL CMD1 SYM	{ Bcompile($2); Lcompile($3); }
REPL : REPL SYM COLON	{ Ldefine($2); }
