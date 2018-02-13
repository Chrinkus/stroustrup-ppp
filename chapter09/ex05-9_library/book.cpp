#include "book.h"

#include <iostream>
#include <vector>
#include <string>

using std::ostream;
using std::vector;
using std::string;

namespace Library_lib {

    // ISBN definitions
    ISBN::ISBN(int g, int p, int t, char c)
        : group{g}, publisher{p}, title{t}, check{c} { }

    ostream& operator<<(ostream& os, const ISBN& I)
    {
        return os << "ISBN " << I.group
                  << "-" << I.publisher
                  << "-" << I.title
                  << "-" << I.check;
    }

    bool operator==(const ISBN& a, const ISBN& b)
    {
        return a.group == b.group &&
               a.publisher == b.publisher &&
               a.title == b.title &&
               a.check == b.check;
    }

    bool operator!=(const ISBN& a, const ISBN& b)
    {
        return !(a == b);
    }

    // Genre definitions
    ostream& operator<<(ostream& os, const Genre g)
    {
        vector<string> genre_tbl = {
            "fiction", "nonfiction", "periodical", "biography", "children"
        };

        return os << genre_tbl[int(g)];
    }

    // Book definitions
    Book::Book(string t, string a, int c, ISBN I, Genre g)
        : title{t}, author{a}, copyright{c}, isbn{I}, genre{g} { }

    ostream& operator<<(ostream& os, const Book& b)
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
}
