//
// Stroustrup - Programming Principles & Practice
//
// Chapter 23 Exercise 13
//
// Write a program to find out if a '.' matches a '\n'.
//
// SPOILER ALERT: It doesn't.

#include <iostream>
#include <stdexcept>
#include <string>
#include <regex>

int main()
try {
    std::string test = "\n";

    std::regex pat {R"(.)"};

    if (std::regex_search(test,pat))
        std::cout << "Dot matches newline!\n";
    else
        std::cout << "Nope!\n";
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

