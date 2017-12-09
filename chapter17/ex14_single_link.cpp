//
// Stroustrup - Programming Principles & Practice
//
// Chapter 17 Exercise 14
//
// A singly-linked list removes the ability to move backwards through the list
// to access previous nodes. Only forward traversal is allowed. As for why this
// would be useful.. I'm not sure. Though it would be easier to add and remove
// items from the middle of a singly linked list than a vector.

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

struct Link {
    string value;
    Link* succ;

    Link(const string& v, Link* s = nullptr)
        : value{v}, succ{s} { }

    Link* insert(Link* n);                  // insert n before this object
    Link* add(Link* n);                     // insert n after this object
    Link* erase();                          // remove this object from list
    Link* find(const string& s);            // find s in list
    const Link* find(const string& s) const;    // find s in const list

    const Link* advance(int n) const;             // move n positions in list

    Link* next() const { return succ; }
};

Link* Link::insert(Link* n)
{
    if (n == nullptr) return this;
    if (this == nullptr) return n;
    n->succ = this;
    return n;
}

Link* Link::add(Link* n)
{
    if (n == nullptr) return this;
    if (this == nullptr) return n;
    n->succ = succ;
    succ = n;
    return this;
}

Link* Link::erase()
{
    if (this == nullptr) return this;
    Link* p = succ;
    succ = nullptr;
    return p;
}

Link* Link::find(const string& s)
{
    Link* p = this;
    while (p) {
        if (p->value == s) return p;
        p = p->succ;
    }
    return nullptr;
}

const Link* Link::find(const string& s) const
{
    if (value == s)
        return this;
    else if (succ)
        return succ->find(s);

    return nullptr;
}

const Link* Link::advance(int n) const
{
    if (n < 0) throw runtime_error("Can't move backwards through list");

    if (0 < n) {
        if (succ == nullptr) return nullptr;

        return succ->advance(--n);
    }
    return this;
}

void print_all(const Link* p)
{
    while(p) {
        cout << p->value << '\n';
        p = p->succ;
    }
}

int main()
try {
    // code
    Link* pantheon = new Link{"Aman'Thul"};
    pantheon = pantheon->add(new Link{"Sargeras"});
    pantheon = pantheon->add(new Link{"Aggramar"});
    pantheon = pantheon->add(new Link{"Eonar"});
    pantheon = pantheon->add(new Link{"Khaz'goroth"});
    pantheon = pantheon->add(new Link{"Norgannon"});
    pantheon = pantheon->add(new Link{"Golganneth"});

    print_all(pantheon);
}
catch(exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}

