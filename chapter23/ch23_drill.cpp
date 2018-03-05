//
// Stroustrup - Programming Principles & Practice
//
// Chapter 23 - Regex Zip Code Example
//
// Becomes the Drill for the chapter
//

#include <iostream>
#include <stdexcept>
#include <regex>
#include <string>
#include <fstream>

using namespace std;

int main()
try {
    std::ifstream in {"input_zip_codes.txt"};
    if (!in) std::cerr << "no file\n";

    std::regex pat {R"(\w{2}\s*\d{5}(-\d{4})?)"};

    int lineno = 0;
    for (std::string line; std::getline(in,line); ) {
        ++lineno;
        std::smatch matches;
        if (std::regex_search(line, matches, pat)) {
            std::cout << lineno << ": " << matches[0] << '\n';
            if (1<matches.size() && matches[1].matched)
                std::cout << "\t: " << matches[1] << '\n';
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

