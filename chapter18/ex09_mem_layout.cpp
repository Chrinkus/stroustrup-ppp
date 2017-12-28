//
// Stroustrup - Programming Principles & Practice
//
// Chapter 18 Exercise 9
//
// Write a program to demonstrate the manner in which static storage, the
// stack, and the free-store are laid out in memory. Do they grow upwards or
// downwards?
//

#include <iostream>
#include <stdexcept>

int gai[] = { 1, 2, 3, 4, 5 };

void f(int ai[], int sz)
{
    for (int i = 0; i < sz; ++i)
        std::cout << ai[i] << ' ' << &ai[i] << '\n';
}

int main()
try {
    // code
    int lai[] = { 1, 1, 2, 3, 5 };

    int* pai = new int[5]{ 3, 6, 9, 12, 15 };

    std::cout << "Static storage:\n";
    f(gai, 5);
    std::cout << '\n';
    std::cout << "Stack storage:\n";
    f(lai, 5);
    std::cout << '\n';
    std::cout << "Free-store:\n";
    f(pai, 5);
    std::cout << '\n';

    delete[] pai;
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

