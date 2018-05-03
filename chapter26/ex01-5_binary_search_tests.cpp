//
// Stroustrup - Programming Principles & Practice
//
// Chapter 26 Exercise 1-5 - Binary Search Tests
//
// Ex 1 - Run binary search against tests from §26.3.2.1
//
// The tests from §26.3.2.1 are saved in file test_b_search.txt.
//
// Ex 2 - Modify the binary search to deal with arbitrary element types (it 
// already does..). Test it against strings and floating point sequences.
//
// Ex 3 - Make a 4 arg version of binary search to take a comparison function.
// Make a list of new opportunities for errors.
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>

#include "ch26_my_binary.h"
#include "ch26_Test.h"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Necessary for Ex 4
template<typename T>
using Iter = typename std::vector<T>::iterator;
template<typename T>
using Search_f = bool (*)(Iter<T>, Iter<T>, const T&);

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// For Ex 3 - 4 arg search
struct Reading {
    int hour;
    float temp;
};

bool operator==(const Reading& a, const Reading& b)
{
    return a.temp == b.temp;
}

bool operator!=(const Reading& a, const Reading& b)
{
    return !(a == b);
}

std::istream& operator>>(std::istream& is, Reading& r)
    // reads the format { 3 11.2 } as a Reading
{
    char ch;
    is >> ch;
    if (!is || ch != '{') {
        is.unget();
        return is;
    }

    int h;
    float t;
    is >> h >> t >> ch;

    if (is && ch == '}') {
        r.hour = h;
        r.temp = t;
    }
    return is;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Example solutions

// Ex 1
int test_all(std::istream& is)
{
    int error_count = 0;
    for (Test t; is >> t; ) {
        bool r = my_binary(t.seq.begin(), t.seq.end(), t.val);

        if (r != t.res) {
            std::cout << "failure: test " << t.label
                      << " binary_search: "
                      << t.seq.size() << " elements, val == " << t.val
                      << " -> " << t.res << " != " << r << '\n';
            ++error_count;
        }
    }
    return error_count;
}

// Ex 3 - Compare function
bool find_temp(const Reading& a, const Reading& b)
{
    return a.temp < b.temp;
}

// Ex 4 - Test Generation
template<typename T>
class Make_search_tests {
    public:
        Make_search_tests(std::initializer_list<T> il) : seq{il} { }

        void add_test(const T& val, bool res)
        {
            auto it = std::find(seq.begin(), seq.end(), val);
            if ((it != seq.end() && res) ||     // found and true
                (it == seq.end() && !res)) {     // not found and false
                tests[val] = res;
            } else {
                std::cerr << val << " test result does not match expected\n";
            }
        }

        void run_tests(Search_f<T> f)
        {
            for (const auto& t : tests) {
                bool res = f(seq.begin(), seq.end(), t.first);
                if (res != t.second)
                    std::cerr << "failure: test for " << t.first
                              << " does not equal " << t.second << '\n';
                else
                    std::cout << "passed: test for " << t.first << '\n';
            }
        }
    private:
        std::vector<T> seq;
        std::unordered_map<T,bool> tests;
};

// Ex 5 - Modify Test
template<typename T, typename C>
void no_mod_test(C& c, const T& val)
{
    C d = c;
    bool res = my_binary(d.begin(), d.end(), val);

    if (c != d)
        std::cerr << "my_binary modifies sequence!\n";
    else
        std::cout << "my_binary is good!\n";
}

template<typename T, typename C, typename BinOp>
void no_mod_test(C& c, const T& val, BinOp f)
{
    C d = c;
    bool res = my_binary(d.begin(), d.end(), val, f);

    if (c != d)
        std::cerr << "my_binary 4 arg modifies sequence!\n";
    else
        std::cout << "my_binary 4 arg is good!\n";
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
int main()
try {
    // Ex 1
    std::string fname1 {"test_b_search.txt"};
    std::ifstream ifs1 {fname1};
    int errors1 = test_all(ifs1);
    std::cout << "number of errors: " << errors1 << '\n';

    // Ex 2
    std::string fname2 {"test_b_string.txt"};
    std::ifstream ifs2 {fname2};
    int errors2 = test_all(ifs2);
    std::cout << "number of errors: " << errors2 << '\n';

    std::string fname2_2 {"test_b_float.txt"};
    std::ifstream ifs2_2 {fname2_2};
    int errors2_2 = test_all(ifs2_2);
    std::cout << "number of errors: " << errors2_2 << '\n';

    // Ex 3
    std::string fname3 {"test_b_reading.txt"};
    std::ifstream ifs3 {fname3};

    std::vector<Reading> vr;
    for (Reading r; ifs3 >> r; )
        vr.push_back(r);

    Reading r1 {0, 7.1};
    bool res = my_binary(vr.begin(), vr.end(), r1, find_temp);
    std::cout << "Was " << r1.temp << " found? " << res << '\n';

    Reading r2 {0, 5.9};
    res = my_binary(vr.begin(), vr.end(), r2, find_temp);
    std::cout << "Was " << r2.temp << " found? " << res << '\n';

    // Ex 4
    std::cout << "Exercise 4: test format\n";
    Make_search_tests<int> test4 {1, 2, 3, 5, 7, 11, 13, 17, 19};
    test4.add_test(7, true);
    test4.add_test(19, true);
    test4.add_test(2, true);
    test4.add_test(11, true);
    test4.add_test(8, false);
    test4.add_test(10, false);
    test4.add_test(13, false);      // should print to std::cerr
    test4.run_tests(my_binary);

    // Ex 5
    std::vector<int> v5 {2, 4, 6, 8, 10, 12};
    no_mod_test(v5, 6);

    no_mod_test(v5, 10, [](const int a, int& b) { return b = 1; });
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

