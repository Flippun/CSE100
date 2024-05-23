#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * Class to implement an binary tree
 */
class BinaryTree {
    public:
        /**
         * Nested helper Node class
         */
        class Node {
            public:
                /**
                 * The label of this node
                 */
                int label;

                /**
                 * Pointer to the node's left child
                 */
                Node* leftChild;

                /**
                 * Pointer to the node's right child
                 */
                Node* rightChild;

                /**
                 * Pointer to the node's parent
                 */
                Node* parent;

                /**
                 * Node constructor, which initializes everything
                 */
                Node(int x) : label(x), leftChild(nullptr), rightChild(nullptr), parent(nullptr) {}

                /**
                 * Print the Newick string of the subtree rooted at this node to standard error
                 */
                void newick() {
                    if(this->leftChild == nullptr && this->rightChild == nullptr) {
                        cerr << this->label;
                        return;
                    }
                    cerr << '(';
                    if(this->leftChild) {
                        this->leftChild->newick();
                        if(this->rightChild) {
                            cerr << ',';
                        }
                    }
                    if(this->rightChild) {
                        this->rightChild->newick();
                    }
                    cerr << ')' << this->label;
                }
        };

        /**
         * BinaryTree constructor, which creates a random Yule tree with n leaves
         */
        BinaryTree(unsigned int n) {
            srand(time(NULL));
            unsigned int count = 1;
            this->root = new Node(1);
            vector<Node*> leaves;
            leaves.push_back(this->root);
            while(leaves.size() < n) {
                unsigned int ind = rand() % leaves.size();
                Node* curr = leaves[ind];
                curr->leftChild = new Node(++count);
                curr->leftChild->parent = curr;
                curr->rightChild = new Node(++count);
                curr->rightChild->parent = curr;
                leaves[ind] = curr->leftChild;
                leaves.push_back(curr->rightChild);
            }
        }

        /**
         * Print the Newick string representing this tree to standard error
         */
        void newick() {
            if(this->root) {
                this->root->newick();
                cerr << ';' << endl;
            }
        }

        /**
         * Return an unordered_map mapping node labels to balance factors,
         * where "balance factor" is defined as right height minus left height
         *
         * For example, in the following binary tree:
         *
         *         (5)
         *        /   \
         *      (2)    (6)
         *     /   \
         *   (1)   (3)
         *            \
         *            (4)
         *
         * You would return an unordered_map bf with the following (key, value) pairs:
         *     - bf[1] =  0 because the balance factor of node 1 is 0 - 0 =  0
         *     - bf[2] =  1 because the balance factor of node 2 is 2 - 1 =  1
         *     - bf[3] =  1 because the balance factor of node 3 is 1 - 0 =  1
         *     - bf[4] =  0 because the balance factor of node 4 is 0 - 0 =  0
         *     - bf[5] = -2 because the balance factor of node 5 is 1 - 3 = -2
         *     - bf[6] =  0 because the balance factor of node 6 is 0 - 0 =  0
         */
        unordered_map<int,int> balanceFactors();

    private:
        /**
         * Pointer to the root node of this binary tree
         */
        Node* root;
};
#endif
