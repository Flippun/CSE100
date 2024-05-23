#include "BST.h"

/**
 * Implement the BST constructor
 */
BST::BST() {
    root = nullptr;
    numElements = 0;
}

/**
 * Implement the BST destructor
 */
BST::~BST() {
    clear();
}

/**
 * Implement size() correctly
 */
unsigned int BST::size() const {
    return numElements;
}

/**
 * Helper function to recursively remove Nodes from the BST
 */
void clearRecursive(BST::Node* node) {
    if (node == nullptr) { 
        return; 
    }

    clearRecursive(node->leftChild);
    clearRecursive(node->rightChild);

    delete(node);
    node = nullptr;
}

/**
 * Implement clear() correctly without memory leaks
 */
void BST::clear() {
    clearRecursive(root);
    numElements = 0;
}

/**
 * Implement insert() correctly
 */
bool BST::insert(int element) {
    if (size() == 0) {
        root = new BST::Node(element);
        numElements++;
        return true;
    }
    BST::Node* current = root;
    while (current->data != element) {
        if (element < current->data) {
            // if no left child exists, insert element as left child
            if (current->leftChild == nullptr) {
                current->leftChild = new BST::Node(element);
                current->leftChild->parent = current;
                numElements++;
                return true;
            }
            // if a left child does exist, traverse left
            else {
                current = current->leftChild;
            }
        }
        else if (element > current->data) {
            // if no right child exists, insert element as right child
            if (current->rightChild == nullptr) {
                current->rightChild = new BST::Node(element);
                current->rightChild->parent = current;
                numElements++;
                return true;
            }
            // if a right child does exist, traverse right
            else {
                current = current->rightChild;
            }
        }
    }
    // If current->data == element
    return false;
}

/**
 * Implement find() correctly
 */
bool BST::find(const int & query) const {
    if (size() == 0) {
        return false;
    }
    BST::Node* current = root;
    while (current->data != query) {
        if (query < current->data) {
            current = current->leftChild;
        }
        else if (query > current->data) {
            current = current->rightChild;
        }
        // if we traversed and there was no such child, failure
        if (current == nullptr) {
            return false;
        }
    }
    // If current == element, element is found
    return true;
}

/**
 * Implement the getLeftMostNode() function correctly
 */
BST::Node* BST::getLeftMostNode() {
    if (size() == 0) {
        return nullptr;
    }
    BST::Node* current = root;
    while (current->leftChild != nullptr) {
        current = current->leftChild;
    }
    return current;
}

/**
 * Implement the BST::Node successor function correctly
 */
BST::Node* BST::Node::successor() {
    if (rightChild != nullptr) {
        BST::Node* tempNode = rightChild;
        while (tempNode->leftChild != nullptr) {
            tempNode = tempNode->leftChild;
        }
        return tempNode;
    }
    else {
        BST::Node* currNode = this;
        BST::Node* parentNode = parent;
        while (parentNode != nullptr && currNode == parentNode->rightChild) {
            currNode = parentNode;
            parentNode = parentNode->parent;
        }
        return parentNode;
    }
}
