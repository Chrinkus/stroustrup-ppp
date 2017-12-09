//
// Stroustrup - Programming Principles & Practice
//
// Chapter 17 Exercise 11
//

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Link {
    public:
        string value;

        Link(const string& v, Link* p = nullptr, Link* s = nullptr)
            : value{v}, prev{p}, succ{s} { }

        Link* insert(Link* n);          // insert n before this object
        Link* add(Link* n);             // insert n after this object
        Link* erase();                  // remove this object from list
        Link* find(const string& s);    // find s in list
        const Link* find(const string& s) const;    // find s in const list
                                                    // (see 18.5.1)
        const Link* advance(int n) const;   // move n positions in list

        Link* next() const { return succ; }
        Link* previous() const { return prev; }
    private:
        Link* prev;
        Link* succ;
};

Link* Link::insert(Link* n)         // insert n before p; return n
{
    if (n == nullptr) return this;  // nothing to insert
    if (this == nullptr) return n;  // nothing to insert into
    n -> succ = this;               // this comes after n
    if (prev) prev -> succ = n;
    n -> prev = prev;               // this' predecessor becomes n's predecessor
    prev = n;                       // n becomes this' predecessor
    return n;
}

Link* Link::add(Link* n)
{
    if (n == nullptr) return this;  // nothing to add
    if (this == nullptr) return n;  // nothing to add into
    n -> prev = this;               // n comes after this
    if (succ) succ -> prev = n;
    n -> succ = succ;
    succ = n;
    return n;
}

Link* Link::erase()                 // remove this object from the list
{
    if (this == nullptr) return nullptr;
    if (succ) succ -> prev = prev;
    if (prev) prev -> succ = succ;
    return succ;
}

Link* Link::find(const string& s)   // find s as value in list
{
    Link* p = this;
    while (p) {
        if (p->value == s) return p;
        p = p->next();
    }
    return nullptr;
}

// Exercise 12 - two finds are defined to handle the case where a const Link*
// calls the find and when a non-const does
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
    if (0 < n) {
        if (succ == nullptr) return nullptr;

        return succ->advance(--n);
    }
    else if (n < 0) {
        if (prev == nullptr) return nullptr;

        return prev->advance(++n);
    }
    return this;
}

void print_all(Link* p)
{
    cout << "{ ";
    while (p) {
        cout << p -> value;
        if (p = p -> next()) cout << ", ";
    }
    cout << " }";
}

int main()
try {
    Link* norse_gods = new Link{"Thor"};
    norse_gods = norse_gods->insert(new Link{"Odin"});
    norse_gods = norse_gods->insert(new Link{"Zeus"});
    norse_gods = norse_gods->insert(new Link{"Freia"});

    Link* greek_gods = new Link{"Hera"};
    greek_gods = greek_gods->insert(new Link{"Athena"});
    greek_gods = greek_gods->insert(new Link{"Mars"});
    greek_gods = greek_gods->insert(new Link{"Poseidon"});

    Link* p = greek_gods->find("Mars");
    if (p) p->value = "Ares";

    Link* p2 = norse_gods->find("Zeus");
    if (p2) {
        if (p2 == norse_gods) norse_gods = p2->next();
        p2->erase();
        greek_gods = greek_gods->insert(p2);
    }

    print_all(norse_gods);
    cout << '\n';

    print_all(greek_gods);
    cout << '\n';
}
catch(exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}

