#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
#include <time.h>
#include <vector>
#include "Set.h"
using namespace std;
const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const unsigned int NUM_STR = 1000;
const unsigned int NUM_REM = 100;
const unsigned int STR_LEN = 10;

/**
 * Test the Set implementations
 */
int main() {
    // set up the tester
    srand(time(NULL));
    unordered_map<string,bool> success = {
        {"ArrayListSet",    true},
        {"HashTableSet",    true},
        {"LinkedListSet",   true},
        {"MultiwayTrieSet", true},
        {"RedBlackTreeSet", true}
    };

    // create simple test Set objects
    ArrayListSet simple_arr_set;
    HashTableSet simple_ht_set;
    LinkedListSet simple_linked_set;
    MultiwayTrieSet simple_mwt_set;
    RedBlackTreeSet simple_rbt_set;

    // create map for convenience in simple tests
    map<string,Set*> simple_sets = {
        {"ArrayListSet",    &simple_arr_set},
        {"HashTableSet",    &simple_ht_set},
        {"LinkedListSet",   &simple_linked_set},
        {"MultiwayTrieSet", &simple_mwt_set},
        {"RedBlackTreeSet", &simple_rbt_set}
    };

    // generate 2 strings for simple test
    string s1, s2;
    for(unsigned int j = 0; j < STR_LEN; ++j) {
        s1 += ALPHABET[rand() % ALPHABET.size()];
        s2 += ALPHABET[rand() % ALPHABET.size()];
    }

    // perform simple tests
    for(auto pair : simple_sets) {
        // check initially empty
        if(pair.second->size() != 0 || pair.second->find(s1)) {
            success[pair.first] = false;
            break;
        }

        // remove non-existent word and check size
        pair.second->remove(s1);
        if(pair.second->size() != 0) {
            success[pair.first] = false;
            break;
        }

        // add a word and check size
        pair.second->insert(s2);
        if(pair.second->size() != 1 || pair.second->find(s1) || !pair.second->find(s2)) {
            success[pair.first] = false;
            break;
        }

        // remove words and check size
        pair.second->remove(s1);
        if(pair.second->size() != 1 || pair.second->find(s1) || !pair.second->find(s2)) {
            success[pair.first] = false;
            break;
        }
        pair.second->remove(s2);
        if(pair.second->size() != 0 || pair.second->find(s1) || pair.second->find(s2)) {
            success[pair.first] = false;
            break;
        }

        // add a word and check size
        pair.second->insert(s1);
        if(pair.second->size() != 1 || !pair.second->find(s1) || pair.second->find(s2)) {
            success[pair.first] = false;
            break;
        }
    }

    // create main test Set objects
    ArrayListSet arr_set;
    HashTableSet ht_set;
    LinkedListSet linked_set;
    MultiwayTrieSet mwt_set;
    RedBlackTreeSet rbt_set;

    // create map for convenience in main tests
    map<string,Set*> sets = {
        {"ArrayListSet",    &arr_set},
        {"HashTableSet",    &ht_set},
        {"LinkedListSet",   &linked_set},
        {"MultiwayTrieSet", &mwt_set},
        {"RedBlackTreeSet", &rbt_set}
    };

    // build list of random strings to add
    unordered_set<string> str_ht;
    for(unsigned int i = 0; i < NUM_STR; ++i) {
        string curr;
        for(unsigned int j = 0; j < STR_LEN; ++j) {
            curr += ALPHABET[rand() % ALPHABET.size()];
        }
        str_ht.insert(curr);
    }
    list<string> str_ll;
    vector<string> str_vec;
    for(auto curr : str_ht) {
        str_ll.push_back(curr);
        str_vec.push_back(curr);
    }

    // add the words to each set
    for(auto pair : sets) {
        unsigned int count = 0;
        for(auto curr : str_ll) {
            if(pair.second->find(curr)) {
                success[pair.first] = false;
                break;
            }
            pair.second->insert(curr);
            pair.second->insert(curr); // duplicate insertion (shouldn't do anything)
            if(!(++count == pair.second->size() && pair.second->find(curr))) {
                success[pair.first] = false;
                break;
            }
        }
    }

    // remove words from each set
    for(unsigned int count = str_ll.size()-1; count >= str_ll.size()-NUM_REM; --count) {
        auto curr = str_ll.back();
        str_ll.pop_back();
        str_vec.pop_back();
        str_ht.erase(curr);
        for(auto pair : sets) {
            if(!success[pair.first]) {
                continue;
            }
            pair.second->remove(curr);
            if(count != pair.second->size() || pair.second->find(curr)) {
                success[pair.first] = false;
            }
        }
    }

    // generate 2 new strings for simple test
    string s3, s4;
    for(unsigned int j = 0; j < STR_LEN; ++j) {
        s3 += ALPHABET[rand() % ALPHABET.size()];
        s4 += ALPHABET[rand() % ALPHABET.size()];
    }

    // redo simple tests
    for(auto pair : simple_sets) {
        // check initially empty
        if(pair.second->size() != 1 || pair.second->find(s3)) {
            success[pair.first] = false;
            break;
        }

        // remove non-existent word and check size
        pair.second->remove(s3);
        if(pair.second->size() != 1) {
            success[pair.first] = false;
            break;
        }

        // add a word and check size
        pair.second->insert(s4);
        if(pair.second->size() != 2 || pair.second->find(s3) || !pair.second->find(s4)) {
            success[pair.first] = false;
            break;
        }

        // remove words and check size
        pair.second->remove(s3);
        if(pair.second->size() != 2 || pair.second->find(s3) || !pair.second->find(s4)) {
            success[pair.first] = false;
            break;
        }
        pair.second->remove(s4);
        if(pair.second->size() != 1 || pair.second->find(s3) || pair.second->find(s4)) {
            success[pair.first] = false;
            break;
        }

        // add a word and check size
        pair.second->insert(s3);
        if(pair.second->size() != 2 || !pair.second->find(s3) || pair.second->find(s4)) {
            success[pair.first] = false;
            break;
        }
    }

    // output results
    for(auto pair : success) {
        if(!success[pair.first]) {
            cout << pair.first << " failed" << endl;
        }
    }
    cout << "SetTest complete" << endl;
    return 0;
}
