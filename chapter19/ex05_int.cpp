//
// Stroustrup - Programming Principles & Practice
//
// Chapter 19 Exercise 5
//
// Define a class Int with a single member of type int. Define constructor,
// assignment & operators.
//

#include <iostream>
#include <stdexcept>

class Int {
    int val;
public:
    Int(int ii = 0) : val{ii} { }

    int get() const { return val; }

    Int& operator=(const int ii) { val = ii; return *this; }
};

std::ostream& operator<<(std::ostream& os, const Int& ii)
{
    return os << ii.get();
}

std::istream& operator>>(std::istream& is, Int& ii)
{
    int x = 0;
    is >> x;
    ii = x;
    return is;
}

int operator+(const Int& a, const Int& b)
{
    return a.get() + b.get();
}

int operator-(const Int& a, const Int& b)
{
    return a.get() - b.get();
}

int operator*(const Int& a, const Int& b)
{
    return a.get() * b.get();
}

int operator/(const Int& a, const Int& b)
{
    return a.get() / b.get();
}

int main()
try {
    Int x {3};
    Int y = 7;
    Int z = x + y;

    std::cout << x << ' ' << y << ' ' << z << '\n';
    std::cout << y - x << '\n';
    std::cout << y * x << '\n';
    std::cout << y / x << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

