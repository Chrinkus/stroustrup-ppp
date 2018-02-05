//
// Stroustrup - Programming Principles & Practice
//
// Chapter 20 Exercise 16
//
// Define an ovector that is like pvector except the access operators return a
// reference to the object pointed to, not the pointer.
//
// This attempt will not use an allocator.
//

#include <iostream>
#include <stdexcept>
#include <initializer_list>

template<typename T>
class ovector {
public:
    using size_type = unsigned long;
    using value_type = T;
    using iterator = T**;

    ovector() : sz{0}, space{0}, elem{nullptr} { }

    explicit ovector(size_type n) : sz{n}, space{n}, elem{new T*[n]}
    {
        for (iterator it = begin(); it != end(); ++it)
            *it = new T{0};
    }

    ovector(std::initializer_list<T> il)
        : sz{il.size()}, space{il.size()}, elem{new T*[il.size()]}
    {
        auto it = elem;
        for (auto a : il) {
            *it = new T{a};
            ++it;
        }
    }

    ~ovector()
    {
        for (auto it = begin(); it != end(); ++it)
            delete *it;
        delete[] elem;
    }

    T& operator[](size_type n) { return *elem[n]; }
    const T& operator[](size_type n) const { return *elem[n]; }

    iterator begin() { return elem; }
    const iterator begin() const { return elem; }
    iterator end() { return elem + sz; }
    const iterator end() const { return elem + sz; }

    size_type size() const { return sz; }
    size_type capacity() const { return space; }
private:
    size_type sz;
    size_type space;
    value_type** elem;
};

template<typename T>
void print(const ovector<T>& ov, char sep = ' ')
{
    for (const auto a : ov)
        std::cout << *a << sep;
    std::cout << '\n';
}

int main()
try {
    ovector<int> ovi1;
    ovector<int> ovi2 (4);
    ovector<int> ovi3 { 1, 1, 2, 3, 5, 8, 13 };

    std::cout << "Empty ovector sizeof: " << sizeof(ovi1) << '\n';
    std::cout << "Empty ovector size: " << ovi1.size() << '\n';
    std::cout << "Default ovector size: " << ovi2.size() << '\n';
    std::cout << "Init_list ovec size: " << ovi3.size() << '\n';

    ovi2[0] = 1979;
    ovi2[1] = 1983;
    ovi2[2] = 2013;
    ovi2[3] = 2017;

    print(ovi2);
    print(ovi3);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

