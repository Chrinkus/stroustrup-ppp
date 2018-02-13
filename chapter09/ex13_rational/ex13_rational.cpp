#include <iostream>

using std::cout;
using std::cin;
using std::cerr;
using std::ostream;

class Rational {
    public:
        // to throw as exception
        class Zero_Denom { };

        // getters
        int get_num() const { return numerator; }
        int get_den() const { return denominator; }

        // constructor
        Rational(int n, int d);
        Rational(int w)
            :numerator{w}, denominator{1} { }

        // double representation
        double to_double() const { return double(numerator) / denominator; }
    private:
        int numerator;
        int denominator;
};

Rational::Rational(int n, int d)
    :numerator{n}, denominator{d}
{
    // Test for zero denom
    if (d == 0) throw Zero_Denom {};

    // TODO: add reduction code here someday
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

// Operators

ostream& operator<<(ostream& os, Rational r)
{
    return os << r.get_num() << "/" << r.get_den();
}

bool operator==(Rational& a, Rational& b)
{
    return a.get_num() == b.get_num() && a.get_den() == b.get_den();
}

bool operator!=(Rational& a, Rational& b)
{
    return !(a == b);
}

Rational operator+(Rational& a, Rational& b)
{
    int numerator, denominator;

    if (a.get_den() == b.get_den()) {
        numerator = a.get_num() + b.get_num();
        denominator = a.get_den();
    }
    else {
        numerator = a.get_num() * b.get_den() + b.get_num() * a.get_den();
        denominator = a.get_den() * b.get_den();
    }

    return Rational{numerator, denominator};
}

Rational operator-(Rational& a, Rational& b)
{
    int numerator, denominator;

    if (a.get_den() == b.get_den()) {
        numerator = a.get_num() - b.get_num();
        denominator = a.get_den();
    }
    else {
        numerator = a.get_num() * b.get_den() - b.get_num() * a.get_den();
        denominator = a.get_den() * b.get_den();
    }

    return Rational{numerator, denominator};
}

Rational operator*(Rational& a, Rational& b)
{
    return Rational{a.get_num() * b.get_num(), a.get_den() * b.get_den()};
}

Rational operator/(Rational& a, Rational& b)
{
    return Rational{a.get_num() * b.get_den(), b.get_num() * a.get_den()};
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

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
