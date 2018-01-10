//
// Stroustrup - Programming Principles & Practice
//
// Chapter 19 Exercise 8
//
// Implement an allocator using malloc() and free(). Get vector as of 19.4 to
// work for a few cases.
//
// Chapter 19 Exercise 9
//
// Re-implement vector::operator=() using an allocator
//

/*
// example from 19.3.7
template<typename T> class allocator {
public:
    // ...
    T* allocate(int n);             // allocate space for n objects of type T
    void deallocate(T* p, int n);   // deallocate n objects of type T starting
                                    // at p

    void construct(T* p, const T& v);   // construct a T with the value v in p
    void destroy(T* p);                 // destroy the T in p
};
*/

#include <iostream>
#include <stdexcept>
#include <algorithm>

struct Car {
    int wheels;
    double engine;
    char model;

    Car(int w = 4, double e = 2.2, char m = 'x')
        : wheels{w}, engine{e}, model{m} { }

    ~Car() { wheels = 0; engine = 0; model = 0; }
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

template<typename T> class allocator {
public:
    T* allocate(int n) { return (T*) malloc(n * sizeof(T)); }
    void deallocate(T* p) { free(p); }      // knows size of allocated block

    void construct(T* p, const T& v) { new(p) T{v}; }   // placement new
    void destroy(T* p) { p->~T(); }         // explicit call to destructor
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

template<typename T, typename A = allocator<T>>
class vector {
    A alloc;        // use allocator to handle memory for elements
    int sz;
    T* elem;
    int space;
public:
    vector() : sz{0}, elem{nullptr}, space{0} { }
    explicit vector(int s) : sz{s}, elem{new T[s]}, space{s}
    {
        for (int i = 0; i < sz; ++i) elem[i] = 0;
    }

    vector(const vector& a)                 // copy constructor
        : sz{a.sz}, elem{new T[a.sz]}, space{a.sz}
    {
        for (int i = 0; i < a.sz; ++i)
            elem[i] = a.elem[i];
    }
    // Exercise 9
    vector& operator=(const vector& a)          // copy assignment
    {
        T* p = alloc.allocate(a.sz);            // allocate new space
        for (int i = 0; i < a.sz; ++i)
            alloc.construct(&p[i], a.elem[i]);  // copy elements
        alloc.deallocate(elem);                 // deallocate old space
        space = sz = a.sz;
        elem = p;
        return *this;
    }

    vector(vector&& a)                      // move constructor
        : sz{a.sz}, elem{a.elem}, space{a.space}
    {
        a.sz = 0;
        a.elem = nullptr;
    }
    vector& operator=(vector&& a)           // move assignment
    {
        delete[] elem;                      // deallocate old space
        elem = a.elem;                      // copy a's members
        sz = a.sz;
        space = a.sz;
        a.elem = nullptr;                   // make a the empty vector
        a.sz = 0;
        a.space = 0;
        return *this;
    }

    ~vector() { delete[] elem; }            // destructor

    T& at(int n);                           // checked access
    const T& at(int n) const;               // checked access

    T& operator[](int n) { return elem[n]; }
    const T& operator[](int n) const { return elem[n]; }

    int size() const { return sz; }
    int capacity() const { return space; }

    void reserve(int newalloc);
    void push_back(const T& d);
    void resize(int newsize, T val = T());
};

template<typename T, typename A> T& vector<T,A>::at(int n)
{
    if (n < 0 || sz <= n)
        throw std::range_error("out of range vector access");
    return elem[n];
}

template<typename T, typename A> const T& vector<T,A>::at(int n) const
{
    if (n < 0 || sz <= n)
        throw std::range_error("out of range vector access");
    return elem[n];
}

template<typename T, typename A>
void vector<T,A>::reserve(int newalloc)
{
    if (newalloc <= space) return;          // never decrease allocation
    T* p = alloc.allocate(newalloc);        // allocate new space
    for (int i = 0; i < sz; ++i) alloc.construct(&p[i], elem[i]);   // copy
    for (int i = 0; i < sz; ++i) alloc.destroy(&elem[i]);           // destroy
    alloc.deallocate(elem);                 // deallocate old space
    elem = p;
    space = newalloc;
}

template<typename T, typename A>
void vector<T,A>::push_back(const T& val)
{
    if (space == 0) reserve(8);             // start with space for 8 elements
    else if (sz == space) reserve(2 * space);   // get more space
    alloc.construct(&elem[sz], val);
    ++sz;
}

template<typename T, typename A>
void vector<T,A>::resize(int newsize, T val)
{
    reserve(newsize);
    for (int i = sz; i < newsize; ++i) alloc.construct(&elem[i], val);
    for (int i = newsize; i < sz; ++i) alloc.destroy(&elem[i]);
    sz = newsize;
}

int main()
try {
    const int sz = 3;
    /*
    allocator<Car> alloc;
    Car* p = alloc.allocate(sz);

    alloc.construct(p, Car{3, 1.8, 'd'});
    alloc.construct(&p[1], Car{});
    alloc.construct(&p[2], Car{18, 4.8, 'a'});

    for (int i = 0; i < sz; ++i)
        std::cout << &p[i] << ' ' << p[i].wheels << '\n';
    std::cout << '\n';

    alloc.destroy(p);

    for (int i = 0; i < sz; ++i)
        std::cout << &p[i] << ' ' << p[i].wheels << '\n';

    alloc.deallocate(p);
    */

    vector<int> v1(sz);
    v1[0] = 37;
    v1[1] = 108;

    for (int i = 0; i < v1.size(); ++i)
        std::cout << v1[i] << ' ';
    std::cout << '\n';

    v1.push_back(9);
    v1.push_back(52);
    v1.push_back(71);
    v1.push_back(28);

    for (int i = 0; i < v1.size(); ++i)
        std::cout << v1[i] << ' ';
    std::cout << '\n';

    v1.resize(20);

    for (int i = 0; i < v1.size(); ++i)
        std::cout << v1[i] << ' ';
    std::cout << '\n';

    v1.resize(3);

    for (int i = 0; i < v1.size(); ++i)
        std::cout << v1[i] << ' ';
    std::cout << '\n';

    std::cout << v1.at(100) << '\n';            // should throw

    vector<int>v2 = v1;
    v2.push_back(204);

    for (int i = 0; i < v2.size(); ++i)
        std::cout << v2[i] << ' ';
    std::cout << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

