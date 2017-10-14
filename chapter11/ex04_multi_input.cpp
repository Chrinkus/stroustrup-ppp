#include "../text_lib/std_lib_facilities.h"

int main()
try {
    cout << "Please enter some integers. Feel free to mix it up:\n";

    while (cin) {
        string input;
        cin >> input;
        stringstream ss {input};
        ss.unsetf(ios::dec);

        int value;
        ss >> value;

        cout << setw(12) << showbase;

        if (input[0] == '0') {
            if (input[1] == 'x' || input[1] == 'X') {
                cout << hex << value << " hexadecimal\t";
            } else {
                cout << oct << value << " octal\t\t";
            }
        } else {
            cout << dec << value << " decimal\t\t";
        }

        cout << "converts to\t"
             << dec << value << " decimal\n";
    }
}
catch(exception& e) {
    cerr << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Something bad happened..\n";
    return 2;
}
