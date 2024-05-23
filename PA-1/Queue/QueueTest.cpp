#include <algorithm>
#include <iostream>
#include <queue>
#include <stdlib.h>
#include <string>
#include <time.h>
#include "Queue.h"
using namespace std;

/**
 * Define messages for use in the tester
 */
#define MESSAGE_SUCCESS "Success"
#define MESSAGE_WRONG_SIZE "Incorrect size"
#define MESSAGE_WRONG_POP "Incorrect string returned by pop()"

/**
 * Generate a random string
 *
 * Adapted from here: https://stackoverflow.com/a/12468109/2134991
 */
string randomString(unsigned int length) {
    auto randomCharacter = []() -> char {
        const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const unsigned int maxIndex = (sizeof(alphabet) - 1);
        return alphabet[rand() % maxIndex];
    };
    string out(length, 0);
    generate_n(out.begin(), length, randomCharacter);
    return out;
}

/**
 * Randomly test the Queue class
 */
int main() {
    // set things up
    srand(time(0));
    unsigned int numAdd1 = (rand() % 100) + 20;
    unsigned int numRemove1 = (rand() % (numAdd1-10)) + 10;
    unsigned int numAdd2 = (rand() % 40) + 10;
    unsigned int numAdd3 = (rand() % 100) + 20;
    Queue studentQ;
    queue<string> trueQ;

    // check initial size
    if(studentQ.size() != trueQ.size()) {
        cout << MESSAGE_WRONG_SIZE << endl;
        return 1;
    }

    // simple test
    studentQ.push("Niema");
    if(studentQ.size() != 1) {
        cout << MESSAGE_WRONG_SIZE << endl;
        return 1;
    }
    if(studentQ.pop() != "Niema") {
        cout << MESSAGE_WRONG_POP << endl;
        return 1;
    }
    if(studentQ.size() != 0) {
        cout << MESSAGE_WRONG_SIZE << endl;
        return 1;
    }

    // add a bunch of strings and check size
    for(unsigned int i = 0; i < numAdd1; ++i) {
        string curr = randomString((rand() % 10) + 10);
        studentQ.push(curr);
        trueQ.push(curr);
        if(studentQ.size() != trueQ.size()) {
            cout << MESSAGE_WRONG_SIZE << endl;
            return 1;
        }
    }

    // remove a bunch of strings and check size + correctness
    for(unsigned int i = 0; i < numRemove1; ++i) {
        string studentCurr = studentQ.pop();
        string trueCurr = trueQ.front();
        trueQ.pop();
        if(studentQ.size() != trueQ.size()) {
            cout << MESSAGE_WRONG_SIZE << endl;
            return 1;
        }
        if(studentCurr != trueCurr) {
            cout << MESSAGE_WRONG_POP << endl;
            return 1;
        }
    }

    // add a bunch of strings and check size
    for(unsigned int i = 0; i < numAdd2; ++i) {
        string curr = randomString((rand() % 10) + 10);
        studentQ.push(curr);
        trueQ.push(curr);
        if(studentQ.size() != trueQ.size()) {
            cout << MESSAGE_WRONG_SIZE << endl;
            return 1;
        }
    }

    // clear and check size
    studentQ.clear();
    trueQ = queue<string>();
    if(studentQ.size() != trueQ.size()) {
        cout << MESSAGE_WRONG_SIZE << endl;
        return 1;
    }

    // add a bunch of strings and check size
    for(unsigned int i = 0; i < numAdd3; ++i) {
        string curr = randomString((rand() % 10) + 10);
        studentQ.push(curr);
        trueQ.push(curr);
        if(studentQ.size() != trueQ.size()) {
            cout << MESSAGE_WRONG_SIZE << endl;
            return 1;
        }
    }

    // if it didn't fail yet, success!
    cout << MESSAGE_SUCCESS << endl;
    return 0;
}
