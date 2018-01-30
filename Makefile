CPPFLAGS=-std=c++11
SRC=main
OBJECTS=
EXE=templatedlist
RM=rm -f

base:
		@echo 'No commands given. Building templated list.'
		clang++ -o $(EXE) $(SRC).cpp $(CPPFLAGS)

clean:
		$(RM) $(EXE)
		
		
		
		
		
		
