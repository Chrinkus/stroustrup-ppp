//
// Stroustrup - Programming Principles & Practice
//
// Chapter 21 - Order.cpp
//
// This is the source file for ch21_order.h
//

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include "./ch21_order.h"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Purchase I/O
std::istream& operator>>(std::istream& is, Purchase& p)
{
    int cc;
    std::string nn;
    double up;
    is >> cc >> nn >> up;

    p.name = nn;
    p.unit_price = up;
    p.count = cc;

    return is;
}

std::ostream& operator<<(std::ostream& os, const Purchase& p)
{
    return os << p.count << ' ' << p.name << ' ' << p.unit_price;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Order member function
double Order::total() const
{
    return std::accumulate(cart.begin(), cart.end(), 0.0,
            [](double t, const Purchase& p)
            { return t += p.count * p.unit_price; });
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Order I/O
std::ostream& operator<<(std::ostream& os, const Order& o)
{
    os << o.name << '\n'
       << o.address << '\n'
       << o.data << "\n\n";

    for (const auto& a : o.cart)
        os << '\t' << a << '\n';
    os << '\n';

    return os;
}

std::istream& operator>>(std::istream& is, Order& o)
{
    std::string nn;

    while (is && nn.size() == 0)    // filter out empty lines
        std::getline(is, nn);

    if (is.eof()) return is;    // catches previous Order's eof() in Purchases

    std::string aa, dd;

    std::getline(is, aa);
    std::getline(is, dd);

    std::vector<Purchase> vp;

    for (Purchase p; is >> p; )
        vp.push_back(p);

    is.clear();             // # of purchases are variable and read terminates
                            // on fail() or eof(). Clear to keep data and let
                            // above check catch eof().
    o.name = nn;
    o.address = aa;
    o.data = dd;
    o.cart = vp;

    return is;
}
