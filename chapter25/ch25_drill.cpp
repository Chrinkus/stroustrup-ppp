//
// Stroustrup - Programming Principles & Practice
//
// Chapter 25 Drill
//

#include <iostream>
#include <stdexcept>
#include <vector>
#include <bitset>
#include <iomanip>

void print_bits(const std::vector<short unsigned int>& v)
{
    for (auto i : v)
        std::cout << std::setw(5) << std::dec << i << " == "
                  << "0x" << std::setfill('0')
                  << std::setw(4) << std::hex << i << " == "
                  << std::setfill(' ')
                  << std::bitset<8*sizeof(short unsigned int)>{i} << '\n';
}

int main()
try {
    // 1 - Run the following:
    // int v = 1;
    unsigned int v = 1;
    for (int i = 0; i<sizeof(v)*8; ++i) {
        std::cout << v << '\n';
        v <<= 1;
    }
    // 2 - Change v to an unsigned int
    
    // 3 - Using hexadecimal literals define short unsigned ints with:
    //   a - Every bit set
    //   b - The lowest bit set
    //   c - The highest bit set
    //   d - The lowest byte set
    //   e - The highest byte set
    //   f - Every second bit set (lowest bit 1)
    //   g - Every second bit set (lowest bit 0)

    std::vector<short unsigned int> v_hex {
        0xffff,     // a
        0x0001,     // b
        0x8000,     // c
        0x00ff,     // d
        0xff00,     // e
        0x5555,     // f
        0xaaaa      // g
    };

    // 4 - Print each as a decimal and hexidecimal (and bitset!)
    std::cout << "HEX LITERAL CHALLENGE\n"
              << "=====================\n";
    print_bits(v_hex);

    // 5 - Repeat 3 & 4 using bitwise operators and only the literals 1 & 0
    std::vector<short unsigned int> v_bit;

    //short unsigned int a = -1;                // definitely cheating..
    short unsigned int a = ~0;
    v_bit.push_back(a);
    short unsigned int b = 1;
    v_bit.push_back(b);
    short unsigned int c = 1;
    c <<= 15;
    v_bit.push_back(c);
    //short unsigned int d = 1; d <<= 8; d -= 1;  // maybe cheating..
    short unsigned int d = 1;
    for (int i = 1; i < 8; ++i) {
        short unsigned int t = 1;
        t <<= i;
        d |= t;
    }
    v_bit.push_back(d);
    short unsigned int e = ~d;
    v_bit.push_back(e);
    short unsigned int f = 1;
    for (int i = 2; i < 15; i += 2) {
        short unsigned int t = 1;
        t <<= i;
        f |= t;
    }
    v_bit.push_back(f);
    short unsigned int g = ~f;
    v_bit.push_back(g);

    std::cout << "BITWISE LITERAL CHALLENGE\n"
              << "=========================\n";
    print_bits(v_bit);
    unsigned int xx = -3; std::cout << std::dec << xx << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

