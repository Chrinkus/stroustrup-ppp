#include "../text_lib/std_lib_facilities.h"

vector<string> get_classes(const char ch)
    // return a vector of class strings that apply to ch
{
    vector<string> classes;

    if (isspace(ch)) classes.push_back("whitespace");
    if (isalpha(ch)) classes.push_back("letter");
    if (isdigit(ch)) classes.push_back("decimal digit");
    if (isxdigit(ch)) classes.push_back("hex digit");
    if (isupper(ch)) classes.push_back("uppercase");
    if (islower(ch)) classes.push_back("lowercase");
    if (isalnum(ch)) classes.push_back("alphanumeric");
    if (iscntrl(ch)) classes.push_back("control char");
    if (ispunct(ch)) classes.push_back("punctuation");
    if (isprint(ch)) classes.push_back("printable");
    if (isgraph(ch)) classes.push_back("alphanumpunct");

    return classes;
}

int main()
{
    cout << "Please enter a string to classify:\n";

    while (cin) {
        // get a line to catch whitespace
        string line;
        getline(cin, line);

        for (char ch : line) {
            vector<string> classifications = get_classes(ch);

            cout << ch << '\t';
            for (string c : classifications)
                cout << c << ' ';

            cout << '\n';
        }
    }
}
