#include "../text_lib/std_lib_facilities.h"

int get_diff(int val1, int val2) {
    int diff;

    if (val1 > val2)
        diff = val1 - val2;
    else
        diff = val2 - val1;

    return diff;
}

int main()
{
    int upper_boundary = 100;
    int lower_boundary = 1;
    int prev = upper_boundary;
    int cur = upper_boundary / 2;
    int diff = 0;
    int iterator = 0;

    char answer = ' ';

    bool guessed = false;

    cout << "Think of a number between 1 and 100.\n";

    while (iterator < 7 && guessed == false) {
        cout << "Is your number less than " << cur << "?(y/n)\n";
        cin >> answer;

        diff = get_diff(prev, cur);
        prev = cur;

        if (answer == 'y') {
            upper_boundary = cur;

            if (cur == lower_boundary + 1)
                guessed = true;
            else {
                if (diff > 1)
                    cur -= diff / 2;
                else
                    cur -= 1;
            }

        } else if (answer == 'n') {
            lower_boundary = cur - 1;

            if (cur == upper_boundary - 1)
                guessed = true;
            else {
                if (diff > 1)
                    cur += diff / 2;
                else
                    cur += 1;
            }
        }

        ++iterator;
    }

    cout << "Is your number " << cur << "?\n";
}
