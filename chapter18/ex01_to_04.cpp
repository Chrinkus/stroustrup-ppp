//
// Stroustrup - Programming Principles & Practice
//
// Chapter 18 Exercise 1-4
//

#include <iostream>
#include <stdexcept>

using namespace std;

//
// Chapter 18 Exercise 1
//
// Write a function that copies a C-style string into free store memory. Do not
// use subscripting, just dereferences. Do not use standard library functions.
//

char* strdup(const char* c, int n)
{
    char* p = new char[n+1];

    for (int i = 0; i < n; ++i)
        *p++ = *c++;

    if (!c) {
        *p = *c;                // grab terminator
        ++n;
    }

    return p -= n;
}

//
// Chapter 18 Exercise 2
//
// Write a function to find the first occurance of a substring in a C-style
// string. Do not use standard library functions or subscripting.
//

char* findx(const char* s, int sn, const char* x, int xn)
{
    char* p = nullptr;
    while (*s && *x) {
        if (*s == *x) {
            const char* save = x;
            p = const_cast<char*>(s);       // function signature demands cast
            while (*s && *x) {
                if (*s != *x) {
                    x = save;
                    p = nullptr;
                    break;
                }
                ++s;
                ++x;
            }
        } else {
            ++s;
        }
    }

    return p;
}

//
// Chapter 18 Exercise 3
//
// Write a function to compare two C-style strings. Return -1 if s1 comes
// before s2, 0 if equal, or 1 if s2 comes before s1. Do not use standard
// library functions or subscripting.
//

int strcmp(const char* s1, const char* s2)
{
    while (*s1) {
        if (!*s2) return 1;
        if (*s1 < *s2) return -1;
        if (*s1 > *s2) return 1;
        ++s1;
        ++s2;
    }
    if (*s2) return -1;
    return 0;
}

//
// Chapter 18 Exercise 3
//
// Test 1-3 with bad C-style strings. Alter 1-3 to take additional length args
// and test against good and bad strings.
//

int main()
try {
    /*
    // Ex 1 - copy string to free store
    char ac[] = "Chrinkus";

    char* pc = strdup(ac);

    // proof
    while(*pc)
        cout << *pc++;
    cout << '\n';

    // Ex 2 - find sub in string
    char test[] = "Wolves are bold";
    char find[] = "ol";

    cout << "Character legend for comparison:\n";
    cout << &test << '\n';

    char* found = findx(test, find);

    if (found) {
        std::cout << "Found! At: " << &found << '\n';
    } else {
        std::cout << "Not found :(\n";
    }

    // Ex 3 - compare strings & return -1, 0, or 1
    char first[] = "Chrinkus";
    char second[] = "Thomas";
    char third[] = "Chrin";

    cout << strcmp(first, second) << '\n';
    cout << strcmp(second, first) << '\n';
    cout << strcmp(first, first) << '\n';
    cout << strcmp(first, third) << '\n';
    cout << strcmp(third, first) << '\n';
    */

    // Ex 4
    char bad1[] {'b', 'a', 'd', ' ', 's', 't', 'r', 'i', 'n', 'g'};
    char bad2[] {'s', 't'};                             // for findx
    char bad3[] {'b', 'a', 'd', ' ', 'm', 'a', 'n'};    // for compare

    /*
    char* pb1 = strdup(bad1);
    while (pb1)
        cout << *pb1++;         // outputs bad string and a bunch of garbage
    cout << '\n';
    */

    /*
    char* pb2 = findx(bad1, bad2);      // works for both found & not found
    if (pb2) {
        std::cout << "Found! At: " << &pb2 << '\n';
    } else {
        std::cout << "Not found :(\n";
    }
    */

    cout << strcmp(bad1, bad2) << '\n';     // works fine(?)
    cout << strcmp(bad1, bad3) << '\n';
    cout << strcmp(bad2, bad3) << '\n';
    cout << strcmp(bad3, bad3) << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

