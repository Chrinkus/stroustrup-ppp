#include "../text_lib/std_lib_facilities.h"

struct ISBN {
    ISBN(int v1, int v2, int v3, char c);
    int val1;
    int val2;
    int val3;
    char chk;
};

ISBN::ISBN(int v1, int v2, int v3, char c)
    : val1{v1}, val2{v2}, val3{v3}, chk{c} { }

ostream& operator<<(ostream& os, ISBN I)
{
    return os << "ISBN: "
              << I.val1 << '-'
              << I.val2 << '-'
              << I.val3 << '-'
              << I.chk;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

class Book {
    public:
        Book(string t, string a, int c, ISBN I);
        void check_in();
        void check_out();

        // getters
        string get_title() const { return title; }
        string get_author() const { return author; }
        int get_copy() const { return copyright; }
        ISBN get_ISBN() const { return isbn; }
        bool get_avail() const { return available; }
    private:
        string title;
        string author;
        int copyright;
        ISBN isbn;
        bool available;
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Book::Book(string t, string a, int c, ISBN I)
     :title{t}, author{a}, copyright{c}, isbn{I}
{
    // Set availability
    available = true;
}

void Book::check_in()
{
    available = true;
}

void Book::check_out()
{
    available = false;
}

ostream& operator<<(ostream& os, Book b)
{
    return os << b.get_title() << '\n'
              << "  " << b.get_author() << '\n'
              << "  " << "Copyright " << b.get_copy() << '\n'
              << "  " << b.get_ISBN() << '\n';
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

int main()
try {
    // Program
    vector<Book> lib = {
        Book{"Eloquent Javascript", "Marijn Haverbeke", 2011,
            ISBN{1, 59327, 282, '0'}},
        Book{"JavaScript: The Good Parts", "Douglas Crockford", 2008, 
            ISBN{0, 596, 51774, '2'}},
        Book{"Programming Principles and Practice Using C++",
            "Bjarne Stroustrup", 2014, ISBN{0, 321, 99278, '4'}}
    };

    for (Book b : lib)
        cout << b << '\n';
}
catch(exception& e) {
    cerr << e.what() << '\n';
}
catch(...) {
    cerr << "Unknown exception" << '\n';
}
