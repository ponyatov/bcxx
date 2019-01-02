%{
#include "compiler.hpp"
%}

%option noyywrap yylineno

%%
[\#\\][^\n]*		{ }						// line comment

0x[0-9a-fA-F]+		{ yylval.hex = strtol(&yytext[2],NULL,0x10); return HEX; }

nop					{ yylval.op = op_NOP; return CMD0; }
bye					{ yylval.op = op_BYE; return CMD0; }

jmp					{ yylval.op = op_JMP; return CMD1; }

.vm					{ return pVM; }
.end				{ return pEND; }
.dump				{ return pDUMP; }

db					{ return DB; }
dw					{ return DW; }
dd					{ return DD; }

begin				{ return cBEGIN; }
again				{ return cAGAIN; }

\:					{ return COLON; }
[a-zA-Z0-9_]+		{ yylval.s = new std::string(yytext); return SYM; }

[ \t\r\n]+			{}						// drop spaces
.					{ yyerror("lexer");	}	// undetected char
