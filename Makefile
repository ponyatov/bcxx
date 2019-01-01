ifeq ($(OS),Windows_NT)
	EXE = .exe
else
	EXE =
endif

FORTH.log: FORTH.src ./bcx$(EXE)
	./bcx$(EXE) < $< > $@ && tail $(TAIL) $@

C = bcx.c compiler.cpp compiler.parser.cpp compiler.lexer.cpp 
H = bcx.h compiler.hpp compiler.parser.hpp

CXXFLAGS += -std=gnu++11

./bcx$(EXE): $(C) $(H)
	$(CXX) $(CXXFLAGS) -o $@ $(C)
	
compiler.lexer.cpp: compiler.lex
	flex -o $@ $<
	
compiler.parser.cpp: compiler.yacc
	bison -o $@ $<

doxy:
	rm -rf docs ; doxygen doxy.gen 1> /dev/null

clean:
	rm -rf compiler.yacc.?pp compiler.lexer.cpp