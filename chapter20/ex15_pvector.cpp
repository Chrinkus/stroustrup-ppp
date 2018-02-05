//
// Stroustrup - Programming Principles & Practice
//
// Chapter 20 Exercise 15
//
// Define a pvector to be like a vector of pointers and destructs objects it
// points to.
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
// pvector - a vector of pointers
template<typename T, typename A = allocator<T>>     // requires Element<T>()
class pvector {
public:
    using size_type = unsigned long;
    using value_type = T;
    using iterator = T*;
    using const_iterator = const T*;

    // Default constructor
    pvector() : sz{0}, elem{nullptr}, space{0} { }

    // explicit single arg constructor
    explicit pvector(size_type n) : sz{n}, space{n}
    {
        elem = alloc.allocate(sz);
        for (iterator it = begin(); it != end(); ++it)
            alloc.construct(it, nullptr);
    }

    // initializer list construction
    pvector(std::initializer_list<value_type> lst)
        : sz{lst.size()}, space{lst.size()}
    {
        elem = alloc.allocate(sz);
        std::copy(lst.begin(), lst.end(), elem);
    }

    ~pvector()
    {
        for (iterator it = begin(); it != end(); ++it) delete *it;
        alloc.deallocate(elem);
    }

    // iterators
    iterator begin() { return elem; }
    const_iterator begin() const { return elem; }
    iterator end() { return elem + sz; }
    const_iterator end() const { return elem + sz; }

    // skipping random access for now
    T& operator[](int n) { return elem[n]; }
    const T& operator[](int n) const { return elem[n]; }

    size_type size() const { return sz; }
    size_type capacity() const { return space; }

    void reserve(size_type);
    void push_back(const T&);
    void resize(size_type, T def = T());
private:
    size_type sz;
    value_type* elem;
    size_type space;
    A alloc;
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// growth
template<typename T, typename A>
void pvector<T,A>::reserve(size_type newalloc)
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
void pvector<T,A>::push_back(const value_type& val)
{
    if (space == 0) reserve(8);
    else if (sz == space) reserve(2 * space);
    alloc.construct(&elem[sz], val);
    ++sz;
}

template<typename T, typename A>
void pvector<T,A>::resize(size_type newsize, value_type val)
{
    reserve(newsize);
    for (size_type i = sz; i < newsize; ++i) alloc.construct(&elem[i], val);
    for (size_type i = newsize; i < sz; ++i) alloc.destroy(&elem[i]);
    sz = newsize;
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

template<typename T>
void print(const pvector<T>& pv)
{
    for (auto a : pv)
        if (a != nullptr)
            std::cout << *a << ' ';
    std::cout << '\n';
}

int main()
try {
    std::cout << "Exercise 15 - pvector\n";

    pvector<int*> pvi1;
    pvector<int*> pvi2 (3);
    pvector<int*> pvi3 {
        new int{1}, new int{1}, new int{2}, new int{3}, new int{5}, new int{8}
    };

    pvi2[0] = new int{37};
    pvi2[1] = new int{10};
    pvi2[2] = new int{2};
    
    std::cout << "size of default pvector: " << pvi1.size() << '\n';
    std::cout << "size of explicit pvector: " << pvi2.size() << '\n';
    std::cout << "size of init_list pvector: " << pvi3.size() << '\n';

    print(pvi1);
    print(pvi2);
    print(pvi3);

    pvector<Test_type*> pvtt1;
    pvector<Test_type*> pvtt2 (4);
    pvector<Test_type*> pvtt3 {
        new Test_type{"redbone"},
        new Test_type{"mac book pro"},
        new Test_type{"New England Patriots"},
        new Test_type{"X Box One X"}
    };

    pvtt3.push_back(new Test_type{"Thursday's coming!"});

    print(pvtt1);
    print(pvtt2);
    print(pvtt3);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

