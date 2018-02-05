//
// Stroustrup - Programming Principles & Practice
//
// Chapter 20 Exercise 13
//
// Modify solution to ex 12 to use 0 (nullptr?) to represent a pointer to the
// one-past-the-end Link (list<Elem>::end())
//
// Removed 'size' from the container to achieve suggested goal of empty list
// size being equal to a single pointer (8 bytes)
//

#include <iostream>
#include <stdexcept>
#include <initializer_list>

template<typename Elem>
struct Link {
    Elem val;           // the value
    Link* prev;         // previous link
    Link* succ;         // successor (next) link
    Link(const Elem& v = Elem{0}, Link* p = nullptr, Link* s = nullptr)
        : val{v}, prev{p}, succ{s} { }
};

template<typename Elem>
class list {
public:
    list() : first{nullptr} { }

    explicit list(int n, Elem def = Elem{})
        : first{nullptr}
    {
        for (int i = 0; i < n; ++i) {
            first = new Link<Elem>{def, nullptr, first};
            if (first->succ != nullptr) first->succ->prev = first;
        }
    }

    list(std::initializer_list<Elem> lst)
        : first{nullptr}
    {
        for (auto it = lst.begin(); it != lst.end(); ++it) {
            first = new Link<Elem>{*it, nullptr, first};
            if (first->succ != nullptr) first->succ->prev = first;
        }
    }

    /*
    list(const list&);                      // copy
    list& operator=(const list&);

    list(list&&);                           // move
    list& operator=(list&&);
    */

    ~list()
    {
        while (first != nullptr) {
            auto p = first->succ;
            delete first;
            first = p;
        }
    }

    class iterator;             // member type: iterator

    iterator begin() { return iterator(first); }
    const iterator begin() const { return iterator(first); }
    iterator end() { return iterator(nullptr); }
    const iterator end() const { return iterator(nullptr); }

    iterator insert(iterator p, const Elem& v); // insert v into list before p
    iterator erase(iterator p);                 // remove p from the list

    void push_front(const Elem& v);             // insert v at front
    void push_back(const Elem& v);              // insert v at end

    /*
    void pop_front();           // remove the first element
    void pop_back();            // remove the last element

    Elem& front();              // the first element
    Elem& back();               // the last element

    // ...
    */
private:
    Link<Elem>* first;
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// iterator member class
template<typename Elem>         // requires Element<Elem>() (19.3.3)
class list<Elem>::iterator {
    Link<Elem>* curr;           // current link
public:
    iterator(Link<Elem>* p) : curr{p} { }

    iterator& operator++() {curr = curr->succ; return *this; }  // forward
    iterator& operator--() {curr = curr->prev; return *this; }  // backward
    Elem& operator*() { return curr->val; }     // get value (dereference)
    Link<Elem>* operator->() { return curr; }
    Link<Elem>* ptr() const { return curr; }

    bool operator==(const iterator& b) const { return curr == b.curr; }
    bool operator!=(const iterator& b) const { return curr != b.curr; }
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// member functions
template<typename Elem>
typename list<Elem>::iterator list<Elem>::insert(list<Elem>::iterator it,
        const Elem& val)
{
    Link<Elem>* p = new Link<Elem>{val, it->prev, it.ptr()};

    if (p->prev != nullptr) p->prev->succ = p;
    if (p->succ != nullptr) p->succ->prev = p;

    return iterator(p);
}

template<typename Elem>
typename list<Elem>::iterator list<Elem>::erase(list<Elem>::iterator it)
{
    if (it.ptr() == nullptr) return iterator(it);   // already gone
    iterator ret = iterator(it->prev);              // return next Link

    if (it->prev != nullptr) it->prev->succ = it->succ;
    if (it->succ != nullptr) it->succ->prev = it->prev;

    delete it.ptr();
    return ret;
}

template<typename Elem> void list<Elem>::push_front(const Elem& v)
{
    first = new Link<Elem>{v, nullptr, first};
    if (first->succ != nullptr) first->succ->prev = first;
}

template<typename Elem> void list<Elem>::push_back(const Elem& v)
{
    auto it = begin();
    while(it->succ != nullptr) ++it;
    it->succ = new Link<Elem>{v, it.ptr()};
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// templated functions
template<typename T>
void print(const list<T>& li, char sep = ' ')
{
    for (auto& a : li)
        std::cout << a << sep;
    std::cout << '\n';
}

template<typename Iter>
Iter high(Iter first, Iter last)
{
    Iter high = first;
    for (Iter p = first; p != last; ++p)
        if (*high < *p) high = p;
    return high;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
int main()
try {
    list<int> li1;
    list<int> li2 (3);
    list<int> li3 { 60, 62, 69, 71, 77 };

    std::cout << "Default constructor size: " << sizeof(li1) << '\n';

    print(li2);
    print(li3);

    auto it = li3.begin();
    ++it; ++it;
    li3.insert(it, 55);                 // insert

    print(li3);

    it = li3.begin();
    ++it;
    li3.erase(it);                      // erase

    li3.push_front(48);                 // push_front
    li3.push_back(80);                  // push_back
    li3.push_back(64);

    print(li3);

    auto h = high(li3.begin(), li3.end());      // high

    std::cout << "The highest in the set is: " << *h << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

