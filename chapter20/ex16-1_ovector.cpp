//
// Stroustrup - Programming Principles & Practice
//
// Chapter 20 Exercise 16
//
// Define an ovector to be just like ovector except that the access operators
// return a reference to the object pointed at.
//

#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include "./ch20_test_type.h"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// 19.3.7 allocator
template<typename T> class allocator {
public:
    T* allocate(int n) { return (T*) malloc(n * sizeof(T)); }
    void deallocate(T* p) { free(p); }

    void construct(T* p, const T& v) { new(p) T{v}; }
    void destroy(T* p) { p->~T(); }
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// ovector - a vector of pointers
template<typename T, typename A = allocator<T*>>    // requires Element<T>()
class ovector {
public:
    using size_type = unsigned long;
    using value_type = T;
    using iterator = T**;
    using const_iterator = const T**;

    // Default constructor
    ovector() : sz{0}, elem{nullptr}, space{0} { }

    // explicit single arg constructor
    explicit ovector(size_type n) : sz{n}, space{n}
    {
        elem = alloc.allocate(sz);
        for (iterator it = begin(); it != end(); ++it)
            alloc.construct(it, new char{'a'});
    }

    /*
    // initializer list construction
    ovector(std::initializer_list<value_type> lst)
        : sz{lst.size()}, space{lst.size()}
    {
        elem = alloc.allocate(sz);
        std::copy(lst.begin(), lst.end(), elem);
    }

    ~ovector()
    {
        for (iterator it = begin(); it != end(); ++it) delete *it;
        alloc.deallocate(elem);
    }
    */

    // iterators
    iterator begin() { return elem; }
    const_iterator begin() const { return elem; }
    iterator end() { return elem + sz; }
    const_iterator end() const { return elem + sz; }

    /*
    // skipping random access for now
    T& operator[](int n) { return elem[n]; }
    const T& operator[](int n) const { return elem[n]; }

    void reserve(size_type);
    void push_back(const T&);
    void resize(size_type, T def = T());
    */

    size_type size() const { return sz; }
    size_type capacity() const { return space; }
private:
    size_type sz;
    value_type** elem;
    size_type space;
    A alloc;
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// growth
/*
template<typename T, typename A>
void ovector<T,A>::reserve(size_type newalloc)
{
    if (newalloc <= space) return;
    value_type* p = alloc.allocate(newalloc);
    for (size_type i = 0; i < sz; ++i) alloc.construct(&p[i], elem[i]);
    for (iterator it = begin(); it != end(); ++it) alloc.destroy(it);
    alloc.destroy(elem);
    elem = p;
    space = newalloc;
}

template<typename T, typename A>
void ovector<T,A>::push_back(const value_type& val)
{
    if (space == 0) reserve(8);
    else if (sz == space) reserve(2 * space);
    alloc.construct(&elem[sz], val);
    ++sz;
}

template<typename T, typename A>
void ovector<T,A>::resize(size_type newsize, value_type val)
{
    reserve(newsize);
    for (size_type i = sz; i < newsize; ++i) alloc.construct(&elem[i], val);
    for (size_type i = newsize; i < sz; ++i) alloc.destroy(&elem[i]);
    sz = newsize;
}
*/
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

template<typename T>
void print(const ovector<T>& ov)
{
    for (auto it = ov.begin(); it != ov.end(); ++it)
        std::cout << *it << ' ';
    std::cout << '\n';
}

int main()
try {
    std::cout << "Exercise 16 - ovector\n";

    ovector<char> oc1;
    ovector<char> oc2 (10);
    //ovector<char> oc3 { 'o', 't', 't', 'a', 'w', 'a' };
    
    std::cout << "Empty ovector size: " << oc1.size() << '\n';
    std::cout << "Default value ovector size: " << oc2.size() << '\n';

    print(oc2);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

