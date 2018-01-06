//
// Stroustrup - Programming Principles & Practice
//
// Chapter 19 Exercise 6
//
// Define a template class Number<T> with all of the functionality of ex05. Try
// to add % and see what happens when Number<double> % Number<int>
//
// Chapter 19 Exercise 7
//
// Try ex02 solution (product_sum()) with vectors of Number<T>'s
//

#include <iostream>
#include <stdexcept>
#include <vector>

template<class T> class Number {
    T val;
public:
    Number(T value = 0) : val{value} { }

    T get() const { return val; }

    T& operator=(const T& value) { val = value; return *this; }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Number<T>& n)
{
    return os << n.get();
}

template<typename T>
std::istream& operator>>(std::istream& is, Number<T>& n)
{
    T x;
    is >> x;
    Number<T> nn {x};
    n = nn;
    return is;
}

template<typename T, typename U>
Number<T> operator+(const Number<T>& t, const Number<U>& u)
{
    return t.get() + u.get();
}

template<typename T, typename U>
Number<T> operator-(const Number<T>& t, const Number<U>& u)
{
    return t.get() - u.get();
}

template<typename T, typename U>
Number<T> operator*(const Number<T>& t, const Number<U>& u)
{
    return t.get() * u.get();
}

template<typename T, typename U>
Number<T> operator/(const Number<T>& t, const Number<U>& u)
{
    return t.get() / u.get();
}

template<typename T, typename U>
Number<T> operator%(const Number<T>& t, const Number<U>& u)
{
    return int(t.get()) % int(u.get());
}

template<typename T, typename U>
void operator+=(Number<T>& t, const Number<U>& u)
{
    int x = t.get() + u.get();
    Number<T> tt {x};
    t = tt;
}

// ex02
template<typename T, typename U>
T product_sum(std::vector<T>& vt, std::vector<U>& vu)
{
    if (vt.size() != vu.size())
        throw std::runtime_error("cannot sum different sized vectors");

    T sum {0};
    for (int i = 0; i < vt.size(); ++i) sum += vt[i] * vu[i];

    return sum;
}

int main()
try {
    /*
    Number<int> age {38};
    Number<double> pi {3.14159};

    std::cout << "Number<int> : " << age << '\n';
    std::cout << "Number<double> : " << pi << '\n';

    std::cout << "Enter an integer: ";
    Number<int> ni;
    std::cin >> ni;
    std::cout << "You entered: " << ni << '\n';

    std::cout << "Integer add: " << age + ni << '\n';
    std::cout << "Double add: " << pi + ni << '\n';
    std::cout << "Integer sub: " << age - ni << '\n';
    std::cout << "Double sub: " << pi - ni << '\n';
    std::cout << "Integer mul: " << age * ni << '\n';
    std::cout << "Double mul: " << pi * ni << '\n';
    std::cout << "Integer div: " << age / ni << '\n';
    std::cout << "Double div: " << pi / ni << '\n';
    std::cout << "Integer mod: " << age % ni << '\n';
    std::cout << "Double mod: " << pi % ni << '\n';
    */

    // ex07
    std::vector<Number<int>> vni1 {1, 2, 3, 4};
    std::vector<Number<int>> vni2 {2, 4, 6, 8};

    Number<int> ni2 = product_sum(vni1, vni2);
    std::cout << ni2 << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

