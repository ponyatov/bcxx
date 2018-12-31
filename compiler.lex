%{
#include "compiler.hpp"
%}

%option noyywrap yylineno

%%
[\#\\][^\n]*		{ }						// line comment

nop					{ yylval.op = op_NOP; return CMD0; }

.end				{ return pEND; }
.					{ yyerror("lexer");	}	// undetected char
