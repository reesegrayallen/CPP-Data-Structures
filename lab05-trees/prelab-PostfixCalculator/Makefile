# Reese Allen rga2uz 10-06-20 Makefile

CXX=clang++
CXXFLAGS=-Wall -g
OFILES = TreeCalc.o TreeCalcTest.o TreeNode.o


a.out: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h

TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h TreeNode.h

TreeNode.o: TreeNode.cpp TreeNode.h

clean:
	-rm -f *.o *~outputfile