//
// Stroustrup - Programming Principles & Practice
//
// Chapter 17 Exercise 13
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

struct God {
    God(const string& n, const string& m, const string& v, const string& w)
        :name{n}, mythology{m}, vehicle{v}, weapon{w} { }

    string name;
    string mythology;
    string vehicle;
    string weapon;
};

ostream& operator<<(ostream& os, God g)
{
    return os << g.name << '\t' << g.mythology;
}

class Link {
    public:
        God value;

        Link(const string& n, const string& m, const string& v,
                const string& w, Link* p = nullptr, Link* s = nullptr) :
            value{n, m, v, w},
            prev{p}, succ{s} { }

        Link* insert(Link* n);          // insert n before this object
        Link* add(Link* n);             // insert n after this object
        Link* add_ordered(Link* n);     // insert lexicographically
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

Link* Link::add_ordered(Link* n)
    // this will always be called from the first element in the list
    // handle insert case: new head of list
    // loop through rest of list and add where appropriate
{
    if (value.name > n->value.name) {
        prev = n;
        n->succ = this;
        return n;
    }
    else {
        Link* p = this;
        while (p->succ) {           // working through list checking lex
            if (p->value.name < n->value.name &&
                    n->value.name < p->succ->value.name) {
                p->add(n);
                return this;
            }
            p = p->succ;
        }
        p->add(n);                  // end of list, add to tail
    }
    return this;
}

Link* Link::erase()                 // remove this object from the list
{
    if (this == nullptr) return nullptr;
    if (succ) succ -> prev = prev;
    if (prev) prev -> succ = succ;
    prev = nullptr;
    succ = nullptr;
    return this;
}

Link* Link::find(const string& s)   // find s as value in list
{
    Link* p = this;
    while (p) {
        if (p->value.name == s) return p;
        p = p->next();
    }
    return nullptr;
}

// Exercise 12 - two finds are defined to handle the case where a const Link*
// calls the find and when a non-const does
const Link* Link::find(const string& s) const
{
    if (value.name == s)
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
    while (p) {
        cout << p -> value << '\n';
        p = p->next();
    }
}

int main()
try {
    Link* gods = new Link{"Thor", "Norse", "Chariot", "Mjolnir"};
    gods = gods->insert(new Link{"Odin", "Norse", "Sleipner", "Gungnir"});
    gods = gods->insert(new Link{"Zeus", "Greek", "", "lightning"});
    gods = gods->insert(new Link{"Freia", "Norse", "chariot", "Brisingamen"});
    gods = gods->insert(new Link{"Hera", "Greek", "chariot", "pomegranate"});
    gods = gods->insert(new Link{"Tyr", "Norse", "chariot", "spear of justice"});
    gods = gods->insert(new Link{"Athena", "Greek", "chariot", "thunderbolt"});
    gods = gods->insert(new Link{"Poseidon", "Greek", "the sea", "trident"});
    gods = gods->insert(new Link{"Ares", "Greek", "chariot", "random spear"}); 

    vector<string> norse {"Odin", "Thor", "Freia", "Tyr"};
    vector<string> greek {"Zeus", "Hera", "Athena", "Poseidon", "Ares"};

    Link* ordered_norse = nullptr; //new Link{"AAA", "AAA", "AAA", "AAA"};
    Link* ordered_greek = nullptr; //new Link{"AAA", "AAA", "AAA", "AAA"};

    for (const auto& a : norse) {
        Link* p = gods->find(a);
        p->erase();

        if (ordered_norse)
            ordered_norse = ordered_norse->add_ordered(p);
        else
            ordered_norse = p;
    }

    for (const auto& a : greek) {
        Link* p = gods->find(a);
        p->erase();

        if (ordered_greek)
            ordered_greek = ordered_greek->add_ordered(p);
        else
            ordered_greek = p;
    }

    cout << "NORSE:\n";
    print_all(ordered_norse);

    cout << "GREEK:\n";
    print_all(ordered_greek);
}
catch(exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}

