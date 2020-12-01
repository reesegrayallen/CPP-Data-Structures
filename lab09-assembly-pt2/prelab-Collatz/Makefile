# REESE ALLEN | rga2uz | Makefile | 11-01-20

CXX = clang++

CXXFLAGS = -Wall -g

AS = nasm

ASFLAGS = -f macho64 -g

OBJECTS = timer.o threexplusone.o  threexinput.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

clean:
	-rm -f *.o *~

threexinput.o: threexinput.cpp timer.h
timer.o: timer.cpp timer.h