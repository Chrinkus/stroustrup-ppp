//
// Stroustrup - Programming Principles & Practice
//
// Chapter 21 Try This: accumulating Records
//

#include <iostream>
#include <stdexcept>
#include <vector>
#include <numeric>

struct Record {
    double unit_price;
    int units;          // number of units sold
};

double price(double v, const Record& r)
{
    return v + r.unit_price * r.units;      // calc price & accum
}

void f(const std::vector<Record>& v)
    // regular function
{
    double total = std::accumulate(v.begin(), v.end(), 0.0, price);

    std::cout << "Actual retail price: " << total << '\n';
}

void f2(const std::vector<Record>& v)
    // lambda!
{
    double total = std::accumulate(v.begin(), v.end(), 0.0,
            [](double v, const Record& r)
                { return v + r.unit_price * r.units; }
        );

    std::cout << "Actual retail price: " << total << '\n';
}

class Total {
public:
    Total() { }
    double operator()(double v, const Record& r)
    {
        return v + r.unit_price * r.units;
    }
};

void f3(const std::vector<Record>& v)
    // function object
{
    double total = std::accumulate(v.begin(), v.end(), 0.0, Total());

    std::cout << "Actual retail price: " << total << '\n';
}

int main()
try {
    std::vector<Record> vr {
        { 1.23, 4 },
        { 3.75, 1 },
        { 2.86, 5 },
        { 0.75, 9 }
    };

    f(vr);
    f2(vr);
    f3(vr);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

