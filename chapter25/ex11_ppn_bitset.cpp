//
// Stroustrup - Programming Principles & Practice
//
// Chapter 25 Exercise 11
//
// Repeat Ex 10 but keep bits in a bitset<32>
//

#include <iostream>
#include <stdexcept>
#include <bitset>

void print(const std::bitset<32>& b)
{
    std::cout << "Bitset b: " << b << '\n'
              << "PFN: " << (b.to_ulong() >> 10) << '\n'
              << "CCA: " << ((b.to_ulong() >> 4) & 0x7) << '\n'
              << "nonreachable: " << ((b.to_ulong() >> 3) & 1) << '\n'
              << "dirty: " << ((b.to_ulong() >> 2) & 1) << '\n'
              << "vaild: " << ((b.to_ulong() >> 1) & 1) << '\n'
              << "global: " << (b.to_ulong() & 1) << '\n';
}
int main()
try {
    std::bitset<32> b1;
    b1 = 230961 << 10;          // PFN
    b1 |= 6 << 4;               // CCA
    // non-reachable not set
    b1 |= 1 << 2;               // dirty
    b1 |= 1 << 1;               // valid
    b1 |= 1;

    print(b1);

    // is there a better way than this or shifting in and out 22?
    std::bitset<32> b2 = b1 >> 10;
    b2 <<= 10;
    b1 ^= b2;
    print(b1);

    b1 |= 438777 << 10;
    print(b1);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

