#include "Set.h"

/**
 * Implement the RedBlackTreeSet methods correctly
 */
unsigned int RedBlackTreeSet::size() {
    return rbt.size();
}

void RedBlackTreeSet::insert(string s) {
    rbt.insert(s);
}

void RedBlackTreeSet::remove(const string & s) {
    rbt.erase(s);
}

bool RedBlackTreeSet::find(const string & s) {
    if (rbt.find(s) != rbt.end()) {
        return true;
    }
    return false;
}
