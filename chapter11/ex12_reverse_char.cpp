#include "../text_lib/std_lib_facilities.h"

int main()
try {
    cout << "Please enter a file to read from:\n";
    string iname;
    cin >> iname;
    ifstream ifs {iname};
    if (!ifs) error("could not read from file ", iname);

    cout << "Please enter a destination file for output:\n";
    string oname;
    cin >> oname;
    ofstream ofs {oname};
    if (!ofs) error("could not write to file ", oname);

    vector<string> lines;
    for (string line; getline(ifs, line); )
        lines.push_back(line);

    for (int i = lines.size() - 1; i >= 0; --i) {

        for (int j = lines[i].size() - 1; j >= 0; --j)
            ofs << lines[i][j];

        ofs << '\n';
    }
}
catch(exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Something serious happened\n";
    return 2;
}
