#include "library.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace Library_lib;

int main()
try{
    cout << "Begin test\n";

    Book good_parts {"JavaScript: The Good Parts", "Douglas Crockford",
            2008, ISBN{0, 596, 51774, '2'}, Genre::nonfiction};
    Book bird_lives {"Bird Lives!", "Ross Russell", 1973,
            ISBN{0, 306, 80679, '7'}, Genre::biography};
    Book goodnight {"Goodnight Moon", "Margret Wise Brown", 1947,
            ISBN{0, 694, 361, '7'}, Genre::children};
    Book ejs {"Eloquent JavaScript", "Marijn Haverbeke", 2011,
            ISBN{1, 59327, 282, '0'}, Genre::nonfiction};

    cout << ejs << '\n';

    Library lib;
    lib.add_book(good_parts);
    lib.add_book(bird_lives);
    lib.add_book(goodnight);
    lib.add_book(ejs);

    Patron chris = lib.add_patron("Chris");
    Patron jacob = lib.add_patron("Jacob");
    Patron caitlin = lib.add_patron("Caitlin");

    cout << good_parts.is_avail() << '\n';
    cout << chris.get_fees() << '\n';

    lib.check_out_book(good_parts, chris,
            Chrono::Date{2017, Chrono::Month::jul, 15});
    cout << good_parts.is_avail() << '\n';

    lib.return_book(good_parts, chris, false);
    cout << good_parts.is_avail() << '\n';
    cout << chris.get_fees() << '\n';

    vector<Patron> outstanding = lib.get_fee_list();
    for (Patron o : outstanding)
        cout << o.get_name() << '\n';
}
catch(exception& e) {
    cerr << e.what();
}
catch(...) {
    cerr << "unknown exception";
}
