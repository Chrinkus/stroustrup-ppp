//
// Stroustrup - Programming Principles & Practice
//
// Chapter 21 Exercise 6
//
// Implement the Fruit example from §21.6.5 using a set<Fruit*, Fruit_cmp>.
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>       // for copying from
#include <set>

struct Fruit {
    std::string name;
    int quantity;
    double unit_price;
    
    explicit Fruit(const std::string& n, int q = 0, double p = 0.0)
        : name{n}, quantity{q}, unit_price{p} { }
};

struct Fruit_ptr_cmp {
    bool operator()(const Fruit* a, const Fruit* b)
    {
        return a->name < b->name;
    }
};

int main()
try {
    std::vector<Fruit> vf {
        Fruit{ "Plum", 3 },
        Fruit{ "Grape", 53 },
        Fruit{ "Banana", 6 },
        Fruit{ "Apple", 4 },
        Fruit{ "Orange", 5 },
        Fruit{ "Cherry", 37 },
        Fruit{ "Kiwi", 0 }
    };

    std::set<Fruit*, Fruit_ptr_cmp> produce;

    // 'copy' vector to set - set elements must be inserted
    for (auto& f : vf)
        produce.insert(&f);

    // print vector for reference
    std::cout << "Vector of fruits:\n"
              << "=================\n";
    for (const auto& f : vf)
        std::cout << f.name << '\n';
    std::cout << '\n';

    // should be same as vector but in lexicographic order
    std::cout << "Set of fruits:\n"
              << "==============\n";
    for (const auto& f : produce)
        std::cout << f->name << '\n';
    std::cout << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

