//
// Stroustrup - Programming Principles & Practice
//
// Chapter 24 - Matrix test
//

#include <iostream>
#include <stdexcept>
#include <numeric>
#include "../text_lib/Matrix.h"

using namespace Numeric_lib;

void f(int n1, int n2, int n3)
{
    Matrix<double,1> ad1 (n1);          // elements are doubles; one dimension
    Matrix<int,1> ai1 (n1);             // elements are ints; one dimension
    ad1(7) = 0;                         // subscript using () - Fortran style
    ad1[7] = 8;                         // [] also works - C style
    Matrix<double,2> ad2(n1,n2);        // 2-dimensional
    Matrix<double,3> ad3(n1,n2,n3);     // 3-dimensional
    ad2(3,4) = 7.5;                     // true multidimensional subscripting
    ad3(3,4,5) = 9.2;
}

void init(Matrix<int,2>& a)
{
    for (int i=0; i<a.dim1(); ++i)
        for (int j=0; j<a.dim2(); ++j)
            a(i,j) = 10*i+j;
}

void print(const Matrix<int,2>& a)
{
    for (int i=0; i<a.dim1(); ++i) {
        for (int j=0; j<a.dim2(); ++j)
            std::cout << a(i,j) << '\t';
        std::cout << '\n';
    }
}

int main()
try {
    f(8,9,10);

    Matrix<int,2> ai2 (5,7);
    init(ai2);
    print(ai2);

    std::cout << '\n';

    Matrix<int,2> b = apply([](const int x) { return x % 17; }, ai2);
    print(b);

    std::cout << '\n';

    std::cout << "Matrix ai2: " << ai2.size() << ' '
              << ai2.dim1() << ' ' << ai2.dim2() << ' ' << " sum: "
              << std::accumulate(ai2.data(), ai2.data() + ai2.size(), 0)
              << '\n';

    ai2 *= 3;
    print(ai2);

    std::cout << '\n';

    std::cout << "Matrix ai2: " << ai2.size() << ' '
              << ai2.dim1() << ' ' << ai2.dim2() << ' ' << " sum: "
              << std::accumulate(ai2.data(), ai2.data() + ai2.size(), 0)
              << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

