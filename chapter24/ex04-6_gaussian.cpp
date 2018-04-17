//
// Stroustrup - Programming Principles & Practice
//
// Chapter 24 - Gaussian Elimination
//
// Exercise 4 - Get the Gaussian Elimination example to run and test it.
// 
// Included are the random vector and matrix generating functions from the 
// random number facilities examination from later in the chapter but they are
// not used in the testing of the gaussian elimination in favour of test cases
// that are predictable.
//
// Exercise 5 - Test with difficult input, use elim_with_pivot to solve
//
// Exercise 6 - Replace dot_product() and scale_and_add with loops
//
// Obviously the code is harder to reason about when descriptive operation
// names such as dot_product and scale_and_add are removed. The loops actually
// weren't too difficult to write so the question is which method "costs" more,
// a semantically recognizable function call or a slightly confusing loop? As
// a thought, the line with scale_and_add isn't much easier to read than a loop
// though knowing the signature of the function automatically helps the
// programmer to deduce what's going on.
//

#include <iostream>
#include <stdexcept>
#include <random>
#include <vector>
#include <sstream>
#include "../text_lib/Matrix.h"
#include "../text_lib/MatrixIO.h"

using Matrix = Numeric_lib::Matrix<double,2>;
using Vector = Numeric_lib::Matrix<double,1>;

using Numeric_lib::Index;

void classical_elimination(Matrix& A, Vector& b)
{
    const Index n = A.dim1();

    // traverse from 1st column to the next-to-last
    // filling zeros into all elements under the diagonal:
    for (Index j = 0; j<n-1; ++j) {
        const double pivot = A(j,j);
        if (pivot == 0) //throw Elim_failure(j);
            throw std::runtime_error("Elim failure");

        // fill zeros into each element under the diagonal of the ith row:
        for (Index i = j+1; i<n; ++i) {
            const double mult = A(i,j) / pivot;
            // begin ex 6
            //A[i].slice(j) = scale_and_add(A[j].slice(j), -mult, A[i].slice(j));
            for (Index k = j; k < A[i].dim1(); ++k)
                A(i,k) += A(j,k) * -mult;
            // end ex 6
            b(i) -= mult*b(j);      // make the corresponding change to b
        }
    }
}

Vector back_substitution(const Matrix& A, const Vector& b)
{
    const Index n = A.dim1();
    Vector x(n);

    for (Index i = n-1; i>=0; --i) {
        // begin ex 6
        //double s = b(i) - dot_product(A[i].slice(i+1),x.slice(i+1));
        double sum = 0;
        for (Index j = i + 1; j < A[i].size(); ++j)
            sum += A(i,j) * x(j);
        double s = b(i) - sum;
        // end ex 6

        if (double m = A(i,i))
            x(i) = s/m;
        else
            throw std::runtime_error("Back subst failure");
            //throw Back_subst_failure(i);
    }

    return x;
}

void elim_with_partial_pivot(Matrix& A, Vector& b)
{
    const Index n = A.dim1();

    for (Index j = 0; j<n; ++j) {
        Index pivot_row = j;

        // look for a suitable pivot:
        for (Index k = j+1; k<n; ++k)
            if (abs(A(k,j)) > abs(A(pivot_row,j))) pivot_row = k;

        // swap the rows if we found a better pivot:
        if (pivot_row!=j) {
            A.swap_rows(j,pivot_row);
            std::swap(b(j), b(pivot_row));
        }

        // elimination:
        for (Index i = j+1; i<n; ++i) {
            const double pivot = A(j,j);
            if (pivot==0) throw std::runtime_error("can't solve pivot==0");
            const double mult = A(i,j)/pivot;
            A[i].slice(j) = scale_and_add(A[j].slice(j), -mult, A[i].slice(j));
            b(i) -= mult*b(j);
        }
    }
}

Vector classical_gaussian_elimination(Matrix A, Vector b)
{
    classical_elimination(A, b);
    return back_substitution(A, b);
}

Vector pivot_elimination(Matrix A, Vector b)
{
    elim_with_partial_pivot(A, b);
    return back_substitution(A, b);
}

Vector operator*(const Matrix& m, const Vector& u)
{
    const Index n = m.dim1();
    Vector v(n);
    for (Index i = 0; i<n; ++i) v(i) = dot_product(m[i],u);
    return v;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Random number-based functions NOT USED
Vector random_vector(Index n)
{
    const int max = 50;
    Vector v(n);
    std::default_random_engine ran{};               // generates integers
    std::uniform_real_distribution<> ureal{0,max};  // maps ints to doubles
                                                    // in [0:max)
    for (Index i = 0; i<n; ++i)
        v(i) = ureal(ran);

    return v;
}

Matrix random_matrix(Index n)
{
    const int max = 50;
    Matrix m(n, n+2);
    std::default_random_engine ran{};
    std::uniform_real_distribution<> ureal{0,max};

    for (Index i = 0; i<m.dim1(); ++i)
        for (Index j = 0; j<m.dim2(); ++j)
            m(i,j) = ureal(ran);

    return m;
}

void solve_random_system(Index n)
{
    Matrix A = random_matrix(n);
    Vector b = random_vector(n);

    std::cout << "A = " << A << '\n';
    std::cout << "b = " << b << '\n';

    try {
        Vector x = classical_gaussian_elimination(A, b);
        std::cout << "classical elim solution is x = " << x << '\n';
        Vector v = A*x;
        std::cout << " A*x = " << v << '\n';
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

int main()
try {
    // ex 4
    std::cout << "Ex 4 - Simple example that runs\n";
    double ad1[][2] { { 2, -5 }, { -2, 4 } };
    double ad2[2]   { 7, -6 };
    Matrix A1 {ad1};
    Vector b1 {ad2};

    std::cout << A1 << '\n';
    std::cout << b1 << '\n';

    Vector x1 = classical_gaussian_elimination(A1, b1);
    std::cout << "classical elim solution is x = " << x1 << '\n';
    Vector v1 = A1 * x1;
    std::cout << "A*x = " << v1 << "\n\n";

    // ex 5 - difficult example
    std::cout << "Ex 5 - A pivot is needed\n";
    Matrix A2 (2, 2);
    Vector b2 (2);
    std::istringstream ism {"{ { 0 1 }{ 1 0 } }"};
    std::istringstream isv {"{ 5 6 }"};
    ism >> A2;
    isv >> b2;

    std::cout << A2 << '\n';
    std::cout << b2 << '\n';

    //Vector x2 = classical_gaussian_elimination(A, b);
    Vector x2 = pivot_elimination(A2, b2);
    std::cout << "pivot elim solution is x = " << x2 << '\n';
    Vector v2 = A2 * x2;
    std::cout << "A*x = " << v2 << "\n\n";
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

