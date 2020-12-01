# REESE ALLEN | rga2uz | Makefile | 11-16-20

CXX=clang++ -std=c++11
CXXFLAGS= -g -Wall -O2
OFILES = middleearth.o traveling.o

a.out: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)
	doxygen

clean:
	-rm -f *.o *~ a.out
