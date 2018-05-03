//
// Stroustrup - Programming Principles & Practice
//
// Chapter 26 Exercise 11
//
// Time the sum example from §26.6 with m being square matrices of 100, 10000,
// 1000000 and 10000000. Use random element values in the range of [-10:10).
// Rewrite the calculation to use a more efficient algorithm.
// 
// My computer can handle upto a 40K x 40K Matrix. Anything else causes my
// system to freeze up with my current solutions. It's interesting that
// parallelizing the solution shows an improvement for some sets but a slow
// down for others.
//

#include <iostream>
#include <stdexcept>
#include <random>
#include <vector>
#include <chrono>
#include <string>
#include <thread>
#include <numeric>
#include "../text_lib/Matrix.h"
#include "../text_lib/MatrixIO.h"

using namespace Numeric_lib;
using namespace std::chrono;

int randint(int min, int max, unsigned int seed = 0)
{
    thread_local static std::default_random_engine ran {seed};
    return std::uniform_int_distribution<>{min, max}(ran);
}

Matrix<double,2> get_square_matrix(int dim)
{
    Matrix<double,2> m {dim, dim};

    const int low = -10;
    const int high = 9;

    for (auto i = 0; i < m.dim1(); ++i) {
        std::cout << i << ' ';
        for (auto j = 0; j < m.dim2(); ++j)
            m(i,j) = randint(low, high);
    }
    std::cout << '\n';

    return m;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Multithreaded fill
void row_fill_task(Matrix<double,2>& m, int n, unsigned int seed)
{
    const int low = -10;
    const int high = 9;

    for (auto i = 0; i < m.dim2(); ++i)
        m(n,i) = randint(low, high, seed);
}

Matrix<double,2> threaded_fill(int dim)
{
    Matrix<double,2> m {dim, dim};

    std::vector<std::thread> vt;
    for (auto i = 0; i < m.dim1(); ++i)
        vt.push_back(std::thread{row_fill_task, std::ref(m), i, randint(1,100)});

    for (auto& t : vt)
        t.join();

    return m;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Timer
class Make_timer {
    public:
        Make_timer() : t1{system_clock::now()} { }

        void operator()(const std::string& lab)
        {
            auto t2 = system_clock::now();

            std::cout << "  " << lab << " took "
                      << duration_cast<milliseconds>(t2 - t1).count()
                      << " milliseconds\n";
        }

        void reset() { t1 = system_clock::now(); }
    private:
        system_clock::time_point t1;
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Slow solution from chapter
double row_sum(const Matrix<double,2>& m, int n)
{
    double s = 0;
    for (auto i = 0; i < m.dim2(); ++i)
        s += m(n, i);
    return s;
}

double row_accum(const Matrix<double,2>& m, int n)
{
    double s = 0;
    for (auto i = 0; i < n; ++i)
        s += row_sum(m, i);
    return s;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Better solution
class Row_accum {
    public:
        Row_accum() : total{0}, rows{0} { }

        double operator()(const Matrix<double,2>& m, int n)
        {
            for (auto i = rows; i < n; ++i) {
                total += row_sum(m, i);
                ++rows;
            }
            return total;
        }
    private:
        double total;
        int rows;
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Multi-threaded solution
void row_accum_task(std::vector<double>& v, const Matrix<double,2>& m, int n)
{
    v[n] = std::accumulate(m.data() + m.dim2() * n,
                           m.data() + m.dim2() * (n + 1),
                           0.0);
}

void forward_sum(std::vector<double>& v)
{
    for (auto i = 1; i < v.size(); ++i)
        v[i] += v[i - 1];
}

std::vector<double> threaded_accum(const Matrix<double,2>& m)
{
    std::vector<double> vd (m.dim1());      // setting size for placement

    std::vector<std::thread> vt;
    vt.reserve(m.dim1());
    for (auto i = 0; i < m.dim1(); ++i)
        vt.push_back(std::thread{row_accum_task,
                                 std::ref(vd),
                                 std::ref(m),
                                 i});

    for (auto& t : vt)
        t.join();
    
    forward_sum(vd);
    return vd;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

int main()
try {
    const int test1 = 4000;

    Make_timer timer;
    /*
    std::cout << "Single threaded creation:\n";
    timer.reset();
    Matrix<double,2> m1 = get_square_matrix(test1);
    timer("square matrix creation");
    */

    std::cout << "Multithreaded creation:\n";
    timer.reset();
    Matrix<double,2> m2 = threaded_fill(test1);
    timer("threaded matrix creation");

    /*
    std::cout << "Slow solution:\n";
    std::vector<double> v1;
    timer.reset();
    for (auto i = 0; i < m2.dim1(); ++i) {
        v1.push_back(row_accum(m2, i + 1));
    }
    timer("slow solution");

    std::cout << v1.back() << '\n';
    */

    std::cout << "Faster solution:\n";
    Row_accum accumer;
    std::vector<double> v2;
    timer.reset();
    for (auto i = 0; i < m2.dim1(); ++i) {
        v2.push_back(accumer(m2, i + 1));
    }
    timer("faster solution?");

    std::cout << v2.back() << '\n';

    std::cout << "Fastest solution:\n";
    timer.reset();
    std::vector<double> v3 = threaded_accum(m2);
    timer("fastet solution?");

    std::cout << v3.back() << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

