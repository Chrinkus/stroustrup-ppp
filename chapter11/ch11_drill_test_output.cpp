#include "../text_lib/std_lib_facilities.h"

// This pretty much is a redo of all of the try-this's from the chapter

int main()
try {
    int birth_year = 1979;

    cout << "decimal\t\t" << birth_year << '\n' << hex
         << "hexadecimal\t" << birth_year << '\n' << oct
         << "octal\t\t" << birth_year << '\n';

    cout << dec << 38 << '\n';

    cout << '|' << setw(8) << "Chris" << '|' << setw(8) << "Schick" 
         << '|' << setw(24) << "seeschickrun@gmail.com"
         << '|' << setw(16) << "(204) 555-1234" << "|\n"
         << '|' << setw(8) << "Dave" << '|' << setw(8) << "Wesst"
         << '|' << setw(24) << "pocketchamp@gmail.com"
         << '|' << setw(16) << "(204) 555-4321" << "|\n";
}
catch(exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Something troubling occurred..\n";
    return 2;
}
