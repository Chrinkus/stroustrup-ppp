#include "../text_lib/std_lib_facilities.h"

int main()
{
    // Program
    cout << "Is it odd or even? Let me tell you! Enter a number:\n";
    int val;
    cin >> val;

    string result = "Its odd!\n";

    if (val % 2 == 0)
        result = "Its even!\n";

    cout << result;
}
