//
// Stroustrup - Programming Principles & Practice
//
// Chapter 20 Exercise 20
//

#include <iostream>
#include <stdexcept>
#include <chrono>
#include <vector>
#include <list>
#include <random>
#include <functional>

using namespace std::chrono;

int main()
try {
    const int n = 1000000;

    // randomizer
    int seed = system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(1, n);
    auto dice = std::bind(distribution, generator);

    std::vector<int> vi;
    std::list<int> li;

    // task Vector
    auto t1 = system_clock::now();          // begin time

    for (int i = 0; i < n; ++i)
        vi.push_back(dice());


    auto t2 = system_clock::now();          // end time

    std::cout << "Task vector took "
              << duration_cast<milliseconds>(t2 - t1).count()
              << " milliseconds.\n\n";

    // task List
    auto t3 = system_clock::now();          // begin time

    for (int i = 0; i < n; ++i)
        li.push_back(dice());

    auto t4 = system_clock::now();          // end time
    
    std::cout << "Task list took "
              << duration_cast<milliseconds>(t4 - t3).count()
              << " milliseconds.\n\n";
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

