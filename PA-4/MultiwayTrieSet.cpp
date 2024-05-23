#include "Set.h"

/**
 * Implement the MultiwayTrieSet constructor
 */
MultiwayTrieSet::MultiwayTrieSet() {
    root = new MultiwayTrieSet::Node();
    numElements = 0;
}

void deleteAll(MultiwayTrieSet::Node* node) {
    unordered_map<char, MultiwayTrieSet::Node*> children = node->children;
    for (auto i = children.begin(); i != children.end(); i++) {
        deleteAll(i->second);
    }

    delete(node);
}

/**
 * Implement the MultiwayTrieSet destructor
 */
MultiwayTrieSet::~MultiwayTrieSet() {
    deleteAll(root);
    numElements = 0;
}

/**
 * Implement the MultiwayTrieSet methods correctly
 */
unsigned int MultiwayTrieSet::size() {
    return numElements;
}

void MultiwayTrieSet::insert(string s) {
    MultiwayTrieSet::Node* curr = root;
    for (char c: s){
        unordered_map<char, MultiwayTrieSet::Node*> children = curr->children;
        if (children.count(c) == 0) {
            curr->children.insert({c, new MultiwayTrieSet::Node()});
            curr = curr->children[c];
        }
        else {
            curr = curr->children[c];
        }
    }
    if (curr->isWord == false) {
        curr->isWord = true;
        numElements++;
    }
}

void MultiwayTrieSet::remove(const string & s) {
    MultiwayTrieSet::Node* curr = root;
    for (char c: s) {
        unordered_map<char, MultiwayTrieSet::Node*> children = curr->children;
        if (children.count(c) == 0) {
            return;
        }
        else {
            curr = children[c];
        }   
    }

    if (curr->isWord == true) {
        curr->isWord = false;
        numElements--;
    }
}

bool MultiwayTrieSet::find(const string & s) {
    MultiwayTrieSet::Node* curr = root;
    for (char c: s) {
        unordered_map<char, MultiwayTrieSet::Node*> children = curr->children;
        if (children.count(c) == 0) {
            return false;
        }
        else {
            curr = children.at(c);
        }   
    }

    if (curr->isWord == true) {
        return true;
    }
    else {
        return false;
    }
}
