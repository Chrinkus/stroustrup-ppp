//
// Stroustrup - Programming Principles & Practice
//
// Chapter 20 Exercise 5
//
// Define input and output operators (<<, >>) for vector.
//

#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <sstream>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
    for (auto& a : v)
        os << a << ' ';
    return os;
}

template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v)
{
    char term = '|';
    for (T t; is >> t; ) {
        if (t == term) break;
        v.push_back(t);
    }
    return is;
}

int main()
try {
    // with ints
    std::vector<int> vi { 1, 2, 3, 4 };

    std::cout << vi << '\n';

    std::cin >> vi;

    std::cout << vi << '\n';

    // with doubles
    std::vector<double> vd;
    std::ifstream ifs {"jack.txt"};
    ifs >> vd;
    std::cout << vd << '\n';

    // with chars - doesn't play nicely with std::cin
    std::vector<char> vc;
    std::istringstream iss {"turbo power"};
    iss >> vc;
    std::cout << vc << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

