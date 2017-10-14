#include "../text_lib/std_lib_facilities.h"

vector<string> split(const string& s)
    // return a vector of whitespace separated substrings of s
{
    vector<string> v;
    istringstream ss {s};

    for (string sub; ss >> sub; )
        v.push_back(sub);

    return v;
}

int main()
try {
    cout << "Enter a long-ish string:\n";
    string line;
    getline(cin, line);

    vector<string> split_up = split(line);

    for (string s : split_up)
        cout << s << '\n';
}
catch(exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown error\n";
    return 2;
}
