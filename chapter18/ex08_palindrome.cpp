//
// Stroustrup - Programming Principles & Practice
//
// Chapter 18 Exercise 8
//
// Rewrite functions from 18.7 to detect palindromes by creating reversed copy
// and comparing to original.
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

bool is_palindrome(const std::string& s)
{
    std::string rev = "";
    for (int i = s.size() - 1; i >= 0; --i)
        rev += s[i];

    if (rev == s) return true;
    return false;
}

bool is_palindrome(const char s[], int n)
{
    char rev[n];
    for (int i = n; i >= 1; --i) {
        rev = s[i];
        ++rev;
    }
    rev = s[n+1];

    std::cout << s << ' ' << rev << '\n';
}

int get_size(const char s[])
{
    int n = 0;
    while (s) { ++n; ++s }
    
    return ++n;
}

int main()
try {
    // code
    /*
    std::vector<std::string> test { "radar", "fruit", "anna", "panama" };

    for (auto& a : test)
        std::cout << a << ": " << is_palindrome(a) << '\n';
    */
    char pal1[] = "radar";
    int pal1_s = get_size(pal1);

    is_palindrome(pal1, pal1_s);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

