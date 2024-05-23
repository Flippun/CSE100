#include "Set.h"
#include <algorithm> 

/**
 * Implement the LinkedListSet methods correctly
 */
unsigned int LinkedListSet::size() {
    return linked.size();
}

void LinkedListSet::insert(string s) {
    auto itr = std::find(linked.begin(), linked.end(), s); 
    if (itr == linked.end()) {
        linked.push_back(s);
    }
}

void LinkedListSet::remove(const string & s) {
    linked.remove(s);
}

bool LinkedListSet::find(const string & s) {
    auto itr = std::find(linked.begin(), linked.end(), s); 
    if (itr != linked.end()) {
        return true;
    }
    return false;
}
