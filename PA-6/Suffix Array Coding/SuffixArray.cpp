#include <string>
#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include "SuffixArray.h"
using namespace std;

/**
 * Construct the Suffix Array of a given string
 *
 * @param s The input string
 * @return A vector<unsigned int> representing the Suffix Array of s
 */
vector<unsigned int> suffix_array(const string & s) {
    // Construct vector containg integers 0, 1, ..., n-1
    vector<unsigned int> suffixArray(s.length());
    iota (begin(suffixArray), end(suffixArray), 0);

    // Sort the array using custom comparator as a lambda expression
    std::sort (suffixArray.begin(), suffixArray.end(), 
                [s] (int i, int j)
                {
                    string iSubstring = s.substr(i);
                    string jSubstring = s.substr(j);
                    auto compareValue = iSubstring.compare(jSubstring); 
                    if (compareValue >= 0) { return false; }
                    else { return true; }
                });
    
    // Return the sorted suffix array
    return suffixArray;
}
