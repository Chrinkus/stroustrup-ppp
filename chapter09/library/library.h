#include "book.h"
#include "../chrono.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace Library_lib {

    class Patron {
        public:
            Patron(string n, int c)
                :name{n}, card_num{c} { }

            void inc_fees(double fee) { fees += fee; }
            void set_fees(double fee) { fees = fee; }

            string get_name() const { return name; }
            int get_card_num() const { return card_num; }
            double get_fees() const { return fees; }
            bool owes_fees() const { return fees > 0; }

        private:
            string name;
            int card_num;
            double fees = 0;
    };

    struct Transaction {
        Book b;
        Patron p;
        Chrono::Date d;
        Transaction(Book bb, Patron pp, Chrono::Date dd)
            :b{bb}, p{pp}, d{dd} { }
    };

    class Library {
        public:
            void add_book(Book b) { books.push_back(b); }
            Patron add_patron(string n);
            void check_out_book(Book& b, const Patron& p,
                    const Chrono::Date& d);
            void return_book(Book& b, Patron& p, bool on_time);
            vector<Patron> get_fee_list();
        private:
            vector<Book> books;
            vector<Patron> patrons;
            vector<Transaction> transactions;

            // private methods
            int get_new_card_num() { return patrons.size(); }
            bool is_patron(const Patron& p);
            bool book_exists(const Book& b);
    };
}
