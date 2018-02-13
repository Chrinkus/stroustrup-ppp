#include "money.h"

Money::Money(double d)
{
    double to_cents = d * 100;
    cents = int(to_cents + 0.5);
}

Money::Money(int c)
{
    cents = c;
}

Money::Money(std::string s, double d)
{
    currency = s;

    double to_cents = d * 100;
    cents = int(to_cents + 0.5);
}

std::ostream& operator<<(std::ostream& os, const Money& m)
{
    return os << m.get_currency() << m.get_dollars();
}

Money operator+(const Money& a, const Money& b)
{
    return Money{a.get_cents() + b.get_cents()};
}

Money operator-(const Money& a, const Money& b)
{
    return Money{a.get_cents() - b.get_cents()};
}
