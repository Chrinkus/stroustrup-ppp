//
// Stroustrup - Programming Principles & Practice
//
// Chapter 23 Exercise 12
//
// Write a program that replaces various date formats within a file with the
// ISO yyyy-mm-dd format. Produce an output file that is identical to the input
// with the dates changed.
//

#include <iostream>
#include <stdexcept>
#include <regex>
#include <string>
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

std::string date_replace(const std::string& s)
    // pat 1 = 12/24/2004
{
    std::regex pat1 {R"(\b(\d{2})/(\d{2})/(\d{4}))"};

    return std::regex_replace(s, pat1, "$3-$1-$2");
}

int main()
try {
    /* test
    std::string s1 = "There is 02/27/1979 a date in here.";

    std::cout << date_replace(s1) << '\n';
    */

    // solution
    std::cout << "Enter a file to replace dates within:\n";
    std::string iname;
    std::cin >> iname;
    std::ifstream ifs {iname};
    if (!ifs) {
        std::cerr << "Could not read from file " << iname << '\n';
        exit(1);
    }

    std::cout << "Enter a destination file:\n";
    std::string oname;
    std::cin >> oname;
    std::ofstream ofs {oname};

    for (std::string line; std::getline(ifs, line); )
        ofs << date_replace(line) << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

