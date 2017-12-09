//
// Stroustrup - Programming Principles & Practice
//
// Chapter 17 Exercise 7
//
// Write a program that reads characters from cin into an array that is
// allocated on the free store. Read until an exclamation mark is encountered.
// Do not use string.
//

#include <iostream>
#include <stdexcept>

using namespace std;

char* add_char(char* cp, char ch)
    // increase the length of a C-string by 1
{
    int n = 0;
    while(cp[n]) ++n;        // get current length

    char* s = new char[n + 1];

    for (int i = 0; cp[i]; ++i)
        s[i] = cp[i];

    s[n] = ch;

    delete[] cp;
    return s;
}

int main()
try {
    // code
    char* store = new char;

    cout << "Please enter some characters. Terminate with '!'\n";

    char ch = 0;
    while(cin.get(ch) && ch != '!') {   // cin.get() to preserve whitespace
        store = add_char(store, ch);
    }

    for (int i = 0; store[i]; ++i)
        cout << store[i];
    cout << '\n';

    delete store;
}
catch(exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}

// Longer strings cause a segmentation fault.. but exercise indicates memory
// exhaustion is not something to protect against.
