//
// Stroustrup - Programming Principles & Practice
//
// Chapter 20 Exercise 14
//
// Define a singly linked list in the style of std::list.
//
// Have gotten 'high' to run along with basic proof of program. Awaiting aid on
// insert() from previous exercise.

#include <iostream>
#include <stdexcept>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
template<typename Elem> struct Link {
    Elem val;
    Link* succ;
    Link(const Elem& v = Elem{0}, Link* s = nullptr)
        : val{v}, succ{s} { }
};
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
template<typename Elem> class slist {
    Link<Elem>* first;
public:
    slist() : first{nullptr} { }

    ~slist()
    {
        for (Link<Elem>* p = first; p != nullptr; p = p->succ) {
            std::cout << p->val << " deleted\n";
            delete p;
        }
    }

    class iterator;

    iterator begin() { return iterator(first); }
    iterator end() { return iterator(nullptr); }

    iterator insert(iterator p, const Elem& v);
    iterator erase(iterator p);

    void push_front(const Elem& v);
    void push_back(const Elem& v);
    void pop_front();
    void pop_back();

    Elem& front();
    //Elem& back();
};
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
template<typename Elem>         // requires Element<Elem>() (19.3.3)
class slist<Elem>::iterator {
    Link<Elem>* curr;           // current link
public:
    iterator(Link<Elem>* p) : curr{p} { }

    iterator& operator++() {curr = curr->succ; return *this; }  // forward
    Elem& operator*() { return curr->val; }     // get value (dereference)
    Link<Elem>* operator->() { return curr; }   // added by me

    bool operator==(const iterator& b) const { return curr == b.curr; }
    bool operator!=(const iterator& b) const { return curr != b.curr; }
};
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
template<typename Elem>
typename slist<Elem>::iterator slist<Elem>::insert(slist<Elem>::iterator p,
        const Elem& v)
    // inserts new element AFTER p
{
    Link<Elem>* q = new Link<Elem>{v, p->succ};
    p->succ = q;
    return iterator(q);
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
template<typename Elem>
typename slist<Elem>::iterator slist<Elem>::erase(slist<Elem>::iterator p)
{
    /* Can't erase p from list w/o backwards access
     * Can remove element AFTER p but that is not an intuitive 'erase p' call
     */
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
template<typename Elem> void slist<Elem>::push_front(const Elem& v)
{
    first = new Link<Elem>{v, first};
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
    slist<int> lst; for (int x; std::cin >> x; ) lst.push_front(x);

    slist<int>::iterator p = high(lst.begin(), lst.end());
    std::cout << "the highest value was " << *p << '\n';
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

int main()
try {
    slist<char> slc;
    slc.push_front('n');
    slc.push_front('i');
    slc.push_front('l');
    slc.push_front('t');
    slc.push_front('i');
    slc.push_front('a');
    slc.push_front('c');

    std::cout << "Printing original list:\n";
    for (auto a : slc)
        std::cout << a << ' ';
    std::cout << '\n';

    std::cout << "Disgracefully adding 'y':\n";
    auto pi = slc.begin();
    ++pi; ++pi;
    slc.insert(pi, 'y');

    for (auto a : slc)
        std::cout << a << ' ';
    std::cout << '\n';

    //f();
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

