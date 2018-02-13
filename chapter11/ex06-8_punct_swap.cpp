#include "../text_lib/std_lib_facilities.h"

// ex 6
// replace punctuation with whitespace
// don't touch characters within a pair of double quotes (?)
//
// ex 7
// replace don't with do not, can't with cannot etc.
// leave hyphens within words
// convert all to lower case
//
// ex 8
// make a dictionary (vector<string>, no repeats)
// run on multipage text file

int main()
{
    cout << "Enter a string to strip of punctuation:\n";
    string line;
    getline(cin, line);

    for (char& ch : line)
        switch (ch) {
            case '.': case ';': case ',': case '?': case '-': case '\'':
                ch = ' ';
        }

    cout << line << '\n';
}
