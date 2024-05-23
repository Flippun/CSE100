#include "BinaryTree.h"

/**
 * Helper function
 */
int calculateHeight(BinaryTree::Node* curr) {
        if (curr == nullptr) {
            return 0;
        }

        int left = calculateHeight(curr->leftChild);
        int right = calculateHeight(curr->rightChild);

        return 1 + std::max(left, right);
}

/**
 * Helper function
 */
int calculateBalanceFactor(BinaryTree::Node* curr) {
    int left = calculateHeight(curr->leftChild);
    int right = calculateHeight(curr->rightChild);

    return right - left;
}

/**
 * Implement the successor function correctly
 */
BinaryTree::Node* successor(BinaryTree::Node* curr) {
    if (curr->rightChild != nullptr) {
        BinaryTree::Node* tempNode = curr->rightChild;
        while (tempNode->leftChild != nullptr) {
            tempNode = tempNode->leftChild;
        }
        return tempNode;
    }
    else {
        BinaryTree::Node* currNode = curr;
        BinaryTree::Node* parentNode = curr->parent;
        while (parentNode != nullptr && currNode == parentNode->rightChild) {
            currNode = parentNode;
            parentNode = parentNode->parent;
        }
        return parentNode;
    }
}

/**
 * Implement balanceFactors() correctly
 */
unordered_map<int,int> BinaryTree::balanceFactors() {
    std::unordered_map<int, int> bf;
    if (root == nullptr) {
        return bf;
    }
   
    BinaryTree::Node* curr = root;
    while (curr->leftChild != nullptr) {
        curr = curr->leftChild;
    }
    while(curr != nullptr) {
        bf[curr->label] = calculateBalanceFactor(curr);
        curr = successor(curr);
    }
    
    return bf;
}


