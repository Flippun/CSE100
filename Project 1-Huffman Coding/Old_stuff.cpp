// Old compress:
// 
// // /**
    //  * Header information:
    //  * 1st 4 bytes = uncompressed size
    //  * 2nd 4 bytes = HCTree serialization size [n]
    //  * Next [n] bytes = HCTree serialization
    //  * Rest of file = compressed bytes
    //  */
    // output->write_int(ogSize);
    // serialize(HCT.root, output);
    // output->write_byte(0x00);
    // // output->write_int(ogSize);
    // // output->write_int(header.size());
    // // for (unsigned char c: header) {
    // //     output->write_byte(c);
    // // }

// 
// // /**
//  * Helper function to serialize the HCTree for the header information
//  */
// void serialize(HCNode* node, FancyOutputStream*& output) {
//     // Check for nullptr
//     if (!node) {
//         return;
//     }

//     // Perform a pre-order traversal. If leaf node, add 1 + symbol. If non-leaf, add 0. 
//     if (node->symbol) {
//         cout << 1 << node->symbol;
//         output->write_byte(1);
//         output->write_byte(node->symbol);
//     }
//     else {
//         cout << 0;
//         output->write_byte(0);
//         serialize(node->c0, output); // , header
//         serialize(node->c1, output); // , header
//     }
// }
// 
// 
// 
// 
//  Old uncompress:
// 
// 

    // // Deserialize Huffman tree from header information
    // int ogSize = input->read_int();
    // // const int headerSize = input->read_int();
    // // int iterations = 0;
    // HCTree HCT;
    // HCT.root = deserialize(input); // headerSize, iterations
// 
// 
// /**
//  * Helper function to deserialize the HCTree from the header information
//  */
// HCNode* deserialize(FancyInputStream*& input) { // const int& headerSize, int& iterations
//     // if (headerSize < iterations) {
//     //     cout << "maxed" << "\n";
//     //     return nullptr;
//     // }
//     // iterations++
//     cout << iteration++ << " ";
//     int data = input->read_byte();
//     if (data == 0x00) {
//         return nullptr;
//     }
//     if (data == 1) {
//         // iterations++;
//         cout << iteration++ << " ";
//         return new HCNode(0, input->read_byte());
//     }
//     else {
//         HCNode* node = new HCNode(0, 0);
//         node->c0 = deserialize(input); // headerSize, iterations
//         node->c1 = deserialize(input); // headerSize, iterations
//         return node;
//     }
// }
// 
//    // // Decode input file and write to output file
    // for (int i = 0; i < ogSize; ++i) {
    //     output->write_byte(HCT.decode(*input));
    // }
    // output->flush();
// 
// 
// 
// 
// 
// Naive Implementation:
// 
// 
// //  /**
//      * Header information:
//      *
//      */
//     for (int i = 0; i < 256; ++i) {
//         output->write_int(freqs[i]);    
//     }
// 
// 
// 
// // // Deserialize Huffman tree from header information
//     vector<int> freqs(256, 0);
//     int byte;
//     int ogSize = 0;
//     for (int i = 0; i < 256; ++i) {
//         byte = input->read_int();
//         freqs[i] = byte;
//         ogSize += byte;
//     } 

//     // Build the Huffman tree
//     HCTree HCT;
//     HCT.build(freqs);

//     // Decode compressed data and write to output file
//     for (int i = 0; i < ogSize; ++i) {
//         output->write_byte(HCT.decode(*input));
//     }
//     output->flush();
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 

