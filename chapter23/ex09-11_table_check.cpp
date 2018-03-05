//
// Stroustrup - Programming Principles & Practice
//
// Chapter 23 Exercise 9
//
// Using eof() try to simplify the table-checking program from §23.9.
//
// Chapter 23 Exercise 10
//
// Modify the table-checking program from §23.9 write a new table where the
// rows with the same initial digit are merged.
//
// First complete and run §23.9 
//
// Error: there are two problems with this example in the text. First is the
// use of tabs within the patterns. My editor, and other editors, I assume,
// insert spaces instead of tabs so using the actual tab special character \t 
// is better.
// The other problem is the absence of a capture group around the [\w ]+
// part of the row pattern. This throws off the from_string conversions and
// causes an error when trying to convert matches[4] to int because there is
// nothing to convert. Later the missing first capture group is tested against
// (to see if it is the 'alle klasser' line) which also will cause a fail.
//
// Exercise 11
//
// Modify the table-checking program to see if the number of students is 
// increasing or decreasing over the years.
// - Not sure what this is asking for, ex 10 groups the students by year so you
// can make an observation based on that output.
//

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <map>

struct bad_from_string : std::bad_cast {
    const char* what() const noexcept override
    {
        return "bad cast from string";
    }
};

template<typename T> T from_string(const std::string& s)
{
    std::istringstream is {s};
    T t;
    if (!(is >> t)) {
        std::cout << s << '\n';
        throw bad_from_string{};
    }
    return t;
}

// ex 10
struct Students {
    int boys = 0;
    int girls = 0;

    int total() const { return boys + girls; }
};

int main()
try {
    std::ifstream in {"input_table.txt"};   // input file
    if (!in) throw std::runtime_error("no input file");

    std::regex header {R"(^[\w ]+(\t[\w ]+)*$)"};           // header line
    std::regex row {R"(^([\w ]+)(\t\d+)(\t\d+)(\t\d+)$)"};  // data line
                                                            // must add first
                                                            // group capture!!
    int lineno = 0;
    std::string line;                       // input buffer
    if (std::getline(in,line)) {            // check header line
        ++lineno;
        std::smatch matches;
        if (!std::regex_match(line,matches,header))
            throw std::runtime_error("no header");
    }

    // column totals
    int boys = 0;
    int girls = 0;

    std::map<char,Students> years;

    while (std::getline(in,line)) {         // check data line
        ++lineno;
        std::smatch matches;
        if (!std::regex_match(line,matches,row))
            throw std::runtime_error("bad line" + std::to_string(lineno));

        // check row
        int curr_boy = from_string<int>(matches[2]);
        int curr_girl = from_string<int>(matches[3]);
        int curr_total = from_string<int>(matches[4]);
        if (curr_boy+curr_girl != curr_total)
            throw std::runtime_error("bad row sum\n");

        char year = matches[1].str()[0];

        if (isdigit(year)) {
            years[year].boys += curr_boy;
            years[year].girls += curr_girl;
        }

        // ex 9 simplification(?)
        if ((in >> std::ws).eof()) {    // check if there's only whitespace
                                        // between current line and eof()
            if (curr_boy != boys || curr_girl != girls)
                throw std::runtime_error("columns don't add up\n");
        } else {                        // update totals
            boys += curr_boy;
            girls += curr_girl;
        }
    }

    // ex 10 output
    std::cout << "AR" << '\t' << "DRENG" << '\t'
              << "PIGE" << '\t' << "ELEVER" << '\n';

    for (const auto& y : years)
        std::cout << y.first << '\t'
                  << y.second.boys << '\t'
                  << y.second.girls << '\t'
                  << y.second.total() << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

