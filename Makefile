ifeq ($(OS),Windows_NT)
	EXE = .exe
else
	EXE =
endif

FORTH.log: FORTH.src ./compiler$(EXE)
	./compiler$(EXE) < $< > $@ && tail $(TAIL) $@

C = compiler.cpp
H = compiler.hpp

./compiler$(EXE): $(C) $(H)
	$(CXX) $(CXXFLAGS) -o $@ $(C)

doxy:
	rm -rf docs ; doxygen doxy.gen 1> /dev/null
