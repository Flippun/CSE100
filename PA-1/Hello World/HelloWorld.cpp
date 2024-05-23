#include <iostream>
#include <string>
using namespace std;

/**
 * Ask user to enter their name, and then greet them
 */
int main() {
    string userName;
    cout << "Enter name: ";
    cin >> userName;
    cout << "Hello, " << userName << "!" << endl << "Welcome to CSE 100!" << endl;
    return 0;
}
