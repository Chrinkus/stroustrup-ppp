//
// Stroustrup - Programming Principles & Practice
//
// Chapter 21 Exercise 5
//
// Redesign and reimplement find() and count() to indicate "not found" without
// returning end().
//
// Count returns 0 which is not really a change.. find on the other hand is not
// much fun. An iterator is passed in by reference and if a value is found, the
// referenced iterator will point to the value. Otherwise the user must ignore
// the iterator.
//

#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>

template<typename Iter, typename T>
bool my_find(Iter& first, Iter last, const T& val)
    // passes in first by reference which will leave that iterator at the point
    // the value was found at. Return value is tested much like STL way.
{
    while (first != last) {
        if (*first == val)
            return true;
        ++first;
    }
    return false;
}

template<typename Iter, typename T>
unsigned int my_count(Iter first, Iter last, const T& val)
    // count stays the same, returns 0 if nothing found..
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
    std::vector<double> vd { 1.23, 2.34, 3.45, 4.56 };

    auto it = vd.begin();
    bool found = my_find(it, vd.end(), 0.7);

    if (found)
        std::cout << "The value was found: " << *it << '\n';
    else
        std::cout << "The value was NOT found..\n";

    std::list<char> lc { 'a', 'b', 'a', 'c', 'd' };

    auto ees = my_count(lc.begin(), lc.end(), 'e');

    std::cout << "There were " << ees << " e's in lc\n";
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

