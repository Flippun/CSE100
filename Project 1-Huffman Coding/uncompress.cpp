#include <iostream>
#include <stdlib.h>
#include <stack>
#include <bitset> 
#include "HCTree.hpp"
using namespace std;

/**
 * Define messages for use
 */
#define MESSAGE_SUCCESS "Success"
#define MESSAGE_WRONG_FORMAT "Incorrect input format"
#define MESSAGE_INPUT_FILE_ERROR "Could not open input file"
#define MESSAGE_OUTPUT_FILE_ERROR "Could not open ouput file"


/**
 * Take as input a compressed file created by the compress program (compressed_file) 
  * and will uncompress the file (uncompressed_file).
 */
int main (int argc, char* argv[]) {
    // Test for correct input
    if (argc != 3) {
        cout << MESSAGE_WRONG_FORMAT << endl;
        return 1;
    }

    // Open input file
    FancyInputStream* input = new FancyInputStream(argv[1]);
    if (!input->good()) {
        cout << MESSAGE_INPUT_FILE_ERROR << endl;
        return 1;
    }

    // Open output file
    FancyOutputStream* output = new FancyOutputStream(argv[2]);
    if (!output->good()) {
        cout << MESSAGE_OUTPUT_FILE_ERROR << endl;
        return 1;
    }

    // Check for empty file
    if (!input->filesize()) { 
        return 0; 
    }

    // Reconstruct frequencies from header information
    vector<int> freqs(256, 0);
    int ogSize = 0;
    for (int j = 0; j < 256; ++j) {
        bitset<24> bs;
        for (int i = 0; i < 24; ++i) {
            int bit = input->read_bit();
            bs.set(i, bit);
        }
        int freq = (int)(bs.to_ulong());
        freqs[j] = freq; 
        ogSize += freq;
    }

    // Build the Huffman tree
    HCTree HCT;
    HCT.build(freqs);

    // Decode compressed data and write to output file
    for (int i = 0; i < ogSize; ++i) {
        output->write_byte(HCT.decode(*input));
    }
    output->flush();

    // Clean up and return
    delete(input);
    delete(output);
    return 0;
}
