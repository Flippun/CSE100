#include <iostream>
#include <string>
#include "SuffixArray.h"
using namespace std;

/**
 * Ask user to enter a string, and compute its Suffix Array
 */
int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    cout << endl;
    for(unsigned int i : suffix_array(s)) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
