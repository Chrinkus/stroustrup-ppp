//
// Stroustrup - Programming Principles & Practice
//
// Chapter 20 Try This: mapping stock data
//

#include <iostream>
#include <stdexcept>
#include <map>
#include <string>
#include <numeric>

double weighted_value(
        const std::pair<std::string, double>& a,
        const std::pair<std::string, double>& b)
    // extract values and multiply
{
    return a.second * b.second;
}

int main()
try {
    std::map<std::string, double> dow_price = {
        { "MMM", 81.86 },
        { "AA", 34.69 },
        { "MO", 54.45 },
        { "BA", 332.83 },
        { "INTC", 43.95 }
    };

    std::map<std::string, double> dow_weight = {
        { "MMM", 5.8549 },
        { "AA", 2.4808 },
        { "MO", 3.8940 },
        { "BA", 1.7182 },
        { "INTC", 2.8783 }
    };

    std::map<std::string, std::string> dow_name = {
        { "MMM", "3M Co." },
        { "AA", "Alcoa Inc." },
        { "MO", "Altria Group Inc." },
        { "BA", "Boeing Inc." },
        { "INTC", "Intel Inc." }
    };

    // example patterns for use
    double alcoa_price = dow_price["AA"];
    double boeing_price = dow_price["BA"];

    if (dow_price.find("INTC") != dow_price.end())
        std::cout << "Intel is in the Dow\n";

    // write price for each company in the Dow index:
    for (const auto& p : dow_price) {
        const std::string& symbol = p.first;
        std::cout << symbol << '\t'
                  << p.second << '\t'
                  << dow_name[symbol] << '\n';
    }

    double dji_index =
        inner_product(dow_price.begin(), dow_price.end(),   // all companies
                dow_weight.begin(),     // their weights
                0.0,                    // initial value
                std::plus<double>(),    // add (as usual)
                weighted_value);        // extract values and weights
                                        // and multiply
    
    std::cout << "Dow Jones Industrial Index: " << dji_index << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

