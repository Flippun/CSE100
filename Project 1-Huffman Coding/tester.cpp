#include <iostream>
#include <stdlib.h>
#include <vector>
#include <numeric>
#include "HCTree.hpp"
using namespace std;


void printBT(const std::string& prefix, const HCNode* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->symbol << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->c1, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->c0, false);
    }
}

void printBT(const HCNode* node)
{
    printBT("", node, false);    
}


int main (int argc, char* argv[]) {
    // Build freqs
    vector<int> freqs(128, 0);
    freqs.insert(freqs.begin() + 78, 1);
    freqs.insert(freqs.begin() + 103, 1);
    freqs.insert(freqs.begin() + 100, 1);
    freqs.insert(freqs.begin() + 108, 1);
    freqs.insert(freqs.begin() + 97, 1);
    // iota (begin(freqs) + 31, end(freqs) - 1, 0);

    // Build HCT
    HCTree hct;
    hct.build(freqs);

    // Encode each node in HCT
    cout << "Printing codes..." << "\n";
    FancyOutputStream* out = new FancyOutputStream(argv[1]);
    hct.encode(78, *out);
    hct.encode(105, *out);
    hct.encode(101, *out);
    hct.encode(109, *out);
    hct.encode(97, *out);

    out->flush();


    // Decode each node in HCT
    // FancyInputStream* input = new FancyInputStream(argv[1]);
    // unsigned char text = hct.decode(*input);
    // cout << text << "\n";
    // text = hct.decode(*input);
    // cout << text << "\n";
    // text = hct.decode(*input);
    // cout << text << "\n";
    // text = hct.decode(*input);
    // cout << text << "\n";
    // text = hct.decode(*input);
    // cout << text << "\n";
    


    // -------------------- Print Statements -------------------------


    // Print freqs
    // cout << "Printing freqs... ";
    // for (int i: freqs) {
    //     cout << i << " ";
    // }
    // cout << "\n";

    // Print HCT structure
    cout << "\n";
    printBT(hct.root);
    cout << "\n";

    // Print HCT leaves
    // cout << "Printing leaves... ";
    // for (HCNode* leaf: hct.leaves) {
    //     if (leaf != nullptr) {
    //         cout << "(" << leaf->count << "," << leaf->symbol << ")" << ' ';
    //     }
    // }
    // cout << "\n";
    
    cout << "\n";
    return 0;
}


