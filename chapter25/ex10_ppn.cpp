//
// Stroustrup - Programming Principles & Practice
//
// Chapter 25 Exercise 10
//
// Initialize a bitfield PPN from §25.5.5 and print out the values. Repeat the 
// exercise but store the PPN in a 32-bit unsigned integer and use bit
// manipulation operators from §25.5.6 to access the bits.
//
// Extra Credit: Test unsigned int against enum of flags.
//

#include <iostream>
#include <stdexcept>

struct PPN {
    // Don't have to pass arg for unused location, it will be skipped
    unsigned int PFN : 22;      // Page Frame Number
    int : 3;                    // unused
    unsigned int CCA : 3;       // Cache Coherency Algorithm
    bool nonreachable : 1;
    bool dirty : 1;
    bool valid : 1;
    bool global : 1;
};

std::ostream& operator<<(std::ostream& os, const PPN& pn)
{
    return os << "Page Frame Number: " << pn.PFN << '\n'
              << "  CCA: " << pn.CCA << '\n'
              << "  nonreachable: " << pn.nonreachable << '\n'
              << "  dirty: " << pn.dirty << '\n'
              << "  valid: " << pn.valid << '\n'
              << "  global: " << pn.global;
}

enum Page_flags {
    global = 1,
    valid = 1 << 1,
    dirty = 1 << 2,
    nonreachable = 1 << 3
};

int main()
try {
    std::cout << "BITFIELD EXAMPLE\n";
    PPN p1 {2600056, 4, 1, 0, 0, 0};
    std::cout << p1 << '\n';
    p1.PFN = 1001;
    p1.CCA = 5;
    p1.nonreachable = 0;
    p1.dirty = 1;
    p1.valid = 1;
    p1.global = 1;
    std::cout << p1 << '\n';

    std::cout << "\nUNSIGNED INT EXAMPLE\n";
    unsigned int p2 = 0;
    p2 = 1001 << 10;            // value occupies "top" 22 bits
    p2 |= 5 << 4;               // keep "top", place 5 4-positions to left
    p2 |= 0 << 3;               // nonreachable
    p2 |= 1 << 2;               // dirty
    p2 |= 1 << 1;               // valid
    p2 |= 1;                    // global

    std::cout << "u_int value: " << p2 << '\n'
              << "Page Frame Number: " << (p2 >> 10) << '\n'
              << "  CCA: " << ((p2 >> 4) & 0x7) << '\n'
              << "  nonreachable: " << ((p2 >> 3) & 1) << '\n'
              << "  dirty: " << ((p2 >> 2) & 1) << '\n'
              << "  valid: " << ((p2 >> 1) & 1) << '\n'
              << "  global: " << (p2 & 1) << '\n';

    std::cout << "\nENUM EXPERIMENTS\n";
    unsigned int x = p2 & dirty;
    if (x) {
        std::cout << "p2 is dirty! unset valid\n";
        p2 ^= valid;
    }
    unsigned int y = p2 & valid;
    if (y) {
        std::cout << "somehow p2 is still valid\n";
    } else {
        std::cout << "p2 is confirmed invalid!\n";
    }
    // no temporaries
    if (!(p2 & valid) && (p2 & global))
        p2 ^= global;

    std::cout << "Final state of p2: " << p2 << '\n'
              << "Page Frame Number: " << (p2 >> 10) << '\n'
              << "  CCA: " << ((p2 >> 4) & 0x7) << '\n'
              << "  nonreachable: " << ((p2 >> 3) & 1) << '\n'
              << "  dirty: " << ((p2 >> 2) & 1) << '\n'
              << "  valid: " << ((p2 >> 1) & 1) << '\n'
              << "  global: " << (p2 & 1) << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

