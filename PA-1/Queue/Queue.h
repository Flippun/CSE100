#ifndef QUEUE_H
#define QUEUE_H
#include <string>
using namespace std;

/**
 * Class to represent a Queue (FIFO) using a Singly-Linked List
 */
class Queue {
    private:
        /**
         * Nested helper Node class
         */
        class Node {
            public:
                /**
                 * The data stored within a Node
                 */
                string data;

                /**
                 * Pointer to the next node in the Queue
                 */
                Node* next;

                /**
                 * Node constructor, which initializes the data
                 */
                Node(string s) : data(s), next(nullptr) {}
        };

        /**
         * Pointer to the head (i.e., first) Node in the Queue
         */
        Node* head;

        /**
         * Pointer to the tail (i.e., last) Node in the Queue
         */
        Node* tail;

        /**
         * Total number of elements currently in the Queue
         */
        unsigned int numElements;

    public:
        /**
         * Queue Constructor, which should initialize an empty Queue
         */
        Queue();

        /**
         * Queue Destructor, which should deallocate anything dynamic
         */
        ~Queue();

        /**
         * Add a new element to the end of the Queue
         *
         * @param s The new element to add
         */
        void push(string s);

        /**
         * Remove and return the element at the front of the Queue
         *
         * @return The element at the front of the Queue
         */
        string pop();

        /**
         * Remove all elements from the Queue
         */
        void clear();

        /**
         * Return the number of elements in the Queue
         *
         * @return The number of elements in the Queue
         */
        unsigned int size();
};
#endif
