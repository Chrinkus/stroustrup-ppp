//
// Stroustrup - Programming Principles & Practice
//
// Chapter 21 Exercise 8
//
// Modify word frequency example from §21.6.1 to output the words in order of
// frequency.
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <map>
#include <fstream>

int main()
try {
    const std::string iname { "./input_story.txt" };

    std::ifstream ifs { iname };
    if (!ifs) throw std::runtime_error("Could not read from file " + iname);

    std::map<std::string,int> words;   // keep (word,frequency) pairs

    for (std::string s; ifs >> s; )
        ++words[s];                     // words is subscripted by a string

    /*
    for (const auto& p : words)
        std::cout << p.first << ": " << p.second << '\n';
    */

    // solution
    std::multimap<int,std::string> freqs;

    for (const auto& w : words)
        freqs.insert(std::pair<int,std::string>(w.second, w.first));

    for (auto it = freqs.rbegin(); it != freqs.rend(); ++it)
        std::cout << it->first << ": " << it->second << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

