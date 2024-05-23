# use g++ with C++11 support
CXX=g++
CXXFLAGS=-Wall -pedantic -g -O0 -std=c++11
OUTFILES=SwapTest

all: $(OUTFILES)

SwapTest: SwapTest.cpp Swap.cpp Swap.h
	$(CXX) $(CXXFLAGS) -o SwapTest SwapTest.cpp Swap.cpp

clean:
	$(RM) $(OUTFILES) *.o
