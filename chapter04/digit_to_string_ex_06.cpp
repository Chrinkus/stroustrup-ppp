#include "../text_lib/std_lib_facilities.h"

int main()
{
    int parsed;

    string num_string = "";

    vector<string> digits_in_strings = { "zero", "one", "two", "three",
            "four", "five", "six", "seven", "eight", "nine" };

    vector<string> digits_as_digits = { "0", "1", "2", "3", "4", "5", "6",
            "7", "8", "9" };

    cout << "Enter a value from 0 - 9:\n";

    while (cin >> num_string) {
        parsed = -1;

        for (int i = 0; i < digits_in_strings.size(); ++i) {
            if (digits_in_strings[i] == num_string)
                parsed = i;
        }

        if (parsed == -1) {
            for (int j = 0; j < digits_as_digits.size(); ++j) {
                if (digits_as_digits[j] == num_string)
                    parsed = j;
            }
        }

        cout << parsed << '\n';
    }
}
