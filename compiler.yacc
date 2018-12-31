%{
#include "compiler.hpp"
%}

%defines %union { char*s; }

%token pEND

%%
REPL :
REPL : REPL pEND	{ exit(0); }
