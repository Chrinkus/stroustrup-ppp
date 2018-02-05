//
// Stroustrup - Programming Principles & Practice
//
// Chapter 19 Vector Implementation Test
//
// Could come back and more thoroughly test the vector

#include <iostream>
#include <stdexcept>
#include "./ch19_vector.h"

vector<double> fill(std::istream& is)
{
    vector<double> res;
    for (double x = 0; x < 1000; ++x) res.push_back(x);
    return res;
}

int main()
try {
    vector<int> vi (10);
    vector<char> vc (10);

    int nn = 1;
    char cc = 'a';
    for (int i = 0; i < 10; ++i) {
        vi[i] = nn++;
        vc[i] = cc++;
    }

    vector<char> vc2 = vc;
    vector<char> vc3 (5);

    vc2[2] = 'z';
    vc3 = vc2;
    vc3[4] = 'E';

    vector<double> vd (5);
    vd[0] = 107.1;

    vd = fill(std::cin);
    vector<double> vd2 = std::move(vd);

    for (int i = 0; i < 10; ++i)
        std::cout << vi[i] << ' ';
    std::cout << '\n';

    for (int i = 0; i < 10; ++i)
        std::cout << vc[i] << ' ';
    std::cout << '\n';

    for (int i = 0; i < 10; ++i)
        std::cout << vc2[i] << ' ';
    std::cout << '\n';

    for (int i = 0; i < 10; ++i)
        std::cout << vc3[i] << ' ';
    std::cout << '\n';

    for (int i = 0; i < vd.size(); ++i)
        std::cout << vd[i] << ' ';
    std::cout << '\n';

    for (int i = 0; i < 10; ++i)
        std::cout << vd2[i] << ' ';
    std::cout << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

