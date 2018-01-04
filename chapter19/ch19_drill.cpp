#include <iostream>
#include <string>
#include <vector>

template<typename T>
struct S {
    explicit S(T vv = 0) : val{vv} { }

    S& operator=(const T&);

    T& get();
    const T& get() const;
    //void set(T new_t) { val = new_t; }

private:
    T val;
};

template<typename T>
T& S<T>::get()
{
    return val;
}

template<typename T>
const T& S<T>::get() const
{
    return val;
}

template<typename T>
S<T>& S<T>::operator=(const T& s)
{
    val = s;
    return *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& v)
{
    os << "{ ";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i] << (i < v.size() - 1 ? ", " : " ");
    }
    os << "}\n";

    return os;
}

template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v)
{
    char ch = 0;
    is >> ch;
    if (ch != '{') {
        is.unget();
        return is;
    }

    for (T val; is >> val; ) {
        v.push_back(val);
        is >> ch;
        if (ch != ',') break;
    }

    return is;
}

template<typename T> void read_val(T& v)
{
    std::cin >> v;
}

int main()
{
    S<int> si {37};
    S<char> sc {'c'};
    S<double> sd {10.2};
    S<std::string> s {"Howdy"};
    S<std::vector<int>> svi { std::vector<int>{1, 1, 2, 3, 5, 8}};

    std::cout << "S<int> : " << si.get() << '\n'
              << "S<char> : " << sc.get() << '\n'
              << "S<double> : " << sd.get() << '\n'
              << "S<string> : " << s.get() << '\n'
              << "S<vector<int>> : " << svi.get() << '\n';

    /*
    std::cout << "S<vector<int>> : ";
    for (auto& a : svi.get())
        std::cout << a << ' ';
    std::cout << '\n';
    */

    /*
    sc.set('s');
    std::cout << "S<char> : " << sc.get() << '\n';
    */

    sd = 3.14159;
    std::cout << "S<double> : " << sd.get() << '\n';

    std::cout << "Reads:\n";

    /*
    std::cout << "Integer: ";
    int ii;
    read_val(ii);
    S<int> si2 {ii};

    std::cout << "Char: ";
    char cc;
    read_val(cc);
    S<char> sc2 {cc};

    std::cout << "Double: ";
    double dd;
    read_val(dd);
    S<double> sd2 {dd};

    std::cout << "String: ";
    std::string ss;
    read_val(ss);
    S<std::string> s2 {ss};

    std::cout << "S<int> read: " << si2.get() << '\n';
    std::cout << "S<char> read: " << sc2.get() << '\n';
    std::cout << "S<double> read: " << sd2.get() << '\n';
    std::cout << "S<string> read: " << s2.get() << '\n';
    */
    std::cout << "Vector<int>: (format: { val1, val2, val3 }) ";
    std::vector<int> vi2;
    read_val(vi2);
    S<std::vector<int>> svi2 {vi2};

    std::cout << "S<vector<int>> read: " << svi2.get() << '\n';
}
