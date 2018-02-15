//
// Stroustrup - Programming Principles & Practice
//
// Chapter 21 Exercise 9
//
// - Define an Order class with customer name, address, data, and shopping cart
// (vector<Purchase>) members.
// - Purchase is a class with product name, unit_price, and count members.
// - Define a mechanism for reading and writing Orders to and from a file.
// - Define a mechanism for printing orders.
// - Create a file of at least 10 Orders
// - Read this file into a vector<Order>, sort it by name, and write it back to
// a file
// - Create another file of about 10 Orders with a third overlapping with first
// - Read this file into a list<Order>, sort by address, and write it back out
// to a file
// - Merge the two output files into a third using std::merge()
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <sstream>
#include "./ch21_order.h"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
struct Cmp_by_name {
    bool operator()(const Order& a, const Order& b)
    {
        return a.name < b.name;
    }
};

struct Cmp_by_address {
    bool operator()(const Order& a, const Order& b)
        // does not take into account appartment addresses
        // would prefer to have an address class for this...
    {
        std::stringstream ssa {a.address};
        std::stringstream ssb {b.address};

        int num_a, num_b;
        std::string street_a, street_b;

        ssa >> num_a >> street_a;
        ssb >> num_b >> street_b;

        if (street_a == street_b)
            return num_a < num_b;
        else
            return street_a < street_b;
    }
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
template<typename C>
void read_orders(const std::string& fname, C& c)
{
    std::ifstream ifs { fname };
    if (!ifs) throw std::runtime_error("Could not read from file " + fname);

    for (Order o; ifs >> o; )
        c.push_back(o);
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
template<typename C>
void write_orders(const std::string& fname, C& c)
{
    std::ofstream ofs { fname };
    if (!ofs) throw std::runtime_error("Could not write to file " + fname);

    for (const auto& o : c)
        ofs << o;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
int main()
try {
    const std::string iname_1 {"input_orders_1.txt"};
    const std::string iname_2 {"input_orders_2.txt"};
    const std::string oname_1 {"output_orders_1.txt"};
    const std::string oname_2 {"output_orders_2.txt"};
    const std::string oname_3 {"output_orders_3.txt"};

    std::vector<Order> vo;
    read_orders(iname_1, vo);

    std::sort(vo.begin(), vo.end(), Cmp_by_name());
    write_orders(oname_1, vo);

    std::list<Order> lo;
    read_orders(iname_2, lo);

    lo.sort(Cmp_by_address());
    write_orders(oname_2, lo);

    // Merge Concerns:
    // std::merge requires that both sequences be sorted by the same criteria.
    // This conflicts with the idea of using ifstreams as iterators since both
    // files are sorted by different comparisons.
    //
    // Options:
    // - re-sort list by name, re-write to output file, std::merge ifstreams
    // - re-sort list by name, std::merge vo and lo to output file
    // - go ahead and try to std::merge the two files and see what happens!
    //
    // Ideally:
    // You'd not want repetitions of the same order. It seems like the best
    // outcome would be achieved by inserting both files into a set and
    // outputting THAT to a file.
    
    lo.sort(Cmp_by_name());
    write_orders(oname_2, lo);

    std::ofstream ofs { oname_3 };
    std::ostream_iterator<Order> oo {ofs};

    std::ifstream ifs_1 {oname_1};
    std::ifstream ifs_2 {oname_2};

    std::istream_iterator<Order> ii_1 {ifs_1};
    std::istream_iterator<Order> ii_2 {ifs_2};
    std::istream_iterator<Order> eos;

    std::merge(ii_1, eos, ii_2, eos, oo, Cmp_by_name());    // madness!!
    /*
    std::merge(
            vo.begin(), vo.end(),
            lo.begin(), lo.end(),
            oo,
            Cmp_by_name()
        );
    */
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

