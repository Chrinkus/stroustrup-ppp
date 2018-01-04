//
// Stroustrup - Programming Principles & Practice
//
// Chapter 19 Exercise 2
//
// Write a template function that takes two vectors and sums the product of
// their corresponding elements.
//

#include <iostream>
#include <stdexcept>
#include <vector>

template<typename T, typename U>
T product_sum(std::vector<T>& vt, std::vector<U>& vu)
{
    if (vt.size() != vu.size())
        throw std::runtime_error("cannot sum different sized vectors");

    T sum = 0;
    for (int i = 0; i < vt.size(); ++i) sum += vt[i] * vu[i];

    return sum;
}

int main()
try {
    std::vector<int> vi1 { 1, 2, 3, 4 };
    std::vector<int> vi2 { 5, 6, 7, 8 };
    std::vector<double> vd { 1.1, 2.2, 3.3, 4.4 };

    std::cout << product_sum(vi1, vi2) << '\n';
    std::cout << product_sum(vi1, vd) << '\n';
    std::cout << product_sum(vd, vi1) << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

