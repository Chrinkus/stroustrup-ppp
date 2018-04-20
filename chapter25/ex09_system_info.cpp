//
// Stroustrup - Programming Principles & Practice
//
// Chapter 25 Exercise 9
//
// Compute the number of bits in an int and determine whether char is signed
// or unsigned.
//

#include <iostream>
#include <stdexcept>

int main()
try {
    std::cout << "Bits in an int: " << 8 * sizeof(int) << '\n';

    char c = -1;

    std::cout << "Is char signed? " << int(c) << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

