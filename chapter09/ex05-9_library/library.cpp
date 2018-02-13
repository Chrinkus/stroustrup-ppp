#include "library.h"

#include <string>
#include <vector>

using namespace std;
using Chrono::Date;

namespace Library_lib {

    bool Library::is_patron(const Patron& p)
    {
        for (Patron lib_p : patrons)
            if (lib_p.get_name() == p.get_name())
                return true;

        return false;
    }

    bool Library::book_exists(const Book& b)
    {
        for (Book lib_b : books)
            if (lib_b.get_ISBN() == b.get_ISBN())
                return true;

        return false;
    }

    Patron Library::add_patron(string n)
    {
        int card_num = get_new_card_num();
        Patron p{n, card_num};
        patrons.push_back(p);
        return p;
    }

    void Library::check_out_book(Book& b, const Patron& p,
            const Chrono::Date& d)
    {
        //if (!is_patron(p)) error("Only patrons can check out books");
        //if (!book_exists(b)) error("We don't carry that book");

        //if (!b.is_avail()) error("All copies of that book are out");
        //if (p.owes_fees()) error("Patron must pay outstanding fees");

        b.check_out();
        Transaction t(b, p, d);
        transactions.push_back(t);
    }

    void Library::return_book(Book& b, Patron& p, bool on_time)
    {
        b.check_in();
        if (!on_time)
            p.inc_fees(1.23);
    }

    vector<Patron> Library::get_fee_list()
    {
        vector<Patron> fee_list;

        for (Patron p : patrons)
            if (p.owes_fees())
                fee_list.push_back(p);

        return fee_list;
    }
}
