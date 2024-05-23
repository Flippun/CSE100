#include <iostream>
#include "Swap.h"
using namespace std;

/**
 * Test the swap function
 */
int main() {
    int a,b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    swap(a,b);
    cout << a << " " << b << endl;
    return 0;
}
