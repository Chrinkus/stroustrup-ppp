//
// Stroustrup - Programming Principles & Practice
//
// Chapter 25 Exercise 5 - Infinite loop
//

#include <iostream>
#include <stdexcept>

int main()
try {
    while(true) {
        std::cout << "here I am, doin stuff.. infinitely...\n";
    }
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

