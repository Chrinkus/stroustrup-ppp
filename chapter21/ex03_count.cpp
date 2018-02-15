//
// Stroustrup - Programming Principles & Practice
//
// Chapter 21 Exercise 3
//
// Implement count() and test it.
//

#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>

template<typename Iter, typename T>
unsigned int my_count(Iter first, Iter last, const T& val)
{
    unsigned int count = 0;
    while (first != last) {
        if (*first == val)
            ++count;
        ++first;
    }

    return count;
}

int main()
try {
    std::vector<char> vc {'a', 'b', 'c', 'd', 'e'};
    std::list<int> li {1, 2, 3, 1, 4, 5, 1};

    std::cout << "a's in vc: " << my_count(vc.begin(), vc.end(), 'a') << '\n'
              << "g's in vc: " << my_count(vc.begin(), vc.end(), 'g') << '\n'
              << "1's in li: " << my_count(li.begin(), li.end(), 1) << '\n'
              << "6's in li: " << my_count(li.begin(), li.end(), 6) << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

