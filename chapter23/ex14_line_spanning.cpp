//
// Stroustrup - Programming Principles & Practice
//
// Chapter 23 Exercise 14
//
// Write a program that reads a file into memory representing line-breaks with
// newline characters and test line-spanning patterns in the manner of §23.8.7.
//
// I think I'm to read an entire file into a string and perform pattern matches
// on that mega-string. Adding newlines between lines read will allow searching
// across lines.
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <regex>

int main()
try {
    std::string fname = "input_dates_2.txt";
    std::ifstream ifs {fname};
    if (!ifs) {
        std::cerr << "Could not read from file " << fname << '\n';
        exit(1);
    }

    std::string file_str;
    for (std::string s; std::getline(ifs,s); )
        file_str += s + '\n';

    while (true) {
        std::regex pattern;
        std::cout << "enter pattern to test:\n";
        std::string pat;
        std::getline(std::cin,pat);

        try {
            pattern = pat;          // test pattern
            std::cout << "pattern: " << pat << '\n';
        }
        catch(std::regex_error) {
            std::cerr << pat << " is not a valid regular expression\n";
            exit(1);
        }

        std::smatch matches;
        if (std::regex_search(file_str,matches,pattern)) {
            std::cout << "Match!\n";
            for (const auto& m : matches)
                std::cout << '\t' << m << '\n';
        } else {
            std::cout << "No match..\n";
        }
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

