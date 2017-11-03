#include "../text_lib/std_lib_facilities.h"

int main()
{
    // Program
    cout << "Write a value from zero to four and I will return it!\n";
    string string_val;
    string numeric_val;
    cin >> string_val;

    if (string_val == "zero")
        numeric_val = "0";
    else if (string_val == "one")
        numeric_val = "1";
    else if (string_val == "two")
        numeric_val = "2";
    else if (string_val == "three")
        numeric_val = "3";
    else if (string_val == "four")
        numeric_val = "4";
    else
        numeric_val = "not a number I know..";

    cout << "Your value is " << numeric_val << '\n';
}
