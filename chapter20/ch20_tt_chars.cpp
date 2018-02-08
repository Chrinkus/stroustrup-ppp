//
// Stroustrup - Programming Principles & Practice
//
// Chapter 20 Try This: char storage
//
// Define each method of storing chars with the value "Hello". Pass each as an
// argument to a function. That function will write out the number of
// characters, compare it to a literal "Hello", and compare the argument to
// "Howdy" to see which would come first.
//

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <list>

std::string cmp_out(int v)
{
    if (v == 0) return " is equal to ";
    else if (v < 0) return " comes before ";
    else return " comes after ";
}

template<typename C, typename D>
std::string stl_cmp(const C& a, const D& b)
{
    if (std::equal(a.begin(), a.end(), b.begin()))
        return " is equal to ";
    else if (std::lexicographical_compare(a.begin(), a.end(), b.begin(),
                b.end()))
        return " comes before ";
    else
        return " comes after ";
}

void fa(const char* p)
    // const char* p == const char p[](?)
{
    std::cout << "C-string length: " << strlen(p) << '\n';

    if (strcmp(p, "Hello") == 0)
        std::cout << "C-string matches 'Hello'\n";

    std::cout << "C-string " << p
              << cmp_out(strcmp(p, "Howdy")) << "Howdy\n";

    char cpy[strlen(p) + 1];
    strcpy(cpy, p);

    std::cout << "C-string copy: " << cpy << '\n';
}

void fs(const std::string& s)
{
    std::cout << "std::string length: " << s.size() << '\n';

    if (s == "Hello")
        std::cout << "std::string matches 'Hello'\n";

    std::cout << "std::string " << s
              << cmp_out(s.compare("Howdy")) << "Howdy\n";

    std::string cpy = s;

    std::cout << "std::string copy: " << cpy << '\n';
}

void fv(const std::vector<char>& v)
{
    std::cout << "std::vector<char> length: " << v.size() << '\n';

    std::string cmp = "Hello";
    if (std::equal(v.begin(), v.end(), cmp.begin()))
        std::cout << "std::vector<char> matches 'Hello'\n";

    std::cout << "std::vector 'Hello'"
              << stl_cmp(v, std::string{"Howdy"}) << "Howdy\n";

    std::vector<char> cpy = v;
    std::cout << "std::vector copy: ";
    for (const auto a : cpy)
        std::cout << a;
    std::cout << '\n';
}

void fl(const std::list<char>& l)
    // fun with args!
{
    std::cout << "std::list<char> length: " << l.size() << '\n';

    if (std::equal(l.begin(), l.end(), std::string{"Hello"}.begin()))
        std::cout << "std::list<char> matches 'Hello'\n";

    std::cout << "std::list 'Hello'"
              << stl_cmp(l, std::string{"Apple"}) << "Apple\n";

    std::list<char> cpy = l;
    std::cout << "std::list copy: ";
    for (const auto a : cpy)
        std::cout << a;
    std::cout << '\n';
}

int main()
try {
    char ac[] = "Hello"; 
    std::string sc = "Hello";
    std::vector<char> vc = { 'H', 'e', 'l', 'l', 'o' };
    std::list<char> lc = { 'H', 'e', 'l', 'l', 'o' };

    fa(ac);
    fs(sc);
    fv(vc);
    fl(lc);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

