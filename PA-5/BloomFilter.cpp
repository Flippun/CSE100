#include "BloomFilter.h"
#include "HashFunctions.h"

/**
 * Implement insert() correctly
 */
void BloomFilter::insert(const string & s) {
    for(unsigned int i = 0; i < K; i++) {
        unsigned int hash = hash_functions[i](s) % M;
        bits[hash] = true;
    }
}

/**
 * Implement find() correctly
 */
bool BloomFilter::find(const string & s) {
    for(unsigned int i = 0; i < K; i++) {
        unsigned int hash = hash_functions[i](s) % M;
        if (!bits[hash]) {
            return false;
        }
    }
    return true;
}
