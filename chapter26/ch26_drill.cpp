//
// Stroustrup - Programming Principles & Practice
//
// Chapter 26 Drill - Binary Search
// 
// This also seems to cover exercise 1 since the tests from §26.3.2.1 are used
// when testing from a file.
//

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <random>
#include <fstream>
#include "ch26_my_binary.h"             // my_binary()
#include "ch26_Test.h"                  // Test

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

// 3. random sequences
int randint(int min, int max)
{
    static std::default_random_engine ran;
    return std::uniform_int_distribution<>{min, max}(ran);
}

int randint(int max)
{
    return randint(0, max);
}

void make_test_file(std::ofstream& ofs,
                    const std::string& lab,
                    int n,
                    int base,
                    int spread)
{
    ofs << "{ " << lab << " "; 
    std::vector<int> v;
    v.reserve(n);
    int elem = base;
    for (int i = 0; i < n; ++i) {
        elem += randint(spread);
        v.push_back(elem);
    }

    int val = base + randint(elem - base);
    ofs << val << " { ";
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (v[i] == val)
            found = true;
        ofs << v[i] << " ";
    }
    ofs << "} " << found << " }\n";
}

int main()
try {
    // 2. test from a file
    std::ifstream ifs0 {"test_b_search.txt"};
    int errors = test_all(ifs0);
    std::cout << "number of errors: " << errors << '\n';

    // 3. generating tests
    // a. A very large sequence
    const int large = 10000000;         // removed 2 - 0's
    std::vector<int> vi1;
    vi1.resize(large);
    for (auto i = 0; i < large; ++i)
        vi1.push_back(i);

    if (my_binary(vi1.begin(), vi1.end(), 37) == false)
        std::cout << "large test failed (37)\n";
    if (my_binary(vi1.begin(), vi1.end(), -1) == true)
        std::cout << "large test failed (-1)\n";

    // b. ten sequences with random numbers
    std::string fname1 {"drill_3_b.txt"};
    std::ofstream ofs1 {fname1};
    int no_of_tests = 10;
    for (auto i = 0; i < no_of_tests; ++i) {
        std::string lab = "random_test_";
        make_test_file(ofs1,
                       lab + std::to_string(i),
                       randint(500),
                       0,
                       randint(50));
    }
    ofs1.close();
   
    std::ifstream ifs1 {fname1};
    errors = test_all(ifs1);
    std::cout << "number of errors (random): " << errors << '\n';

    // c. ten sequences with 0, 1, 2...9 random elements
    std::string fname2 {"drill_3_c.txt"};
    std::ofstream ofs2 {fname2};
    for (auto i = 0; i < no_of_tests; ++i) {
        std::string lab = "random_elements_";
        make_test_file(ofs2, lab + std::to_string(i), i, 0, 5);
    }
    ofs2.close();

    std::ifstream ifs2 {fname2};
    errors = test_all(ifs2);
    std::cout << "number of errors (0-9): " << errors << '\n';

    // 4. repeat these tests for sequences of strings
    std::ifstream ifs3 {"test_b_string.txt"};
    errors = test_all(ifs3);
    std::cout << "number of string errors: " << errors << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

