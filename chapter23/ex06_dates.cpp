//
// Stroustrup - Programming Principles & Practice
//
// Chapter 23 Exercise 6 - Date Finder
//
// Write a program that finds dates in a text file. Write out each line that
// contains at least one date.
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <regex>
#include <fstream>

bool has_date(const std::string& s)
    // pat1 = 12/24/2004
    // pat2 = Mon(,) Feb 26 2018 (comma optional)
    // pat3 = January 12, 1995
{
    std::regex pat1 {R"(\d{2}/\d{2}/\d{4})"};
    std::regex pat2 {R"(\b[A-Za-z]+,? [A-Za-z]+ \d{1,2} \d{4}\b)"};
    std::regex pat3 {R"(\w+ \d{1,2}, \d{4}\b)"};

    return std::regex_search(s, pat1) ||
           std::regex_search(s, pat2) ||
           std::regex_search(s, pat3);
}

int main()
try {
    std::ifstream ifs {"input_dates.txt"};
    if (!ifs) {
        std::cerr << "Could not read from input file\n";
        return 1;
    }

    int lineno = 0;
    std::string line;

    while (ifs) {
        ++lineno;
        std::getline(ifs, line);
        if (has_date(line))
            std::cout << lineno << ": " << line << '\n';
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

