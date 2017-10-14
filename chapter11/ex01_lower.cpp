#include "../text_lib/std_lib_facilities.h"

int main()
try {
    cout << "Please enter a file to make lowercase:\n";
    string iname;
    cin >> iname;
    ifstream ist {iname};
    if (!ist) error("could not read from file ", iname);

    cout << "Please enter a destination for output:\n";
    string oname;
    cin >> oname;
    ofstream ost {oname};
    if (!ost) error("could not write to file ", oname);

    for (string s; ist >> s; ) {
        for (char& c : s)
            c = tolower(c);

        ost << s << ' ';
    }
    
    if (ist.eof())
        cout << iname << " read complete\n";
    else
        error("could not complete operation");
}
catch(exception& e) {
    cerr << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Something terrible happened!\n";
    return 2;
}
