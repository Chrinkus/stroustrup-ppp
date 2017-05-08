#include "../text_lib/std_lib_facilities.h"

int get_integer(string num_string)
{
    int parsed = -1;
    int i = 0;

    vector<string> digits_in_strings = { "zero", "one", "two", "three",
            "four", "five", "six", "seven", "eight", "nine" };

    vector<string> digits_as_digits = { "0", "1", "2", "3", "4", "5", "6",
            "7", "8", "9" };

    // try to find num_string as a word. if so, convert to int
    for (i = 0; i < digits_in_strings.size(); ++i) {
        if (digits_in_strings[i] == num_string)
            parsed = i;
    }

    if (parsed == -1) {
        // it must be a digit. convert from string to int
        for (i = 0; i < digits_as_digits.size(); ++i) {
            if (digits_as_digits[i] == num_string)
                parsed = i;
        }
    }

    return parsed;
}

int main()
{
    // Calculator
    int val1 = 0;
    int val2 = 0;

    double result = 0;

    char operation = ' ';

    string dig_str1 = "";
    string dig_str2 = "";

    cout << "Enter two digits, in order, and an operation to perform\n";
    while (cin >> dig_str1 >> dig_str2 >> operation) {

        val1 = get_integer(dig_str1);
        val2 = get_integer(dig_str2);

        switch (operation) {
            case '+':
                result = val1 + val2;
                break;
            case '-':
                result = val1 - val2;
                break;
            case '*':
                result = val1 * val2;
                break;
            case '/':
                result = double(val1) / val2;
                break;
            default:
                cout << "Error: unrecognized operation\n";
        }

        cout << "That equals: " << result << " shall we do another?\n";
    }
}
