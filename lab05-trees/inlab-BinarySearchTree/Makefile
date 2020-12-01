# Reese Allen rga2uz 10-06-20 Makefile

CXX=clang++
CXXFLAGS=-Wall -g
OFILES = BSTPathTest.o BinaryNode.o BinarySearchTree.o 

a.out: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h

BinaryNode.o: BinaryNode.cpp BinaryNode.h

BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h

clean:

	-rm -f *.o *~outputfile