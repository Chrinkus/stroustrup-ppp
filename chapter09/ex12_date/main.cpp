//
// Stroustrup - Programming Principles & Practice
//
// Chapter 9 Exercise 12
//
// Change the representation of a Date to be the number of days since January
// 1, 1970, represented as a long int and reimplement the functions from §9.8.
//
// Additional notes found in date.h
//

#include <iostream>
#include <stdexcept>
#include "date.h"

using Chrono_days::Date;

int main()
try {
    Date d1 {0};
    std::cout << d1 << '\n';

    Date d2 {1};
    std::cout << d2 << '\n';

    Date d3 {365};
    std::cout << d3 << '\n';

    Date d4 {1096};             // Day 0 + 365 + 365 + 366 (1972 was leapyear)
    std::cout << d4 << '\n';    //> (1973, January, 1)

    Date d5 {3344};
    std::cout << d5 << '\n';    //> (1979, February, 27)

    std::cout << "Enter a day in the format (YYYY, MM, DD):\n";
    Date d6 {};
    std::cin >> d6;
    std::cout << d6 << ": " << d6.get_days() << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

