//
// Stroustrup - Programming Principles & Practice
//
// Chapter 20 Exercise 7
//
// Find the lexicographical last string in an unsorted vector<string>
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

template<typename Iter>
Iter greatest(Iter first, Iter last)
{
    Iter g = first;
    for (Iter p = first; p != last; ++p)
        if (*g < *p) g = p;
    return g;
}

int main()
try {
    std::vector<std::string> vs { "Tommy", "Dola", "High", "Cookie", "Jim B",
        "Andy", "Hogan", "Squirrel" };

    auto p = greatest(vs.begin(), vs.end());

    std::cout << "The lexi-last string was: " << *p << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

