# use g++ with C++11 support
CXX=g++
CXXFLAGS?=-Wall -pedantic -g -O0 -std=c++11
OUTFILES=BinaryTreeTest

all: $(OUTFILES)

BinaryTreeTest: BinaryTreeTest.cpp BinaryTree.cpp BinaryTree.h
	$(CXX) $(CXXFLAGS) -o BinaryTreeTest BinaryTreeTest.cpp BinaryTree.cpp

clean:
	$(RM) $(OUTFILES) *.o
