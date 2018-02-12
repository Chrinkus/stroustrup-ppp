//
// Stroustrup - Programming Principles & Practice
//
// Chapter 21 Try This: Stream iterators
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <vector>
#include <set>

int main()
try {
    std::string from, to;
    std::cin >> from >> to;         // get source and target file names

    std::ifstream is { from };      // open input stream
    std::ofstream os { to };        // open output stream

    /*
    // vector dictionary - stores multiples, needs to be sorted
    std::istream_iterator<std::string> ii { is };
    std::istream_iterator<std::string> eos;
    std::ostream_iterator<std::string> oo { os, "\n" };

    std::vector<std::string> b { ii, eos };
    std::sort(b.begin(), b.end());
    std::copy(b.begin(), b.end(), oo);

    // emphatically not recommended solution - only reads what it needs then
    // quits. Don't guess at file content size.
    const int max_size = 30;
    std::vector<std::string> b {max_size};
    std::copy(ii, eos, b.begin());
    for (const auto a : b) std::cout << a << ' ';
    std::cout << '\n';
    */

    // set dictionary - no multiples, sorts self
    std::set<std::string> b { std::istream_iterator<std::string>{is},
            std::istream_iterator<std::string>{} };
    std::copy(b.begin(), b.end(),
            std::ostream_iterator<std::string>{os, "\n"});
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

