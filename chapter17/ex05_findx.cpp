//
// Stroustrup - Programming Principles & Practice
//
// Chapter 17 Exercise 5
//
// Write a function, char* findx(const char* s, const char* x), that finds the
// first occurrence of the C-style string x in s.
//

#include <iostream>
#include <stdexcept>

using std::cout;

const char* findx(const char* s, const char* x)
{
    for (int i = 0; s[i]; ++i)
        if (s[i] == x[0]) {
            for (int j = 1; ; ++j)
                if (!x[j]) {
                    return &s[i];
                } else if (x[j] != s[i + j]) {
                    break;
                }
        }

    return nullptr;         // returned for falsey test
}

int main()
try {
    char cs1[] = "For the Horde?";
    char cs2[] = "Horde";
    char cs3[] = "Alliance";

    const char* found = findx(cs1, cs2);
    const char* not_found = findx(cs1, cs3);

    if (found)
        cout << "Glory to the Horde!!" << found << '\n';

    if (not_found)
        cout << "Glory to the Alliance!!" << not_found << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "unknown exception\n";
    return 2;
}
