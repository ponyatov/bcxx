/// @file
/// @brief bytecode compiler C++ code

#include "compiler.hpp"

#define YYERR "\n\n" << yylineno << ":" << msg << "[" << yytext << "]\t\n"

void yyerror(std::string msg) { std::cout << YYERR; std::cerr << YYERR ; exit(-1); }

int main() { return yyparse(); }

std::map<std::string,CELL> label;
std::map<std::string,std::vector<CELL>> forward;

void Lcompile(std::string *name) {
	if (label.find(*name) != label.end())			// compile known label
		compile(label[*name]);
	else {
		if (forward.find(*name) == forward.end())	// if not in forward[]
			forward[*name] = std::vector<CELL>();	// create empty vector
		forward[*name].push_back(Cp);				// register current Cp
		Wcompile(0x1234);							// compile dummy address
	}
}

void Ldefine(std::string *name) {
	label[*name] = Cp;								// register new label
	fprintf(stderr,"\n%.4X: %s",Cp,name->c_str());	// dump symbol table
	auto fw = forward.find(*name);					// resolve forwards
	if ( fw != forward.end() )
		for (auto it = fw->second.begin(); it != fw->second.end(); it++ )
			Wstore(*it,Cp);							// patch all fwd refs
}
