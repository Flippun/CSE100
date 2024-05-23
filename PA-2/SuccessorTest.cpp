#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <set>
#include "BST.h"
using namespace std;

/**
 * Define messages for use in the tester
 */
#define MESSAGE_SUCCESS "Success"
#define MESSAGE_INCORRECT "Your successor() function returned the wrong node"
#define MESSAGE_PREMATURE_NULL "Your successor() function returned NULL too early"
#define MESSAGE_NOT_NULL_AT_END "Your successor() function was not NULL when we expected it to be (at the end)"
#define MESSAGE_INCORRECT_LEFTMOST_EMPTY "Your getLeftMostNode() function did not return NULL on an empty BST"

/**
 * Test BST class using numbers from standard input
 */
int main() {
    // randomly sample a bunch of integers
    BST bst;
    if(bst.getLeftMostNode() != nullptr) {
        cout << MESSAGE_INCORRECT_LEFTMOST_EMPTY << endl;
        return 1;
    }
    srand(time(NULL));
    set<int> nums;
    while(nums.size() < 100) {
        int num = (rand() % 10000) - 5000;
        nums.insert(num);
        bst.insert(num);
    }

    // test successor
    BST::Node* curr = bst.getLeftMostNode();
    for(int num : nums) {
        if(curr == nullptr) {
            cout << MESSAGE_PREMATURE_NULL << endl;
            return 1;
        }
        if(curr->data != num) {
            cout << MESSAGE_INCORRECT << endl;
            return 1;
        }
        curr = curr->successor();
    }
    if(curr != nullptr) {
        cout << MESSAGE_NOT_NULL_AT_END << endl;
        return 1;
    }

    // if it didn't fail yet, success!
    cout << MESSAGE_SUCCESS << endl;
    return 0;
}
