#include "../text_lib/std_lib_facilities.h"

bool search_word(string& word, string& line)
    // search a line for a given word
    // if found return true else return false
{
    stringstream ss {line};

    for (string s; ss >> s; )
        if (s == word) return true;

    return false;
}

vector<string> get_lines(ifstream& ist)
    // retrieve the contents of a file stream by line
{
    vector<string> lines;

    while (ist) {
        string line;
        getline(ist, line);
        lines.push_back(line);
    }

    if (!ist && !ist.eof())
        error("couldn't fill from file");

    return lines;
}

int main()
try {
    cout << "Enter the file to search:\n";
    string iname;
    cin >> iname;
    ifstream ist {iname};
    if (!ist) error("could not read from file ", iname);

    cout << "Enter a word to search for:\n";
    string word;
    cin >> word;

    vector<string> lines = get_lines(ist);

    for (int i = 0; i < lines.size(); ++i)
        if (search_word(word, lines[i]))
            cout << i + 1 << ' ' << lines[i] << '\n';
}
catch(exception& e) {
    cerr << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Error of unknown type\n";
    return 2;
}
