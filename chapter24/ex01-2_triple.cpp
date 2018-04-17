//
// Stroustrup - Programming Principles & Practice
//
// Chapter 24 Exercise 1
//
// Define a single triple function that can be used by a.apply(triple) and 
// apply(triple,a). Explain why it would be a bad idea to write every function
// to be used by apply() that way.
//
// Exercise 2
//
// Do exercise 1 using function objects.
//

#include <iostream>
#include <stdexcept>
#include "../text_lib/Matrix.h"
#include "../text_lib/MatrixIO.h"

using namespace Numeric_lib;

double triple(const double x)
    // this, to me, is the best triple: takes a value, returns a value without
    // changing original.
{
    return x * 3;
}

void triple_ref(double& x)
    // this would be necessary for changing a Matrix in-place but would prefer
    // to write it as a lambda since its so short.
{
    x *= 3;
}

double omni_triple(double& x)
    // this both changes a value in place and returns a value. This is the 
    // opposite of funcitonal in the worst way.
{
    x *= 3;
    return x;
}

// ex 2
class Triple {
public:
    double operator()(double& x)
    {
        x *= 3;
        return x;
    }
};

int main()
try {
    Matrix<double,2> md1(3,4);

    for (int i = 0; i<md1.dim1(); ++i)
        for (int j = 0; j<md1.dim2(); ++j)
            md1(i,j) = i*10+j;

    std::cout << "md1 init: " << md1 << '\n';

    Matrix<double,2> md2 = apply(omni_triple,md1);

    std::cout << "md2 init: " << md2 << '\n';
    std::cout << "md1 status: " << md1 << '\n';

    md1.apply(omni_triple);
    std::cout << "md1 tripled: " << md1 << '\n';

    md2.apply([](double& x) { x *= 8; });
    std::cout << "md2 lambda'd: " << md2 << '\n';

    // ex 2
    Matrix<double,2> md3 = apply(Triple(),md1);
    std::cout << "md3 init: " << md3 << '\n';

    md3.apply(Triple());
    std::cout << "md3 tripled: " << md3 << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

