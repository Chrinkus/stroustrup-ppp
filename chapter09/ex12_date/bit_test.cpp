//
// Stroustrup - Programming Principles & Practice
//
// Chapter 9 Exercise 12
//
// Comparison of space for Date representation
//

#include <iostream>
#include <stdexcept>

enum class Month : unsigned char {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

// Bit solution
struct Date_bits {
    unsigned int year: 12;
    Month month: 4;
    unsigned int day: 5;
    bool valid: 1;
};

// Current implementation
struct Date_rep {
    int year = 1970;
    Month month = Month::jan;
    int day = 1;
    bool valid = false;
};

int main()
try {
    Date_bits db1 {1979, Month::dec, 27};
    std::cout << "Bitset year: " << db1.year << '\n';       // 1979
    std::cout << "Bitset month: " << int(db1.month) << '\n';
    std::cout << "Bitset valid: " << db1.valid << '\n';

    Date_rep dr1 {};
    std::cout << "Non-bit size: " << sizeof(dr1) << '\n';   // 16 bytes

    auto pdr = std::make_unique<Date_rep>();
    std::cout << "Ptr size: " << sizeof(pdr) << '\n';       // 8 bytes

    std::cout << "Bitset size: " << sizeof(db1) << '\n';    // 4 bytes
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

