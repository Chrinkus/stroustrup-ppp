#include "../text_lib/std_lib_facilities.h"

string disemvowel(const string& s)
    // removes vowels from a string
{
    string output = "";
    vector<char> vowels {'a', 'e', 'i', 'o', 'u'};

    for (char ch : s) {
        bool vowel = false;

        for (char v : vowels)
            if (ch == v) vowel = true;

        if (!vowel)
            output += ch;
    }

    return output;
}

int main()
try {
    cout << "Enter a file to disemvowel:\n";
    string iname;
    cin >> iname;
    ifstream ist {iname};
    if (!ist) error("could not read from file ", iname);

    cout << "Enter a destination for the output:\n";
    string oname;
    cin >> oname;
    ofstream ost {oname};
    if (!ost) error("could not write to file ", oname);

    while (ist) {
        string line;
        getline(ist, line);
        ost << disemvowel(line) << '\n';
    }

    if (!ist && !ist.eof())
        error ("trouble while reading from stream");
}
catch(exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Something unexpected happened\n";
    return 2;
}
