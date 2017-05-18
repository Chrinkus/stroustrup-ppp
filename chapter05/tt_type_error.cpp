#include "../text_lib/std_lib_facilities.h"

int area(int length, int width) {
    return length * width;
}

int main()
{
    // Program
    int x0 = arena(7);          // error: undeclared function
    int x1 = area(7);           // error: wrong number of arguments
    int x2 = area("seven", 2);  // error: 1st argument has a wrong type

    int x4 = area(10, -7);      // OK: but how is -7 a width?
    int x5 = area(10.7, 9.3);   // OK: but calls area (10,9)
    char x6 = area(100, 9999);  // OK: but truncates the result
}
