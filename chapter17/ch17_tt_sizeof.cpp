#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cout;
using std::string;

void sizes_char(char c, char* p)
{
    cout << "the size of char is " << sizeof(char) << ' '
         << sizeof(c) << '\n';
    cout << "the size of char* is " << sizeof(char*) << ' '
         << sizeof(p) << '\n';
}

void sizes_int(int i, int* p)
{
    cout << "the size of int is " << sizeof(int) << ' ' << sizeof(i) << '\n';
    cout << "the size of int* is " << sizeof(int*) << ' ' << sizeof(p) << '\n';
}

void sizes_bool(bool b, bool* p)
{
    cout << "the size of bool is " << sizeof(bool) << ' ' << sizeof(b) << '\n';
    cout << "the size of bool* is " << sizeof(bool*) << ' '
         << sizeof(p) << '\n';
}

void sizes_double(double d, double* p)
{
    cout << "the size of double is " << sizeof(double) << ' '
         << sizeof(d) << '\n';
    cout << "the size of double* is " << sizeof(double*) << ' '
         << sizeof(p) << '\n';
}

void sizes_string(string s, string* p)
{
    cout << "the size of string is " << sizeof(string) << ' '
         << sizeof(s) << '\n';
    cout << "the size of string* is " << sizeof(string*) << ' '
         << sizeof(p) << '\n';
}

int main()
try {
    // Pointers
    int x = 17;         // set aside an "int-size" piece of memory & put 17
    int* pi = &x;       // int* - creates an int pointer or pointer to int
                        // &x - "address of" operator, unary &
                        // *pi - "contents of" operator, unary *, dereference

    double e = 2.71828;
    double* pd = &e;

    cout << "pi==" << pi << "; contents of pi==" << *pi << '\n';
    cout << "pd==" << pd << "; contents of pd==" << *pd << '\n';

    cout << '\n';

    char c = 'a';
    char* pc = &c;

    bool t = true;
    bool* pb = &t;

    string s = "Hello world";
    string* ps = &s;

    sizes_char(c, pc);
    sizes_int(x, pi);
    sizes_bool(t, pb);
    sizes_double(e, pd);
    sizes_string(s, ps);

    std::vector<int> v(1000);   // vector with 1000 elements of type int
    cout << "the size of vector<int>(1000) is " << sizeof(v) << '\n';
}
catch(std::exception& e) {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}
