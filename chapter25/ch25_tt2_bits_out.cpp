//
// Stroustrup - Programming Principles & Practice
//
// Chapter 25 Try This - Bit output
//

#include <iostream>
#include <stdexcept>
#include <bitset>

int main()
try {
    for (unsigned i; std::cin >> i; )
        std::cout << std::dec << i << " == "
                  << std::hex << "0x" << i << " == "
                  << std::bitset<8*sizeof(unsigned)>{i} << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

