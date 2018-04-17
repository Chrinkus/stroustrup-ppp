//
// Stroustrup - Programming Principles & Practice
//
// Chapter 24 Exercise 7
//
// Rewrite the Gaussian elimination program w/o using the Matrix library.
//

#include <iostream>
#include <stdexcept>
#include <vector>
#include <numeric>

using Matrix = std::vector<std::vector<double>>;
using Vector = std::vector<double>;

std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
    os << "{\n";
    for (const auto& v : m) {
        os << "  {  ";
        for (const auto& d : v)
            os << d << "  ";
        os << "}\n";
    }
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
    os << "{  ";
    for (const auto& d : v)
        os << d << "  ";
    os << "}";
    return os;
}

void classical_elimination(Matrix& A, Vector& b)
{
    const auto n = A.size();

    for (auto j = 0; j < n-1; ++j) {
        const double pivot = A[j][j];
        if (pivot == 0) throw std::runtime_error("Elim failure");

        for (auto i = j+1; i < n; ++i) {
            const double mult = A[i][j] / pivot;

            for (auto k = j; k < A[i].size(); ++k)
                A[i][k] += A[j][k] * -mult;

            b[i] -= mult * b[j];
        }
    }
}

Vector back_substitution(const Matrix& A, const Vector& b)
{
    const auto n = A.size();
    Vector x(n);

    for (int i = n-1; i >= 0; --i) {
        double sum = 0;
        for (auto j = i + 1; j < A[i].size(); ++j)
            sum += A[i][j] * x[j];

        double s = b[i] - sum;
        if (double m = A[i][i])
            x[i] = s / m;
        else
            throw std::runtime_error("Back subst failure");
    }
    return x;
}

Vector classical_gaussian_elimination(Matrix A, Vector b)
{
    classical_elimination(A, b);
    return back_substitution(A, b);
}

Vector operator*(const Matrix& m, const Vector& u)
{
    const auto n = m.size();
    Vector v(n);
    for (auto i = 0; i < n; ++i)
        v[i] = std::inner_product(m[i].begin(), m[i].end(), u.begin(), 0);
    return v;
}

int main()
try {
    // 2x2 Matrix, 2x1 Vector
    Matrix A1 { { 2, -5 }, { -2, 4 } };
    Vector b1 { 7, -6 };

    std::cout << A1 << '\n';
    std::cout << b1 << '\n';

    Vector x1 = classical_gaussian_elimination(A1, b1);
    std::cout << "classical elim solution is x = " << x1 << '\n';
    Vector v1 = A1 * x1;
    std::cout << "A*x = " << v1 << "\n\n";

    // 3x3 Matrix, 3x1 Vector
    Matrix A2 {{1, 1, 2}, {-1, -2, 3}, {3, -7, 4}};
    Vector b2 {8, 1, 10};

    std::cout << A2 << '\n';
    std::cout << b2 << '\n';

    Vector x2 = classical_gaussian_elimination(A2, b2);
    std::cout << "classical elim solution is x = " << x2 << '\n';
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

