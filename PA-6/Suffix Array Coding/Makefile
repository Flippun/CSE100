# use g++ with C++11 support
CXX=g++
CXXFLAGS?=-Wall -pedantic -g -O0 -std=c++11
OUTFILES=SuffixArrayTest

all: $(OUTFILES)

SuffixArrayTest: SuffixArrayTest.cpp SuffixArray.cpp SuffixArray.h
	$(CXX) $(CXXFLAGS) -o SuffixArrayTest SuffixArrayTest.cpp SuffixArray.cpp

clean:
	$(RM) $(OUTFILES) *.o
