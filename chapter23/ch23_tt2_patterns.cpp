//
// Stroustrup - Programming Principles & Practice
//
// Chapter 23 Try This - Pattern Factory
//
// Accept a pattern and a set of lines from input. Check the pattern and search
// for lines with that pattern.
//

#include <iostream>
#include <stdexcept>
#include <regex>
#include <string>

int main()
try {
    std::regex pattern;
    
    std::string pat;
    std::cout << "enter pattern: ";
    std::getline(std::cin,pat);         // read pattern

    try {
        pattern = pat;                  // this checks pat
        std::cout << "pattern: " << pat << '\n';
    }
    catch(std::regex_error) {
        std::cout << pat << " is not a valid regular expression\n";
        exit(1);
    }

    std::cout << "now enter lines:\n";
    int lineno = 0;

    for (std::string line; std::getline(std::cin,line); ) {
        ++lineno;
        std::smatch matches;
        if (std::regex_search(line,matches,pattern)) {
            std::cout << "line " << lineno << ": " << line << '\n';
            for (int i = 0; i < matches.size(); ++i)
                std::cout << "\tmatches[" << i << "]: "
                          << matches[i] << '\n';
        } else {
            std::cout << "didn't match\n";
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

