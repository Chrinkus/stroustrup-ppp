//
// Stroustrup - Programming Principles & Practice
//
// Chapter 24 Try This - Overflow and Truncation
//

#include <iostream>
#include <stdexcept>

void f(int i, double fpd)
{
    char c = i;         // yes: chars really are very small integers
    short s = i;        // beware: an int may not fit in a short int
    i = i + 1;          // what if i was the largest int?
    long lg = i * i;    // beware: a long may not be any larger than an int
    float fps = fpd;    // beware: a large double may not fit in a float
    i = fpd;            // truncates: eg., 5.7 -> 5
    fps = i;            // you can lose precision (for very large int values)

    std::cout << "c: " << c << " s: " << s << " i: " << i << '\n';
}

void g()
{
    char ch = 0;
    for (int i = 0; i < 500; ++i)
        std::cout << int(ch++) << '\t';
}

int main()
try {
    //g();
    f(52, 3.14159);
    f(2000000, 5.5);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

