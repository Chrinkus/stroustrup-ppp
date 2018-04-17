//
// Stroustrup - Programming Principles & Practice
//
// Chapter 24 Drill
//
// Some fun and odd stuff here, including a sqrt exercise from chapter 5.
//

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <complex>
#include <numeric>
#include "../text_lib/Matrix.h"
#include "../text_lib/MatrixIO.h"

using Numeric_lib::Matrix;

void sqrt_out()
    // why is this a chapter 24 exercise..?
{
    int val;
    std::cin >> val;
    if (val < 0)
        std::cout << "no square root\n";
    else
        std::cout << sqrt(val) << '\n';
}

int main()
try {
    // 1. Print the size of a char, short, int, long, float, double, int* and
    // a double*;
    std::cout << "OBJECT SIZEOFs:\n"
              << "char: " << sizeof(char) << '\n'
              << "short: " << sizeof(short) << '\n'
              << "int: " << sizeof(int) << '\n'
              << "long: " << sizeof(long) << '\n'
              << "float: " << sizeof(float) << '\n'
              << "double: " << sizeof(double) << '\n'
              << "int*: " << sizeof(int*) << '\n'
              << "double*: " << sizeof(double*) << "\n\n";

    // 2. Print out the sizes of different types of Matrixes
    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int,2> d(10,10);
    Matrix<int,3> e(10,10,10);

    std::cout << "MATRIX SIZEOFs:\n"
              << "Matrix<int>(10): " << sizeof(a) << '\n'
              << "Matrix<int>(100): " << sizeof(b) << '\n'
              << "Matrix<double>(10): " << sizeof(c) << '\n'
              << "Matrix<int,2>(10,10): " << sizeof(d) << '\n'
              << "Matrix<int,3>(10,10,10): " << sizeof(e) << "\n\n";

    // 3. Print out the number of elements in the different Matrixes
    std::cout << "MATRIX ELEMENTS:\n"
              << "Matrix<int>(10): " << a.size() << '\n'
              << "Matrix<int>(100): " << b.size() << '\n'
              << "Matrix<double>(10): " << c.size() << '\n'
              << "Matrix<int,2>(10,10): " << d.size() << '\n'
              << "Matrix<int,3>(10,10,10): " << e.size() << "\n\n";

    // 4. Take ints from cin and output the sqrt of them. Check for bad input.
    std::cout << "Enter some ints for square-rooting:\n";
    for (int i = 0; i < 5; ++i)
        sqrt_out();

    // 5. Read 10 floating point values from input into a Matrix
    std::cout << "Enter 10 floats for entry into a Matrix:\n";
    const int entries = 10;

    Matrix<double> md(entries);
    for (int i = 0; i < entries; ++i)
        std::cin >> md[i];

    std::cout << md << '\n';

    // 6. Compute a multiplication table and print it.
    std::cout << "Enter the dimensions for the table: ";
    int m, n;
    std::cin >> m >> n;
    std::cout << '\n';

    Matrix<double,2> mult_table(m,n);

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            mult_table(i,j) = i == 0 || j == 0 ? i + j : i * j;

    //std::cout << mult_table << '\n'; // ugly
    for (int i = 0; i < mult_table.dim1(); ++i) {
        for (int j = 0; j < mult_table.dim2(); ++j)
            std::cout << std::setw(5) << mult_table(i,j);
        std::cout << '\n';
    }

    // 7. Read 10 complex<double>s in from cin. Output the sum.
    std::cout << "Enter 10 complex numbers:\n";
    Matrix<std::complex<double>> mcd (10);
    for (int i = 0; i < mcd.size(); ++i) {
        std::cin >> mcd[i];
    }

    std::cout << "Total: "
              << std::accumulate(mcd.data(), mcd.data() + mcd.size(),
                      std::complex<double>{})
              << '\n';

    // 8. Read 6 ints into a Matrix<int,2> (2,3) and print them out
    std::cout << "Enter 6 ints for a 2x3 Matrix:\n";
    Matrix<int,2> mm (2,3);
    for (int i = 0; i < mm.dim1(); ++i)
        for (int j = 0; j < mm.dim2(); ++j)
            std::cin >> mm[i][j];

    std::cout << mm << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

