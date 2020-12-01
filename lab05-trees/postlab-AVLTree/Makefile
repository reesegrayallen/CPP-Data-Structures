# Reese Allen rga2uz 10-08-20 Makefile

CXX=clang++
CXXFLAGS=-Wall -g
OFILES = AVLNode.o AVLPathTest.o AVLTree.o

a.out: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

AVLNode.o: AVLNode.cpp AVLNode.h

AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h

AVLTree.o: AVLTree.cpp AVLNode.h AVLTree.h

clean:
	-rm -f *.o *~outputfile
