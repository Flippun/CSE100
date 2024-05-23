#include <functional>
#include <stdlib.h>
#include <string>
#include <vector>
#include "HashFunctions.h"
using namespace std;

unsigned int h1(const string & s) {
    unsigned int o = 0;
    for(const char & c : s) {
        o += c;
    }
    return o;
}

unsigned int h2(const string & s) {
    unsigned int o = 0;
    for(const char & c : s) {
        o = (13*o) + c;
    }
    return o;
}

unsigned int h3(const string & s) {
    unsigned int o = 0;
    for(const char & c : s) {
        o = (17*o) + c;
    }
    return o;
}

unsigned int h4(const string & s) {
    unsigned int o = 0;
    for(const char & c : s) {
        o = (17*o) + c;
        if(o > 13) {
            o -= 13;
        }
    }
    return o;
}

unsigned int h5(const string & s) {
    return s.size();
}

const vector<function<unsigned int(const string &)>> hash_functions{h1,h2,h3,h4,h5};

unsigned int sample_in_range(unsigned int min_val, unsigned int max_val) {
    return (rand() % (max_val - min_val)) + min_val;
}
