#include "../text_lib/std_lib_facilities.h"

int main()
{
    cout << "Enter a measurement in miles to convert to kilometers:\n";
    double miles;
    cin >> miles;
    double kilometers = miles * 1.609;
    cout << "There are " << kilometers
         << " kilometers in " << miles
         << " miles.\n";
}
