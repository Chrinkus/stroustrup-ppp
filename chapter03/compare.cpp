#include "../text_lib/std_lib_facilities.h"

int main()
{
    cout << "Please enter two floating point values\n";
    double val1;
    double val2;
    cin >> val1 >> val2;

    if (val1 < val2)
        cout << val1 << " is the lesser\n"
             << val2 << " is the greater\n";
    if (val2 < val1)
        cout << val2 << " is the lesser\n"
             << val1 << " is the greater\n";

    cout << "Their sum is " << val1+val2 << '\n'
         << "Their difference is " << val1-val2 << '\n'
         << "Their product is " << val1*val2 << '\n'
         << "Their ratio is " << val1/val2 << '\n';
}
