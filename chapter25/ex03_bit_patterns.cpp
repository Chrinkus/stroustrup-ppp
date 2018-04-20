//
// Stroustrup - Programming Principles & Practice
//
// Chapter 25 Exercise 3
//
// Initialize a 32-bit signed integer with the following bit patterns:
// - all zeros
// - all ones
// - alternating 1's and 0's starting w/1
// - alternating 1's and 0's starting w/0
// - repeating 1100
// - repeating 0011
// - alternating bytes starting w/1
// - alternating bytes starting w/0
//
// Then repeat with an unsigned integer.
//
// NOTE: Not sure how this is different from the drill. Are we to initialize
// them with the value and print the bits? Or initialize with the bits and
// print the value? I think instead we are performing the same function as
// the drill but using 32 bit integer types instead of shorts.
//
// UPDATE: Ok the difference is getting a signed int and unsigned int out of
// the same bit pattern. Here I used hex patterns again and had to C-style cast
// the unsigned int into a signed int.
//
// LASTLY: This is my favourite piece of code I've written so far.
//

#include <iostream>
#include <stdexcept>
#include <vector>

template<typename T, typename U>
void ints_from_bits(const std::vector<U>& pat, std::vector<T>& out)
    // Provide a vector of unsigned integer type U as bit patterns and
    // transform them to the desired output type T
{
    if (sizeof(T) != sizeof(U))
        throw std::runtime_error("ints_from_bits(): type sizes must match");

    if (out.size() < pat.size())
        out.resize(pat.size());

    std::transform(pat.begin(), pat.end(), out.begin(),
            [](const U ui) { return T(ui); });
}

template<typename C> void print(const C& c)
    // print the contents of a container
{
    for (const auto& v : c)
        std::cout << v << '\n';
}

int main()
try {
    std::vector<unsigned int> patterns {
        0x0,            // all zeros
        0xffffffff,     // all ones
        0x55555555,     // alternating 1's and 0's starting w/1
        0xaaaaaaaa,     // alternating 1's and 0's starting w/0
        0xcccccccc,     // repeating 1100
        0x33333333,     // repeating 0011
        0x0f0f0f0f,     // alternating bytes starting w/1
        0xf0f0f0f0      // alternating bytes starting w/0
    };

    std::vector<int> vi;
    ints_from_bits(patterns, vi);

    std::vector<unsigned int> vu;
    ints_from_bits(patterns, vu);

    std::cout << "Signed integer bit patterns\n";
    print(vi);

    std::cout << "Unsigned integer bit patterns\n";
    print(vu);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

