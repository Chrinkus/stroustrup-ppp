#include "../text_lib/std_lib_facilities.h"

int main()
try {
    cout << "What file of numbers shall we format?\n";
    string iname;
    cin >> iname;
    ifstream ifs {iname};
    if (!ifs) error("could not read from file ", iname);

    cout << "What file shall we output to?\n";
    string oname;
    cin >> oname;
    ofstream ofs {oname};
    if (!ofs) error("could not write to file ", oname);

    vector<double> vd;
    for (double d; ifs >> d; )
        vd.push_back(d);

    ofs << scientific << setprecision(8);   // they should stick

    for (int i = 0; i < vd.size(); ++i) {
        ofs << setw(20) << vd[i];           // setw applied for every val

        if (i % 4 == 3) ofs << '\n';
    }
}
catch(exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Error!\n";
    return 2;
}
