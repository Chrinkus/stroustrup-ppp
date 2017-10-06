#include "../text_lib/std_lib_facilities.h"

void fill_only_ints(ifstream& ifs, vector<int>& v)
    // only fill with ints, otherwise discard as string and recurse
{
    for (int i; ifs >> i; ) v.push_back(i);
    if (ifs.eof()) return;
    ifs.clear();
    string discard;
    ifs >> discard;
    fill_only_ints(ifs, v);
}

int main()
try {
    cout << "Enter the file with some ints:\n";
    string fname;
    cin >> fname;
    ifstream ifs { fname };

    if (!ifs) error("could not read from file ", fname);
    ifs.exceptions(ifs.exceptions()|ios_base::badbit);

    vector<int> only_ints;
    fill_only_ints(ifs, only_ints);

    int sum = 0;
    for (int i : only_ints) sum += i;

    cout << "The sum of all ints in that file is: " << sum << '\n';
}
catch(exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Something weird went wrong..\n";
    return 2;
}
