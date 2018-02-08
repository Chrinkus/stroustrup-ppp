//
// Stroustrup - Programming Principles & Practice
//
// Chapter 21 Try This: find() implementations
//

#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>

template<typename In, typename T>
    // requires Input_iterator<In>()
    //     && Equality_comparable<Value_type<T>>()
In pro_find(In first, In last, const T& val)
    // find the first element in [first:last) that equals val
{
    while (first != last && *first != val) ++first;
    return first;
}

template<typename In, typename T>
    // requires Input_iterator<In>()
    //     && Equality_comparable<Value_type<T>>()
In pleb_find(In first, In last, const T& val)
    // find the first element in [first:last) that equals val
{
    for (In p = first; p != last; ++p)
        if (*p == val) return p;
    return last;
}

int main()
try {
    std::vector<int> vi { 1, 1, 2, 3, 5, 8, 13, 21 };
    std::list<char> lc { 'c', 'a', 'i', 't', 'l', 'i', 'n' };

    std::cout << "Enter an integer to find in vi:\n";
    int x;
    std::cin >> x;

    auto vit = pro_find(vi.begin(), vi.end(), x);
    auto vit2 = pleb_find(vi.begin(), vi.end(), x);
    if (vit == vit2)
        std::cout << "Both 'find's produced same output for vectors.\n";

    if (vit != vi.end()) {
        std::cout << "Found " << x << " in vi!\n";
    } else {
        std::cout << "That number is in another vector..\n";
    }

    std::cout << "Guess a letter in my wife's name:\n";
    char ch;
    std::cin >> ch;

    auto lit = pro_find(lc.begin(), lc.end(), ch);
    auto lit2 = pleb_find(lc.begin(), lc.end(), ch);
    if (lit == lit2)
        std::cout << "Both 'find's produced same output for lists.\n";

    if (lit != lc.end()) {
        std::cout << "Found " << ch << " in lc!\n";
    } else {
        std::cout << "That is not a letter in my wife's name..\n";
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

