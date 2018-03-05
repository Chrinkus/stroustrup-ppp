//
// Stroustrup - Programming Principles & Practice
//
// Chapter 23 - Regex testing
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <regex>
#include <sstream>

int main()
try {
    /*
    std::regex reg1 {"\\s\\w{3}\\s"};     
    std::regex reg2 {R"(\s\w{3}\s)"};    
    std::regex reg3;                    

    std::string pat = "\\s\\w{3}\\s";
    reg3 = pat;

    std::string test = "bake cab cabbage";
    std::smatch matches;

    if (std::regex_search(test,matches,reg1))
        for (int i = 0; i < matches.size(); ++i)
            std::cout << matches[i] << '\n';
    */

    std::regex floater {R"(\d+\.\d+)"};

    std::string test2 = "You owe me $4.37, pal!";
    std::smatch matches2;
    if (std::regex_search(test2,matches2,floater))
        std::cout << matches2[0] << '\n';

    std::stringstream ss;
    ss << matches2[0];
    double res;
    ss >> res;
    
    std::cout << "Double: " << res << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

