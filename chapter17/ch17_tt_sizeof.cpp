#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cout;
using std::string;

void sizes_char(char c, char* p, char& r)
{
    cout << "the size of char is " << sizeof(char) << ' '
         << sizeof(c) << '\n';
    cout << "the size of char* is " << sizeof(char*) << ' '
         << sizeof(p) << '\n';
    cout << "the size of char& is " << sizeof(char&) << ' '
         << sizeof(r) << '\n';
}

void sizes_int(int i, int* p, int& r)
{
    cout << "the size of int is " << sizeof(int) << ' ' << sizeof(i) << '\n';
    cout << "the size of int* is " << sizeof(int*) << ' ' << sizeof(p) << '\n';
    cout << "the size of int& is " << sizeof(int&) << ' ' << sizeof(r) << '\n';
}

void sizes_bool(bool b, bool* p, bool& r)
{
    cout << "the size of bool is " << sizeof(bool) << ' ' << sizeof(b) << '\n';
    cout << "the size of bool* is " << sizeof(bool*) << ' '
         << sizeof(p) << '\n';
    cout << "the size of bool& is " << sizeof(bool&) << ' '
         << sizeof(r) << '\n';
}

void sizes_double(double d, double* p, double& r)
{
    cout << "the size of double is " << sizeof(double) << ' '
         << sizeof(d) << '\n';
    cout << "the size of double* is " << sizeof(double*) << ' '
         << sizeof(p) << '\n';
    cout << "the size of double& is " << sizeof(double&) << ' '
         << sizeof(r) << '\n';
}

void sizes_string(string s, string* p, string& r)
{
    cout << "the size of string is " << sizeof(string) << ' '
         << sizeof(s) << '\n';
    cout << "the size of string* is " << sizeof(string*) << ' '
         << sizeof(p) << '\n';
    cout << "the size of string& is " << sizeof(string&) << ' '
         << sizeof(r) << '\n';
}

void sizes_long(long l, long* p, long& r)
{
    cout << "the size of long is " << sizeof(long) << ' ' << sizeof(l) << '\n';
    cout << "the size of long* is " << sizeof(long*) << ' '
         << sizeof(p) << '\n';
    cout << "the size of long& is " << sizeof(long&) << ' '
         << sizeof(r) << '\n';
}

int main()
try {
    // Pointers
    int x = 17;         // set aside an "int-size" piece of memory & put 17
    int* pi = &x;       // int* - creates an int pointer or pointer to int
    int& ri = x;        // &x - "address of" operator, unary &
                        // *pi - "contents of" operator, unary *, dereference

    double e = 2.71828;
    double* pd = &e;
    double& rd = e;

    cout << "pi==" << pi << "; contents of pi==" << *pi << '\n';
    cout << "ri==" << ri << "; address of ri==" << &ri << '\n';
    cout << "pd==" << pd << "; contents of pd==" << *pd << '\n';
    cout << "rd==" << rd << "; address of rd==" << &rd << '\n';

    cout << '\n';

    char c = 'a';
    char* pc = &c;
    char& rc = c;

    bool t = true;
    bool* pb = &t;
    bool& rb = t;

    string s = "Hello world";
    string* ps = &s;
    string& rs = s;

    long l = 10000000000000;
    long* pl = &l;
    long& rl = l;

    sizes_char(c, pc, rc);
    sizes_int(x, pi, ri);
    sizes_bool(t, pb, rb);
    sizes_double(e, pd, rd);
    sizes_string(s, ps, rs);
    sizes_long(l, pl, rl);

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
