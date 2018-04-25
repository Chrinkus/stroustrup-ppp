//
// Stroustrup - Programming Principles & Practice
//
// Chapter 25 Exercise 14
//
// Attempt 2: Just make a simple vector that owns a pool of memory to allocate
// from.
//
// Implement a simple vector that can hold at most N elements allocated from a
// pool. Test with N = 1000 and integer elements.
// 

#include <iostream>
#include <stdexcept>

template<typename T, unsigned long N>
class Pool {
    public:
        using size_type = unsigned long;

        Pool() : pool{new T[N]}, in_use{0} { }
        T* get() { return &pool[in_use++]; }
        void free(T*) { --in_use; }
        size_type available() const { return N - in_use; }
    private:
        T* pool;
        size_type in_use;
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

class Bad_size { };

template<typename T, unsigned long N>
class Vector {
    public:
        using size_type = unsigned long;
        using value_type = T;

        Vector() : sz{0}, elem{nullptr} { }
        explicit Vector(size_type n) : sz{0}, elem{nullptr}
        {
            if (n > N) throw Bad_size{};
            for (auto i = 0; i < n; ++i) push_back(T{0});
        }

        void push_back(T);
        void pop_back();

        T& operator[](size_type n) { return elem[n]; }
        const T& operator[](size_type n) const { return elem[n]; }

        size_type size() const { return sz; }
    private:
        size_type sz;
        T* elem;
        Pool<T,N> alloc;
};

template<typename T, unsigned long N>
void Vector<T,N>::push_back(T t)
{
    if (sz == N)
        throw Bad_size{};

    auto p = alloc.get();

    if (!elem) elem = p;

    *p = t;
    ++sz;
}

template<typename T, unsigned long N>
void Vector<T,N>::pop_back()
{
    elem[sz-1] = 0;
    --sz;
    alloc.free(&elem[sz-1]);
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

template<typename T, unsigned long N>
void print(const Vector<T,N>& v)
{
    for (auto i = 0; i < v.size(); ++i)
        std::cout << v[i] << ' ';
    std::cout << '\n';
}

int main()
try {
    std::cout << "Default constructor w/push_backs\n";
    Vector<int,10> v1;
    v1.push_back(2);
    v1.push_back(37);
    print(v1);

    std::cout << "Pop back off Vector\n";
    v1.pop_back();
    print(v1);

    std::cout << "Push back again\n";
    v1.push_back(10);
    print(v1);

    std::cout << "Size constructor 3\n";
    Vector<double,5> v2 (3);
    print(v2);

    std::cout << "Pushing into size constructor\n";
    v2.push_back(7.2);
    print(v2);

    /*
    Vector<char,10> v_err1 (15);
    Vector<char,3> v_err2;
    v_err2.push_back('a');
    v_err2.push_back('b');
    v_err2.push_back('c');
    v_err2.push_back('d');
    */

    Vector<int,1000> v3;
    for (auto i = 0; i < 1000; ++i)
        v3.push_back(i);

    print(v3);
}
catch(Bad_size) {
    std::cerr << "Attempted to increase Vector beyond size of pool\n";
    return 3;
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

