#include <iostream>
#include <stdlib.h>
#include <bitset> 
#include "HCTree.hpp"
using namespace std;

/**
 * Define messages for use
 */
#define MESSAGE_SUCCESS "Success"
#define MESSAGE_WRONG_FORMAT "Incorrect input format"
#define MESSAGE_EMPTY_FILE "File is empty"
#define MESSAGE_INPUT_FILE_ERROR "Could not open input file"
#define MESSAGE_OUTPUT_FILE_ERROR "Could not open ouput file"


/**
 * Take as input an arbitrary file (original_file) and will use Huffman Compression 
 * to create a compressed version of the file (compressed_file):
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
    int ogSize = input->filesize();
    if (!ogSize) { 
        return 0; 
    }

    // Find frequences of bytes in orginal file
    vector<int> freqs(256, 0);
    int byte;
    while ((byte = input->read_byte()) != -1) {
        ++freqs[byte];
    }
    
    // Build the Huffman tree
    HCTree HCT;
    HCT.build(freqs);

    /**
     * Header information:
     * Stores frequency of bytes 0-255 using a 3-byte integer representation for a 768 byte header.
     */
    for (int i = 0; i < 256; ++i) {
        int freq = freqs[i];
        bitset<24> bs(freq);
        for (int i = 0; i < 24; ++i) {
            output->write_bit(bs[i]);   
        }  
    }
     
    // Encode input file and write to output file
    input->reset();
    while ((byte = input->read_byte()) != -1) {
        HCT.encode(byte, *output);
    }
    output->flush();

    // Clean up and return
    delete(input);
    delete(output);
    return 0; 
}
