//
// Stroustrup - Programming Principles & Practice
//
// Chapter 21 Exercise 7
//
// Write a binary search function for a vector<int> and a list<string>. Test
// them and compare their similarities.
//
// The implementations were very similar with the list version requiring an
// extra 'middle' iterator being created every pass through the while loop.
// Unfortunately the list version also relies on std::advance to move its 
// iterators which seems awfully deliberate.
//
// Note: I have no idea how a binary search would work on a list since the
// elements are not contiguous in memory and lists don't have random-access
// iterators. The best I can do, to make the list version similar to the
// vector, is to use std::advance to move the iterator which seems a lot like
// O(n) time. The only way this is useful is if the actual comparison itself is
// an expensive task.
//
// Later: I just re-read the section in the text and confirmed on cplusplus.org
// that a binary_search only needs to return a boolean to indicate whether the
// value was found. This simplifies things a little.

#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>
#include <string>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Boolean return solution
template<typename Ran, typename T>
    // requires Random_access_iterator<Ran>()
bool bin_rand(Ran first, Ran last, const T& val)
{
    auto half = std::distance(first, last);

    while (first != last && half != 0) {
        if (*first == val) return true;
        half /= 2;
        first[half] > val
            ? last = first + half
            : first = first + half;
    }

    return false;
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

template<typename Iter, typename T>
Iter bin_vec(Iter first, Iter last, const T& val)
{
    auto half = std::distance(first, last);
    auto end = last;

    while (first != last && half != 0) {
        std::cout << *first << '\t' << *last << '\t' << half << '\n';
        if (*first == val) return first;
        half /= 2;
        first[half] > val
            ? last = first + half
            : first = first + half;
    }

    return end;
}

template<typename Iter, typename T>
Iter bin_lst(Iter first, Iter last, const T& val)
{
    auto half = std::distance(first, last);
    auto end = last;

    while (first != last && half != 0) {
        std::cout << *first << '\t' << *last << '\t' << half << '\n';
        if (*first == val) return first;

        half /= 2;
        auto mid = first;
        std::advance(mid, half);
        *mid > val
            ? std::advance(last, -half)
            : std::advance(first, half);
    }

    return end;
}

int main()
try {
    std::vector<int> vi { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };

    auto it = bin_vec(vi.begin(), vi.end(), 8);
    if (it != vi.end())
        std::cout << "Found value in vector: " << *it << '\n';

    std::list<std::string> ls {
        "aaa", "bbb", "ccc", "ddd", "eee", "fff",
        "ggg", "hhh", "iii", "jjj", "kkk", "lll"
    };

    auto it2 = bin_lst(ls.begin(), ls.end(), "bbb");
    if (it2 != ls.end())
        std::cout << "Found value in list: " << *it2 << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

