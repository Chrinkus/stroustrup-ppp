//
// Stroustrup - Programming Principles & Practice
//
// Chapter XX Exercise XX
//

#include <iostream>
#include <stdexcept>

using namespace std;

int main()
try {
    // code
}
catch(exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}

