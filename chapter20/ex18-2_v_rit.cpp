//
// Stroustrup - Programming Principles & Practice
//
// Chapter 20 Exercise 18
//
// Define a range-checked iterator for vector (random-access)
//
// Range checks:
// - cannot increment or decrement beyond [begin:end)
// - cannot subscript beyond [begin:end)
// - cannot derefence end

#include <iostream>
#include <stdexcept>
#include <string>

template<typename T>
class vector {
public:
    using size_type = unsigned long;
    using value_type = T;

    vector() : sz{0}, space{0}, elem{nullptr} { }

    explicit vector(size_type n)
        : sz{n}, space{n}, elem{new T[n]}
    {
        for (auto it = begin(); it != end(); ++it) *it = T{0};
    }

    vector(std::initializer_list<T> il)
        : sz{il.size()}, space{il.size()}, elem{new T[il.size()]}
    {
        std::copy(il.begin(), il.end(), elem);
    }

    ~vector() { delete[] elem; }

    class iterator;

    iterator begin() { return iterator(elem, *this); }
    const iterator begin() const { return iterator(elem, *this); }
    iterator end() { return iterator(elem + sz, *this); }
    const iterator end() const { return iterator(elem + sz, *this); }

    T& operator[](int n) { return elem[n]; }
    const T& operator[](int n) const { return elem[n]; }

    size_type size() const { return sz; }

private:
    size_type sz;
    size_type space;
    value_type* elem;
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// range-checking iterator
template<typename T>
class vector<T>::iterator {
    T* curr;
    const vector<T>& vec;
public:
    iterator(T* p) : curr{p} { }

    iterator(T* p, const vector<T>& v)
        : curr{p}, vec{v} { }

    iterator& operator++();
    iterator& operator--();

    T& operator*();
    const T& operator*() const;

    T& operator[](int);
    const T& operator[](int) const;

    bool operator==(const iterator& b) const { return curr == b.curr; }
    bool operator!=(const iterator& b) const { return curr != b.curr; }
};

template<typename T>
typename vector<T>::iterator& vector<T>::iterator::operator++()
{
    if (*this == vec.end())
        throw std::out_of_range("Range Error: ++end");
    ++curr;
    return *this;
}

template<typename T>
typename vector<T>::iterator& vector<T>::iterator::operator--()
{
    if (*this == vec.begin())
        throw std::out_of_range("Range Error: --begin");
    --curr;
    return *this;
}

template<typename T> T& vector<T>::iterator::operator*()
{
    if (*this == vec.end())
        throw std::out_of_range("Range Error: *end");
    return *curr;
}

template<typename T> const T& vector<T>::iterator::operator*() const
{
    if (*this == vec.end())
        throw std::out_of_range("Range Error: *end");
    return *curr;
}

template<typename T> T& vector<T>::iterator::operator[](int n)
{
    auto p = curr + n;
    if (p < vec.begin().curr || vec.end().curr <= p)
        throw std::out_of_range("Range Error: []");
    return curr[n];
}

template<typename T> const T& vector<T>::iterator::operator[](int n) const
{
    auto p = curr + n;
    if (p < vec.begin().curr || vec.end().curr <= p)
        throw std::out_of_range("Range Error: []");
    return curr[n];
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
template<typename T> void print(const vector<T>& v, char sep = ' ')
{
    for (const auto a : v)
        std::cout << a << sep;
    std::cout << '\n';
}

int main()
try {
    vector<std::string> vs1;
    vector<std::string> vs2 (3);
    vector<std::string> vs3 { "Resident Evil", "Dead Rising", "Bioshock",
            "Gears of War", "Crackdown"};

    std::cout << "Empty vec size: " << vs1.size() << '\n';
    std::cout << "Default vec size: " << vs2.size() << '\n';
    std::cout << "Init_list vec size: " << vs3.size() << '\n';

    print(vs1);
    print(vs2);
    print(vs3);

    std::cout << "Default init: " << vs2[1] << '\n';

    auto ss_it = vs3.begin();
    std::cout << "Iter []: " << ss_it[2] << '\n';

    try {
        auto it = vs3.begin();
        --it;
    } catch (std::out_of_range& e) {
        std::cout << e.what() << '\n';
    }

    try {
        auto it = vs3.end();
        ++it;
    } catch (std::out_of_range& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        auto it = vs3.end();
        std::cout << *it << '\n';
    } catch (std::out_of_range& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        auto it = vs3.begin();
        std::cout << it[37] << '\n';
    } catch (std::out_of_range& e) {
        std::cerr << e.what() << '\n';
    }
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

