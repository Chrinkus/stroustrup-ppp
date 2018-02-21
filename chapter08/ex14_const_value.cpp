//
// Stroustrup - Programming Principles & Practice
//
// Chapter 8 Exercise 14
//
// What are the implications of declaring a non-reference const argument?
//
// A non-reference const passes a copy of a value that you don't want to
// modify. Maybe if you were returning the value in the end after using it
// for side-effect purposes..? Perhaps declaring const can help an optimization
// in the compiler..? If a value is smaller than a reference to itselt (int or
// char) then maybe we don't want to pass a reference but we still want the
// benefits of const?
//

#include <iostream>
#include <stdexcept>

double print_double(const double cd)
    // return value after using it but not modifying it
    // but why need to? obviously the caller has access to the value and 
    // doesn't need it returned..
{
    std::cout << cd * 2 << '\n';
    return cd;
}

int main()
try {
    // code
    print_double(9.8);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

