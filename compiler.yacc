%{
#include "compiler.hpp"
%}

%defines %union { uint8_t op; }

%token pEND
%token <op> CMD0

%%
REPL :
REPL : REPL pEND	{ DUMP(); BYE(); }
REPL : REPL CMD0	{ M[Cp++] = $2; }
