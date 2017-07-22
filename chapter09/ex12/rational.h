#include <iostream>

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

        // double representation
        double to_double() const { return double(numerator) / denominator; }
    private:
        int numerator;
        int denominator;
};

ostream& operator<<(ostream& os, const Rational& r);

bool operator==(const Rational& a, const Rational& b);
bool operator!=(const Rational& a, const Rational& b);

Rational operator+(const Rational& a, const Rational& b);
Rational operator-(const Rational& a, const Rational& b);
Rational operator*(const Rational& a, const Rational& b);
Rational operator/(const Rational& a, const Rational& b);
