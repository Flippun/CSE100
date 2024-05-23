# use g++ with C++11 support
CXX=g++
CXXFLAGS?=-Wall -pedantic -g -O0 -std=c++11
OUTFILES=BSTTest SuccessorTest

all: $(OUTFILES)

BSTTest: BSTTest.cpp BST.cpp BST.h
	$(CXX) $(CXXFLAGS) -o BSTTest BSTTest.cpp BST.cpp

SuccessorTest: SuccessorTest.cpp BST.cpp BST.h
	$(CXX) $(CXXFLAGS) -o SuccessorTest SuccessorTest.cpp BST.cpp

clean:
	$(RM) $(OUTFILES) *.o
