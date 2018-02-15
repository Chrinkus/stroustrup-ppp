//
// Stroustrup - Programming Principles & Practice
//
// Chapter 21 Order.h
//
// This is a header for the multiple exercises that use the Order class.
//

#include <iostream>
#include <string>
#include <vector>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
struct Purchase {
    std::string name;
    double unit_price = 0;
    int count = 0;
};

std::istream& operator>>(std::istream& is, Purchase& p);
std::ostream& operator<<(std::ostream& os, const Purchase& p);

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
struct Order {
    std::string name;
    std::string address;
    std::string data;               // ? taken as payment method
    std::vector<Purchase> cart;

    double total() const;
};

std::ostream& operator<<(std::ostream& os, const Order& o);
std::istream& operator>>(std::istream& is, Order& o);

