//
// Stroustrup - Programming Principles & Practice
//
// Chapter 19 Exercise 3
//
// Write a template class Pair that can hold a pair of values of any type.
// Implement a simple symbol table.
//

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

template<typename T, typename U> class Pair {
    T t;
    U u;
public:
    Pair(T label, U value) : t{label}, u{value} { }

    T val_t() const { return t; }
    U val_u() const { return u; }
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
class Symbol_table {
    std::vector<Pair<std::string, double>> st;

public:
    Symbol_table() { }

    int size() const { return st.size(); }

    void define(const std::string& s, double d) { st.push_back({s, d}); }

    double operator[](const std::string& s);
    const double operator[](const std::string& s) const;
};

double Symbol_table::operator[](const std::string& s)
{
    for (auto& a : st)
        if (a.val_t() == s)
            return a.val_u();

    throw std::runtime_error("unknown symbol " + s);
}

const double Symbol_table::operator[](const std::string& s) const
{
    for (auto& a : st)
        if (a.val_t() == s)
            return a.val_u();

    throw std::runtime_error("unknown symbol " + s);
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

int main()
try {
    /*
    std::vector<Pair<std::string, double>> sym_table;

    sym_table.push_back({"PI", 3.14159});

    Pair<std::string, double> pd {"e", 2.71828};

    sym_table.push_back(pd);

    std::cout << sym_table[0].name() << ' ' << sym_table[0].get() << '\n';
    std::cout << sym_table[1].name() << ' ' << sym_table[1].get() << '\n';
    */

    Symbol_table sym_tbl;

    sym_tbl.define("PI", 3.14159);

    std::cout << "Size of symbol table: " << sym_tbl.size() << '\n';
    std::cout << "PI in table: " << sym_tbl["PI"] << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

