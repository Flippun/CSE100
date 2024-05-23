# use g++ with C++11 support
CXX=g++
CXXFLAGS=-Wall -pedantic -g -O0 -std=c++11
OUTFILES=HelloWorld

all: $(OUTFILES)

HelloWorld: HelloWorld.cpp
	$(CXX) $(CXXFLAGS) -o HelloWorld HelloWorld.cpp

clean:
	$(RM) $(OUTFILES) *.o
