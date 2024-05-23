# use g++ with C++11 support
CXX=g++
CXXFLAGS?=-Wall -pedantic -g -O0 -std=c++11
OUTFILES=SetTest

all: $(OUTFILES)

SetTest: SetTest.cpp ArrayListSet.cpp HashTableSet.cpp LinkedListSet.cpp MultiwayTrieSet.cpp RedBlackTreeSet.cpp Set.h
	$(CXX) $(CXXFLAGS) -o SetTest SetTest.cpp ArrayListSet.cpp HashTableSet.cpp LinkedListSet.cpp MultiwayTrieSet.cpp RedBlackTreeSet.cpp

clean:
	$(RM) $(OUTFILES) *.o
