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

bool operator==(const ISBN& a, const ISBN& b)
{
    return a.val1 == b.val1
        && a.val2 == b.val2
        && a.val3 == b.val3
        && a.chk == b.chk;
}

bool operator!=(const ISBN& a, const ISBN& b)
{
    return !(a == b);
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

enum class Genre {
    fiction, nonfiction, periodical, biography, children
};

ostream& operator<<(ostream& os, const Genre g)
{
    vector<string> genre_tbl = {
        "fiction", "nonfiction", "periodical", "biography", "children"
    };

    return os << genre_tbl[int(g)];
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

class Book {
    public:
        Book(string t, string a, int c, ISBN I, Genre g);
        bool is_avail() { return available; }
        void check_in() { available = true; }
        void check_out() { available = false; }

        // getters
        string  get_title()     const { return title; }
        string  get_author()    const { return author; }
        int     get_copy()      const { return copyright; }
        ISBN    get_ISBN()      const { return isbn; }
        Genre   get_genre()     const { return genre; }
    private:
        string title;
        string author;
        int copyright;
        ISBN isbn;
        bool available;
        Genre genre;
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Book::Book(string t, string a, int c, ISBN I, Genre g)
     :title{t}, author{a}, copyright{c}, isbn{I}, genre {g}
{
    // Set availability
    available = true;
}

ostream& operator<<(ostream& os, const Book b)
{
    return os << b.get_title() << '\n'
              << "  " << b.get_author() << '\n'
              << "  " << b.get_genre() << '\n'
              << "  " << b.get_ISBN() << '\n';
}

bool operator==(const Book& a, const Book& b)
{
    return a.get_ISBN() == b.get_ISBN();
}

bool operator!=(const Book& a, const Book& b)
{
    return !(a == b);
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

int main()
try {
    // Program
    vector<Book> lib = {
        Book{"Eloquent Javascript", "Marijn Haverbeke", 2011,
            ISBN{1, 59327, 282, '0'}, Genre::nonfiction},
        Book{"JavaScript: The Good Parts", "Douglas Crockford", 2008, 
            ISBN{0, 596, 51774, '2'}, Genre::nonfiction}
    };

    for (Book b : lib)
        cout << b << '\n';

    cout << "Are EJS and Good Parts the same book?\n";
    cout << (lib[0] == lib[1] ? "YES" : "NO") << '\n';

    Book ppp = Book{
        "Programming Principles and Practice Using C++",
        "Bjarne Stroustrup",
        2014,
        ISBN{0, 321, 99278, '4'},
        Genre::nonfiction
    };

    Book ppp2 = ppp;

    cout << "Is PPP available?\n";
    cout << (ppp.is_avail() ? "YES" : "NO") << '\n';

    ppp.check_out();

    cout << "Is PPP available?\n";
    cout << (ppp.is_avail() ? "YES" : "NO") << '\n';

    cout << "Is there another copy available?\n";
    cout << (ppp2 == ppp && ppp2.is_avail() ? "YES" : "NO") << '\n';

    cout << "What genre is PPP?\n";
    cout << ppp.get_genre() << '\n';
}
catch(exception& e) {
    cerr << e.what() << '\n';
}
catch(...) {
    cerr << "Unknown exception" << '\n';
}
