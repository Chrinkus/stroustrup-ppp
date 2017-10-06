#include "../text_lib/std_lib_facilities.h"

int sum_of_file(string fname)
    // returns the sum of all integers in a file
{
    ifstream ist { fname };
    if (!ist) error("could not read from file ", fname);

    int sum = 0;
    for (int i; ist >> i; )
        sum += i;

    return sum;
}

int main()
try {
    cout << sum_of_file("white_ints.txt") << '\n';
}
catch (exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Something awful happened..\n";
    return 2;
}
