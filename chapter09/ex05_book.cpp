#include "../text_lib/std_lib_facilities.h"

class Book {
    public:
        Book(string a, string t, string I, Date c);
        void check_in();
        void check_out();
    private:
        string ISBN;
        string title;
        string author;
        Date copyright;
        bool available;
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Book::Book(string a, string t, string I, Date c)
     :author{a}, title{t}, ISBN{I}, copyright{c}
{
    // Validate ISBN
    if (I.size() != 7)
        error("invalid ISBN");

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
