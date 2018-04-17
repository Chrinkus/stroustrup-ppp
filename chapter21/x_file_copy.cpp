//
// Stroustrup - Programming Principles & Practice
//
// Chapter 21 Scratch - playing with istream & ostream iterators.
//
// I wanted to see what the results of piping an istream iterator into an
// ostream iterator would be. Since writing to and from stream iterators is 
// like using '>>' and '<<' the resulting output file was devoid of whitespace.
//
// Adding a separator doesn't fix the issue as you only get THAT type of ws.
// It seems the only way would be to use std::getline and append '\n' to the
// end of each read.
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>

int main()
try {
    std::cout << "enter source and destination files:\n";
    std::string src, dest;
    std::cin >> src >> dest;

    std::ifstream ifs {src};
    std::ofstream ofs {dest};

    std::istream_iterator<std::string> ii {ifs};
    std::istream_iterator<std::string> eos;
    std::ostream_iterator<std::string> oo {ofs, " "};

    std::copy(ii, eos, oo);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

