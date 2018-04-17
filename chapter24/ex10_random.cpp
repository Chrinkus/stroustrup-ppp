//
// Stroustrup - Programming Principles & Practice
//
// Chapter 24 Exercise 10
//
// Write a program to test randomness of default_random_engine.
//

#include <iostream>
#include <stdexcept>
#include <random>
#include <vector>
#include <functional>       // std::bind

int randint(int max)
    // from std_lib_facilities.h
{
    static std::default_random_engine ran;
    return std::uniform_int_distribution<>{0,max}(ran);
}

template<typename T>
void print_histogram(const std::vector<T>& v)
{
    for (auto i = 0; i != v.size(); ++i) {
        std::cout << i << '\t';
        for (auto j = 0; j < v[i]; ++j)
            std::cout << '*';
        std::cout << '\n';
    }
}

int main()
try {
    // ex 10
    std::cout << "Enter a maximum value and how many times to draw:\n";
    int sz, rolls;
    std::cin >> sz >> rolls;

    std::vector<int> hist1(sz);

    for (auto i = 0; i < rolls; ++i)
        ++hist1[randint(sz)];

    std::cout << "uniform distribution:\n";
    print_histogram(hist1);

    // from the chapter
    auto gen = std::bind(std::normal_distribution<double>{15,4.0},
            std::default_random_engine{});

    std::vector<int> hist2(sz);

    for (auto i = 0; i < rolls; ++i)
        ++hist2[int(round(gen()))];

    std::cout << "normal distribution:\n";
    print_histogram(hist2);

    // from cplusplus.com
    auto gen2 = std::bind(std::chi_squared_distribution<double>{5.0},
            std::default_random_engine{});

    std::vector<double> hist3(sz);

    for (auto i = 0; i < rolls; ++i) {
        double x = gen2();
        if (0.0 <= x && x < sz)
            ++hist3[round(x)];
    }

    std::cout << "chi-squared distribution:\n";
    print_histogram(hist3);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

