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
        Book(string a, string t, ISBN I, Date c);
        void check_in();
        void check_out();
    private:
        ISBN I;
        string title;
        string author;
        Date copyright;
        bool available;
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Book::Book(string a, string t, string I, Date c)
     :author{a}, title{t}, ISBN{I}, copyright{c}
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

