//
// Stroustrup - Programming Principles & Practice
//
// Chapter 24 Exercise 11
//
// Write a swap_columns() to match swap_rows().
//
// Exercise 12
//
// Implement addition and multiplication for Matrices.
//

#include <iostream>
#include <stdexcept>
#include "../text_lib/Matrix.h"
#include "../text_lib/MatrixIO.h"

using namespace Numeric_lib;

// Ex 11
template<typename T>
void swap_columns(Matrix<T>& m, Index i, Index j)
{
    if (i == j) return;

    std::swap(m(i), m(j));
}

template<typename T, int N>
void swap_columns(Matrix<T,N>& m, Index i, Index j)
{
    for (Index k = 0; k < m.dim1(); ++k)
        std::swap(m(k,i), m(k,j));
        //swap_columns(m[k], i, j);     // can't call in terms of self
}

// Ex 12
Matrix<double> operator*(Matrix<double,2>& a, Matrix<double>& b)
{
    if (a.dim2() != b.dim1())
        throw std::runtime_error("incompatible dimensions for multiplication");

    Matrix<double> out (a.dim1());

    for (Index i = 0; i < out.size(); ++i)
        out(i) = dot_product(a[i], b);

    return out;
}

template<int N>
Matrix<double,N> operator+(Matrix<double,N>& a, Matrix<double,N>& b)
{
    // not a fool-proof test but if same N and dim1 then most likely same
    // dimensions. test for size too.
    if (a.dim1() != b.dim1() || a.size() != b.size())
        throw std::runtime_error("can't add matrices of different dimensions");

    Matrix<double,N> m = a;                 // copy a into out Matrix

    for (Index i = 0; i < m.size(); ++i)
        m.data()[i] += b.data()[i];         // copy from array avoids dimension
                                            // detection
    return m;
}

int main()
try {
    // Ex 11 - swap_columns()

    // single dimension swap
    Matrix<double> m1 (5);
    for (auto i = 0; i < m1.dim1(); ++i)
        m1(i) = i;

    std::cout << "Initial state of m1: " << m1 << '\n';
    swap_columns(m1, 2, 4);
    std::cout << "Post swap m1: " << m1 << '\n';

    // two dimension swap
    Matrix<double,2> m2 (4, 5);
    for (auto i = 0; i < m2.dim1(); ++i)
        for (auto j = 0; j < m2.dim2(); ++j)
            m2(i,j) = 10 + i * 10 + j;

    std::cout << "Initial state of m2: " << m2 << '\n';
    swap_columns(m2, 1, 2);
    std::cout << "Post swap m2: " << m2 << '\n';

    // Ex 12 - Matrix addition

    // multi-dimension addition
    Matrix<double,2> m3 (4, 5);         // same size as m2
    m3 = 3;                             // set all values to 3
    Matrix<double,2> m4 = m2 + m3;
    std::cout << "Results of addition: " << m4 << '\n';

    // single dimension addition
    Matrix<double> m5 (5);
    m5 = 5;
    Matrix<double> m6 = m1 + m5;
    std::cout << "Results of addition: " << m6 << '\n';

    // Matrix multiplication
    auto m7 = m2 * m1;
    std::cout << "Results of multiplication: " << m7 << '\n';

    // more fun and tests
    double ad1[][2] { { 2, -5 }, { -2, 4 } };
    double ad2[2]   { 7, -6 };
    Matrix<double,2> m8 {ad1};
    Matrix<double> m9 {ad2};
    auto m10 = m8 * m9;
    std::cout << "More multiplication: " << m10 << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

