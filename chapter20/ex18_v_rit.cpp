//
// Stroustrup - Programming Principles & Practice
//
// Chapter 20 Exercise 18
//
// Define a range-checked iterator for vector (random-access)
//

#include <iostream>
#include <stdexcept>
#include <string>

template<typename T>
class vector {
public:
    using size_type = unsigned long;
    using value_type = T;
    //using iterator = T*;
    //using const_iterator = const T*;

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

    iterator begin() { return iterator(elem, elem, sz); }
    const iterator begin() const { return iterator(elem, elem, sz); }
    iterator end() { return iterator(elem + sz, elem, sz); }
    const iterator end() const { return iterator(elem + sz, elem, sz); }

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
    T* first;
    T* last;
public:
    iterator(T* p, T* elem, vector<T>::size_type sz)
        : curr{p}, first{elem}, last{elem + sz} { }

    iterator& operator++();
    iterator& operator--();

    T& operator*() { return *curr; }
    const T& operator*() const { return *curr; }

    bool operator==(const iterator& b) const { return curr == b.curr; }
    bool operator!=(const iterator& b) const { return curr != b.curr; }
};

template<typename T>
typename vector<T>::iterator& vector<T>::iterator::operator++()
{
    if (curr == last) throw std::out_of_range("vector<T>::iterator");
    ++curr;
    return *this;
}

template<typename T>
typename vector<T>::iterator& vector<T>::iterator::operator--()
{
    if (curr == first) throw std::out_of_range("vector<T>::iterator");
    --curr;
    return *this;
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

    try {
        auto it = vs3.begin();
        --it;
    } catch (std::out_of_range) {
        std::cout << "decrementing from begin throws error!\n";
    }

    try {
        auto it = vs3.end();
        ++it;
    } catch (std::out_of_range) {
        std::cout << "incrementing from end throws error!\n";
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

