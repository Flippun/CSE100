#include <string>
#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include "BWT.h"
using namespace std;

/**
 * Implement bwt() correctly
 */
string bwt(const string & s) {
    // Construct array containg integers 0, 1, ..., n-1
    vector<unsigned int> indexArray(s.length());
    iota (begin(indexArray), end(indexArray), 0);  

    // Sort the indexArray using custom comparator as a lambda expression
    std::sort (indexArray.begin(), indexArray.end(), 
                [s] (int i, int j)
                {
                    string iSubstring = s.substr(i) + s.substr(0, i);
                    string jSubstring = s.substr(j) + s.substr(0, j);
                    auto compareValue = iSubstring.compare(jSubstring); 
                    if (compareValue >= 0) { return false; }
                    else { return true; }
                });

    // Construct the Burrows-Wheeler Transform from the sorted indices
    string BWT;
    for (auto i: indexArray) {
        if (i == 0) {
            BWT = BWT + s.back();
        }
        else {
            unsigned int lastColumn = i - 1;
            BWT = BWT + s[lastColumn];
        }
    }

    // Return the Burrows-Wheeler Transform
    return BWT;
}
