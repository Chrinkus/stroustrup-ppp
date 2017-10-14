#include "../text_lib/std_lib_facilities.h"

vector<string> split(const string& s, const string& w)
    // returns a vector of whitespace separated substrings
    // whitespace defined as regular whitespace and added w
{
    string copy = s;

    for (char& ch : copy)
        for (char cw : w)
            if (ch == cw) ch = ' ';

    istringstream ss {copy};
    vector<string> v;

    for (string sub; ss >> sub; )
        v.push_back(sub);

    return v;
}

int main()
try {
    cout << "Enter some kind of string to split\n";
    string line;
    getline(cin, line);
    
    cout << "Split using what character set?\n";
    string char_set;
    getline(cin, char_set);

    vector<string> split_up = split(line, char_set);

    for (string str : split_up)
        cout << str << '\n';
}
catch(exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Something serious...\n";
    return 2;
}
