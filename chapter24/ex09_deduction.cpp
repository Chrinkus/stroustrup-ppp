//
// Stroustrup - Programming Principles & Practice
//
// Chapter 24 Exercise 9
//
// Rewrite the nonmember apply() funcitons to return a Matrix of the return
// type of the function applied.
//

#include <iostream>
#include <stdexcept>
#include <vector>
#include <numeric>
#include <complex>
#include "../text_lib/Matrix.h"
#include "../text_lib/MatrixIO.h"

using namespace Numeric_lib;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// vector testing

// returns int
template<typename C> struct Always_7 {
    int operator()(C c) { return 7; }
};

// returns char
template<typename C> struct Always_z {
    char operator()(C c) { return 'z'; }
};

// returns std::vector<double>
template<typename C> struct Triple_all {
    auto operator()(const C& v)
    {
        std::vector<double> vv;
        for (const auto& d : v)
            vv.push_back(d * 3);
        return vv;
    }
};

// returns double
template<typename C> class Triple_sum {
    public:
        Triple_sum(double d) : init{d} { }
        auto operator()(const C& c) 
        {
            return std::accumulate(c.begin(), c.end(), init,
                    [](double a, double b) { return a += b * 3; });
        }
    private:
        double init;
};

// returns complex<double>
struct Get_complex {
    std::complex<double> operator()(const std::vector<double>& vd)
    {
        std::complex<double> z {0, 0};
        for (auto i = 0; i < vd.size(); i += 2) {
            z += std::complex<double>{vd[i], vd[i+1]};
        }
        return z;
    }
};

template<typename F, typename C> auto my_apply(F f, C c)
{
    return f(c);
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Matrix implementation

template<typename T> class Make_complex {
    public:
        Make_complex(T t) : init{t} { }
        std::complex<T> operator()(const T& t)
        {
            return std::complex<T>{t,init++};
        }
    private:
        T init;
};

template<typename T> class Alpha {
    public:
        char operator()(const T& t) { return alph++; }
    private:
        char alph = 'a';
};

template<typename F, typename A>
auto my_matrix_apply(F f, A x)
{
    Matrix<decltype(f(x(0)))> res(x.size());

    for (auto i = 0; i < x.size(); ++i)
        res.data()[i] = f(x.data()[i]);

    return xfer(res);
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

int main()
try {
    std::vector<double> vd { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };

    auto x1 = my_apply(Always_7<std::vector<double>>(), vd);
    std::cout << "is it 7? " << x1 << '\n';
    auto x2 = my_apply(Always_z<std::vector<double>>(), vd);
    std::cout << "is it z? " << x2 << '\n';

    auto x3 = my_apply(Triple_all<std::vector<double>>(), vd);
    std::cout << "is it a vector of doubles? ";
    for (const auto& a : x3)
        std::cout << a << ' ';
    std::cout << '\n';

    auto x4 = my_apply(Triple_sum<std::vector<double>>(0.0), vd);
    std::cout << "is it a double? " << x4 << '\n';

    auto x5 = my_apply(Triple_sum<std::vector<double>>(1000), vd);
    std::cout << "is it a big double? " << x5 << '\n';

    auto x6 = my_apply(Get_complex(), vd);
    std::cout << "is it complex? " << x6 << '\n';

    Numeric_lib::Matrix<double> m1 (vd.data(), (int)vd.size());
    auto m2 = my_matrix_apply(Make_complex<double>(0.0), m1);
    auto m3 = my_matrix_apply(Alpha<double>(), m1);

    std::cout << m1 << '\n';
    std::cout << m2 << '\n';
    std::cout << m3 << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

