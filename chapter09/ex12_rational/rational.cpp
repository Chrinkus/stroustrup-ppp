#include "rational.h"

Rational::Rational(int n, int d)
    :numerator{n}, denominator{d}
{
    if (d == 0) throw Zero_Denom {};
}

ostream& operator<<(ostream& os, const Rational& r)
{
    return os << r.get_num() << "/" << r.get_den();
}

bool operator==(const Rational& a, const Rational& b)
{
    return a.get_num() == b.get_num() && a.get_den() == b.get_den();
}

bool operator!=(const Rational& a, const Rational& b)
{
    return !(a == b);
}

Rational operator+(const Rational& a, const Rational& b)
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

Rational operator-(const Rational& a, const Rational& b)
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

Rational operator*(const Rational& a, const Rational& b)
{
    return Rational{a.get_num() * b.get_num(), a.get_den() * b.get_den()};
}

Rational operator/(const Rational& a, const Rational& b)
{
    return Rational{a.get_num() * b.get_den(), b.get_num() * a.get_den()};
}
