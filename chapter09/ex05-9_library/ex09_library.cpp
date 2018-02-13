struct Transaction {
    Book b;
    Patron p;
    Date d;
    Transaction(Book bb, Patron pp, Date dd)
        :b{bb}, p{pp}, d{dd} { }
};

class Library {
    public:
        void add_book(Book b) { books.push_back(b); }
        void add_patron(Patron p);
        void check_out_book(Book b, Patron p);
        vector<Patron> get_fee_list();
    private:
        vector<Book> books;
        vector<Patron> patrons;
        vector<Transaction> transactions;

        // private methods
        int get_new_card_num() { return patrons.size(); }
        bool is_patron(Patron& p);
        bool book_exists(Book& b);
};

bool Library::is_patron(Patron& p)
{
    for (Patron lib_p : patrons)
        if (lib_p.get_name() == p.get_name())
            return true;

    return false;
}

bool Library::book_exists(Book& b)
{
    for (Book lib_b : books)
        if (lib_b.get_ISBN() == b.get_ISBN())
            return true;

    return false;
}

void Library::add_patron(string n)
{
    int card_num = get_new_card_num();
    patrons.push_back(Patron(n, card_num));
}

void Library::check_out_book(Book& b, Patron& p, Date& d)
{
    // Check for patron & book in library system
    if (!is_patron(p)) error("Only library patrons may check-out books");
    if (!book_exists(b)) error("The library currently does not own that book");

    // Check if book is currently available
    if (!b.is_avail()) error("Book is currently unavailable");

    // Check if user owes any outstanding fees
    if (p.owes_fees()) error("Patron cannot borrow books until fees paid");

    b.check_out();
    Transaction t(b, p, d);
    transactions.push_back(t);
}

vector<Patron> Library::get_fee_list()
{
    vector<Patron> fee_list;

    for (Patron p : patrons)
        if (p.owes_fees())
            fee_list.push_back(p);

    return fee_list;
}
