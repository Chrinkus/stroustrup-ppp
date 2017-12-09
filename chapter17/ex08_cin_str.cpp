//
// Stroustrup - Programming Principles & Practice
//
// Chapter 17 Exercise 8
//
// Repeat last exercise (read in chars to memory) but read into a string
// instead.

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

int main()
try {
    // code
    string store = "";

    cout << "Enter some characters. Terminate with '!'\n";
    char ch;
    while (cin.get(ch) && ch != '!')
        store += ch;

    cout << store << '\n';
}
catch(exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}

