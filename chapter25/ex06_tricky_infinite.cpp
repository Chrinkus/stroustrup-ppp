//
// Stroustrup - Programming Principles & Practice
//
// Chapter 25 Exercise 6 - Infinite loop w/resource termination
//

#include <iostream>
#include <stdexcept>
#include <vector>
#include <complex>
#include <string>

struct Node {
    int* pi;
    double* pd;
    std::complex<double>* pcd;
    std::string ss;
};

Node* recurse_forever(std::vector<Node*>& v, unsigned long n)
{
    std::cout << n << '\n';
    v.push_back(recurse_forever(v, n + 1));

    int x = 37;
    double y = 2.718281828;
    std::complex<double> z {sqrt(3), sqrt(n)};
    std::string s {"Let's exhaust some stack memory!"};

    return new Node{&x, &y, &z, s};
}

int main()
try {
    std::vector<Node*> vn;
    recurse_forever(vn, 1);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

