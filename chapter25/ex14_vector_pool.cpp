//
// Stroustrup - Programming Principles & Practice
//
// Chapter 25 Exercise 14
//
// Implement a simple vector that can hold at most N elements allocated from a
// pool. Test with N = 1000 and integer elements.
// 
// To manage the Pool memory I need a linked list. I will use std::list for to
// get started and implement a pool-specific list later. I realize the
// ridiculousness of using a std::list to prevent std::vector from calling
// "new".
//
// The tricky part here is that the elements of a vector are contiguous and a
// list makes it tricky to find that many continuous slots. They may all be 
// available but not next to each other anymore.
//
// UPDATE: Ok, I took this the wrong way. I thought I was making a Pool that
// a vector could allocate from but apparently the exercise is asking for a
// vector that pre-allocates its space then uses it as needed. I think.
//

#include <iostream>
#include <stdexcept>
#include <list>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

template<typename T, int N>
class Pool {
    public:
        Pool() : elem{new T[N]}
        {
            for (T* p = elem; p < elem + N; ++p)
                free_pool.push_back(p);
        }

        T* get();                   // get a T from the pool
        void free(T*);              // return a T to the pool

        T* get_block(int n);        // get n Ts from the pool
        void free_block(T*, int);   // return n Ts to the pool

        int available() const { return free_pool.size(); }
        void test() const;
    private:
        T* elem;                    // pool memory
        std::list<T*> free_pool;
        typename std::list<T*>::iterator find_contiguous(int n);
};

template<typename T, int N>
T* Pool<T,N>::get()
    // check for free T
    // capture list.front() and remove it
    // return capture
{
    if (free_pool.size()) {
        T* p = free_pool.front();
        free_pool.pop_front();
        return p;
    } else {
        return nullptr;
    }
}

template<typename T, int N>
T* Pool<T,N>::get_block(int n)
{
    auto it = find_contiguous(n);
    if (it == free_pool.end())
        return nullptr;

    auto it2 = it;
    auto p = *it;
    std::advance(it2, n);
    free_pool.erase(it, it2);
    return p;
}

template<typename T, int N>
void Pool<T,N>::free(T* p)
    // clear contents of p
    // give it back to the pool
    // IN ORDER: for vector use!
{
    *p = T{0};
    auto it = free_pool.begin();
    while (*it < p) ++it;
    free_pool.insert(it, p);
}

template<typename T, int N>
void Pool<T,N>::free_block(T* p, int n)
    // clear contents of n p's
    // return them to the pool in order
{
    auto it = free_pool.begin();
    while (*it < p) ++it;

    for (int i = n-1; i >= 0; --i) {
        p[i] = T{0};
        it = free_pool.insert(it, &p[i]);
    }
}

template<typename T, int N>
typename std::list<T*>::iterator Pool<T,N>::find_contiguous(int n)
    // for every element, check ahead n-1 elements to see if the range is
    // contiguous. std::distance is used to ensure that std::advance does not
    // leave the container's range.
{
    if (available() < n)
        return free_pool.end();

    for (auto it = free_pool.begin();
            std::distance(it, free_pool.end()) > (n-1);
            ++it) {

        auto p = it;
        std::advance(p, n-1);
        if (*it + (n-1) == *p)
            return it;
    }

    return free_pool.end();
}

template<typename T, int N>
void Pool<T,N>::test() const
{
    for (const auto& a : free_pool)
        std::cout << a << '\n';
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

/*
template<typename T, int N, typename A = Pool<T,N>>
class Vector {
    public:
        using size_type = unsigned long;
        using value_type = T;

        Vector() : sz{0}, space{0}, elem{nullptr} { }

        explicit Vector(size_type n)
            : sz{n}, space{n} , elem{nullptr}
        {
            if (alloc.available() > n)
                elem = alloc.get_block(n);
            else {
                std::cerr << "Not enough free space\n";
                sz = 0;
                space = 0;
            }
        }

    private:
        A alloc;
        size_type sz;
        size_type space;
        value_type* elem;
};
*/

int main()
try {
    Pool<int,10> i_pool;
    std::cout << "Pool available (init): " << i_pool.available() << '\n';
    i_pool.test();

    int* q1 = i_pool.get();
    *q1 = 7;
    std::cout << "One object allocated to " << q1
              << " with value " << *q1 << '\n';
    std::cout << "Pool available (get): " << i_pool.available() << '\n';

    int* q2 = i_pool.get();
    int* q3 = i_pool.get();
    int* q4 = i_pool.get();

    std::cout << "Several objects allocated to:\n"
              << q2 << ' ' << q3 << ' ' << q4 << '\n';
    //i_pool.test();
    std::cout << "Pool available (gets): " << i_pool.available() << '\n';

    int* q5 = i_pool.get();
    int* q6 = i_pool.get();
    int* q7 = i_pool.get();
    //i_pool.test();

    i_pool.free(q7);
    i_pool.free(q1);
    i_pool.free(q2);
    i_pool.free(q3);
    i_pool.free(q4);
    i_pool.free(q5);

    std::cout << "Pool available (frees): " << i_pool.available() << '\n';
    i_pool.test();

    auto p = i_pool.get_block(3);
    std::cout << "Pool available (get_block): " << i_pool.available() << '\n';
    i_pool.test();

    i_pool.free_block(p, 3);
    std::cout << "Pool available (free_block): " << i_pool.available() << '\n';
    i_pool.test();
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

