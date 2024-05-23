#include <iostream>
#include <stdlib.h>
#include <stack>
#include "HCTree.hpp"
using namespace std;

/**
 * Use the Huffman algorithm to build a Huffman coding tree.
 * PRECONDITION: freqs is a vector of ints, such that freqs[i] is the frequency of occurrence of byte i in the input file.
 * POSTCONDITION: root points to the root of the trie, and leaves[i] points to the leaf node containing byte i.
 */
void HCTree::build(const vector<int>& freqs) { 
    // Creates priority queue of HCNode*, lowest frequency on top
    priority_queue<HCNode*, vector<HCNode*>, HCNodePtrComp> pq;
    for (size_t i = 0; i < freqs.size(); ++i) {
        if (freqs[i] == 0) { 
            continue; 
        }
        HCNode* newNode = new HCNode(freqs[i], i);   
        pq.push(newNode);
        leaves[i] = newNode;
    }

    // Builds the Huffman Tree within the priority queue
    while (pq.size() > 1) {
        // Removes smallest two frequency tree's from priority queue
        HCNode* c0 = pq.top();
        pq.pop();
        HCNode* c1 = pq.top();
        pq.pop();

        // Constructs new tree with root node containing combined frequency
        HCNode* newNode = new HCNode(c0->count + c1->count, 0);
        newNode->c0 = c0;
        c0->p = newNode;
        newNode->c1 = c1;
        c1->p = newNode;

        // Pushes root of new tree to priority queue
        pq.push(newNode);
    }

    // Assigns root of HCTree
    if (!pq.empty()) {
        root = pq.top();
    }
}


/**
 * Helper function to recursively deallocate all HCNode's
 */
void deleteAll(HCNode* node) {
    if (node->c0) {
        deleteAll (node->c0);
    }
    if (node->c1) {
        deleteAll (node->c1);
    }
    delete(node);
}

/**
 * Destructor for the HCTree class.
 */
HCTree::~HCTree() {
    if (root) {
        deleteAll(root);
    }
    root = nullptr;
    leaves.clear();
}


/**
 * Write to the given FancyOutputStream the sequence of bits coding the given symbol.
 * PRECONDITION: build() has been called, to create the coding tree, and initialize root pointer and leaves vector.
 */
void HCTree::encode(unsigned char symbol, FancyOutputStream & out) const {
    // Iterate from leaf node containg symbol to the root, pushing huffman code to a stack
    stack<int> stack;
    HCNode* node = leaves[symbol];
    while(node->p) {
        if (node == node->p->c0) {
            stack.push(0);
        }
        else {
            stack.push(1);
        }
        node = node->p;
    }

    // Write to output from the stack
    while (!stack.empty()) {
        out.write_bit(stack.top());
        stack.pop();
    }
}


/**
 * Return symbol coded in the next sequence of bits from the stream.
 * PRECONDITION: build() has been called, to create the coding tree, and initialize root pointer and leaves vector.
 */
unsigned char HCTree::decode(FancyInputStream & in) const {
    // Iterate from root, move left if read is 0 and right if read is 1, stop at leaf
    int bit;
    HCNode* node = root;
    while (node->c0 && node->c1) {
        bit = in.read_bit();
        if (bit) {
            node = node->c1;
        }
        else {
            node = node->c0;
        }
    }
    return node->symbol;
}
