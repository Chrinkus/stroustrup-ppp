//
// Stroustrup - Programming Principles & Practice
//
// Chapter 18 Exercise 10
//
// Fix the palindrome solution in chapter to allow for long strings. First
// report if the string was too long then accommodate a long string.
//
// NOT YET COMPLETE

#include <iostream>
#include <stdexcept>

bool is_palindrome(const char s[], int n)
{
    int first = 0;
    int last = n - 1;
    while (first < last) {
        if (s[first] != s[last]) return false;
        ++first;
        --last;
    }
    return true;
}

std::istream& read_word(std::istream& is, char* buffer, int max)
{
    is.width(max);
    is >> buffer;

    if (strlen(buffer) >= max && buffer[max])
        throw std::runtime_error("string too large to check");

    return is;
}

int main()
try {
    constexpr int max = 8;
    for (char s[max]; read_word(std::cin, s, max); ) {
        std::cout << s << " is";
        if (!is_palindrome(s, strlen(s))) std::cout << " not";
        std::cout << " a plaindrome\n";
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

