//
// Stroustrup - Programming Principles & Practice
//
// Chapter 19 Exercise 1
//
// Write a template function that adds the elements of one vector to another.
//

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

template<typename T>
void f(std::vector<T>& v1, std::vector<T>& v2)
{
    if (v1.size() > v2.size())
        throw std::runtime_error("not enough elements in v2");

    for (int i = 0; i < v1.size(); ++i)
        v1[i] += v2[i];
}

int main()
try {
    std::vector<int> va { 1, 2, 3, 4 };
    std::vector<int> vb { 3, 6, 9, 12 };

    f(va, vb);

    for (auto& a : va)
        std::cout << a << ' ';
    std::cout << '\n';

    std::vector<std::string> vs1 { "fire", "oak", "foo" };
    std::vector<std::string> vs2 { "truck", "bank", "bar" };

    f(vs1, vs2);

    for (auto& a : vs1)
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

