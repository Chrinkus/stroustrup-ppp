//
// Stroustrup - Programming Principles & Practice
//
// Chapter 23 Exercise 7
//
// Write a program that finds credit card numbers in a file.
//
// Need to first detect a certain length of digits, then validate them against
// the Luhn formula. I'm not concerned with matching different vendor's initial
// patterns yet..
//
// So apparently even though "most" credit card numbers can be validated with
// the Luhn algorithm, most of the example card numbers from the site do NOT
// pass the algorithm. Oh well.
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <regex>
#include <vector>
#include <numeric>
#include <fstream>

void print(const std::vector<int>& v)
{
    for (const auto& i : v)
        std::cout << i << ' ';
    std::cout << '\n';
}

bool has_credit_card(const std::string& s,
        std::match_results<std::string::const_iterator>& m)
{
    std::regex pat {R"([\d]{13,19})"};

    return std::regex_search(s,m,pat);
}

bool passes_luhn(const std::sub_match<std::string::const_iterator>& sm)
    // remove last digit and save for comparison
    // reverse the numbers
    // multiply digits in odd positions by 2
    // subtract 9 from any number greater than 9
    // add the numbers and compare the last digit (total % 10) to the original
    // last digit saved for comparison
{
    std::string s = sm.str();

    std::vector<int> vi;
    for (const auto& c : s) {
        vi.push_back(c - '0');          // convert character digits to ints
    }

    int cmp = vi.back();
    vi.pop_back();

    std::reverse(vi.begin(), vi.end());

    for (int i = 0; i < vi.size(); ++i) {
        if (!(i % 2))
            vi[i] *= 2;
        if (vi[i] > 9)
            vi[i] -= 9;
    }

    return std::accumulate(vi.begin(), vi.end(), 0) % 10 == cmp;
}

int main()
try {
    std::string iname = "input_cards.txt";
    std::ifstream ifs {iname};
    if (!ifs) {
        std::cerr << "Could not open file " << iname << '\n';
        exit(1);
    }

    int lineno = 0;
    std::smatch matches;
    for (std::string line; std::getline(ifs,line); ) {
        ++lineno;
        if (has_credit_card(line,matches) && passes_luhn(matches[0]))
            std::cout << lineno << ": " << matches[0] << '\n';
    }
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

