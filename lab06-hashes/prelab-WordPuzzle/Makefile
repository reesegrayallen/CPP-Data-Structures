# Reese Allen rga2uz 10-12-20 Makefile

CXX=clang++
CXXFLAGS=-Wall -g
OFILES = hashTable.o timer.o wordPuzzle.o

a.out: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

hashTable.o: hashTable.cpp hashTable.h

timer.o: timer.cpp timer.h

wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h

clean:
	-rm -f *.o *~outputfile
