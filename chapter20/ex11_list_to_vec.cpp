//
// Stroustrup - Programming Principles & Practice
//
// Chapter 20 Exercise 11
//
// copy the elements from a list of ints to a vector of doubles.
//

#include <iostream>
#include <stdexcept>
#include <list>
#include <vector>

std::vector<double> list_to_vec(const std::list<int>& l)
{
    std::vector<double> v (l.size());

    std::copy(l.begin(), l.end(), v.begin());

    return v;
}

int main()
try {
    std::list<int> l { 1, 2, 3, 4, 5, 6, 7, 8 };

    std::vector<double> v = list_to_vec(l);

    for (auto& a : v)
        std::cout << a << ' ';
    std::cout << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

