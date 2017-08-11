#include "rational.h"
#include <iostream>

using std::cout;
using std::cin;
using std::cerr;

int main()
try {
    cout << "Enter the integers of two rational numbers:\n";
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    Rational r1{a, b};
    Rational r2{c, d};

    cout << "Add: " << r1 + r2 << '\n'
         << "Sub: " << r1 - r2 << '\n'
         << "Mul: " << r1 * r2 << '\n'
         << "Div: " << r1 / r2 << '\n';

    return 0;
}
catch(std::exception& e) {
    cerr << e.what() << '\n';
}
catch(...) {
    cerr << "unknown exception" << '\n';
}
