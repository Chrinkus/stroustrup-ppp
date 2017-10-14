#include "../text_lib/std_lib_facilities.h"

int main()
{
    cout << "Enter a file to count chars from:\n";
    string iname;
    cin >> iname;
    ifstream ifs {iname};
    if (!ifs) error("could not read from file ", iname);

    int space = 0;
    int alpha = 0;
    int digit = 0;
    int xdigit = 0;
    int upper = 0;
    int lower = 0;
    int alnum = 0;
    int cntrl = 0;
    int punct = 0;
    int print = 0;
    int graph = 0;

    for (char ch; ifs >> ch; ) {
        if (isspace(ch)) space += 1;
        if (isalpha(ch)) alpha += 1;
        if (isdigit(ch)) digit += 1;
        if (isxdigit(ch)) xdigit += 1;
        if (isupper(ch)) upper += 1;
        if (islower(ch)) lower += 1;
        if (isalnum(ch)) alnum += 1;
        if (iscntrl(ch)) cntrl += 1;
        if (ispunct(ch)) punct += 1;
        if (isprint(ch)) print += 1;
        if (isgraph(ch)) graph += 1;
    }

    cout << "spaces: " << space << '\n'     // not sure why this is 0
         << "alphas: " << alpha << '\n'
         << "digits: " << digit << '\n'
         << "xdigit: " << xdigit << '\n'
         << "uppers: " << upper << '\n'
         << "lowers: " << lower << '\n'
         << "alnums: " << alnum << '\n'
         << "cntrls: " << cntrl << '\n'
         << "puncts: " << punct << '\n'
         << "prints: " << print << '\n'
         << "graphs: " << graph << '\n';
}
