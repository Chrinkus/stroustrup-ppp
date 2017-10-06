#include "../text_lib/std_lib_facilities.h"

void fill_from_file(ifstream& ifs, vector<string>& v)
    // fill vector with strings from file stream
{
    ifs.exceptions(ifs.exceptions()|ios_base::badbit);

    for (string s; ifs >> s; )
        v.push_back(s);
    if (ifs.eof()) return;
    error("encountered fail during input file stream");
}

int main()
try {
    cout << "Please enter first file to read from:\n";
    string file_1;
    cin >> file_1;
    ifstream ifs1 {file_1};
    if (!ifs1) error("could not read from file ", file_1);

    cout << "Now enter the second file to read from:\n";
    string file_2;
    cin >> file_2;
    ifstream ifs2 {file_2};
    if (!ifs2) error("could not read from file ", file_2);

    cout << "Finally, enter the destination file:\n";
    string file_3;
    cin >> file_3;
    ofstream ofs {file_3};
    if (!ofs) error("could not write to file ", file_3);

    vector<string> contents_1;
    vector<string> contents_2;
    fill_from_file(ifs1, contents_1);
    fill_from_file(ifs2, contents_2);

    for (string s : contents_1)
        ofs << s << ' ';
    for (string s : contents_2)
        ofs << s << ' ';
}
catch(exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Something weird happened..\n";
    return 2;
}
