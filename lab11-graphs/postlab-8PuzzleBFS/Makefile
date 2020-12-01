# REESE ALLEN | rga2uz | Makefile | 11-19-20

CXX=clang++ -std=c++11
CXXFLAGS= -g -Wall -O2
OFILES = puzzle.o

a.out: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)
	doxygen

clean:
	-rm -f *.o *~ a.out
