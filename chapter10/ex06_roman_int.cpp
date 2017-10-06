#include "../text_lib/std_lib_facilities.h"

class Roman_int {
    string r;
public:
    Roman_int(string s) :r{s} { }

    int as_int();
};

int get_roman_val(char r)
    // get the numeric equivalent to a given roman character
{
    int val;

    switch (r) {
        case 'I':
            val = 1;
            break;
        case 'V':
            val = 5;
            break;
        case 'X':
            val = 10;
            break;
        case 'L':
            val = 50;
            break;
        case 'C':
            val = 100;
            break;
        case 'D':
            val = 500;
            break;
        case 'M':
            val = 1000;
            break;
        default:
            error("unsupported char in Roman_int");
            break;
    }

    return val;
}

int Roman_int::as_int()
{
    vector<int> char_ints;

    for (char c : r)
        char_ints.push_back(get_roman_val(c));

    int sum = 0;
    int start = char_ints.size() - 1;
    
    for (int i = start; i >= 0; --i) {
        if (i == start)
            sum += char_ints[i];
        else {
            char_ints[i] < char_ints[i + 1]
                ? sum -= char_ints[i]
                : sum += char_ints[i];
        }
    }

    return sum;
}

int main() 
try {
    Roman_int rom {"XLII"};

    cout << rom.as_int() << '\n';
}
catch(exception& e) {
    cerr << e.what() << '\n';
}
catch(...) {
    cerr << "something bad happened\n";
}
