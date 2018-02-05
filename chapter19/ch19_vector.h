#include <iostream>
#include <stdexcept>

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
// 19.4 vector
template<typename T, typename A = allocator<T>>
class vector {
    int sz;
    T* elem;
    int space;
    A alloc;
public:
    vector() : sz{0}, elem{nullptr}, space{0}
    {
        std::cout << "default constructor called!\n";
    }

    explicit vector(int n) : sz{n}, elem{nullptr}, space{n}
    {
        std::cout << "explicit constructor called!\n";
        elem = alloc.allocate(n);
        for (T* p = elem; p != elem + n; ++p) alloc.construct(p, 0);
    }

    vector(const vector&);                      // copy constructor
    vector& operator=(const vector&);           // copy assignment

    vector(vector&&);                           // move constructor
    vector& operator=(vector&&);                // move assignment

    ~vector()                                   // destructor
    {
        std::cout << "destructor called!\n";
        for (T* p = elem; p != elem + sz; ++p) alloc.destroy(p);
        alloc.deallocate(elem);
    }

    T& at(int);                                 // checked access
    const T& at(int) const;     

    T& operator[](int n) { return elem[n]; }    // unchecked access
    const T& operator[](int n) const { return elem[n]; }

    int size() const { return sz; }
    int capacity() const { return space; }

    void reserve(int);                          // growth
    void push_back(const T&);
    void resize(int, T val = T());
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// copy operations
template<typename T, typename A> vector<T,A>::vector(const vector<T,A>& v)
    : sz{v.sz}, elem{nullptr}, space{v.sz}
{
    std::cout << "copy constructor called!\n";
    elem = alloc.allocate(v.sz);
    std::copy(v.elem, v.elem + v.sz, elem);
}

template<typename T, typename A>
vector<T,A>& vector<T,A>::operator=(const vector<T,A>& v)
{
    std::cout << "copy assignment called!\n";
    if (this == &v) return *this;       // check for self-assignment

    if (v.sz <= space) {                // check if already have enough space
        for (int i = 0; i < v.sz; ++i) elem[i] = v.elem[i];
        for (int i = v.sz; i < sz; ++i) alloc.destroy(&elem[i]);
        sz = v.sz;
        return *this;
    }

    T* p = alloc.allocate(v.sz);        // general solution
    std::copy(v.elem, v.elem + v.sz, p);
    for (T* q = elem; q != elem + sz; ++q) alloc.destroy(q);
    alloc.deallocate(elem);
    space = sz = v.sz;
    elem = p;
    return *this;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// move operations
template<typename T, typename A> vector<T,A>::vector(vector<T,A>&& v)
    : sz{v.sz}, elem{v.elem}, space{v.space}
{
    std::cout << "move constructor called!\n";
    v.sz = 0;
    v.elem = nullptr;
}

template<typename T, typename A>
vector<T,A>& vector<T,A>::operator=(vector<T,A>&& v)
{
    std::cout << "move assignment called!\n";
    for (T* p = elem; p != elem + sz; ++p) alloc.destroy(p);
    alloc.deallocate(elem);
    elem = v.elem;
    sz = v.sz;
    space = v.space;
    v.sz = 0;
    v.elem = nullptr;
    return *this;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// range checking
template<typename T, typename A> T& vector<T,A>::at(int n)
{
    if (n < 0 || sz < n) throw std::out_of_range("");
    return elem[n];
}

template<typename T, typename A> const T& vector<T,A>::at(int n) const
{
    if (n < 0 || sz < n) throw std::out_of_range("");
    return elem[n];
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// growth
template<typename T, typename A>
void vector<T,A>::reserve(int newalloc)
{
    if (newalloc <= space) return;      // never decrease allocation
    T* p = alloc.allocate(newalloc);    // allocate new space
    for (int i = 0; i < sz; ++i) alloc.construct(&p[i], elem[i]);   // copy
    for (int i = 0; i < sz; ++i) alloc.destroy(&elem[i]);           // destroy
    alloc.deallocate(elem);             // deallocate old space
    elem = p;
    space = newalloc;
}

template<typename T, typename A>
void vector<T,A>::push_back(const T& val)
{
    if (space == 0) reserve(8);         // start with space for 8 elements
    else if (sz == space) reserve(2 * space);   //get more space
    alloc.construct(&elem[sz], val);            // add val at end
    ++sz;                                       // increase size
}

template<typename T, typename A>
void vector<T,A>::resize(int newsize, T val)
{
    reserve(newsize);
    for (int i = sz; i < newsize; ++i) alloc.construct(&elem[i], val);
    for (int i = newsize; i < sz; ++i) alloc.destroy(&elem[i]);
    sz = newsize;
}

