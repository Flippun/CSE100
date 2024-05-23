#include "Queue.h"

/**
 * Implement Queue constructor
 */
Queue::Queue() {
    head = nullptr;
    tail = nullptr;
    numElements = 0;
}

/**
 * Implement the Queue destructor
 */
Queue::~Queue() {
    clear();
}

/**
 * Implement size() correctly
 */
unsigned int Queue::size() {
    return numElements;
}

/**
 * Implement clear() correctly without memory leaks
 */
void Queue::clear() {
    while(size() > 0) {
        pop();
    }
}

/**
 * Implement push() correctly
 */
void Queue::push(string s) {
    Node* newNode = new Node(s);
    if (numElements == 0) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    numElements++;
}

/**
 * Implement pop() correctly without memory leaks
 */
string Queue::pop() {
    if (numElements == 0) {
        return NULL;
    }
    Node* temp = head;
    string value = head->data;
    head = head->next;
    delete temp;
    if (head == nullptr) {
        tail = nullptr;
    }
    numElements--;
    return value;
}
