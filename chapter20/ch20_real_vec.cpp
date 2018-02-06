//
// Stroustrup - Programming Principles & Practice
//
// Chapter 20 std::vector comparison
//

#include <iostream>
#include <stdexcept>
#include <vector>

int main()
try {
    std::vector<char> vc (10);

    char ch = 'a';
    for (auto it = vc.begin(); it != vc.end(); ++it)
        *it = ch++;

    for (auto c : vc)
        std::cout << c << ' ';
    std::cout << '\n';

    auto it = vc.begin();
    std::cout << "deref iter: " << *it << '\n';       // a
    std::cout << "ss 1 iter: " << it[1] << '\n';     // b
    std::cout << "ss 5 iter: " << it[5] << '\n';     // f

    try {
        --it;
        std::cout << "before begin: " << *it << '\n';
    } catch(std::exception& e) {
        std::cout << "Bad: " << e.what() << '\n';
    }

    try {
        std::cout << "ss 100 iter: " << it[100] << '\n';
    } catch(std::exception& e) {
        std::cout << "Bad: " << e.what() << '\n';
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

