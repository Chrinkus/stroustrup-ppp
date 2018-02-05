//
// Stroustrup - Programming Principles & Practice
//
// Chapter 20 Exercise 19
//
// Define a range-checked iterator for a list (bi-directional). Test on minimal
// list.
//

#include <iostream>
#include <stdexcept>
#include <initializer_list>

template<typename T>
struct Link {
    T val;
    Link* prev;
    Link* succ;
    Link(const T& v = T{0}, Link* p = nullptr, Link* s = nullptr)
        : val{v}, prev{p}, succ{s} { }
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

template<typename T>
class list {
public:
    list() : first{nullptr} { }

    list(std::initializer_list<T> ilst)
        : first{nullptr}
    {
        for (auto it = ilst.begin(); it != ilst.end(); ++it) {
            first = new Link<T>{*it, nullptr, first};
            if (first->succ != nullptr) first->succ->prev = first;
        }
    }

    ~list()
    {
        while(first != nullptr) {
            auto p = first->succ;
            delete first;
            first = p;
        }
    }

    class iterator;

    iterator begin() { return iterator(first); }
    const iterator begin() const { return iterator(first); }
    iterator end() { return iterator(nullptr); }
    const iterator end() const { return iterator(nullptr); }

    void push_front(const T&);
    void push_back(const T&);

private:
    Link<T>* first;
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

template<typename T>
class list<T>::iterator {
    Link<T>* curr;
public:
    iterator(Link<T>* p) : curr{p} { }

    iterator& operator++()
    {
        if (curr == nullptr) throw std::out_of_range("List it");
        curr = curr->succ;
        return *this;
    } 

    iterator& operator--()
    {
        if (curr->prev == nullptr) throw std::out_of_range("List it");
        curr = curr->prev;
        return *this;
    }

    T& operator*() { return curr->val; }
    const T& operator*() const { return curr->val; }

    Link<T>* operator->() { return curr; }
    Link<T>* ptr() { return curr; }

    bool operator==(const iterator& b) const { return curr == b.curr; }
    bool operator!=(const iterator& b) const { return curr != b.curr; }
};
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

template<typename T> void list<T>::push_front(const T& v)
{
    first = new Link<T>{v, nullptr, first};
    if (first->succ != nullptr) first->succ->prev = first;
}

template<typename T> void list<T>::push_back(const T& v)
{
    auto it = begin();
    while (it->succ != nullptr) ++it;
    it->succ = new Link<T>{v, it.ptr()};
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

int main()
try {
    list<double> ld { 1.55, 4.2, 6.45, 8.2, 2.9 };
    ld.push_front(3.14159);
    ld.push_back(2.71828);

    for (auto a : ld)
        std::cout << a << ' ';
    std::cout << '\n';

    auto b = ld.begin();
    try { --b; }
    catch(std::out_of_range&) {
        std::cout << "begin decrement denied!\n";
    }

    auto e = ld.end();
    try { ++e; }
    catch(std::out_of_range&) {
        std::cout << "end increment denied!\n";
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

