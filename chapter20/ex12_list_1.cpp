//
// Stroustrup - Programming Principles & Practice
//
// Chapter 20 Exercise 12
//
// Complete the definition of a List from 20.4.1-2. Get the high() example to 
// run. Allocate a Link to represent one past the end.
//
// Had many issues with this exercise. Mostly dealing with the difference
// between pointers and iterators. Exercise 13 cleans up a lot of the issues
// and is a better 'list' implementation overall.
//
// This file remains 'messy' for archival reasons.
//

#include <iostream>
#include <stdexcept>

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
    // representation and implementation details
    int sz;
    Link<Elem>* first;
    Link<Elem>* last;           // one beyond the last link
public:
    list() : sz{0}, first{new Link<Elem>{}}, last{first} { }

    explicit list(int n, Elem def = Elem())
        : sz{n}, first{new Link<Elem>{}}, last{first}
    {
        for (int i = 0; i < n; ++i) {
            first = new Link<Elem>{def, nullptr, first};
            first->succ->prev = first;
        }
    }

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
    iterator end() { return iterator(last); }

    iterator insert(iterator p, const Elem& v); // insert v into list before p
    //iterator erase(iterator p);                 // remove p from the list

    void push_front(const Elem& v);             // insert v at front
    void push_back(const Elem& v);              // insert v at end
    /*

    void pop_front();           // remove the first element
    void pop_back();            // remove the last element

    Elem& front();              // the first element
    Elem& back();               // the last element

    // ...
    */
    int size() const { return sz; }
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

    bool operator==(const iterator& b) const { return curr == b.curr; }
    bool operator!=(const iterator& b) const { return curr != b.curr; }
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// member functions
template<typename Elem>
typename list<Elem>::iterator list<Elem>::insert(list<Elem>::iterator p,
        const Elem& v)
{
    Link<Elem>* q = new Link<Elem>{v, p->prev};

    if (p->succ) q->succ = p->succ->prev;
    else q->succ = last;
    p->prev = q;

    if (q->prev) q->prev->succ = q;
    else first = q;

    ++sz;
    return iterator(q);
}

/*
template<typename Elem>
typename list<Elem>::iterator list<Elem>::erase(list<Elem>::iterator p)
{
    if (p->prev) p->prev->succ = p->succ;
    if (p->succ) p->succ->prev = p->prev;
    if (first == p) first = p->succ;
    p->prev = nullptr;
    p->succ = nullptr;
    delete p;
}
*/

template<typename Elem> void list<Elem>::push_front(const Elem& v)
{
    Link<Elem>* p = new Link<Elem>{v};
    p->succ = first;
    first->prev = p;
    first = p;
    ++sz;
}

template<typename Elem> void list<Elem>::push_back(const Elem& v)
{
    Link<Elem>* p = new Link<Elem>{v};

    if (last == first) first = p;
    else last->prev->succ = p;

    p->prev = last->prev;
    p->succ = last;
    last->prev = p;
    ++sz;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

template<typename Iter>
Iter high(Iter first, Iter last)
{
    Iter high = first;
    for (Iter p = first; p != last; ++p)
        if (*high < *p) high = p;
    return high;
}

void f()
{
    list<int> lst; for (int x; std::cin >> x; ) lst.push_front(x);

    list<int>::iterator p = high(lst.begin(), lst.end());
    std::cout << "the highest value was " << *p << '\n';
}

int main()
try {
    list<int> li1;
    std::cout << "Empty list size: " << li1.size() << '\n';

    list<int> li2 (9);
    std::cout << "int init'd size: " << li2.size() << '\n';

    for (auto& l : li2)
        l = 7;

    for (auto& l : li2)
        std::cout << l << ' ';
    std::cout << '\n';

    list<char> lc1;
    lc1.push_front('a');
    lc1.push_back('c');
    lc1.push_front('j');
    lc1.push_back('o');
    lc1.push_back('b');

    auto pi = lc1.begin();
    ++pi; ++pi; ++pi;
    lc1.insert(pi, 'k');
    lc1.insert(lc1.begin(), 'A');
    lc1.insert(lc1.end(), 'Z');

    for (auto a : lc1)
        std::cout << a << ' ';
    std::cout << '\n';

    list<char> lc2;
    lc2.push_back('o');
    lc2.push_back('r');
    lc2.push_back('a');
    lc2.push_front('n');

    for (auto a : lc2)
        std::cout << a << ' ';
    std::cout << '\n';

    f();
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

