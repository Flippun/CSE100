#include "Set.h"
#include <algorithm> 

/**
 * Implement the ArrayListSet methods correctly
 */
unsigned int ArrayListSet::size() {
    return arr.size();
}

void ArrayListSet::insert(string s) {
    auto itr = std::find(arr.begin(), arr.end(), s); 
    if (itr == arr.end()) {
        arr.push_back(s);
    }
}

void ArrayListSet::remove(const string & s) {
    auto itr = std::find(arr.begin(), arr.end(), s); 
    if (itr != arr.end()) {
        arr.erase(itr);
    }
}

bool ArrayListSet::find(const string & s) {
    auto itr = std::find(arr.begin(), arr.end(), s); 
    if (itr != arr.end()) {
        return true;
    }
    return false;
}
