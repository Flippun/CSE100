#include <iostream>
#include "FastSaga.h"
using namespace std;

/**
 * Print each movie in the Fast (& Furious) Saga using an iterator
 */
int main() {
    FastSaga movies;
    unsigned int count = 0;
    for(string title : movies) {
        cout << title << endl;
        ++count;
    }
    cout << endl << "There are " << count << " Fast Saga movies. #FAMILY" << endl;
    return 0;
}
