//
// Stroustrup - Programming Principles & Practice
//
// Chapter 20 Drill
//

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <list>
#include <array>
#include <string>

template<typename C>
void print_contents(const C& c, const std::string& s = "")
{
    std::cout << s << '\t';
    for (auto& a : c)
        std::cout << a << ' ';
    std::cout << '\n';
}

template<typename C>
void inc_contents(C& c, int n = 1)
{
    for (auto& a : c)
        a += n;
}

// 6 Write a copy operation
template<typename Iter1, typename Iter2>
    // requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    for (Iter1 p = f1; p != e1; ++p)
        *f2++ = *p;
    return f2;
}

int main()
try {
    constexpr int size = 10;

    // 1(?) Define an array of 10 ints w/values 0-9
    int arr[size]; 
    for (int i = 0; i < size; ++i) arr[i] = i;
    print_contents(arr, "built-in []: ");

    // 1 - by virtue of instruction 4 to copy
    std::array<int, size> ai;
    std::copy(arr, arr + size, ai.begin());
    print_contents(ai, "std::array: ");

    // 2 Define a vector with the same 10 elements
    std::vector<int> vi(size);
    std::copy(arr, arr + size, vi.begin());
    print_contents(vi, "std::vector: ");

    // 3 Define a list with the same 10 elements
    std::list<int> li(size);
    std::copy(arr, arr + size, li.begin());
    print_contents(li, "std::list: ");

    std::cout << '\n';

    // 4 Define copies of the array, vector & list
    std::array<int, size> ai2 = ai;
    std::vector<int> vi2 = vi;
    std::list<int> li2 = li;
    print_contents(ai2, "array copy: ");
    print_contents(vi2, "vector copy: ");
    print_contents(li2, "list copy: ");

    std::cout << '\n';

    // 5 Increase values in array by 2, vector by 3 and list by 5
    inc_contents(ai2, 2);
    inc_contents(vi2, 3);
    inc_contents(li2, 5);
    print_contents(ai2, "array inc'd: ");
    print_contents(vi2, "vector inc'd: ");
    print_contents(li2, "list inc'd: ");

    std::cout << '\n';

    // 7 Use my_copy to copy array into vector and list into array
    my_copy(ai2.begin(), ai2.end(), vi2.begin());
    my_copy(li2.begin(), li2.end(), ai2.begin());
    print_contents(ai2, "array copied: ");
    print_contents(vi2, "vector copied: ");
    print_contents(li2, "list copied: ");

    // 8 Use std::find to search for values
    std::vector<int>::iterator vit;
    vit = std::find(vi2.begin(), vi2.end(), 3);
    if (vit != vi2.end())
        std::cout << "Found at: " << std::distance(vi2.begin(), vit) << '\n';
    else
        std::cout << "Not found..\n";

    std::list<int>::iterator lit;
    lit = std::find(li2.begin(), li2.end(), 27);
    if (lit != li2.end())
        std::cout << "Found at: " << std::distance(li2.begin(), lit) << '\n';
    else
        std::cout << "Not found..\n";
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

