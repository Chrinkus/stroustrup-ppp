//
// Stroustrup - Programming Principles & Practice
//
// Chapter 21 Exercise 12
//
// Provide a GUI for querying a file of Orders.
//
// NOTE: I will come back to all GUI exercises after reviewing ch12-16
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

