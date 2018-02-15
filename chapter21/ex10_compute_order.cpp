//
// Stroustrup - Programming Principles & Practice
//
// Chapter 21 Exercise 10
//
// Compute the total value of the orders in the two files from ex09.
//

#include <iostream>
#include <stdexcept>
#include <numeric>
#include <fstream>
#include "./ch21_order.h"

double get_order_total(const std::string& iname)
{
    std::ifstream ifs {iname};
    if (!ifs)
        throw std::runtime_error("Could not read from file " + iname);

    std::istream_iterator<Order> ii {ifs};
    std::istream_iterator<Order> eos;

    double total = std::accumulate(ii, eos, 0.0,
            [](double sum, const Order& o)
            { return sum += o.total(); });

    return total;
}

int main()
try {
    const std::string iname_1 {"./output_orders_1.txt"};
    const std::string iname_2 {"./output_orders_2.txt"};
    const std::string iname_3 {"./output_orders_3.txt"};

    std::cout << "The total cost of orders in file 1 is: "
              << get_order_total(iname_1) << '\n';

    std::cout << "The total cost of orders in file 2 is: "
              << get_order_total(iname_2) << '\n';

    std::cout << "The total cost of orders in file 3 is: "
              << get_order_total(iname_3) << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

