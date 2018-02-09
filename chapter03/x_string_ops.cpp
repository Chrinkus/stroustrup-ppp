// fun with string operations

#include "../text_lib/std_lib_facilities.h"

int main()
{
    cout << "Please enter your first and second names\n";
    string first;
    string second;
    cin >> first >> second;
    string name = first + " " + second;
    cout << "Hello, " << name << '\n';

    if (first == second) cout << "that's the same name twice\n";
    if (first < second)
        cout << first << " is alphabetically before " << second << '\n';
    if (first > second)
        cout << first << " is alphabetically after " << second << '\n';
}
