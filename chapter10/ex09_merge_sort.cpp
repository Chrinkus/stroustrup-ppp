#include "../text_lib/std_lib_facilities.h"

void fill_from_file(ifstream& ifs, vector<string>& v)
{
    ifs.exceptions(ifs.exceptions()|ios_base::badbit);

    for (string s; ifs >> s; ) v.push_back(s);
    if (ifs.eof()) return;
    error("encountered fail in file read");
}

int main()
try {
    cout << "Enter the first file of words:\n";
    string file_1;
    cin >> file_1;
    ifstream ifs_1 { file_1 };
    if (!ifs_1) error("could not read from file ", file_1);

    cout << "Enter the second file of words:\n";
    string file_2;
    cin >> file_2;
    ifstream ifs_2 { file_2 };
    if (!ifs_2) error("could not read from file ", file_2);

    vector<string> words;

    fill_from_file(ifs_1, words);
    fill_from_file(ifs_2, words);

    sort(words);

    for (string w : words)
        cout << w << ' ';
    cout << '\n';
}
catch(exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Something weird happened..\n";
    return 2;
}
