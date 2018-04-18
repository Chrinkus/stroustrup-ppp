//
// Stroustrup - Programming Principles & Practice
//
// Chapter 25 Try This - Infinite loop
//

#include <iostream>
#include <stdexcept>

void infinite()
    // i will never reach 160 because the largest positive value of a signed
    // char is 127 at which point it rolls over to -128 and counts back to 0.
{
    unsigned char max = 160;        // very large
    for (signed char i = 0; i < max; ++i) std::cout << int(i) << '\n';
}

int main()
try {
    infinite();
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

