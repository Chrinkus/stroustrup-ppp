#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

void error(string s)
{
    throw runtime_error(s);
}

void error(string s1, string s2)
{
    throw runtime_error(s1 + s2);
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

struct Person {
    Person() { }
    Person(string ff, string ll, int aa);

    string first_name() const { return first; }
    string last_name() const { return last; }
    int age() const { return a; }

private:
    string first;
    string last;
    int a;
};

Person::Person(string ff, string ll, int aa)
    : first{ff}, last{ll}, a{aa}
{
    if (aa < 0 || 150 < aa) error("Person(): invalid age");
    
    string nn = ff + ll;        // check both names at once
    for (char c : nn) {
        switch(c) {
            case ';': case ':': case '"': case '[': case ']': case '*':
            case '&': case '^': case '%': case '$': case '#': case '@':
            case '!':
                error("Person(): bad char in names");
                break;
            default:
                break;
        }
    }
}

ostream& operator<<(ostream& os, const Person& p)
{
    return os << p.first_name() << ' '
              << p.last_name() << '\t'
              << p.age();
}

istream& operator>>(istream& is, Person& p)
{
    string f;
    string l;
    int a;

    is >> f >> l >> a;
    if (!is) error("Unable to read into Person");

    p = Person(f, l, a);

    return is;
}

int main()
try {
    // Chapter 15 Drill
    // Class definition drill

    vector<Person> vp;

    cout << "Enter some names and ages. Terminate with name 'end'\n";

    for (Person p; cin >> p; ) {
        if (p.first_name() == "end") break;
        vp.push_back(p);
    }

    for (Person p : vp)
        cout << p << '\n';

}
catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    std::cerr << "Unknown error!\n";
    return 2;
}
