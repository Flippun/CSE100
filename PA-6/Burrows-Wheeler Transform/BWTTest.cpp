#include <iostream>
#include <string>
#include "BWT.h"
using namespace std;

/**
 * Ask user to enter a string, and compute its Burrows-Wheeler Transform
 */
int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    if(s[s.size()-1] != '$') {
        cerr << "String must end with end-of-string symbol ($)" << endl;
        exit(1);
    }
    cout << endl << bwt(s) << endl;
    return 0;
}
