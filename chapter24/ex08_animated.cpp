//
// Stroustrup - Programming Principles & Practice
//
// Chapter 24 Exercise 8
//
// Animate the Gaussian elimination.
//
// I'll come back to this after my overhaul of the GUI support library.
//

#include <iostream>
#include <stdexcept>

int main()
try {
    // code
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

