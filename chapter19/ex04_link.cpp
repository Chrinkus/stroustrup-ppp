//
// Stroustrup - Programming Principles & Practice
//
// Chapter 19 Exercise 4
//
// Modify the Link class from Chapter 17 to be a template with the type of
// value as the template argument. Then redo ex 13 from Chapter 17 with
// Link<God>
//
// NOTE: Chapter 17 was completed a month ago at the beginning of Advent of
// Code. Comparing this solution to what I came up with for Ch 17 E 13 reveals
// how far I've come in this short time. Aside from AoC I also had dedicated
// myself to reviewing chapters 17 & 18 and writing extensive notes on the 
// material to solidify it's content in my mind.
//

#include <iostream>
#include <stdexcept>
#include <string>

template<typename T> struct Link {
    T value;
    Link<T>* prev;
    Link<T>* succ;
    Link(const T& v, Link<T>* p = nullptr, Link<T>* s = nullptr)
        : value{v}, prev{p}, succ{s} { }

    Link<T>* insert(Link<T>* n);        // insert n before this object
    Link<T>* add(Link<T>* n);           // insert n after this object
    Link<T>* add_ordered(Link<T>* n);   // insert lexicographically
    Link<T>* erase();                   // remove this object from the list
};

template<typename T>
Link<T>* Link<T>::insert(Link<T>* n)
{
    if (n == nullptr) return this;  // protect against nullptr arg
    n->prev = prev;
    n->succ = this;
    if (prev) prev->succ = n;
    prev = n;
    return n;
}

template<typename T>
Link<T>* Link<T>::add(Link<T>* n)
{
    if (n == nullptr) return this;  // protect against nullptr arg
    n->prev = this;
    n->succ = succ;
    if (succ) succ->prev = n;
    succ = n;
    return this;
}

template<typename T>
Link<T>* Link<T>::add_ordered(Link<T>* n)
    // most likely called by the head of a list
{
    if (n == nullptr) return this;
    if (n->value < value) return insert(n);

    Link<T>* p = this;
    while (p->succ && p->succ->value < n->value)
        p = p->succ;

    p->add(n);
    return this;
}

template<typename T>
Link<T>* Link<T>::erase()
{
    if (prev) prev->succ = succ;
    if (succ) succ->prev = prev;
    prev = nullptr;
    succ = nullptr;
    return this;
}

struct God {
    std::string name;
    std::string myth;
    std::string weap;
    God(const std::string& n, const std::string& m, const std::string& w)
        : name{n}, myth{m}, weap{w} { }
};

std::ostream& operator<<(std::ostream& os, God& g)
{
    return os << g.name << ' ' << g.weap;
}

bool operator<(const God& a, const God& b) { return a.name < b.name; }
bool operator>(const God& a, const God& b) { return a.name > b.name; }
bool operator<=(const God& a, const God& b) { return a.name <= b.name; }
bool operator>=(const God& a, const God& b) { return a.name >= b.name; }
bool operator==(const God& a, const God& b) { return a.name == b.name; }
bool operator!=(const God& a, const God& b) { return !(a == b); }

template<typename T>
void print_all(Link<T>* p)
{
    while (p) {
        std::cout << p->value << '\n';
        p = p->succ;
    }
}

Link<God>* break_out_list(Link<God>*& list, const std::string& s)
    // if match is found at list head, transfer head to succ link
    // if match is found, store ptr to q->succ before erasing q
{
    Link<God>* p = nullptr;                 // new list
    Link<God>* q = list;

    while (q) {
        if (q->value.myth == s) {
            if (q->prev == nullptr) list = list->succ;

            Link<God>* t = q->succ;
            p = p == nullptr ? q->erase() : p->add_ordered(q->erase());
            q = t;
        }
        else q = q->succ;
    }

    return p;
}

int main()
try {
    God thor {"Thor", "Norse", "Mjolnir"};
    God odin {"Odin", "Norse", "Gungnir"};
    God zeus {"Zeus", "Greek", "Lightning"};
    God freia {"Freia", "Norse", "Brisingamen"};
    God hera {"Hera", "Greek", "pomegranate"};
    God tyr {"Tyr", "Norse", "spear of justice"};
    God athena {"Athena", "Greek", "thunderbolt"};
    God poseidon {"Poseidon", "Greek", "trident"};
    God ares {"Ares", "Greek", "random spear"};

    Link<God>* gods = new Link<God>{thor};
    gods = gods->add(new Link<God>{odin});
    gods = gods->insert(new Link<God>{zeus});
    gods = gods->add(new Link<God>{freia});
    gods = gods->insert(new Link<God>{hera});
    gods = gods->add(new Link<God>{tyr});
    gods = gods->insert(new Link<God>{athena});
    gods = gods->add(new Link<God>{poseidon});
    gods = gods->add(new Link<God>{ares});

    std::cout << '\n';

    std::cout << "All Gods:\n";
    std::cout << "=========\n";
    print_all(gods);
    std::cout << '\n';

    Link<God>* norse = break_out_list(gods, "Norse");

    std::cout << "Norse Gods:\n";
    std::cout << "===========\n";
    print_all(norse);
    std::cout << '\n';

    Link<God>* greek = break_out_list(gods, "Greek");

    std::cout << "Greek Gods:\n";
    std::cout << "===========\n";
    print_all(greek);
    std::cout << '\n';

    std::cout << "All Gods:\n";
    std::cout << "=========\n";
    print_all(gods);
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

