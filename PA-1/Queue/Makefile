# use g++ with C++11 support
CXX=g++
CXXFLAGS=-Wall -pedantic -g -O0 -std=c++11
OUTFILES=QueueTest

all: $(OUTFILES)

QueueTest: QueueTest.cpp Queue.cpp Queue.h
	$(CXX) $(CXXFLAGS) -o QueueTest QueueTest.cpp Queue.cpp

clean:
	$(RM) $(OUTFILES) *.o
