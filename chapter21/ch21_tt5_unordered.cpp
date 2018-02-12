//
// Stroustrup - Programming Principles & Practice
//
// Chapter 21 Try This: unordered_map test
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>

int main()
try {
    std::unordered_map<std::string, int> game_releases = {
        { "Resident Evil", 1996 },
        { "Resident Evil 2", 1998 },
        { "Resident Evil 3", 1999 },
        { "Resident Evil 4", 2005 },
        { "Resident Evil 5", 2009 },
        { "Resident Evil 6", 2012 },
        { "Resident Evil 7", 2017 }
    };

    for (const auto& g : game_releases)
        std::cout << g.first << '\t' << g.second << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

