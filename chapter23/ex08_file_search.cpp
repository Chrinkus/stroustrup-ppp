//
// Stroustrup - Programming Principles & Practice
//
// Chapter 23 Exercise 8
//
// Modify the program from §23.8.7 so that it takes as inputs a pattern and a
// file name.
//

#include <iostream>
#include <stdexcept>
#include <regex>
#include <string>
#include <fstream>

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

    std::cout << "now enter a file to search:\n";
    std::string iname;
    std::cin >> iname;
    std::ifstream ifs {iname};
    if (!ifs) {
        std::cerr << "Could not read from file " << iname << '\n';
    }

    int lineno = 0;
    for (std::string line; std::getline(ifs,line); ) {
        ++lineno;
        std::smatch matches;
        if (std::regex_search(line,matches,pattern)) {
            std::cout << "line " << lineno << ": " << line << '\n';
            for (int i = 0; i < matches.size(); ++i)
                std::cout << "\tmatches[" << i << "]: "
                          << matches[i] << '\n';
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

