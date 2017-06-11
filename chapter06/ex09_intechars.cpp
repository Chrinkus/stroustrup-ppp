#include "../text_lib/std_lib_facilities.h"

class Char_stream {
    public:
        char get();
};

char Char_stream::get()
{
    char ch;
    cin >> ch;

    return ch;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Char_stream cs;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

int power(int base, int exp)
{
    int output = 1;

    for (int i = 0; i < exp; ++i)
        output *= base;

    return output;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

string pluralize(int val, string quantity)
{
    if (val != 1)
        return quantity + "s";
    else
        return quantity;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

int main()
{
    vector<int> digits;
    cout << "Enter an integer upto 4 digits long. Terminate with '|'.\n";
    bool end = false;

    while (!end && digits.size() < 4) {
        char ch = cs.get();
        if (ch == '|')
            end = true;
        else
            digits.push_back(ch - '0');
    }

    int ones;
    int tens;
    int hundreds;
    int thousands;
    int value;
    for (int i = 0; i < digits.size(); ++i) {
        int exponent = digits.size() - 1 - i;
        switch (exponent) {
            case 3:
                thousands = digits[i];
                break;
            case 2:
                hundreds = digits[i];
                break;
            case 1:
                tens = digits[i];
                break;
            case 0:
                ones = digits[i];
                break;
            default:
                error("out of range exponent");
        }
        value += digits[i] * power(10, exponent);
    }

    cout << value << " is ";

    if (thousands) cout << thousands << " " 
        << pluralize(thousands, "thousand") << " and ";

    if (hundreds) cout << hundreds << " "
        << pluralize(hundreds, "hundred") << " and ";

    if (tens) cout << tens << " " << pluralize(tens, "ten") << " and ";

    if (ones) cout << ones << " " << pluralize(ones, "one") << ".\n";

    return 0;
}
