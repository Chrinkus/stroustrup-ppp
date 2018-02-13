#include <iostream>
#include <string>

class Money {
    public:
        Money(double);
        Money(int);
        Money(std::string, double);

        int get_cents() const { return cents; }
        std::string get_currency() const { return currency; }
        double get_dollars() const { return double(cents) / 100; }
    private:
        long int cents;
        std::string currency = "$";
};

std::ostream& operator<<(std::ostream&, const Money&);
//std::istream& operator>>(std::istream&, Money&);

Money operator+(const Money&, const Money&);
Money operator-(const Money&, const Money&);
