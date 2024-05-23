#include <iostream>
#include "BinaryTree.h"
using namespace std;

/**
 * Test BinaryTree balanceFactors() function
 */
int main() {
    BinaryTree tree(100);
    tree.newick();
    unordered_map<int,int> bf = tree.balanceFactors();
    for(auto pair : bf) {
        cout << pair.first << '\t' << pair.second << endl;
    }
    return 0;
}
