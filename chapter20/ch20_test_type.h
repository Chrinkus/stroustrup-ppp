#include <iostream>
#include <string>

struct Test_type {
    std::string s;
    unsigned long i;
    double d;
    char c;

    Test_type() : s{"def"}, i{0}, d{0.0}, c{'\0'} { }
    Test_type(const std::string& ss)
        : s{ss}, i{ss.size()}, d{ss.size() / 3.14159}, c{ss[0]} { }

    ~Test_type() { std::cout << s << " destructed!\n"; }
};

std::ostream& operator<<(std::ostream& os, const Test_type& tt)
{
    return os << tt.s << ' '
              << tt.i << ' '
              << tt.d << ' '
              << tt.c << '\n';
}
