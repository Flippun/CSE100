#ifndef BST_H
#define BST_H
using namespace std;

/**
 * Class to implement a Binary Search Tree (BST)
 */
class BST {
    public:
        /**
         * Nested helper Node class
         */
        class Node {
            public:
                /**
                 * The data stored within a node
                 */
                int data;

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
                Node(int d) : data(d), leftChild(nullptr), rightChild(nullptr), parent(nullptr) {}

                /**
                 * Find the successor of this Node
                 *
                 * @return Node* Pointer to the successor of this Node, or nullptr if none exists
                 */
                Node* successor();
        };

        /**
         * BST Constructor, which should initialize an empty BST
         */
        BST();

        /**
         * BST Destructor, which should deallocate anything dynamic
         */
        ~BST();

        /**
         * Insert a new element to this BST
         *
         * @param element The new element to insert
         * @return true if the insertion was successful, otherwise false (e.g. duplicate)
         */
        bool insert(int element);

        /**
         * Find a query element in this BST
         *
         * @param query The query element to find
         * @return true if query exists in this BST, otherwise false
         */
        bool find(const int & query) const;

        /**
         * Return the left-most node in this BST, or nullptr if empty
         *
         * @return The left-most node in this BST, or nullptr if empty
         */
        Node* getLeftMostNode();

        /**
         * Remove all elements from the BST
         */
        void clear();

        /**
         * Return the number of elements in the BST
         *
         * @return The number of elements in the BST
         */
        unsigned int size() const;

    private:
        /**
         * Pointer to the root node of this BST
         */
        Node* root;

        /**
         * Total number of elements currently in the BST
         */
        unsigned int numElements;
};
#endif
